//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : main.c
// Description: ������
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/30
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

volatile __byte_type 	gu8v_FlagMain; 		// Bit���Iλ
volatile unsigned char WorkModeState;		// MCU����ģʽ��B���Iλ
volatile unsigned char gu8v_HaltTime;		// MCU���ߕr�gӋ�r
volatile unsigned char gu8v_TxDataHigh;
volatile unsigned char gu8v_TxDataLow;
volatile unsigned int  gu16v_Temp;
void main()
{
	//�Д��Ƿ����늏�λ���߷�������r�µď�λ
	//�������늏�λ��������늏�λ��ʼ������֮����WDT�����ʼ��
	if (_to == 0 || _pdf ==0)
	{
		//��늏�λ��ʼ��
		fun_PowerOnInit();		// config SYS Clock,RAM,LVR,wdt,Timer,TimeBase
		fun_KeyInit();
		fun_LCDInit();
		//���30S���M�����ߠ�B
		gu8v_HaltTime  = HaltTime_Default - HaltTime30S;
		// User RAM config
		fun_HijackInit();
		gu8v_TxDataLow =0;
		gu8v_TxDataHigh=255;
		WorkModeState = HALTMODE;
	}
	else
	{
		//WDT�����λ��ʼ��
		_wdtc = WDT_Function_Default;
		fun_ResetInit();
	}
//��ѭ�h
	while(1)
	{
		GCC_CLRWDT();		
		fun_HijackRx();
		//�Ƿ�˯�ߕr�g
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
			// �Ñ��������΄�
			// ---------
//			fun_HijcakTx(gu8v_TxDataHigh,gu8v_TxDataLow);
		}
		//݆ԃ��������ģʽ
		switch (WorkModeState)
		{
			// ԇ���z�yģʽ
			case STRIPSCHECKMODE:
				GCC_CLRWDT();
				break;
			// Ѫ���z�yģʽ
			case BLEEDINGMODE:
				GCC_CLRWDT();
				break;
			//Ѫ�����yģʽ
			case MEASURENOMODE:
				GCC_CLRWDT();
				break;
			//����ģʽ
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





