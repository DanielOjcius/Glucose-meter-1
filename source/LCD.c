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

volatile unsigned char 	gu8v_LCDHigh;
volatile unsigned char 	gu8v_LCDLow;

volatile static unsigned char lu8v_LCD_Buffer[10] __attribute__ ((at(0x190)));
const unsigned char lu8v_LCD_Tab1[18] =
 {0x07,0x00,0x05,0x01,0x02,0x03,0x07,0x01,0x07,0x03,0x07,0x06,0x07,0x04,0x07,0x07}; //0~9~ A ~ F
const unsigned char lu8v_LCD_Tab2[18] =
 {0x0d,0x05,0x0b,0x0f,0x07,0x0e,0x0e,0x05,0x0f,0x0F,0x07,0x0e,0x08,0x0f,0x0a,0x02}; //0~9~ A ~ F
/********************************************************************
Function: LCD初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_LCDInit()
{
	_type = 0;
	_lcden = 1;
	// _lcdc = LCDC_Default;
	unsigned char lu8v_lcdcount;
	for (lu8v_lcdcount = 0; lu8v_lcdcount < 10; lu8v_lcdcount++)
	{
		lu8v_LCD_Buffer[lu8v_lcdcount] = 0XFF;
	}
}
/********************************************************************
Function: LCD update
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_LCDUpdate(unsigned char DataHigh,unsigned char DataLow)
{
	gu8v_temp0 = DataHigh & 0xf0;
	GCC_SWAP(gu8v_temp0);
	lu8v_LCD_Buffer[0] = lu8v_LCD_Tab1[gu8v_temp0];
	lu8v_LCD_Buffer[1] = lu8v_LCD_Tab2[gu8v_temp0];

	gu8v_temp0 = DataHigh & 0x0f;
	lu8v_LCD_Buffer[2] = lu8v_LCD_Tab1[gu8v_temp0];
	lu8v_LCD_Buffer[3] = lu8v_LCD_Tab2[gu8v_temp0];

	gu8v_temp0 = DataLow & 0xf0;
	GCC_SWAP(gu8v_temp0);
	lu8v_LCD_Buffer[4] = lu8v_LCD_Tab1[gu8v_temp0];
	lu8v_LCD_Buffer[5] = lu8v_LCD_Tab2[gu8v_temp0];

	gu8v_temp0 = DataLow & 0x0f;
	lu8v_LCD_Buffer[6] = lu8v_LCD_Tab1[gu8v_temp0];
	lu8v_LCD_Buffer[7] = lu8v_LCD_Tab2[gu8v_temp0];




	// lu8v_LCD_Buffer[0] = lu8v_LCD_Tab1[(DataHigh&0xf0)>>4];
	// lu8v_LCD_Buffer[1] = lu8v_LCD_Tab2[(DataHigh&0xf0)>>4];

	// lu8v_LCD_Buffer[2] = lu8v_LCD_Tab1[(DataHigh&0x0f)];
	// lu8v_LCD_Buffer[3] = lu8v_LCD_Tab2[(DataHigh&0x0f)];

	// lu8v_LCD_Buffer[4] = lu8v_LCD_Tab1[(DataLow&0xf0)>>4];
	// lu8v_LCD_Buffer[5] = lu8v_LCD_Tab2[(DataLow&0xf0)>>4];

	// lu8v_LCD_Buffer[6] = lu8v_LCD_Tab1[(DataLow&0x0f)];
	// lu8v_LCD_Buffer[8] = lu8v_LCD_Tab2[(DataLow&0x0f)];
}
