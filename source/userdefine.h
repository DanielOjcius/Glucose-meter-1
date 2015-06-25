//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Readme.h
// Description: user 自定義參數設定
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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@ 系統基礎設定 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// 支持HT45F75 和 HT45F77
#define HT45F75			// LED顯示
// #define HT45F77      // LCD顯示

//  可選頻率有
//  HIRC : 4800000,9600000，1440000
//  HXT  : 4000000,8000000，120000
#define SysFrequency	4800000
//@@@@@@@@@@@@@@@@@@@@@@@@@@@ SPI/IIC選擇 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// 選擇SIM的功能,SIM中的SPI和IIC由於引腳和暫存器共用,因此只能選擇其中一個功能
#define SIM_SPI
// #define SIM_IIC
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 按鍵相關 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// 按鍵IO選擇
#define KeyPort  			_pa
#define KeyPortIO			_pac


#define KeyPortIO_Default   0B01010000 // 取PA4 & PA 6
// 定義了按鍵未按下時候的狀態
#define KeyNoPush			0B01010000
//對應按鍵按下時候的取反狀態
#define KeyWeigh			0B00010000  // pa4
#define KeyImpedance		0B01000000  // pa6
#define KeyCal 				0B00010000  // pa4 長按 校準模式

#define KEYSCANCYCLE		7.8
#define LOOGPRESS			1000/KEYSCANCYCLE
#define SHORTPRESS			100/KEYSCANCYCLE

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                         ADC 相關
#define ADCLockCntThreshold 		4 	// ADC鎖定需要的穩定次數
#define WeighLockThreshold			20 	// 重量鎖定允許變化的範圍
#define ImpedanceLockThreshold		10  // 阻抗鎖定允許變化的範圍
#define AutoWeighThreshold			50  // 自動上稱重量閥值
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                        重量校準參數
// 第一次為進行校準時設定的初始校準值
//#define CalData0Kg_Default			2915  	//
//#define CalData50Kg_Default			4140   // 7055
//#define CalData100Kg_Default		4185   // 11240
//#define CalData150Kg_Default		4173   //15413
#define CalData0Kg_Default			35703  	//
#define CalData50Kg_Default			4136   // 7055
#define CalData100Kg_Default		3342   // 11240
#define CalData150Kg_Default		5020   //15413
// 校準值存放在EEPROM的對應地址
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
