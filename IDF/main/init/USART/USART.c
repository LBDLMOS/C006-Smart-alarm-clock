/*
* @file         USART.c
* @brief        usart初始化
* @author       LBDLMOS（email:my@lbdlmos.cf,qq:334482015）
* @par Copyright (c):  
*               LBDLMOS
*/

//导入
#include "USART.h"
extern char gettxt;

/*
* uart初始化(已调用)
* @param[in]   void  		       :无
* @retval      void                :无
*/

void uart_init(void)
{
//串口配置结构体
uart_config_t uart1_config,uart2_config;
//串口参数配置->uart1
uart1_config.baud_rate = 9600; //波特率
uart1_config.data_bits = UART_DATA_8_BITS; //数据位
uart1_config.parity = UART_PARITY_DISABLE; //校验位
uart1_config.stop_bits = UART_STOP_BITS_1; //停止位
uart1_config.flow_ctrl = UART_HW_FLOWCTRL_DISABLE; //硬件流控
uart_param_config(UART_NUM_1, &uart1_config); //设置串口
//IO映射-> T:IO4  R:IO5
uart_set_pin(UART_NUM_1, TXD1_PIN, RXD1_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
//注册串口服务即使能+设置缓存区大小
uart_driver_install(UART_NUM_1, RX1_BUF_SIZE * 2, TX1_BUF_SIZE * 2, 0, NULL, 0);
//创建串口1接收任务
xTaskCreate(uart1_rx_task, "uart1_rx_task", 1024*2, NULL, configMAX_PRIORITIES, NULL);
}


/*
* usart发送
* @param[in]   void  		       :char-内容
* @retval      void                :无
*/
void printf(char a){
uart_write_bytes(UART_NUM_1, a, strlen(a));
}


/*
* 
* @param[in]   void  		       :无
* @retval      void                :无需调用，gettxt为接受值
*/
void uart1_rx_task()
{
    uint8_t* data = (uint8_t*) malloc(RX1_BUF_SIZE+1);//分配内存，用于串口接收
    while (1) {
        //获取串口1接收的数据
        const int rxBytes = uart_read_bytes(UART_NUM_1, data, RX1_BUF_SIZE, 10 / portTICK_RATE_MS);
        if (rxBytes > 0) {
            data[rxBytes] = 0;//在串口接收的数据增加结束符
            gettxt=(char *)data
        }
    }
    free(data);//释放申请的内存
}

/*
* 初始化
* @param[in]   void  		       :无
* @retval      void                :无
*/
void MY1690_Init(void){ /
	uart_init();//串口3初始化并启动
	MY1690_STOP(); //上电初始化后发送一次指令激活MP3芯片
}

/*
* 播放
* @param[in]   void  		       :无
* @retval      void                :无
*/
void MY1690_PLAY(void){ 
    printf("\xAA\x18\x01\x00\xC3");
	printf("\xAA\x02\x00\xAC"); //其中 \x 后接十六进制数据
}

/*
* 音量加1
* @param[in]   void  		       :无
* @retval      void                :无
*/
void MY1690_VUP(void){ 
	printf("\xAA\x14\x00\xBE");
}

/*
* 音量减1
* @param[in]   void  		       :无
* @retval      void                :无
*/
void MY1690_VDOWN(void){ 
	printf("\xAA\x15\x00\xBF");
}

/*
* 停止
* @param[in]   void  		       :无
* @retval      void                :无
*/
void MY1690_STOP(void){ 
	printf("\xAA\x04\x00\xAE");
}
