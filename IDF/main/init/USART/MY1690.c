#include "SOUND.h"

void MY1690_Init(void){ //初始化
	uart_init();//串口3初始化并启动
	MY1690_STOP(); //上电初始化后发送一次指令激活MP3芯片
}
void MY1690_PLAY(void){ //播放
	printf("\x7e\x03\x11\x12\xef"); //其中 \x 后接十六进制数据
}
void MY1690_PAUSE(void){ //暂停
	printf("\x7e\x03\x12\x11\xef");
}
void MY1690_PREV(void){ //上一曲
	printf("\x7e\x03\x14\x17\xef");
}
void MY1690_NEXT(void){ //下一曲
	printf("\x7e\x03\x13\x10\xef");
}
void MY1690_VUP(void){ //音量加1
	printf("\x7e\x03\x15\x16\xef");
}
void MY1690_VDOWN(void){ //音量减1
	printf("\x7e\x03\x16\x15\xef");
}
void MY1690_STOP(void){ //停止
	printf("\x7e\x03\x1E\x1D\xef");
}
///////////////////////////////////////////////////////需修改，换用杨桃语音播报驱动点曲
void MY1690_CMD1(u8 a){	//无参数的指令发送  a操作码
	u8 i;
	i=3^a;//取校验码（异或）
	USART_SendData(USART3 , 0x7e);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , 0x03);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , a);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , i);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , 0xef);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
}
void MY1690_CMD2(u8 a,u8 b){ //有参数的指令发送 a操作码 b参数
	u8 i;
	i=4^a;//取校验码（异或）
	i=i^b;//取校验码（异或）
	USART_SendData(USART3 , 0x7e);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , 0x04);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , a);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , b);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , i);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , 0xef);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
}
void MY1690_CMD3(u8 a,u16 b){ //有参数的指令发送 a操作码 b参数（16位）
	u8 i,c,d;
	c=b/0x100; //将16位参数分成2个8位参数
	d=b%0x100;
	i=5^a;//取校验码（异或）
	i=i^c;//取校验码（异或）
	i=i^d;//取校验码（异或）
	USART_SendData(USART3 , 0x7e);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , 0x05);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , a);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , c);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , d);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , i);		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
	USART_SendData(USART3 , 0xef);	while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==RESET); //检查发送中断标志位
}