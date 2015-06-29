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

#define gbv_HalfBit			gu8v_Flag0.bits.b0 		// ���I�L�����Iλ
#define gbv_PowerOn			gu8v_Flag0.bits.b1 		// ��һ����늘��Iλ
#define gbv_KeyPress		gu8v_Flag0.bits.b2		// ���I�����Iλ,�M�밴�IDebounce
#define gbv_firstBit		gu8v_Flag0.bits.b3		//
#define gbv_ADDGetDataOK	gu8v_Flag0.bits.b4		// �õ�һ�PADCֵ
#define gbv_ADC_Locking		gu8v_Flag0.bits.b5  	// ADCֵ̎춷�����B��,��߀�]���i��,�˕r�ӑB��������ֵ
#define gbv_7_8ms			gu8v_Flag0.bits.b6		// TimeBase0 7.8ms���Iλ,��춰��I�ɜy�Ȅ���
#define gbv_LedPoint		gu8v_Flag0.bits.b7 		// ����߶Δ��a���@ʾС���c���Iλ


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
#define fskFrequency1	fskFrequency0/2				;Fsk high���l�ʞ�low��һ��

#endif
