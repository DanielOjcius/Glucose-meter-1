//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Readme.h
// Description: user �Զ��x�����O��
//Targer Board:
//   MCU      : HT45F75/HT45F77
//   Author   : ChenTing
//   Date     : 2015/06/02
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef _USERDEFINE_H_
#define _USERDEFINE_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@ ϵ�y���A�O�� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// ֧��HT45F75 �� HT45F77
#define HT45F75			// LED�@ʾ
// #define HT45F77      // LCD�@ʾ

//  ���x�l����
//  HIRC : 4800000,9600000��1440000
//  HXT  : 4000000,8000000��120000
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
//                        ����У�ʅ���
// ��һ�Ξ��M��У�ʕr�O���ĳ�ʼУ��ֵ
//#define CalData0Kg_Default			2915  	//
//#define CalData50Kg_Default			4140   // 7055
//#define CalData100Kg_Default		4185   // 11240
//#define CalData150Kg_Default		4173   //15413
#define CalData0Kg_Default			35703  	//
#define CalData50Kg_Default			4136   // 7055
#define CalData100Kg_Default		3342   // 11240
#define CalData150Kg_Default		5020   //15413
// У��ֵ�����EEPROM�Č�����ַ
#define EEPROMAddrCal_000KgLow		0x01
#define EEPROMAddrCal_000KgHigh		0x02
#define EEPROMAddrCal_050KgLow		0x03
#define EEPROMAddrCal_050KgHigh		0x04
#define EEPROMAddrCal_100KgLow		0x05
#define EEPROMAddrCal_100KgHigh		0x06
#define EEPROMAddrCal_150KgLow		0x07
#define EEPROMAddrCal_150KgHigh		0x08
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@











#endif
