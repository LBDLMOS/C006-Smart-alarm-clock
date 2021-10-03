/*
* @file         GPIO_init.c
* @brief        io初始化
* @author       LBDLMOS（email:my@lbdlmos.cf,qq:334482015）
* @par Copyright (c):  
*               LBDLMOS
				步进电机驱动部分摘自doyoung.net
*/

//导入
#include "GPIO_init.h"

u8 STEP; 


/*
* gpio初始化(已在其他函数中调用)
* @param[in]   void  		       :无
* @retval      void                :无
*/

void gpio_set(){
    gpio_reset_pin(MA1);
    gpio_set_direction(MA1, GPIO_MODE_OUTPUT);

    gpio_reset_pin(MA2);
    gpio_set_direction(MA2, GPIO_MODE_OUTPUT);

    gpio_reset_pin(MA3);
    gpio_set_direction(MA3, GPIO_MODE_OUTPUT);

    gpio_reset_pin(MA4);
    gpio_set_direction(MA4, GPIO_MODE_OUTPUT);

    gpio_reset_pin(MB1);
    gpio_set_direction(MB1, GPIO_MODE_OUTPUT);

    gpio_reset_pin(MB2);
    gpio_set_direction(MB2, GPIO_MODE_OUTPUT);

    gpio_reset_pin(MB3);
    gpio_set_direction(MB3, GPIO_MODE_OUTPUT);

    gpio_reset_pin(MB4);
    gpio_set_direction(MB4, GPIO_MODE_OUTPUT);

    //gpio_reset_pin(power);
    //gpio_set_direction(power, GPIO_MODE_OUTPUT);
}

/*
* 步进设置
* @param[in]   void  		       :无
* @retval      void                :无
*/

void gpio_init(){
    gpio_set();
    gpio_set_level(MA1, 0);
    gpio_set_level(MA2, 0);
    gpio_set_level(MA3, 0);
    gpio_set_level(MA4, 0);
    gpio_set_level(MB1, 0);
    gpio_set_level(MB2, 0);
    gpio_set_level(MB3, 0);
    gpio_set_level(MB4, 0);
}


/*
* A关
* @param[in]   void  		       :无
* @retval      void                :无
*/

void STEP_MOTOR_OFFA (void){//电机断电
	gpio_set_level(MA1, 0);
    gpio_set_level(MA2, 0);
    gpio_set_level(MA3, 0);
    gpio_set_level(MA4, 0);
}


/*
* B关
* @param[in]   void  		       :无
* @retval      void                :无
*/

void STEP_MOTOR_OFFB (void){//电机断电
    gpio_set_level(MB1, 0);
    gpio_set_level(MB2, 0);
    gpio_set_level(MB3, 0);
    gpio_set_level(MB4, 0);
}

/*
* A单走
* @param[in]   void  		       :无
* @retval      void                :无
*/
void STEP_MOTOR_8A (u8 a,u16 speed){//电机单步8拍
	switch (a){
		case 0:
		    gpio_set_level(MA2, 0);
    		gpio_set_level(MA3, 0);
    		gpio_set_level(MA4, 0);//0
			gpio_set_level(MA1, 1);//1
			break;
		case 1:
			gpio_set_level(MA2, 1);
    		gpio_set_level(MA3, 0);
    		gpio_set_level(MA4, 0);//0
			gpio_set_level(MA1, 1);//1
			break;
		case 2:
			gpio_set_level(MA2, 1);
    		gpio_set_level(MA3, 0);
    		gpio_set_level(MA4, 0);//0
			gpio_set_level(MA1, 0);//1
			break;
		case 3:
			gpio_set_level(MA2, 1);
    		gpio_set_level(MA3, 1);
    		gpio_set_level(MA4, 0);//0
			gpio_set_level(MA1, 0);//1
			break;
		case 4:
			gpio_set_level(MA2, 0);
    		gpio_set_level(MA3, 1);
    		gpio_set_level(MA4, 0);//0
			gpio_set_level(MA1, 0);//1
			break;
		case 5:
			gpio_set_level(MA2, 0);
    		gpio_set_level(MA3, 1);
    		gpio_set_level(MA4, 1);//0
			gpio_set_level(MA1, 0);//1
			break;
		case 6:
			gpio_set_level(MA2, 0);
    		gpio_set_level(MA3, 0);
    		gpio_set_level(MA4, 1);//0
			gpio_set_level(MA1, 0);//1
			break;
		case 7:
			gpio_set_level(MA2, 0);
    		gpio_set_level(MA3, 0);
    		gpio_set_level(MA4, 1);//0
			gpio_set_level(MA1, 1);//1
			break;
		default:
			break;
	}
	vTaskDelay(speed / portTICK_PERIOD_MS); //延时
	STEP_MOTOR_OFFA(); //进入断电状态，防电机过热
}

