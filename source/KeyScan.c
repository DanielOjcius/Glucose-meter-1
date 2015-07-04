//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : KeyScan.c
// Description: ���I�������
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75/HT45F77
//   Author   : ChenTing
//   Date     : 2015/05/28
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.H"
volatile __byte_type 	gu8v_FlagKey; 			// ���IBit���Iλ
volatile unsigned char 	gu8v_KeyRelease;   		// ���Iጷű��水�Iֵ
volatile unsigned char 	gu8v_KeyNow;	   		// ���εõ��İ��I��B
volatile unsigned char 	gu8v_KeyLast;	   		// �ϴεõ��İ��I��B
volatile unsigned int   gu8v_KeyDebounceCnt;	// ���IDebounce�ĴΔ�
/********************************************************************
Function: ���I�����ӳ���
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_KeyScan()
{
	KeyPortIO   = KeyPortIO_Default;
	GCC_NOP(); //���t��IO��B������Ҫ�r�g
	GCC_NOP();
	//��ȡIO״̬
	gu8v_KeyNow =  KeyPort & KeyPortIO_Default;
	// gu8v_KeyNow = gu8v_KeyNow ^ KeyNoPush;
	if (gu8v_KeyLast == gu8v_KeyNow)
	{
		// ���Iδ̧��
		if (gbv_KeyPress)
		{
			gu8v_KeyDebounceCnt++;   // Key Debounce
		}
		else
		{
			// �޼�����
			gu8v_KeyRelease = 00;
		}
	}
	else
	{
		// ���I̧��
		if (gbv_KeyPress)
		{
			// �����ͷŶ���
			if (gu8v_KeyDebounceCnt > LOOGPRESS)
			{
				gbv_KeyLongPress = 1; //�L�� ȡ�Iֵ
				gu8v_KeyRelease = gu8v_KeyLast ^ KeyPortIO_Default;
			}
			if (SHORTPRESS < gu8v_KeyDebounceCnt &&  gu8v_KeyDebounceCnt< LOOGPRESS)
			{
				gbv_KeyLongPress = 0; //�̰� ȡ�Iֵ
				gu8v_KeyRelease = gu8v_KeyLast ^ KeyPortIO_Default;
			}
			gbv_KeyPress = 0;
			gu8v_KeyDebounceCnt = 0;
		}
		else
		{
			// ��һ���а�������
			gbv_KeyPress = 1;
			gu8v_KeyDebounceCnt = 0;
		}
	}
	gu8v_KeyLast = gu8v_KeyNow; 	// �������һ�εļ�ֵ
}
/********************************************************************
Function: ���I�΄�
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
Function: ���I��ʼ��
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_KeyInit()
{
	// ���I����
	_pawu = KeyPortIO_Default;
	KeyPortIO   = KeyPortIO_Default;
	GCC_NOP();
	GCC_NOP();
	gu8v_KeyNow =  KeyPort & KeyPortIO_Default;
	gu8v_KeyLast = gu8v_KeyNow;
	gbv_KeyPress = 0;
}


