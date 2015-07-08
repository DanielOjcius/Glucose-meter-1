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
#define gbv_TxBitHigh			gu8v_FlagTx.bits.b0 		// �l��high���Iλ
#define gbv_TxFirstEnter		gu8v_FlagTx.bits.b1			// ��һ���M��Timer�l�ͳ���
#define gbv_TxSecondEnter		gu8v_FlagTx.bits.b2			// �ڶ����M��Timer�l�ͳ���
#define gbv_TxThirdEnter		gu8v_FlagTx.bits.b3  		// �������M��Timer���Iλ
#define gbv_TxFourthEnter		gu8v_FlagTx.bits.b4			// ���Ĵ��M��Timer���Iλ
#define gbv_TxDataOk			gu8v_FlagTx.bits.b5 		// Hijack�l����ɘ��Iλ
// #define gbv_Txbuf				gu8v_FlagTx.bits.b6			// �@ʾ�l��ֵ
// #define gbv_Rxbuf				gu8v_FlagTx.bits.b7			// �@ʾ����ֵ


extern volatile __byte_type 	gu8v_FlagRx;				// Bit���Iλ
// #define gbv_RxFirstBit			gu8v_FlagRx.bits.b0 		// Hijack���յ�һ��bit
#define gbv_RxDealBitOk			gu8v_FlagRx.bits.b1 		// Hijack���յ�һ��bit
#define gbv_RxFirstEnter		gu8v_FlagRx.bits.b2			// ��һ���M��Timer���Iλ
#define gbv_RxSecondEnter		gu8v_FlagRx.bits.b3			// �ڶ����M��Timer���Iλ
// #define gbv_RxThirdEnter		gu8v_FlagRx.bits.b4  		// �������M��Timer���Iλ
#define gbv_RxBitHigh			gu8v_FlagRx.bits.b5 		// ���յ�һ����λ���Iλ
#define gbv_RxError				gu8v_FlagRx.bits.b6 		// �����e�`���Iλ
#define gbv_RxDataOk			gu8v_FlagRx.bits.b7 		// ���ճɹ����Iλ

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
#define HijackFrequency1	1378
#define HijackFrequency0	HijackFrequency1/2	// 689		// Fsk high���l�ʞ�low��һ��
#define HiajackCnt0			1000000/(HijackFrequency0)/2 		// 725
#define HiajackCnt1			1000000/HijackFrequency1/2 		// 362
#define Tolerance			50
#define hijack_Period0_Max	(HiajackCnt0*2)/4 + Tolerance	// 1450/4 + 20 = 382
#define hijack_Period0_Min	(HiajackCnt0*2)/4 - Tolerance	// 1450/4 - 20 = 342
#define hijack_Period1_Max	(HiajackCnt1*2)/4 + Tolerance	// 725/4 + 20 = 201
#define hijack_Period1_Min	(HiajackCnt1*2)/4 - Tolerance	// 725/4 - 20 = 161
#endif
