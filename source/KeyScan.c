//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : KeyScan.c
// Description: 按鍵掃描程序
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75/HT45F77
//   Author   : ChenTing
//   Date     : 2015/05/28
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.H"
volatile __byte_type 	gu8v_FlagKey; 			// 按鍵Bit標誌位
volatile unsigned char 	gu8v_KeyRelease;   		// 按鍵釋放保存按鍵值
volatile unsigned char 	gu8v_KeyNow;	   		// 當次得到的按鍵狀態
volatile unsigned char 	gu8v_KeyLast;	   		// 上次得到的按鍵狀態
volatile unsigned int   gu8v_KeyDebounceCnt;	// 按鍵Debounce的次數
/********************************************************************
Function: 按鍵掃描子程序
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_KeyScan()
{
	KeyPortIO   = KeyPortIO_Default;
	GCC_NOP(); //延遲，IO狀態穩定需要時間
	GCC_NOP();
	//读取IO状态
	gu8v_KeyNow =  KeyPort & KeyPortIO_Default;
	// gu8v_KeyNow = gu8v_KeyNow ^ KeyNoPush;
	if (gu8v_KeyLast == gu8v_KeyNow)
	{
		// 按鍵未抬起
		if (gbv_KeyPress)
		{
			gu8v_KeyDebounceCnt++;   // Key Debounce
		}
		else
		{
			// 无键按下
			gu8v_KeyRelease = 00;
		}
	}
	else
	{
		// 按鍵抬起
		if (gbv_KeyPress)
		{
			// 按键释放动作
			if (gu8v_KeyDebounceCnt > LOOGPRESS)
			{
				gbv_KeyLongPress = 1; //長按 取鍵值
				gu8v_KeyRelease = gu8v_KeyLast ^ KeyPortIO_Default;
			}
			if (SHORTPRESS < gu8v_KeyDebounceCnt &&  gu8v_KeyDebounceCnt< LOOGPRESS)
			{
				gbv_KeyLongPress = 0; //短按 取鍵值
				gu8v_KeyRelease = gu8v_KeyLast ^ KeyPortIO_Default;
			}
			gbv_KeyPress = 0;
			gu8v_KeyDebounceCnt = 0;
		}
		else
		{
			// 第一次有按键按下
			gbv_KeyPress = 1;
			gu8v_KeyDebounceCnt = 0;
		}
	}
	gu8v_KeyLast = gu8v_KeyNow; 	// 更新最后一次的键值
}
/********************************************************************
Function: 按鍵任務
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_KeyTask()
{
	if  (gu8v_KeyRelease == KeyTx)
	{
		gu8v_TxDataHigh--;
		gu8v_TxDataLow++;
		fun_HijcakTx(gu8v_TxDataHigh,gu8v_TxDataLow);
	}
	gu8v_KeyRelease = 0;
}
/********************************************************************
Function: 按鍵初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_KeyInit()
{
	// 按鍵喚醒
	_pawu = KeyPortIO_Default;
	KeyPortIO   = KeyPortIO_Default;
	GCC_NOP();
	GCC_NOP();
	gu8v_KeyNow =  KeyPort & KeyPortIO_Default;
	gu8v_KeyLast = gu8v_KeyNow;
	gbv_KeyPress = 0;
}


