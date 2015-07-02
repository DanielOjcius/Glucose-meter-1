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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 公共函數 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void fun_HijcakTx(unsigned char FisrtData,unsigned char SecondData);
void fun_HijackRx();
void fun_HijackInit();
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 變量聲明 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
extern volatile __byte_type 	gu8v_FlagTx; 			// Bit標誌位
#define gbv_TxBitHigh			gu8v_FlagTx.bits.b0 		// 按鍵長按標誌位
#define gbv_TxFirstEnter		gu8v_FlagTx.bits.b1			// 第一次進入Timer標誌位
#define gbv_TxSecondEnter		gu8v_FlagTx.bits.b2			// 第二次進入Timer標誌位
#define gbv_TxThirdEnter		gu8v_FlagTx.bits.b3  		// 第三次進入Timer標誌位
#define gbv_TxFourthEnter		gu8v_FlagTx.bits.b4			// 第四次進入Timer標誌位
#define gbv_TxDataOk			gu8v_FlagTx.bits.b5 		// Hijack發送完成標誌位

extern volatile __byte_type 	gu8v_FlagRx;				// Bit標誌位
#define gbv_RxGetBitOk			gu8v_FlagRx.bits.b0 		// Hijack接收到一個bit
#define gbv_RxDealBitOk			gu8v_FlagRx.bits.b1 		// Hijack接收到一個bit
#define gbv_RxFirstEnter		gu8v_FlagRx.bits.b2			// 第一次進入Timer標誌位
#define gbv_RxSecondEnter		gu8v_FlagRx.bits.b3			// 第二次進入Timer標誌位
#define gbv_RxThirdEnter		gu8v_FlagRx.bits.b4  		// 第三次進入Timer標誌位
#define gbv_RxBitHigh			gu8v_FlagRx.bits.b5 		// 按鍵長按標誌位
#define gbv_RxError				gu8v_FlagRx.bits.b6 		// 按鍵長按標誌位
#define gbv_RxDataOk			gu8v_FlagRx.bits.b7 		// 按鍵長按標誌位

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 預定義  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define Hijack_TX_Bias				1
#define Hijack_TX_StartIdle			2
#define Hijack_TX_StartBit			3
#define Hijack_TX_FirstData			4
#define Hijack_TX_SecondData		5
#define Hijack_TX_ParityBit			6
#define Hijack_TX_StopBit			7
#define Hijack_TX_StopIdle			8
#define Hijack_TX_OK				9
#define Hijack_RX_Bias				1
#define Hijack_RX_StartIdle			2
#define Hijack_RX_StartBit			3
#define Hijack_RX_FirstData			4
#define Hijack_RX_SecondData		5
#define Hijack_RX_ParityBit			6
#define Hijack_RX_StopBit			7
#define Hijack_RX_StopIdle			8

#define Hijack_TX_IO 		_pac5
#define Hijack_TX 	 		_pa5
#define Hijack_RX_IO 		_pac6
#define Hijack_RX 	 		_pa6
#define Hijack_Wakeup_IO 	_pac4
#define Hijack_Wakeup 	 	_pa4
#define Hijack_Wakeup_W	 	_pawu4

#define Hijack_ENVCC_IO 	_pac3
#define Hijack_ENVCC    	_pa3
#define HijackFrequency0	1378
#define HijackFrequency1	HijackFrequency0/2				//Fsk high的頻率為low的一半
#define HiajackCnt0			1000000/HijackFrequency0/2
#define HiajackCnt1			1000000/HijackFrequency1/2
#define Tolerance			25
#define hijack_Period0_Max	HiajackCnt0 + Tolerance
#define hijack_Period0_Min	HiajackCnt0 - Tolerance
#define hijack_Period1_Max	HiajackCnt1 + Tolerance
#define hijack_Period1_Min	HiajackCnt1 - Tolerance

#endif
