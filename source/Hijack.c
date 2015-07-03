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

volatile __byte_type 	gu8v_FlagTx; 			// Bit標誌位
volatile unsigned char  lu8v_HijackTxState;		// Hijack發送狀態
volatile unsigned char  lu8v_HijackTxCnt;		// Hijack發送狀態
volatile unsigned char  lu8v_HijackTxParityCnt;	// Hijack發送狀態
volatile unsigned char  gu8v_TxFisrtData;		// Hijack發送第一筆數據
volatile unsigned char  gu8v_TxSecondData;		// Hijack發送第二筆數據

volatile __byte_type 	gu8v_FlagRx;			// Bit標誌位
volatile unsigned char  lu8v_HijackRxState;		// Hijack發送狀態
volatile unsigned char  lu8v_HijackRxCnt;		// Hijack發送狀態
volatile unsigned char  lu8v_HijackRxParityCnt;	// Hijack發送狀態
volatile unsigned char  gu8v_RxFisrtData;		// Hijack發送第一筆數據
volatile unsigned char  gu8v_RxSecondData;		// Hijack發送第二筆數據

volatile __16_type 		gu16_TimeCnt1;			// Hijack 接收週期
volatile __16_type 		gu16_TimeCnt2;			// Hijack 接收週期

/********************************************************************
Function: Hijack 初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_HijackInit()
{
	Hijack_TX_IO = 0;
	Hijack_TX    = 0;
	Hijack_Wakeup_IO = 1;
	Hijack_Wakeup = 0;
	Hijack_Wakeup_W = 1;
	Hijack_ENVCC_IO = 0;
	Hijack_ENVCC = 0;
	// for Hijack 接收
	Hijack_RX_IO = 1;
	Hijack_RX 	 = 0;
	_integ &= 0b11111100;
	_integ |= INT0_Defualt;
	_int0f = 0;
	_int0e = 1;
}
/********************************************************************
Function: Hijack 發送數據
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_HijcakTx(unsigned char FisrtData,unsigned char SecondData)
{
	if (gbv_TxDataOk)
	{
		gbv_TxDataOk = 0;
		gbv_TxFirstEnter = 1;
		lu8v_HijackTxCnt = 0;
		lu8v_HijackTxState = Hijack_TX_Bias;
		gu8v_TxFisrtData = FisrtData;
		gu8v_TxSecondData = SecondData;
		//演示用
		gu8v_TxDataHigh--;
		gu8v_TxDataLow++;
		// 開啟time 發送音頻信號
		_t0on = 1;
		_emi = 1;
	}
}
void fun_HijackRx()
{
	if (gbv_RxDataOk)
	{
		gbv_RxDataOk = 0;
		// TODO 更新數據到LCD

		//回復到初始接收狀態
		gbv_RxFirstEnter = 1;
		gbv_RxSecondEnter =0;
		gbv_RxThirdEnter =0;
		lu8v_HijackRxCnt = 0;
	}
	else if (gbv_RxError)
	{
		gbv_RxError = 0;
		// TODO 更新ERROR到LCD

		// 回復到初始接收狀態
		gbv_RxFirstEnter = 1;
		gbv_RxSecondEnter =0;
		gbv_RxThirdEnter =0;
		lu8v_HijackRxCnt = 0;
	}
}
/********************************************************************
Function: INT0中斷服務子程序
INPUT	:
OUTPUT	:
NOTE	: Hijack 接收數據
********************************************************************/
DEFINE_ISR(INT0_ISR, INT0_VECTOR)
{
	if (gbv_RxFirstEnter)
	{
		gbv_RxFirstEnter = 0;
		gbv_RxSecondEnter= 1;
		_t3on = 1;
		lu8v_HijackRxState = Hijack_RX_Bias;
	}
	else if (gbv_RxSecondEnter)
	{
		gbv_RxSecondEnter = 0;
		gbv_RxThirdEnter  = 1;
		gu16_TimeCnt1.byte.byte1 = _tm3dh;
		gu16_TimeCnt1.byte.byte0 = _tm3dl;
		_t3on = 0;
		_t3on = 1;
	}
	else if (gbv_RxThirdEnter)
	{
		gbv_RxThirdEnter = 0;
		gbv_RxSecondEnter = 1;
		gu16_TimeCnt2.byte.byte1 = _tm3dh;
		gu16_TimeCnt2.byte.byte0 = _tm3dl;
		gbv_RxGetBitOk = 1;
	}
	if (gbv_RxGetBitOk)
	{
		gbv_RxGetBitOk = 0;
		if ((gu16_TimeCnt1.u16 < hijack_Period0_Max) &&(gu16_TimeCnt1.u16 < hijack_Period0_Min))
		{
			if ((gu16_TimeCnt2.u16<hijack_Period0_Max)&&(gu16_TimeCnt2.u16 < hijack_Period0_Min))
			{
				gbv_RxBitHigh = 0;
				gbv_RxDealBitOk = 1;
			}
		}
		else if ((gu16_TimeCnt1.u16 < hijack_Period1_Max)&&(gu16_TimeCnt1.u16<hijack_Period1_Min))
		{
			if ((gu16_TimeCnt2.u16<hijack_Period1_Max)&&(gu16_TimeCnt2.u16 < hijack_Period1_Min))
			{
				gbv_RxBitHigh = 1;
				gbv_RxDealBitOk = 1;
			}
		}
		else
		{
			gbv_RxError = 1;
			gbv_RxFirstEnter = 1;
		}
	}
	if (gbv_RxDealBitOk)
	{
		gbv_RxDealBitOk = 0;
		switch(lu8v_HijackRxState)
		{
			case Hijack_RX_Bias:
				if ((gbv_RxBitHigh == 0) &&(lu8v_HijackRxCnt<12))
				{
					lu8v_HijackRxCnt++;
					if (lu8v_HijackRxCnt == 12)
					{
						lu8v_HijackRxState = Hijack_RX_StartIdle;
						lu8v_HijackRxCnt = 0;
					}
				}
				else
				{
					gbv_RxError = 1;
				}
				break;
			case Hijack_RX_StartIdle:
				if ((gbv_RxBitHigh == 1)&&(lu8v_HijackRxCnt<3))
				{
					lu8v_HijackRxCnt++;
					if (lu8v_HijackRxCnt == 3)
					{
						lu8v_HijackRxState = Hijack_RX_StartBit;
						lu8v_HijackRxCnt = 0;
					}
				}
				else
				{
					gbv_RxError = 1;
				}
				break;
			case Hijack_RX_StartBit:
				if (gbv_RxBitHigh == 0)
				{
					lu8v_HijackRxState = Hijack_RX_FirstData;
				}
				else
				{
					gbv_RxError = 1;
				}
				break;
			case Hijack_RX_FirstData:
				if (lu8v_HijackRxCnt<8)
				{
					lu8v_HijackRxCnt++;
					if (gbv_RxBitHigh == 1)
					{
						gu8v_RxFisrtData = (gu8v_RxFisrtData<<1) | 0x01;
						lu8v_HijackRxParityCnt++;
					}
					else
					{
						gu8v_RxFisrtData = (gu8v_RxFisrtData<<1) | 0x00;
					}
					if (lu8v_HijackRxCnt == 8)
					{
						lu8v_HijackRxState = Hijack_RX_SecondData;
						lu8v_HijackRxCnt = 0;
					}
				}
				break;
			case Hijack_RX_SecondData:
				if (lu8v_HijackRxCnt<8)
				{
					lu8v_HijackRxCnt++;
					if (gbv_RxBitHigh == 1)
					{
						gu8v_RxSecondData = (gu8v_RxSecondData<<1) | 0x01;
						lu8v_HijackRxParityCnt++;
					}
					else
					{
						gu8v_RxSecondData = (gu8v_RxSecondData<<1) | 0x00;
					}
					if (lu8v_HijackRxCnt == 8)
					{
						lu8v_HijackRxState = Hijack_RX_ParityBit;
						lu8v_HijackRxCnt = 0;
					}
				}
				break;
			case Hijack_RX_ParityBit:
				if (gbv_RxBitHigh == (lu8v_HijackRxParityCnt & 0x01))
				{
					lu8v_HijackRxState = Hijack_RX_StopBit;
				}
				else
				{
					gbv_RxError = 1;
				}
				break;
			case Hijack_RX_StopBit:
				if (gbv_RxBitHigh == 1)
				{
					lu8v_HijackRxState = Hijack_RX_StopIdle;
				}
				else
				{
					gbv_RxError = 1;
				}
				break;
			case Hijack_RX_StopIdle:
				if (lu8v_HijackRxCnt <3)
				{
					lu8v_HijackRxCnt++;
					if (gbv_RxBitHigh == 0)
					{
						gbv_RxError = 1;
					}

				}
				if (lu8v_HijackRxCnt == 3)
				{
					gbv_RxDataOk = 1;
					lu8v_HijackRxState = Hijack_RX_Bias;
				}
				break;
			default:
				break;
		}
	}
}
/********************************************************************
Function: Timer0中斷服務子程序
INPUT	:
OUTPUT	:
NOTE	: Hijack 發送數據
********************************************************************/
DEFINE_ISR(Timer0A_ISR, Timer0A_VECTOR)
{
	GCC_CLRWDT();
	if (gbv_TxFirstEnter)
	{
		Hijack_TX = 1;
		if (lu8v_HijackTxState == Hijack_TX_OK)
		{
			// 需要給手機端低位計算一個停止標誌
			// 手機接收端
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			GCC_NOP();
			_t0on = 0;
			gbv_TxDataOk = 1;
			Hijack_TX = 0;
		}
		else
		{
			gbv_TxFirstEnter = 0;
			gbv_TxSecondEnter =1;
			switch (lu8v_HijackTxState)
			{
				//建立Bias信號 12bit 0
				case Hijack_TX_Bias:
					lu8v_HijackTxCnt++;
					gbv_TxBitHigh = 0;
					if (lu8v_HijackTxCnt > 11)
					{
						lu8v_HijackTxState = Hijack_TX_StartIdle;
						lu8v_HijackTxCnt = 0;
					}
					break;
				//建立IDLE信號 3bit 1
				case Hijack_TX_StartIdle:
					lu8v_HijackTxCnt++;
					gbv_TxBitHigh = 1;
					if (lu8v_HijackTxCnt > 2)
					{
						lu8v_HijackTxState = Hijack_TX_StartBit;
						lu8v_HijackTxCnt = 0;
					}
					break;
				// START信號 1bit 0
				case Hijack_TX_StartBit:
					gbv_TxBitHigh = 0;
					lu8v_HijackTxState = Hijack_TX_FirstData;
					break;
				// 第一筆DATA
				case Hijack_TX_FirstData:
					if (lu8v_HijackTxCnt < 8)
					{
						if (((gu8v_TxFisrtData <<lu8v_HijackTxCnt) & 0x80) == 0x80)
						{
							gbv_TxBitHigh = 1;
							lu8v_HijackTxParityCnt++;
						}
						else
						{
							gbv_TxBitHigh = 0;
						}
						lu8v_HijackTxCnt++;
						if (lu8v_HijackTxCnt == 8)
						{
							lu8v_HijackTxCnt = 0;
							lu8v_HijackTxState = Hijack_TX_SecondData;
						}
					}
					break;
				// 第二筆DATA
				case Hijack_TX_SecondData:
					if (lu8v_HijackTxCnt < 8)
					{
						if (((gu8v_TxSecondData <<lu8v_HijackTxCnt) & 0x80) == 0x80)
						{
							gbv_TxBitHigh = 1;
							lu8v_HijackTxParityCnt++;
						}
						else
						{
							gbv_TxBitHigh = 0;
						}
						lu8v_HijackTxCnt++;
						if (lu8v_HijackTxCnt == 8)
						{
							lu8v_HijackTxCnt = 0;
							lu8v_HijackTxState = Hijack_TX_ParityBit;
						}
					}
					break;
				// 奇校驗
				case Hijack_TX_ParityBit:
					if ((lu8v_HijackTxParityCnt & 0x01) == 0x00)
					{
						gbv_TxBitHigh = 1;
					}
					else
					{
						gbv_TxBitHigh = 0;
					}
					lu8v_HijackTxState = Hijack_TX_StopBit;
					break;
				// Stop 信號 1bit 1
				case Hijack_TX_StopBit:
					gbv_TxBitHigh = 1;
					lu8v_HijackTxState = Hijack_TX_StopIdle;
					break;
				// IDLE 信號 3bit 1
				case Hijack_TX_StopIdle:
					lu8v_HijackTxCnt++;
					gbv_TxBitHigh =1;
					if (lu8v_HijackTxCnt > 2)
					{
						lu8v_HijackTxState = Hijack_TX_OK;
						lu8v_HijackTxCnt = 0;
					}
					break;
				default:
					break;
			}
		}
	}
	else if (gbv_TxSecondEnter)
	{
		gbv_TxSecondEnter = 0;
		if (gbv_TxBitHigh)
		{
			gbv_TxFirstEnter = 1;
			Hijack_TX = 0;	// high 的週期為 low的一半
		}
		else
		{
			gbv_TxThirdEnter = 1;
		}
	}
	else if (gbv_TxThirdEnter)
	{
		gbv_TxThirdEnter = 0;
		gbv_TxFourthEnter = 1;
		Hijack_TX = 0;
	}
	else if (gbv_TxFourthEnter)
	{
		gbv_TxFourthEnter = 0;
		gbv_TxFirstEnter = 1;
	}
	_t0af = 0;
}
