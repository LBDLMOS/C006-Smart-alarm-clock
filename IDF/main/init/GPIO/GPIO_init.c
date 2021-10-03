/**
文件名：GPIO_init.c
文件说明：io初始化
修改时间：
共7个函数：函数名（参数）（解释）
**/

//导入
#include "GPIO_init.h"

u8 STEP; 

/**函数1：gpio初始化(已在其他函数中调用)
参数：
返回值:
**/
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

/**函数2：设置
参数：
返回值:
**/
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

/**函数2：设置
参数：
返回值:
**/
void STEP_MOTOR_OFFA (void){//电机断电
	gpio_set_level(MA1, 0);
    gpio_set_level(MA2, 0);
    gpio_set_level(MA3, 0);
    gpio_set_level(MA4, 0);
}

/**函数2：设置
参数：
返回值:
**/
void STEP_MOTOR_OFFB (void){//电机断电
    gpio_set_level(MB1, 0);
    gpio_set_level(MB2, 0);
    gpio_set_level(MB3, 0);
    gpio_set_level(MB4, 0);
}

/**函数2：设置
参数：
返回值:
**/
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

/**函数2：设置
参数：
返回值:
**/
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

/**函数2：设置
参数：
返回值:
**/
void STEP_MOTOR_LOOPA (u8 RL,u8 LOOP,u8 speed){//电机按圈数运行
	STEP_MOTOR_NUMA(RL,LOOP*4076,speed); 
}
