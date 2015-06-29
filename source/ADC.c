//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : ADC.C
// Description: ADC&OPA相關設定
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"


/********************************************************************
Function: ADC初始化設置
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
Function: 開始ADC 採樣
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_ADCStart()
{
	_eocb   = 0;
	_adoff = 0;
//  初始化ADC轉換
	_start = 0; //start = 0,1,0開始ADC轉換
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
//  關閉ADC 電源
	_adoff = 1;
}

