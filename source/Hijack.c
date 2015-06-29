//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Hijack.c
// Description: 音頻通信相關函數
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

volatile __byte_type 	gu8v_Flag0; 		// Bit標誌位
volatile __byte_type 	gu8v_Flag1;			// Bit標誌位
volatile unsigned char  lu8v_HijackTXState	// Hijack發送狀態
/********************************************************************
Function: Hijack 發送數據
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_HijcakSend(unsigned char lu8v_FisrtData,unsigned char lu8v_SecondData)
{
	Hijack_TX_IO = 0;
	Hijack_TX    = 1;
//建立Bias信號 12bit0
}

void fun_HijackBuildBias()
{

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ INT0 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DEFINE_ISR(INT0_ISR, INT0_VECTOR)
{

}
DEFINE_ISR(Timer0A_ISR, Timer0A_VECTOR)
{
	if (gbv_firstBit)
	{
		gbv_firstBit = 0;
		Hijack_TX = 1;
		switch (lu8v_HijackTXState)
		{
			case HijackTX_Bias:
				lu8v_HijackCnt++;
				if (lu8v_HijackCnt > 12)
				{
					lu8v_HijackTXState = Hijack_TX_StartIdle;
					lu8v_HijackCnt = 0;

					gbv_DouleBit   = 1;
				}
				break;
			case Hijack_TX_StartIdle:

				break;
			case Hijack_TX_StartBit:
				break;
			case Hijack_TX_FirstData:
				break;
			case Hijack_TX_SecondData:
				break;
			case Hijack_TX_ParityBit:
				break;
			case Hijack_TX_StopBit:
				break;
			case Hijack_TX_StopIdle:
				break;
			default:
				break;
		}
	}
	else
	{
		gbv_firstBit = 1;
		Hijack_TX = 0;
	}

}
