//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Readme.h
// Description: user 自定義參數設定
//Targer Board:
//   MCU      : HT45F75/HT45F77
//   Author   : ChenTing
//   Date     : 2015/06/26
//___________________________________________________________________
//___________________________________________________________________
#ifndef _USERDEFINE_H_
#define _USERDEFINE_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@ 系統基礎設定 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// 支持 HT45F65,HT45F66,HT45F67
#define HT45F67
//  可選頻率有 4000000,8000000，12000000
//  可選時鐘來源有 HIRC,HXT
#define HIRC
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











#endif
