//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : sys_init.c
// Description: ϵ�y��ʼ�����P����
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75
//   Author   : ChenTing
//   Date     : 2015/05/26
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"


/********************************************************************
Function: MCU��λ��ʼ��
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_ResetInit()
{
	//IO
	fun_GPIOInit();


}
/********************************************************************
Function: MCU��늳�ʼ��
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_PowerOnInit()
{
//IAP not need	to init
//RAM
	fun_RamInit();
//Sys Clock
	_smod0 = 0x03;		// Fsys = Fh
//IO
	fun_GPIOInit();
//WDT
	_wdtc = WDT_Function_Default;
//LVR
	_lvrc = LVR_Voltage_Default;
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
	_emi  = 1;	//�_��TimeBase 1���醾�љz�y
}
/********************************************************************
Function: �P�]����ģ�K�M��HLATģʽ
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_PrepareToHalt()
{

	fun_GPIOInit();
	//�P�]ADC��LDO,VCM��
//	fun_ADCStop();
	//�P�] timer
	_t0on = 0;
//	_pt1on = 0;
//	_pt2on = 0;
	// �P�] UART
	_uarten = 0;
	// �P�] SIM
	_simen = 0;
	// �P�]�Д�
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
Function: GPIO��ʼ��
INPUT	: none
OUTPUT	: none
NOTE	: ����IO config��ݔ��low
********************************************************************/
void fun_GPIOInit()
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
	//PE PORT
	_pec = 0x00;
	_pe  = 0x00;
	_pepu= 0xff;
#ifndef HT45F65
	//PF PORT
	_pfc = 0x00;
	_pf  = 0x00;
	_pfpu= 0xff;
	//PG PORT
	_pgc = 0x00;
	_pg  = 0x00;
	_pgpu= 0xff;
	//PH PORT
	_phc = 0x00;
	_ph  = 0x00;
	_phpu= 0xff;
#endif
// ���_�D��
#ifdef HT45F65
	_pafs = PAFS_Default;
	_pbfs = PBFS_Default;
	_pcfs = PCFS_Default;
	_pdfs0= PDFS0_Default;
	_pdfs1= PDFS1_Default;
	_pefs0= PEFS0_Default;
	_pefs1= PEFS1_Default;
#endif
#ifdef HT45F66
	_pafs = PAFS_Default;
	_pbfs = PBFS_Default;
	_pcfs = PCFS_Default;
	_pdfs = PDFS_Default;
	_pefs = PEFS_Default;
	_pffs = PFFS_Default;
	_pgfs = PGFS_Default;
	_phfs = PHFS_Default;
	_sfs0 = SFS0_Default;
	_sfs1 = SFS1_Default;
#endif
#ifdef HT45F67
	_pafs = PAFS_Default;
	_pbfs = PBFS_Default;
	_pcfs = PCFS_Default;
	_pdfs = PDFS_Default;
	_pefs = PEFS_Default;
	_pffs = PFFS_Default;
	_pgfs = PGFS_Default;
	_phfs = PHFS_Default;
	_sfs0 = SFS0_Default;
	_sfs1 = SFS1_Default;
#endif
}
/********************************************************************
Function:Ram_Init
INPUT	:
OUTPUT	:
NOTE	:HT45F75 �oBANK1,BANK1��LCD�@ʾ�^��
		:HT45F77 ��LCD,�t��BANK1
********************************************************************/
void fun_RamInit()
{
	_bp &= 0b11100000;
	_mp1 = 0x80;
	while((_bp &0b00011111) <=RamBankSectorSum)
	{
		for(_tblp = 0x00;_tblp < 128;_tblp++)
		{
			 _iar1 = 0;
			  _mp1++;
		}
		_mp1 = 0x80;
		_bp++;
	}
}