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
#ifndef _PROJECT_H_
#define _PROJECT_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 變量聲明 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
extern volatile unsigned char gu8v_HaltTime;		// MCU休眠時間計時
extern volatile unsigned char WorkModeState;		// MCU工作模式狀態標誌位
extern volatile unsigned char gu8v_TxDataHigh;
extern volatile unsigned char gu8v_TxDataLow;
extern volatile unsigned int  gu16v_Temp;
extern volatile __byte_type 	gu8v_FlagMain; 			// Bit標誌位
#define gbv_7_8ms				gu8v_FlagMain.bits.b0 		// 按鍵長按標誌位

//#define gbv_TxFirstEnter		gu8v_Flag2.bits.b1		// 第一次進入Timer標誌位
//#define gbv_TxSecondEnter		gu8v_Flag2.bits.b2		// 第二次進入Timer標誌位
//#define gbv_TxThirdEnter		gu8v_Flag2.bits.b3  	// 第三次進入Timer標誌位
//#define gbv_TxFourthEnter		gu8v_Flag2.bits.b4		// 第四次進入Timer標誌位
//#define gbv_TxDataOk			gu8v_Flag2.bits.b5 		// Hijack發送完成標誌位


#define STRIPSCHECKMODE			1
#define BLEEDINGMODE			2
#define HALTMODE            	3
#define MEASURENOMODE			4
// 系統自動休眠時間設定
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
