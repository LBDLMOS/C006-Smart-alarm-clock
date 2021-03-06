/*
* @file         EC11.c
* @brief        EC11初始化
* @author       LBDLMOS（email:my@lbdlmos.cf,qq:334482015）
* @par Copyright (c):  
*               LBDLMOS
                EC11驱动部分摘自doyoung.net
*/

//导入
#include "EC11.h"
u8 KUP;//旋钮锁死标志（1为锁死）
u16 cou;

/*
* ec11-gpio初始化
* @param[in]   void  		       :无
* @retval      void                :无
*/

void ENCODER_Init(void){ //接口初始化
	gpio_reset_pin(ENCODER_L);
    gpio_set_direction(ENCODER_L, GPIO_MODE_INPUT);

    gpio_reset_pin(ENCODER_D);
    gpio_set_direction(ENCODER_D, GPIO_MODE_INPUT);

    gpio_reset_pin(ENCODER_R;
    gpio_set_direction(ENCODER_R, GPIO_MODE_INPUT);			
}


/*
* iic read 
* @param[in]   void  		       :无
* @retval      void                :1左2右3按0无
*/

u8 ENCODER_READ(void){ //接口初始化
	u8 a;//存放按键的值
	u8 kt;
	a=0;
	if(gpio_get_level(ENCODER_L)) && KUP=0;	//判断旋钮是否解除锁死
	if(gpio_get_level(ENCODER_L) && KUP==0){ //判断是否旋转旋钮，同时判断是否有旋钮锁死
		vTaskDelay(0.1 / portTICK_PERIOD_MS);
		kt=gpio_get_level(ENCODER_R);	//把旋钮另一端电平状态记录
		vTaskDelay(3 / portTICK_PERIOD_MS); //延时
		if(!gpio_get_level(ENCODER_L)){ //去抖
			if(kt==0){ //用另一端判断左或右旋转
				a=1;//右转
			}else{
				a=2;//左转
			}
			cou=0; //初始锁死判断计数器
			while(!gpio_get_level(ENCODER_L) && cou<60000){ //等待放开旋钮，同时累加判断锁死
				cou++;KUP=1;vTaskDelay(0.02 / portTICK_PERIOD_MS);; //
			}
		}
	}
	if(!gpio_get_level(ENCODER_D) && KUP==0){ //判断旋钮是否按下  
		vTaskDelay(0.02 / portTICK_PERIOD_MS);
		if(!gpio_get_level(ENCODER_D)){ //去抖动
			a=3;//在按键按下时加上按键的状态值
			while(ENCODER_D==0);	//等等旋钮放开
		}
	}
	return a;
} 