//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : fun_isr.c
// Description: �����Дຯ�����
//Targer Board: None
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/26
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@ REMARK @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ��춏ͺ��Д�,��춹����Д���ڵ�ַ,
// ��ʹ�������Ѓ���Д๦��,
// ����Multin_ISR(n=0,1,2)��ֱ��coding,ͨ�^�Д಻ͬ���Iλ�Д��Д�e
// ��ֻʹ��������һ��Д๦��,
// ��ֱ���_�������������coding(��Ҫ����Multin_ISR(n=0,1,2))

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ INT0 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// DEFINE_ISR(INT0_ISR, INT0_VECTOR)
// {

// }  for hijack RX
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ INT1 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DEFINE_ISR(INT1_ISR, INT1_VECTOR)
{

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ADC @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DEFINE_ISR(ADC_ISR, ADC_VECTOR)
{

}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ Multi0 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//REMARK:Timer 0,1��A/P���^���Д��ַ��ͬ
DEFINE_ISR(Multi0_ISR, Multi0__VECTOR)
{

}
// DEFINE_ISR(Timer0A_ISR, Timer0A_VECTOR)
// {

// }
// DEFINE_ISR(Timer0P_ISR, Timer0P_VECTOR)
// {

// }
// DEFINE_ISR(Timer1A_ISR, Timer1A_VECTOR)
// {

// }
// DEFINE_ISR(Timer1P_ISP, Timer1P_VECTOR)
// {

// }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ Multi1 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//REMARK:LVD,SPI1,UART���Д��ַ��ͬ
DEFINE_ISR(Multi1_ISR, Multi1__VECTOR)
{

}
// DEFINE_ISR(LVD_ISR, LVD_VECTOR)
// {

// }
// DEFINE_ISR(SPI1_ISR, SPI1_VECTOR)
// {

// }
// DEFINE_ISR(UART_ISR, UART_VECTOR)
// {

// }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ Multi2 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//REMARK:SIM,PINTB,Timer2 A/P���Д��ַ��ͬ
DEFINE_ISR(Multi2_ISR, Multi2__VECTOR)
{

}
// DEFINE_ISR(SIM_SPI_ISR, SIM_SPI_VECTOR)
// {

// }
// DEFINE_ISR(SIM_IIC_ISR, SIM_IIC_VECTOR)
// {

// }
// DEFINE_ISR(PINTB_ISR, PINTB_VECTOR)
// {

// }
// DEFINE_ISR(Timer2A_ISR, Timer2A_VECTOR)
// {

// }
// DEFINE_ISR(Timer2P_ISP, Timer2P_VECTOR)
// {

// }
//@@@@@@@@@@@@@@@@@@@@@@@@ Timebase0 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DEFINE_ISR(Timebase0_ISR, Timebase0_VECTOR)
{

}
//@@@@@@@@@@@@@@@@@@@@@@@@ Timebase1 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
DEFINE_ISR(Timebase1_ISR, Timebase1_VECTOR)
{

}


