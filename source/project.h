//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : HT45F75Config.c
// Description: HT45F75�����������O��
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75
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
extern volatile __byte_type 	gu8v_FlagMain; 			// Bit���Iλ
#define gbv_7_8ms				gu8v_FlagMain.bits.b0 		// ���I�L�����Iλ

//#define gbv_TxFirstEnter		gu8v_Flag2.bits.b1		// ��һ���M��Timer���Iλ
//#define gbv_TxSecondEnter		gu8v_Flag2.bits.b2		// �ڶ����M��Timer���Iλ
//#define gbv_TxThirdEnter		gu8v_Flag2.bits.b3  	// �������M��Timer���Iλ
//#define gbv_TxFourthEnter		gu8v_Flag2.bits.b4		// ���Ĵ��M��Timer���Iλ
//#define gbv_TxDataOk			gu8v_Flag2.bits.b5 		// Hijack�l����ɘ��Iλ


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
