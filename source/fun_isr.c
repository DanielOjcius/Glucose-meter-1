//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : fun_isr.c
// Description: �����Дຯ�����
//Targer Board: None
//   MCU      : HT45F75
//   Author   : ChenTing
//   Date     : 2015/05/26
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"
//@------------�ⲿ�Д�0��ں���--------------@
DEFINE_ISR(INT0_ISR, INT0_VECTOR)
{

}

//@------------�ⲿ�Д�0��ں���--------------@
DEFINE_ISR(INT1_ISR, INT1_VECTOR)
{

}
//@-----------Timer0�Д���ں���--------------@
//Important:A/P���^���Д��ַ��ͬ
DEFINE_ISR(Timer0A_ISR, Timer0A_VECTOR)	//A���^���Д�
{

}
// DEFINE_ISR(Timer0P_ISR, Timer0P_VECTOR) //P���^���Д�
// {

// }
//@-----------ADC �Д���ں���--------------@
DEFINE_ISR(ADC_ISR, ADC_VECTOR)
{

}
//@---------Timebase0 �Д���ں���----------@
DEFINE_ISR(Timebase0_ISR, Timebase0_VECTOR)
{

}
//@---------Timebase1 �Д���ں���----------@
DEFINE_ISR(Timebase1_ISR, Timebase1_VECTOR)
{

}
//_________________________________________________//
//important:LVD��EEPROM��UART��SIM����һ���Д��ַ
//@-----------LVD �Д���ں���--------------@
// DEFINE_ISR(LVD_ISR, LVD_VECTOR)
// {

// }
//@-----------EEPROM �Д���ں���--------------@
// DEFINE_ISR(EEPROM_ISR, EEPROM_VECTOR)
// {

// }
//@-----------UART �Д���ں���--------------@
DEFINE_ISR(UART_ISR, UART_VECTOR)
{

}
//@-----------SIM_SPI �Д���ں���--------------@
// DEFINE_ISR(SIM_SPI_ISR, SIM_SPI_VECTOR)
// {

// }
//@-----------SIM_IIC �Д���ں���--------------@
// DEFINE_ISR(SIM_IIC_ISR, SIM_IIC_VECTOR)
// {

// }
//_________________________________________________//
//important:IICTO��Timer1 A&P �Ƚ�������һ���ж����
//@-----------IICTO �Д���ں���--------------@
// DEFINE_ISR(IICTO, IICTO_VECTOR)
// {

// }
DEFINE_ISR(Timer1A_ISR, Timer1A_VECTOR) //A �Ƚ����ж�
{

}
// DEFINE_ISR(Timer1P_ISP, Timer1P_VECTOR) //P �Ƚ����ж�
// {

// }
//_________________________________________________//
//important:Timer2 A&P �Ƚ�������һ���ж����
DEFINE_ISR(Timer2A_ISR, Timer2A_VECTOR) //A �Ƚ����ж�
{

}
// DEFINE_ISR(Timer2P_ISP, Timer2P_VECTOR) //P �Ƚ����ж�
// {

// }