/*
* A走
* @param[in]   void  		       :无
* @retval      void                :无
*/
void STEP_MOTOR_NUMA (u8 RL,u16 num,u8 speed){//电机按步数运行
	u16 i;
	for(i=0;i<num;i++){	
		if(RL==1){ //当RL=1右转，RL=0左转
			STEP++;
			if(STEP>7)STEP=0;
		}else{
			if(STEP==0)STEP=8;
			STEP--;
		}
		STEP_MOTOR_8A(STEP,speed);
	}
}

/*
* B单走
* @param[in]   void  		       :无
* @retval      void                :无
*/
void STEP_MOTOR_8B (u8 a,u16 speed){//电机单步8拍
	switch (a){
		case 0:
		    gpio_set_level(MB2, 0);
    		gpio_set_level(MB3, 0);
    		gpio_set_level(MB4, 0);//0
			gpio_set_level(MB1, 1);//1
			break;
		case 1:
			gpio_set_level(MB2, 1);
    		gpio_set_level(MB3, 0);
    		gpio_set_level(MB4, 0);//0
			gpio_set_level(MB1, 1);//1
			break;
		case 2:
			gpio_set_level(MB2, 1);
    		gpio_set_level(MB3, 0);
    		gpio_set_level(MB4, 0);//0
			gpio_set_level(MB1, 0);//1
			break;
		case 3:
			gpio_set_level(MB2, 1);
    		gpio_set_level(MB3, 1);
    		gpio_set_level(MB4, 0);//0
			gpio_set_level(MB1, 0);//1
			break;
		case 4:
			gpio_set_level(MB2, 0);
    		gpio_set_level(MB3, 1);
    		gpio_set_level(MB4, 0);//0
			gpio_set_level(MB1, 0);//1
			break;
		case 5:
			gpio_set_level(MB2, 0);
    		gpio_set_level(MB3, 1);
    		gpio_set_level(MB4, 1);//0
			gpio_set_level(MB1, 0);//1
			break;
		case 6:
			gpio_set_level(MB2, 0);
    		gpio_set_level(MB3, 0);
    		gpio_set_level(MB4, 1);//0
			gpio_set_level(MB1, 0);//1
			break;
		case 7:
			gpio_set_level(MB2, 0);
    		gpio_set_level(MB3, 0);
    		gpio_set_level(MB4, 1);//0
			gpio_set_level(MB1, 1);//1
			break;
		default:
			break;
	}
	vTaskDelay(speed / portTICK_PERIOD_MS); //延时
	STEP_MOTOR_OFFB(); //进入断电状态，防电机过热
}

/*
* B走
* @param[in]   void  		       :无
* @retval      void                :无
*/
void STEP_MOTOR_NUMB (u8 RL,u16 num,u8 speed){//电机按步数运行
	u16 i;
	for(i=0;i<num;i++){	
		if(RL==1){ //当RL=1右转，RL=0左转
			STEP++;
			if(STEP>7)STEP=0;
		}else{
			if(STEP==0)STEP=8;
			STEP--;
		}
		STEP_MOTOR_8B(STEP,speed);
	}
}
