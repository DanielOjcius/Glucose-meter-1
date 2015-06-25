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


//#define gbv_KeyLongPress	gu8v_Flag0.bits.b0 		// 按鍵長按標誌位
//#define gbv_PowerOn			gu8v_Flag0.bits.b1 		// 第一次上電標誌位
//#define gbv_KeyPress		gu8v_Flag0.bits.b2		// 有鍵按下標誌位,進入按鍵Debounce
//#define gbv_BalanceOK		gu8v_Flag0.bits.b3		//
//#define gbv_ADDGetDataOK	gu8v_Flag0.bits.b4		// 得到一筆ADC值
//#define gbv_ADC_Locking		gu8v_Flag0.bits.b5  	// ADC值處於穩定狀態中,但還沒有鎖定,此時動態更新重量值
//#define gbv_7_8ms			gu8v_Flag0.bits.b6		// TimeBase0 7.8ms標誌位,用於按鍵偵測等動作
//#define gbv_LedPoint		gu8v_Flag0.bits.b7 		// 用於七段數碼管顯示小數點標誌位
//
//#define gbv_Get_Impedance_Error	gu8v_Flag1.bits.b0 	// 阻抗量測錯誤標誌位
//#define gbv_CALing				gu8v_Flag1.bits.b1  // 處於校準模式標誌位,用於固定時間未偵測到有效校準重量則進入阻抗量測
//#define gbv_WeighOk				gu8v_Flag1.bits.b2 	// 用於重量量測ok,顯示當前重量固定時間后,進入阻抗量測模式
//#define gbv_ImpedanceOk			gu8v_Flag1.bits.b3  // 阻抗量測ok,顯示當前阻抗固定時間后,進入休眠前取零點模式
//#define gbv_HeavierLeft			gu8v_Flag1.bits.b4  // 平衡判斷左邊更重標誌位
//#define gbv_HeavierRight		gu8v_Flag1.bits.b5  // 平衡判斷右邊更重標誌位
//#define gbv_HeavierAbove		gu8v_Flag1.bits.b6  // 平衡判斷上邊更重標誌位
//#define gbv_HeavierBelow		gu8v_Flag1.bits.b7  // 平衡判斷下邊更重標誌位

#define WEIGHMODE 			1
#define IMPEDANCEMODE       2
#define HALTMODE            3
#define GETZEROMODE         4
#define AUTOWEIGHMODE       5
#define BalanceMODE       	6
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
