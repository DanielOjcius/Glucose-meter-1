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
volatile unsigned char  lu8v_HijackTxState;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackTxCnt;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackTxParityCnt;	// Hijack�l�͠�B
volatile unsigned char  gu8v_TxFisrtData;		// Hijack�l�͵�һ�P����
volatile unsigned char  gu8v_TxSecondData;		// Hijack�l�͵ڶ��P����

volatile __byte_type 	gu8v_FlagRx;			// Bit���Iλ
volatile unsigned char  lu8v_HijackRxState;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackRxCnt;		// Hijack�l�͠�B
volatile unsigned char  lu8v_HijackRxParityCnt;	// Hijack�l�͠�B
volatile unsigned char  gu8v_RxFisrtData;		// Hijack�l�͵�һ�P����
volatile unsigned char  gu8v_RxSecondData;		// Hijack�l�͵ڶ��P����

volatile __16_type 		gu16_TimeCnt1;			// Hijack �����L��
volatile __16_type 		gu16_TimeCnt2;			// Hijack �����L��

/********************************************************************
Function: Hijack ��ʼ��
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
	// for Hijack ����
	Hijack_RX_IO = 1;
	Hijack_RX 	 = 0;
	_integ &= 0b11111100;
	_integ |= INT0_Defualt;
	_int0f = 0;
	_int0e = 1;
}
/********************************************************************
Function: Hijack �l�͔���
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
		//��ʾ��
		gu8v_TxDataHigh--;
		gu8v_TxDataLow++;
		// �_��time �l�����l��̖
		_t0on = 1;
		_emi = 1;
	}
}
void fun_HijackRx()
{
	if (gbv_RxDataOk)
	{
		gbv_RxDataOk = 0;
		// TODO ��������LCD

		//�؏͵���ʼ���ՠ�B
		gbv_RxFirstEnter = 1;
		gbv_RxSecondEnter =0;
		gbv_RxThirdEnter =0;
		lu8v_HijackRxCnt = 0;
	}
	else if (gbv_RxError)
	{
		gbv_RxError = 0;
		// TODO ����ERROR��LCD

		// �؏͵���ʼ���ՠ�B
		gbv_RxFirstEnter = 1;
		gbv_RxSecondEnter =0;
		gbv_RxThirdEnter =0;
		lu8v_HijackRxCnt = 0;
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
		Hijack_TX = 1;
		if (lu8v_HijackTxState == Hijack_TX_OK)
		{
			// ��Ҫ�o�֙C�˵�λӋ��һ��ֹͣ���I
			// �֙C���ն�
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
				//����IDLE��̖ 3bit 1
				case Hijack_TX_StartIdle:
					lu8v_HijackTxCnt++;
					gbv_TxBitHigh = 1;
					if (lu8v_HijackTxCnt > 2)
					{
						lu8v_HijackTxState = Hijack_TX_StartBit;
						lu8v_HijackTxCnt = 0;
					}
					break;
				// START��̖ 1bit 0
				case Hijack_TX_StartBit:
					gbv_TxBitHigh = 0;
					lu8v_HijackTxState = Hijack_TX_FirstData;
					break;
				// ��һ�PDATA
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
				// �ڶ��PDATA
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
				// ��У�
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
				// Stop ��̖ 1bit 1
				case Hijack_TX_StopBit:
					gbv_TxBitHigh = 1;
					lu8v_HijackTxState = Hijack_TX_StopIdle;
					break;
				// IDLE ��̖ 3bit 1
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
			Hijack_TX = 0;	// high ���L�ڞ� low��һ��
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
