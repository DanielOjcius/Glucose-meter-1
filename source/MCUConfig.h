//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : HT45F75Config.c
// Description: HT45F75暫存器快速設定
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75
//   Author   : ChenTing
//   Date     : 2015/05/26
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef _MCUCONFIG_H_
#define _MCUCONFIG_H_


//設置初始化 rambank 個數
#define RamBankSectorSum	4


//__________________________________________________________________//
//					-----ISR VECTOR Defination------;
//中斷入口地址
#define	START_VECTOR			0x000		//主程序
#define INT0_VECTOR				0x004		//Intrrupt 0
#define INT1_VECTOR				0x008		//Intrrupt 1
#define Timer0A_VECTOR			0x00C		//timer0 A
#define Timer0P_VECTOR			0x00C		//timer0 P
#define ADC_VECTOR				0x010		//ADC
#define Timebase0_VECTOR		0x014		//timebase0
#define Timebase1_VECTOR		0x018		//timebase1
#define LVD_VECTOR				0x01C		//LVD
#define EEPROM_VECTOR			0x01C		//EEPROM
#define UART_VECTOR				0x01C		//UART
#define SIM_SPI_VECTOR			0x01C		//SIM SPI
#define SIM_IIC_VECTOR			0x01C		//SIM IIC
#define IICTO_VECTOR			0x020		//IIC 超时
#define Timer1A_VECTOR			0x020		//timer1 A
#define Timer1P_VECTOR			0x020		//timer1 P
#define Timer2A_VECTOR			0x024		//timer2 A
#define Timer2P_VECTOR			0x024		//timer2 P



#endif
