//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : sys_init.c
// Description: 系統初始化相關程序
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75
//   Author   : ChenTing
//   Date     : 2015/05/26
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"


/********************************************************************
Function: MCU復位初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_ResetInit()
{
	//IO
	fun_GPIO();


}
/********************************************************************
Function: MCU上電初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_PowerOnInit()
{
//IAP not need	to init
//EEPROM not need to init
	//RAM
	fun_RamInit();
	//Sys Clock
//	#if ((SysFrequency == 4000000)|(SysFrequency == 8000000) | (SysFrequency == 1200000))
//		_smod = 0x03;	//SysFrequnency = fH
//	#endif
//	#if ((SysFrequency == 4000000)|(SysFrequency == 8000000) | (SysFrequency == 12000000))
//		_smod = 0x03;	//SysFrequnency = fH
//	#endif
	//WDT
	_wdtc = WDT_Function_Default;
	//LVR
	_lvrc = LVR_Voltage_Default;
	//IO
	fun_GPIO();
//Timer0
	_t0on  = 0;
	_tm0c0 = TM0C0_Default;
	_tm0c1 = TM0C1_Default;
	_tm0al = TM0AL_Default;
	_tm0ah = TM0AH_Default;
	_mf0f  = 0;
	_mf0e  = 1;
//	_ta0f  = 0;
//	_ta0e  = 1;
	_t0on  = 1;
//Timer1
//Timer2

	//TimeBase
	_tbc  = TimeBase_Default;
	_tb0f = 0;
	_tb0e = 1;
	_tb1f = 0;
	_tb1e = 1;
	_emi  = 1;	//開啟TimeBase 1作為喚醒檢測
}
/********************************************************************
Function: 關閉各個模塊進入HLAT模式
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_PrepareToHalt()
{

	fun_GPIO();
	//關閉ADC及LDO,VCM等
//	fun_ADCStop();
	//關閉 timer
	_t0on = 0;
//	_pt1on = 0;
//	_pt2on = 0;
	// 關閉 UART
	_uarten = 0;
	// 關閉 SIM
	_simen = 0;
	// 關閉中斷
	_emi = 0;
	_tb1e = 0;
	_tb1f = 0;
	_tb0e = 0;
	_tb0f = 0;
	_wdtc = WDT_Disable;
}
//HALT
//SLEEPMode0	@(IDLEN==0  & LVDEN==Disable & WDT Disable )
//Stop:CPU,Fsub,Fs,Disable WDT,LVDEN must Disable

//SLEEPMode1	@(IDLEN==0  & (LVDEN==Disable || WDT Disable) )
//Stop:CPU,Fsub,Fs,
//Run :Enable WDT or LVDEN

//IDLEMode0		@(IDLEN==1  & FSYSON==0 )
//Stop:CPU,Fs
//Run :Fsub

//IDLEMode1		@(IDLEN==1  & FSYSON==1 )
//Stop:CPU
//Run :Fs,Fsub

/********************************************************************
Function: GPIO初始化
INPUT	: none
OUTPUT	: none
NOTE	: 所有IO config為輸出low
********************************************************************/
void fun_GPIO()
{
	//PA PORT
	_pac = 0x00;
	_pa  = 0x00;
	_papu= 0xff;
	_pawu= 0x00;
	//PB PORT
	_pbc = 0x00;
	_pb  = 0x00;
	_pbpu= 0xff;
	//PC PORT
	_pcc = 0x00;
	_pc  = 0x00;
	_pcpu= 0xff;
	//PD PORT
	_pdc = 0x00;
	_pd  = 0x00;
	_pdpu= 0xff;
#ifdef HT45F77
	//PE PORT
	_pec = 0x00;
	_pe  = 0x00;
	_pepu= 0xff;
#endif
}
/********************************************************************
Function:Ram_Init
INPUT	:
OUTPUT	:
NOTE	:HT45F75 無BANK1,BANK1為LCD顯示區域
		:HT45F77 有LCD,則有BANK1
********************************************************************/
void fun_RamInit()
{
//	_mp1h = 0;
//	_mp1l = 0x80;
//	while(_mp1h <RamBankSectorSum)
//	{
//		for(_tblp = 0x00;_tblp < 128;_tblp++)
//		{
//			 _iar1 = 0;
//			  _mp1l++;
//		}
//		_mp1l = 0x80;
//		_mp1h++;
//	}
}
