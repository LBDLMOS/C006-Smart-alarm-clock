#ifndef __SHUND_H
#define __SOUND_H

/**
文件名：SOUND.h
文件说明：声音播放
修改时间：21.7.30-00.03
共11个函数：函数名（参数）（解释）
**/

//导入
#include "USART.h"

void MY1690_Init(void);//初始化
void MY1690_PLAY(void);	//直接输入的指令
void MY1690_PREV(void);
void MY1690_NEXT(void);
void MY1690_PAUSE(void);
void MY1690_VUP(void);
void MY1690_VDOWN(void);
void MY1690_STOP(void);
void MY1690_CMD1(u8 a);	//全部指令输入
void MY1690_CMD2(u8 a,u8 b); 
void MY1690_CMD3(u8 a,u16 b);
		 				    
#endif
