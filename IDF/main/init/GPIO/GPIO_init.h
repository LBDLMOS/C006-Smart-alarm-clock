#ifndef GPIO_INIT_H
#define GPIO_INIT_H

/*
* @file         GPIO_init.h
* @brief        io配置
* @author       LBDLMOS（email:my@lbdlmos.cf,qq:334482015）
* @par Copyright (c):  
*               LBDLMOS
*/

//导入
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
//#define EC11_A 25
//#define EC11_B 26
//#define EC11_C 27

#define MA1 12
#define MA2 13
#define MA3 14
#define MA4 15

#define MB1 16
#define MB2 17
#define MB3 18
#define MB4 19

extern u8 STEP; //定义单步计数 全局变量

//#define power 5//pcb设计bug,5v升压芯片使能脚未接入主控

//函数声明
void gpio_set();//函数1io初始化
void gpio_init();//函数2io设置
void STEP_MOTOR_Init(void);//初始化
void STEP_MOTOR_OFFA (void);//断电状态
void STEP_MOTOR_OFFA (void);//断电状态
void STEP_MOTOR_8A (u8 a,u16 speed);
void STEP_MOTOR_NUMA (u8 RL,u16 num,u8 speed);//电机按步数运行
void STEP_MOTOR_8B (u8 a,u16 speed);
void STEP_MOTOR_NUMB (u8 RL,u16 num,u8 speed);//电机按步数运行

#endif