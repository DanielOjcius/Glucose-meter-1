//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : KeyScan.h
// Description: ���I�������
//Targer Board: 
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/30
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef _KEY_SCAN_H
#define _KEY_SCAN_H

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ���ú��� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void fun_KeyScan();
void fun_KeyTask();
void fun_KeyInit();
void fun_JackCheck();
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ׃���� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
extern volatile __byte_type 	gu8v_FlagKey; 			// ���IBit���Iλ
extern volatile unsigned char 	gu8v_KeyRelease;
extern volatile unsigned char 	gu8v_KeyTrigger;
extern volatile unsigned char 	gu8v_KeyPress;
extern volatile unsigned char  	gu8v_KeyShortPress;

#define gbv_KeyPress			gu8v_FlagKey.bits.b1		// ���I�����Iλ,�M�밴�IDebounce
#define gbv_KeyLongPress		gu8v_FlagKey.bits.b2		// ���I�����Iλ,�M�밴�IDebounce

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ �A̎��  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ���IIO�x��
#define KeyPort  			_pb
#define KeyPortIO			_pbc
#define KeyPortIO_Default   0b00111000 // ȡPb5
// ���x�˰��Iδ���r��Ġ�B
#define KeyNoPush			0b00111000
//�������I���r���ȡ����B
#define KeyTx				0b00100000  // pb5
#define KEYSCANCYCLE		7.8
#define LOOGPRESS			1000/KEYSCANCYCLE
#define SHORTPRESS			100/KEYSCANCYCLE


#endif



