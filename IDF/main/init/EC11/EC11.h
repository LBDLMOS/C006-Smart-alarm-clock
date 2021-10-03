#ifndef __EC11_H
#define __EC11_H	 

/**
文件名：IIC.h
文件说明：IIC初始化
修改时间：
共2个函数：函数名（参数）（解释）
**/

//导入
#include <stdio.h>
#include "esp_system.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define ENCODER_L	25	//定义IO接口
#define ENCODER_D	21	//定义IO接口
#define ENCODER_R	27	//定义IO接口


void ENCODER_Init(void);//初始化
u8 ENCODER_READ(void);


		 				    
#endif