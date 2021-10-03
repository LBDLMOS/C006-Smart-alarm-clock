#ifndef IIC_H
#define IIC_H

/**
文件名：IIC.h
文件说明：IIC初始化
修改时间：
共1个函数：函数名（参数）（解释）
**/

//导入
#include <stdio.h>
#include "string.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
//I2C
#define I2C_SCL_IO 33 //SCL->IO33
#define I2C_SDA_IO 32 //SDA->IO32
#define I2C_MASTER_NUM I2C_NUM_1 //I2C_1
#define WRITE_BIT I2C_MASTER_WRITE //写:0
#define READ_BIT I2C_MASTER_READ //读:1
#define ACK_CHECK_EN 0x1 //主机检查从机的ACK
#define ACK_CHECK_DIS 0x0 //主机不检查从机的ACK
#define ACK_VAL 0x0 //应答
#define NACK_VAL 0x1 //不应答

//函数声明
void i2c_init(void);//函数1

#endif