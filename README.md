# 智能闹钟

#### 介绍
ESP32智能闹钟
在响铃同时移动，并自动避障，用户必须抓到后计算一道数学题方可解除，防止贪睡\n软硬件综合项目,支持多组闹钟设定，贪睡模式，避障车模式，强制清醒模式，贪睡模式等

#### 软件架构
C语言
ESP32-IDF开发

#### 安装教程

尚在开发中

#### 使用说明

尚在开发中

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request

#### 项目地址
[Github](https://github.com/LBDLMOS/C005-Smart-alarm-clock)\n
[Gitee](https://gitee.com/LBDLMOS/C005-Smart-alarm-clock)

#### 文件结构
├── 主目录                   
├── Arduino版                         
├── nain.c 
├── 驱动
│   ├── GPIO
│   ├── IIC               
│   ├── EC11         
│   ├── TOUCH                
│   ├── WIFI             
│   ├── USART         
│   └── OTHER
├── PCB文件

#### 特别感谢
以下文件中部分内容为引用，特此感谢\n
GPIO_init.c:步进电机驱动部分摘自doyoung.net\n
EC11.c:EC11驱动部分摘自doyoung.net\n
IIC.c:oled驱动摘自红旭无线开发团队，QQ群：671139854\n
fonts.c:来自Tilen Majerle,Alexander Lutsai
