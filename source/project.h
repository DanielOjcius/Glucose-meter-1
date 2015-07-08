//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : HT45F75Config.c
// Description: HT45F6x
//Targer Board: 
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/05/26
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef _PROJECT_H_
#define _PROJECT_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ׃���� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
extern volatile unsigned char gu8v_HaltTime;		// MCU���ߕr�gӋ�r
extern volatile unsigned char WorkModeState;		// MCU����ģʽ��B���Iλ
extern volatile unsigned char gu8v_TxDataHigh;
extern volatile unsigned char gu8v_TxDataLow;
extern volatile unsigned int  gu16v_Temp;
extern volatile unsigned char  gu8v_temp0;
extern volatile unsigned char  gu8v_temp1;
extern volatile __byte_type 	gu8v_FlagMain; 				// Bit���Iλ
#define gbv_7_8ms				gu8v_FlagMain.bits.b0 		// 7.8ms���r���Iλ



#define STRIPSCHECKMODE			1
#define BLEEDINGMODE			2
#define HALTMODE            	3
#define MEASURENOMODE			4
// ϵ�y�Ԅ����ߕr�g�O��
#define TimeBaseCycle    	1000 	// ms
#define HaltTime60S			60000/TimeBaseCycle
#define HaltTime30S			30000/TimeBaseCycle
#define HaltTime10S			10000/TimeBaseCycle
#define HaltTime5S			5000/TimeBaseCycle
#define HaltTime3S			3000/TimeBaseCycle
#define HaltTime2S			2000/TimeBaseCycle
#define HaltTime1S			1000/TimeBaseCycle
#define HaltTime_Default	HaltTime60S

#endif
