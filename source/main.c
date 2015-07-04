//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : main.c
// Description: 主程序
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/30
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

volatile __byte_type 	gu8v_FlagMain; 		// Bit標誌位
volatile unsigned char WorkModeState;		// MCU工作模式狀態標誌位
volatile unsigned char gu8v_HaltTime;		// MCU休眠時間計時
volatile unsigned char gu8v_TxDataHigh;
volatile unsigned char gu8v_TxDataLow;
volatile unsigned int  gu16v_Temp;
void main()
{
	//判斷是否為上電復位或者非正常情況下的復位
	//如果是上電復位，執行上電復位初始化，反之執行WDT溢出初始化
	if (_to == 0 || _pdf ==0)
	{
		//上電復位初始化
		fun_PowerOnInit();		// config SYS Clock,RAM,LVR,wdt,Timer,TimeBase
		fun_KeyInit();
		fun_LCDInit();
		//上電30S后進入休眠狀態
		gu8v_HaltTime  = HaltTime_Default - HaltTime30S;
		// User RAM config
		fun_HijackInit();
		gu8v_TxDataLow =0;
		gu8v_TxDataHigh=255;
		WorkModeState = HALTMODE;
	}
	else
	{
		//WDT溢出復位初始化
		_wdtc = WDT_Function_Default;
		fun_ResetInit();
	}
//主循環
	while(1)
	{
		GCC_CLRWDT();		
		fun_HijackRx();
		//是否到睡眠時間
		if (gu8v_HaltTime > HaltTime_Default)
		{
//				WorkModeState = HALTMODE;
		}
		if (gbv_7_8ms == 1)
		{
			gbv_7_8ms = 0;
			fun_KeyScan();
			fun_KeyTask();
			fun_LCDUpdate();
			// 用戶的其他任務
			// ---------
//			fun_HijcakTx(gu8v_TxDataHigh,gu8v_TxDataLow);
		}
		//輪詢各個工作模式
		switch (WorkModeState)
		{
			// 試紙檢測模式
			case STRIPSCHECKMODE:
				GCC_CLRWDT();
				break;
			// 血量檢測模式
			case BLEEDINGMODE:
				GCC_CLRWDT();
				break;
			//血糖量測模式
			case MEASURENOMODE:
				GCC_CLRWDT();
				break;
			//休眠模式
			case HALTMODE:
				fun_PrepareToHalt();
				GCC_HALT();
				GCC_NOP();
				GCC_NOP();
				GCC_NOP();
				fun_WakeUpFromHalt();
				break;
			default:
				break;
		}
	}
}





