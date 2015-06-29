//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : ADC.C
// Description: ADC&OPA���P�O��
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"


/********************************************************************
Function: ADC��ʼ���O��
INPUT	: ADCChannnel
OUTPUT	:
NOTE	:
********************************************************************/
void fun_ADCInit(unsigned char ADCChannel )
{
	_adcr0 = ADCChannel;
	_adcr1 = ADCSampleRate;
	_adcr2 = ADCVR_Default;
}
/********************************************************************
Function: �_ʼADC ���
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_ADCStart()
{
	_eocb   = 0;
	_adoff = 0;
//  ��ʼ��ADC�D�Q
	_start = 0; //start = 0,1,0�_ʼADC�D�Q
	_start = 1;
	_start = 0;
//  User RAM Init

}
/********************************************************************
Function: Disable ADC
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_ADCStop()
{
//  �P�]ADC �Դ
	_adoff = 1;
}

