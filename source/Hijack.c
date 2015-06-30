//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Hijack.c
// Description: ���lͨ�����P����
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

volatile __byte_type 	gu8v_FlagTx; 			// Bit���Iλ
volatile __byte_type 	gu8v_FlagRx;			// Bit���Iλ
volatile unsigned char  lu8v_HijackTxState;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackRxState;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackTxCnt;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackRxCnt;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackParityCnt;	// Hijack�l�͠�B
volatile unsigned char  gu8v_FisrtData;			// Hijack�l�͵�һ�P����
volatile unsigned char  gu8v_SecondData;		// Hijack�l�͵ڶ��P����

volatile __16_type 		gu16_TimeCnt1;			// Hijack �����L��
volatile __16_type 		gu16_TimeCnt2;			// Hijack �����L��
/********************************************************************
Function: Hijack �l�͔���
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_HijcakTxStart(unsigned char FisrtData,unsigned char SecondData)
{
	if (gbv_TxDataOk)
	{
		gbv_TxDataOk = 0;
		Hijack_TX_IO = 0;
		Hijack_TX    = 0;
		gbv_TxFirstEnter = 1;
		lu8v_HijackTxCnt = 0;
		lu8v_HijackTxState = Hijack_TX_Bias;
		gu8v_FisrtData = FisrtData;
		gu8v_SecondData = SecondData;
		// �_��time �l�����l��̖
		_t0on = 1;
		_emi = 1;
	}
}
/********************************************************************
Function: INT0�Д�����ӳ���
INPUT	:
OUTPUT	:
NOTE	: Hijack ���Ք���
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
					if (lu8v_HijackRxCnt == 8)
					{
						lu8v_HijackRxState = Hijack_RX_SecondData;
						lu8v_HijackRxCnt = 0;
					}
				}
				break;
			case Hijack_RX_SecondData:
				break;
			case Hijack_RX_ParityBit:
				break;
			case Hijack_RX_StopBit:
				break;
			case Hijack_RX_StopIdle:
				break;
			default:
				break;
		}
	}
}
/********************************************************************
Function: Timer0�Д�����ӳ���
INPUT	:
OUTPUT	:
NOTE	: Hijack �l�͔���
********************************************************************/
DEFINE_ISR(Timer0A_ISR, Timer0A_VECTOR)
{
	GCC_CLRWDT();
	if (gbv_TxFirstEnter)
	{
		gbv_TxFirstEnter = 0;
		gbv_TxSecondEnter =1;
		Hijack_TX = 1;
		switch (lu8v_HijackTxState)
		{
			//����Bias��̖ 12bit 0
			case Hijack_TX_Bias:
				lu8v_HijackTxCnt++;
				gbv_TxBitHigh = 0;
				if (lu8v_HijackTxCnt > 11)
				{
					lu8v_HijackTxState = Hijack_TX_StartIdle;
					lu8v_HijackTxCnt = 0;
				}
				break;
			case Hijack_TX_StartIdle:
				lu8v_HijackTxCnt++;
				gbv_TxBitHigh = 1;
				if (lu8v_HijackTxCnt > 2)
				{
					lu8v_HijackTxState = Hijack_TX_StartBit;
					lu8v_HijackTxCnt = 0;
				}
				break;
			case Hijack_TX_StartBit:
				gbv_TxBitHigh = 0;
				lu8v_HijackTxState = Hijack_TX_FirstData;
				break;
			case Hijack_TX_FirstData:
				lu8v_HijackTxCnt++;
				if (lu8v_HijackTxCnt < 8)
				{
					if (((gu8v_FisrtData <<lu8v_HijackTxCnt) & 0x80) == 0x80)
					{
						gbv_TxBitHigh = 1;
					}
					else
					{
						gbv_TxBitHigh = 0;
						lu8v_HijackParityCnt++;
					}
				}
				else
				{
					lu8v_HijackTxCnt = 0;
					lu8v_HijackTxState = Hijack_TX_SecondData;
				}
				break;
			case Hijack_TX_SecondData:
				lu8v_HijackTxCnt++;
				if (lu8v_HijackTxCnt < 8)
				{
					if (((gu8v_SecondData <<lu8v_HijackTxCnt) & 0x80) == 0x80)
					{
						gbv_TxBitHigh = 1;
					}
					else
					{
						gbv_TxBitHigh = 0;
						lu8v_HijackParityCnt++;
					}
				}
				else
				{
					lu8v_HijackTxCnt = 0;
					lu8v_HijackTxState = Hijack_TX_ParityBit;
				}
				break;
			case Hijack_TX_ParityBit:
				if ((lu8v_HijackParityCnt & 0x01) == 0x01)
				{
					gbv_TxBitHigh = 1;
				}
				lu8v_HijackTxState = Hijack_TX_StopBit;
				break;
			case Hijack_TX_StopBit:
				gbv_TxBitHigh = 1;
				lu8v_HijackTxState = Hijack_TX_StopIdle;
				break;
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
	else if (gbv_TxSecondEnter)
	{
		gbv_TxSecondEnter = 0;
		if (gbv_TxBitHigh)
		{
			gbv_TxFirstEnter = 1;
			Hijack_TX = 0;	// high ���L�ڞ� low��һ��
			if (lu8v_HijackTxState == Hijack_TX_OK)
			{
				_t0on = 0;
				gbv_TxDataOk = 1;
			}
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
