//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : LCD.c
// Description: LCD顯示相關函數
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

volatile unsigned char lu8v_LED_Buffer[5];
volatile static unsigned int lu8v_LCD_Buffer[8] __attribute__ ((at(0x190)));
const unsigned char lu8v_LCD_HEX[18] =
 {0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F, // 0~9
 0x77,0x7C,0x39,0x5E,0x79,0x71,0x00,0x3f}; // A ~ F,None,all

/********************************************************************
Function: LCD初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_LCDInit()
{
	_lcdc = LCDC_Default;
	unsigned char lu8v_lcdcount;
	for (lu8v_lcdcount = 0; lu8v_lcdcount < 8; lu8v_lcdcount++)
	{
		lu8v_LCD_Buffer[lu8v_lcdcount] = lu8v_LCD_HEX[17];
	}
}
/********************************************************************
Function: LCD update
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_LCDUpdate()
{

}
