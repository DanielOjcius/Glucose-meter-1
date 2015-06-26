//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Readme.h
// Description: user �Զ��x�����O��
//Targer Board:
//   MCU      : HT45F75/HT45F77
//   Author   : ChenTing
//   Date     : 2015/06/26
//___________________________________________________________________
//___________________________________________________________________
#ifndef _USERDEFINE_H_
#define _USERDEFINE_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@ ϵ�y���A�O�� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ֧�� HT45F65,HT45F66,HT45F67
#define HT45F67
//  ���x�l���� 4000000,8000000��12000000
//  ���x�r犁�Դ�� HIRC,HXT
#define HIRC
#define SysFrequency	4800000
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ SPI/IIC�x�� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// �x��SIM�Ĺ���,SIM�е�SPI��IIC������_�͕���������,���ֻ���x������һ������
#define SIM_SPI
// #define SIM_IIC
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ���I���P @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ���IIO�x��
#define KeyPort  			_pa
#define KeyPortIO			_pac


#define KeyPortIO_Default   0B01010000 // ȡPA4 & PA 6
// ���x�˰��Iδ���r��Ġ�B
#define KeyNoPush			0B01010000
//�������I���r���ȡ����B
#define KeyWeigh			0B00010000  // pa4
#define KeyImpedance		0B01000000  // pa6
#define KeyCal 				0B00010000  // pa4 �L�� У��ģʽ

#define KEYSCANCYCLE		7.8
#define LOOGPRESS			1000/KEYSCANCYCLE
#define SHORTPRESS			100/KEYSCANCYCLE

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                         ADC ���P
#define ADCLockCntThreshold 		4 	// ADC�i����Ҫ�ķ����Δ�
#define WeighLockThreshold			20 	// �����i�����S׃���Ĺ���
#define ImpedanceLockThreshold		10  // �迹�i�����S׃���Ĺ���
#define AutoWeighThreshold			50  // �Ԅ��ϷQ�����yֵ
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@











#endif
