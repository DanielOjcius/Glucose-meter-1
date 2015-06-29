//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Hijack.c
// Description: 音頻通信相關設定
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#ifndef HIJACK_H_
#define HIJACK_H_

#define gbv_HalfBit			gu8v_Flag0.bits.b0 		// 按鍵長按標誌位
#define gbv_PowerOn			gu8v_Flag0.bits.b1 		// 第一次上電標誌位
#define gbv_KeyPress		gu8v_Flag0.bits.b2		// 有鍵按下標誌位,進入按鍵Debounce
#define gbv_firstBit		gu8v_Flag0.bits.b3		//
#define gbv_ADDGetDataOK	gu8v_Flag0.bits.b4		// 得到一筆ADC值
#define gbv_ADC_Locking		gu8v_Flag0.bits.b5  	// ADC值處於穩定狀態中,但還沒有鎖定,此時動態更新重量值
#define gbv_7_8ms			gu8v_Flag0.bits.b6		// TimeBase0 7.8ms標誌位,用於按鍵偵測等動作
#define gbv_LedPoint		gu8v_Flag0.bits.b7 		// 用於七段數碼管顯示小數點標誌位


#define HijackTX_Bias				1
#define Hijack_TX_StartIdle			2
#define Hijack_TX_StartBit			3
#define Hijack_TX_FirstData			4
#define Hijack_TX_SecondData		5
#define Hijack_TX_ParityBit			6
#define Hijack_TX_StopBit			7
#define Hijack_TX_StopIdle			8


#define Hijack_TX_IO 		_pac5
#define Hijack_TX 	 		_pa5
#define Hijack_RX_IO 		_pac6
#define Hijack_RX 	 		_pa6
#define Hijack_RX_IO 		_pac6
#define Hijack_RX 	 		_pa6
#define Hijack_Wakeup_IO 	_pac6
#define Hijack_Wakeup 	 	_pa6
#define Hijack_ENVCC_IO 	_pac4
#define Hijack_ENVCC    	_pa4
#define fskFrequency0	1378
#define fskFrequency1	fskFrequency0/2				;Fsk high的頻率為low的一半

#endif
