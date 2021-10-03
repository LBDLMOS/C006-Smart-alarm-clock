#ifndef USART_H
#define USART_H
/*
* @file         USART.h
* @brief        usart初始化
* @author       LBDLMOS（email:my@lbdlmos.cf,qq:334482015）
* @par Copyright (c):  
*               LBDLMOS
*/

//导入
#include <stdio.h>
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "string.h"

//UART1
#define RX1_BUF_SIZE        (1024)
#define TX1_BUF_SIZE        (512)
#define TXD1_PIN            (GPIO_NUM_5)
#define RXD1_PIN            (GPIO_NUM_4)  

//函数声明
void uart_init(void);//函数1
void printf(char a);//函数2
void uart1_rx_task();//函数3
char gettxt;
void MY1690_Init(void);//初始化
void MY1690_PLAY(void);	//直接输入的指令
void MY1690_VUP(void);
void MY1690_VDOWN(void);
void MY1690_STOP(void);


#endif