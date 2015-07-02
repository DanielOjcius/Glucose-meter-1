//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Hijack.c
// Description: ���lͨ�����P�O��
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#ifndef HIJACK_H_
#define HIJACK_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ �������� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void fun_HijcakTx(unsigned char FisrtData,unsigned char SecondData);
void fun_HijackRx();
void fun_HijackInit();
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ׃���� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
extern volatile __byte_type 	gu8v_FlagTx; 			// Bit���Iλ
#define gbv_TxBitHigh			gu8v_FlagTx.bits.b0 		// ���I�L�����Iλ
#define gbv_TxFirstEnter		gu8v_FlagTx.bits.b1			// ��һ���M��Timer���Iλ
#define gbv_TxSecondEnter		gu8v_FlagTx.bits.b2			// �ڶ����M��Timer���Iλ
#define gbv_TxThirdEnter		gu8v_FlagTx.bits.b3  		// �������M��Timer���Iλ
#define gbv_TxFourthEnter		gu8v_FlagTx.bits.b4			// ���Ĵ��M��Timer���Iλ
#define gbv_TxDataOk			gu8v_FlagTx.bits.b5 		// Hijack�l����ɘ��Iλ

extern volatile __byte_type 	gu8v_FlagRx;				// Bit���Iλ
#define gbv_RxGetBitOk			gu8v_FlagRx.bits.b0 		// Hijack���յ�һ��bit
#define gbv_RxDealBitOk			gu8v_FlagRx.bits.b1 		// Hijack���յ�һ��bit
#define gbv_RxFirstEnter		gu8v_FlagRx.bits.b2			// ��һ���M��Timer���Iλ
#define gbv_RxSecondEnter		gu8v_FlagRx.bits.b3			// �ڶ����M��Timer���Iλ
#define gbv_RxThirdEnter		gu8v_FlagRx.bits.b4  		// �������M��Timer���Iλ
#define gbv_RxBitHigh			gu8v_FlagRx.bits.b5 		// ���I�L�����Iλ
#define gbv_RxError				gu8v_FlagRx.bits.b6 		// ���I�L�����Iλ
#define gbv_RxDataOk			gu8v_FlagRx.bits.b7 		// ���I�L�����Iλ

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ �A���x  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
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
#define HijackFrequency1	HijackFrequency0/2				//Fsk high���l�ʞ�low��һ��
#define HiajackCnt0			1000000/HijackFrequency0/2
#define HiajackCnt1			1000000/HijackFrequency1/2
#define Tolerance			25
#define hijack_Period0_Max	HiajackCnt0 + Tolerance
#define hijack_Period0_Min	HiajackCnt0 - Tolerance
#define hijack_Period1_Max	HiajackCnt1 + Tolerance
#define hijack_Period1_Min	HiajackCnt1 - Tolerance

#endif
