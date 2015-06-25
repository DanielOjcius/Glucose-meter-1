//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : fun_isr.c
// Description: 所有中斷函數入口
//Targer Board: None
//   MCU      : HT45F75
//   Author   : ChenTing
//   Date     : 2015/05/26
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"
//@------------外部中斷0入口函數--------------@
DEFINE_ISR(INT0_ISR, INT0_VECTOR)
{

}

//@------------外部中斷0入口函數--------------@
DEFINE_ISR(INT1_ISR, INT1_VECTOR)
{

}
//@-----------Timer0中斷入口函數--------------@
//Important:A/P比較器中斷地址相同
DEFINE_ISR(Timer0A_ISR, Timer0A_VECTOR)	//A比較器中斷
{

}
// DEFINE_ISR(Timer0P_ISR, Timer0P_VECTOR) //P比較器中斷
// {

// }
//@-----------ADC 中斷入口函數--------------@
DEFINE_ISR(ADC_ISR, ADC_VECTOR)
{

}
//@---------Timebase0 中斷入口函數----------@
DEFINE_ISR(Timebase0_ISR, Timebase0_VECTOR)
{

}
//@---------Timebase1 中斷入口函數----------@
DEFINE_ISR(Timebase1_ISR, Timebase1_VECTOR)
{

}
//_________________________________________________//
//important:LVD、EEPROM、UART、SIM共用一個中斷地址
//@-----------LVD 中斷入口函數--------------@
// DEFINE_ISR(LVD_ISR, LVD_VECTOR)
// {

// }
//@-----------EEPROM 中斷入口函數--------------@
// DEFINE_ISR(EEPROM_ISR, EEPROM_VECTOR)
// {

// }
//@-----------UART 中斷入口函數--------------@
DEFINE_ISR(UART_ISR, UART_VECTOR)
{

}
//@-----------SIM_SPI 中斷入口函數--------------@
// DEFINE_ISR(SIM_SPI_ISR, SIM_SPI_VECTOR)
// {

// }
//@-----------SIM_IIC 中斷入口函數--------------@
// DEFINE_ISR(SIM_IIC_ISR, SIM_IIC_VECTOR)
// {

// }
//_________________________________________________//
//important:IICTO、Timer1 A&P 比较器共用一个中断入口
//@-----------IICTO 中斷入口函數--------------@
// DEFINE_ISR(IICTO, IICTO_VECTOR)
// {

// }
DEFINE_ISR(Timer1A_ISR, Timer1A_VECTOR) //A 比较器中断
{

}
// DEFINE_ISR(Timer1P_ISP, Timer1P_VECTOR) //P 比较器中断
// {

// }
//_________________________________________________//
//important:Timer2 A&P 比较器共用一个中断入口
DEFINE_ISR(Timer2A_ISR, Timer2A_VECTOR) //A 比较器中断
{

}
// DEFINE_ISR(Timer2P_ISP, Timer2P_VECTOR) //P 比较器中断
// {

// }


