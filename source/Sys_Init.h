//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : sys_init.h
// Description: ϵ�y��ʼ�����P����
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75
//   Author   : ChenTing
//   Date     : 2015/05/26
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef SYS_INIT_H_
#define SYS_INIT_H_


void fun_PowerOnInit();
void fun_ResetInit();
void fun_GPIO();
void fun_RamInit();
void fun_SysInit();
void fun_PrepareToHalt();


//					@---------------IAP config---------------@
//Setting in IAP.h
//					@-------------WDT config--------------@
//___________________________________________________________________
//Please in Option select WDT clock Source
//if WDT clock Source fs =fsub
//WDT time���㷽ʽ:
//WDT time =  2^18/fsub
//example:(max time �����2^18��Source fs = 32768)
//WDT time = 2^18/32768= 8s
#define WDT_Disable				0B10101000
#define WDTtime2_8				0B01010000  //2^8/Fs
#define WDTtime2_10				0B01010001	//2^10/Fs
#define WDTtime2_12				0B01010010	//2^12/Fs
#define WDTtime2_14				0B01010011	//2^14/Fs
#define WDTtime2_15				0B01010100	//2^15/Fs
#define WDTtime2_16				0B01010101	//2^16/Fs
#define WDTtime2_17				0B01010110	//2^17/Fs
#define WDTtime2_18				0B01010111	//2^18/Fs
#define WDT_Function_Default	WDTtime2_18

//					@-------------LVR config--------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  LVS7  |  LVS6  |  LVS5  |  LVS4  |  LVS3  |  LVS2  |  LVS1  |  LVS0  |
// |______________________________________________________________________________
// | POR  |   0    |   1    |   0    |   1    |   0    |   1    |   0    |   1    |
// |_______________________________________________________________________________
// BIT 7~0  LVS7~LVS0:LVR늉��x��
// 			01010101:  2.1V     00110011:  2.55V
//			10011001:  3.15V    10101010:  3.8V
//          ����ֵ: MCU��λ
//___________________________________________________________________
#define LVR_Voltage2_1			0B01010101
#define LVR_Voltage2_55			0B00110011
#define LVR_Voltage3_15			0B10011001
#define LVR_Voltage3_8			0B10101010
#define LVR_Voltage_Default		LVR_Voltage2_1	//POR=2.1V


//					@-------------EEPROM config--------------@
//Setting in EEPROM.h

//					@-------------IO config--------------@
//Setting in Target.h

//					@-------------Timer config-----------@
//Setting in Timer.h
//                           @--------------TMnC0---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name | TnPAU  | TnCK2  | TnCK1  | TnCK0  |  TnON  | TnRP2  | TnRP1  | TnRP0  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7  TnPAU:TMnӋ������ͣ����λ
// 			0:  �\��
//			1:  ��ͣ
// BIT 6~4  TnCK2~TnCK0:�x��TMnӋ���r�
// 			000:  fsys/4   001:  fsys   010:   fh/16
// 			011:  fh/64    100:  fsub   101:   ����λ
// 			110:  TCKn������    111:  TCKn�½���
// BIT 3  TnON:TMnӋ����on/off����λ
// 			0:  off
//			1:  on
// BIT 2~0 TnRP2~TnRP0:TMn CCRP 3bit�Ĵ������cTMnӋ����bit9~bit7���^��Pƥ���L��	/�r��L��
// 			000:  1024   001:  128   010:   256
// 			011:  384    100:  512   101:   640
// 			110:  768    111:  896
#define TM0C0_Default		0x30   // CLOCK  fsys/64
//                           @--------------TMnC1---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TnM1  |  TnM0  |  TnIO1 |  TnIO0 |  TnOC  | TnPOL  | TnDPX  | TnCCLR |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~6  TnM1~TnM0:�x��TMn����ģʽλ
// 			00:  ���^��ƥ��ݔ��ģʽ   01:δ���xģʽ
//			10:  PWMģʽ              11:���r/Ӌ����ģʽ
// BIT 5~4  TnIO1~TnIO0:�x��TPn_0��TPn_1ݔ������λ
//���^ƥ��ݔ��ģʽ
// 			00:  �o׃��          01:  ݔ����
//			10:  ݔ����          11:  ݔ�����D
//PWMģʽ
// 			00:  ���ƟoЧ��B    01:  ������Ч��B
//			10:  PWMݔ��         11:  δ���x
//Ӌ����/���rģʽ: δ���x
// BIT 3  TnOC
// ���^ƥ��ݔ��ģʽ             PWMģʽ
// 			0:  ��ʼ��             0:  ����Ч
//			1:  ��ʼ��             1:  ����Ч
// BIT 2  TnPOL:TPn_0,TPn_1ݔ���O�Կ���λ
// 			0:  ͬ��
//			1:  ����
// BIT 1  TnDPX: TMn PWM�L��/ռ�ձȿ���λ
// 			0:  CCRP-�L��   ;CCRA-ռ�ձ�
//			1:  CCRP-ռ�ձ� ;CCRP-�L��
// BIT 0  TnCCLR:�x��TMnӋ��������l��λ
// 			0:  TMn���^��Pƥ��
//			1:  TMn���^��Aƥ��
#define TM0C1_Default		0xC1
#define TM0AL_Default		0x2C
#define TM0AH_Default		0x01
//					@-------Internal Power config--------@
//Setting in Others file  when need

//					@------------ADC config--------------@
//                           @--------------TBC---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TBON  |  TBCK  |  TB11  |  TB10  | LXTLP  |  TB02  |  TB01  |  TB00  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   1    |   1    |   0    |   1    |   1    |   1    |
// |_______________________________________________________________________________
// BIT 7  TBON:TB0��TB1����λ
// 			0:  Disable
//			1:  Enable
// BIT 6  TBCK:�x��ftb�r�λ
// 			0:  fsub
//			1:  fsys/4
// BIT 5~4  TB11~TB10:TimeBase1����L��
// 			00:  2^12/ftb   01:  2^13/ftb
//			10:  2^14/ftb   11:  2^15/ftb
// BIT 3  LXTLP:LXT�͹��Ŀ���λ
// 			0:  ���ن���ģʽ
//			1:  �͹���ģʽ
// BIT 2~0  TB02~TB00��TimeBase0����L��
// 			000:  2^8/ftb    001:  2^9/ftb    010:  2^10/ftb
// 			011:  2^11/ftb   100:  2^12/ftb   101:  2^13/ftb
// 			110:  2^14/ftb   111:  2^15/ftb

#define TimeBase_Default 	0B10110000	//TimeBase1 1S   TimeBase 0  7.8ms

//					@------------ADC config--------------@
//Setting in ADC.h

//					@-------Temperature config-----------@
//Setting in Others file  when need

//					@-------------SIM config-------------@
//Setting in SIM.h

//					@-------------UART config-------------@
//Setting in UART.h
#endif
