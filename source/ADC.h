//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : ADC.h
// Description: ADC&OPA相關設定
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//___________________________________________________________________
//___________________________________________________________________
#ifndef ADC_H_
#define ADC_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 變量聲明 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 公共函數 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void fun_ADCInit(unsigned char ADCChannel );
void fun_ADCStart();
void fun_ADCStop();
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 預定義  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                           @--------------ADCR0---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  START |  EOCB  |  ADOFF |   -    |   -    |  ACS2  |  ACS1  |  ACS0  |
// |______________________________________________________________________________
// | POR  |   0    |   1    |   1    |   -    |   -    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7  START:啟動A/D轉化位
// 			0→1→0:  啟動
//			0→1:  重置A/D轉化，並且設置EOCB為1
// BIT 6  EOCB:A/D轉化結束標誌
// 			0:  A/D轉化結束
//			1:  A/D轉化中
// BIT 5  ADOFF:ADC模塊電源控制位
// 			0:  ADC模擬電源開
//			1:  ADC模擬電源關
// BIT 4~3  未定義
// BIT 2~0  ACS2~ACS0:選擇A/D通道
// 			000:  AN0        001:  AN1        010: AN2
// 			011:  AN3        100:  AN4,OP1S0
//          101:  AN5,OP1S1  110:  AN6,OP1S2
// 			111:  AN7,OP2O
#define ADCChannel_AN0 	0x00
#define ADCChannel_AN1 	0x01
#define ADCChannel_AN2 	0x02
#define ADCChannel_AN3 	0x03
#define ADCChannel_AN4 	0x04
#define ADCChannel_AN5 	0x05
#define ADCChannel_AN6 	0x06
#define ADCChannel_AN7 	0x07
//                           @--------------ADCR1---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |   -    |   -    |   -    |   -    |   -    |  ADCK2 |  ADCK1 |  ADCK0 |
// |______________________________________________________________________________
// | POR  |   -    |   -    |   -    |   -    |   -    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~3  未定義,讀為0
// BIT 2~0  ADCK2~ADCK0:選擇ADC時鐘源
// 			000: fsys      001: fsys/2   010: fsys/4
// 			011: fsys/8    100: fsys/16  101: fsys/32
// 			110: fsys/64   001: 未定義
#define ADCSampleRate	0x00
//                           @--------------ADCR2---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |   -    |   -    |   -    |   -    |  VRPS1 |  VRPS0 |  VRNS1 |  VRNS0 |
// |______________________________________________________________________________
// | POR  |   -    |   -    |   -    |   -    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~4  未定義,讀為0
// BIT 3~2  VRPS1,VRPS0
// 			00:  來自AVDD     01:來自ADVRH引腳
//			1x:  來自Bandgap
// BIT 1~0  VRNS1,VRNS0:ADC反相參考電壓選擇
// 			00:  來自AVSS    01:來自ADVRL引腳
//			1x:  來自DACO引腳
#define ADCVR_AVDD_AVSS		0x00
#define ADCVR_AVDD_ADVRL	0x01
#define ADCVR_AVDD_DACO		0x03
#define ADCVR_ADVRH_AVSS	0x04
#define ADCVR_ADVRH_ADVRL	0x05
#define ADCVR_ADVRH_DACO	0x07
#define ADCVR_Bandgap_AVSS	0x0C
#define ADCVR_Bandgap_ADVRL	0x0D
#define ADCVR_Bandgap_DACO	0x0F
#define ADCVR_Default		ADCVR_AVDD_AVSS
#endif
