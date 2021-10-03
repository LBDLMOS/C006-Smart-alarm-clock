/**
文件名：IIC.c
文件说明：IIC初始化
修改时间：21.7.29-21.11
共1个函数：函数名（参数）（解释）
**/

//导入
#include "IIC.h"

/**函数1：IIC初始化
参数：
返回值:
**/
void i2c_init(void)
{
//i2c配置结构体
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;                    //I2C模式
    conf.sda_io_num = I2C_SDA_IO;                   //SDA IO映射
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;        //SDA IO模式
    conf.scl_io_num = I2C_SCL_IO;                   //SCL IO映射
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;        //SCL IO模式
    conf.master.clk_speed = 100000;                 //I2C CLK频率
    i2c_param_config(I2C_MASTER_NUM, &conf);        //设置I2C
    //注册I2C服务即使能
    i2c_driver_install(I2C_MASTER_NUM, conf.mode,0,0,0);
}
