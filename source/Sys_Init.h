//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : sys_init.h
// Description: 系統初始化相關程序
//Targer Board: HT45F6x
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/26
//___________________________________________________________________
//___________________________________________________________________
#ifndef SYS_INIT_H_
#define SYS_INIT_H_
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 共用函數 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void fun_PowerOnInit();
void fun_ResetInit();
void fun_GPIOInit();
void fun_RamInit();
void fun_SysInit();
void fun_PrepareToHalt();
void fun_WakeUpFromHalt();

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 中斷地址 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define	START_VECTOR			0x000		// 主程序
#define INT0_VECTOR				0x004		// Intrrupt 0
#define INT1_VECTOR				0x008		// Intrrupt 1
#define ADC_VECTOR				0x00C		// ADC
// HT45F65 中斷入口地址
#ifdef HT45F65
// Multi Function Interrupts 0
#define Multi0__VECTOR			0x010		// 復合中斷0
#define Timer0A_VECTOR			0x010		// timer0 A
#define Timer0P_VECTOR			0x010		// timer0 P
#define Timer1A_VECTOR			0x010		// timer1 A
#define Timer1P_VECTOR			0x010		// timer1 P
// Multi Function Interrupts 1
#define Multi1__VECTOR			0x014		// 復合中斷1
#define LVD_VECTOR				0x014		// LVD
#define SPI1_VECTOR				0x014		// SPI1
#define UART_VECTOR				0x014		// UART
// Multi Function Interrupts 2
#define Multi2__VECTOR			0x018		// 復合中斷2
#define SIM_SPI_VECTOR			0x018		// SIM SPI
#define SIM_IIC_VECTOR			0x018		// SIM IIC
#define PINTB_VECTOR			0x018		// PINTB
#define Timer2P_VECTOR			0x018		// timer2 P
#define Timer2A_VECTOR			0x018		// timer2 A

#define Timebase0_VECTOR		0x01C		// timebase0
#define Timebase1_VECTOR		0x020		// timebase1
#endif
// HT45F66&HT45F67 中斷入口地址
#ifndef HT45F65
// Multi Function Interrupts 0
#define Multi0__VECTOR			0x010		// 復合中斷0
#define Timer0A_VECTOR			0x010		// timer0 A
#define Timer0P_VECTOR			0x010		// timer0 P
#define Timer2A_VECTOR			0x010		// timer2 A
#define Timer2P_VECTOR			0x010		// timer2 P
// Multi Function Interrupts 1
#define Multi1__VECTOR			0x014		// 復合中斷1
#define Timer1A_VECTOR			0x014		// timer1 A
#define Timer1P_VECTOR			0x014		// timer1 P
#define Timer1B_VECTOR			0x014		// timer1 B
#define UART_VECTOR				0x014		// UART
// Multi Function Interrupts 2
#define Multi2__VECTOR			0x018		// 復合中斷2
#define SIM_SPI_VECTOR			0x018		// SIM SPI
#define SIM_IIC_VECTOR			0x018		// SIM IIC
#define PINTB_VECTOR			0x018		// PINTB
#define Timer3P_VECTOR			0x018		// timer2 P
#define Timer3A_VECTOR			0x018		// timer2 A
// Multi Function Interrupts 3
#define Multi3__VECTOR			0x01C		// 復合中斷3
#define LVD_VECTOR				0x01C		// LVD
#define SPI1_VECTOR				0x01C		// SPI1

#define Timebase0_VECTOR		0x020		// timebase0
#define Timebase1_VECTOR		0x024		// timebase1
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ RAM Bank @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifdef HT45F65
	//設置初始化 rambank 個數
	#define RamBankSectorSum	3
#endif
#ifdef HT45F66
	//設置初始化 rambank 個數
	#define RamBankSectorSum	5
#endif
#ifdef HT45F67
	//設置初始化 rambank 個數
	#define RamBankSectorSum	5
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ IAP @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Setting in IAP.h
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ WDT @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Please in Option select WDT clock Source
//if WDT clock Source fs =fsub
//WDT time计算方式:
//WDT time =  2^18/fsub
//example:(max time 周期最长2^18，Source fs = 32768)
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
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ LVR @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  LVS7  |  LVS6  |  LVS5  |  LVS4  |  LVS3  |  LVS2  |  LVS1  |  LVS0  |
// |______________________________________________________________________________
// | POR  |   0    |   1    |   0    |   1    |   0    |   1    |   0    |   1    |
// |_______________________________________________________________________________
// BIT 7~0  LVS7~LVS0:LVR電壓選擇
// 			01010101:  2.1V     00110011:  2.55V
//			10011001:  3.15V    10101010:  3.8V
//          其他值: MCU復位
#define LVR_Voltage2_1			0B01010101
#define LVR_Voltage2_55			0B00110011
#define LVR_Voltage3_15			0B10011001
#define LVR_Voltage3_8			0B10101010
#define LVR_Voltage_Default		LVR_Voltage2_1	//POR=2.1V
//					@-------------IO config--------------@
//Setting in Target.h
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Timer @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                 TM0         TM1         TM2           TM3
// HT45F65      CTM-10bits  CTM-10bits  STM-16bits        -
// HT45F66/67   CTM-10bits  ETM-10bits  STM-16bits   CTM-10bits
//                           @--------------TMnC0---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name | TnPAU  | TnCK2  | TnCK1  | TnCK0  |  TnON  | TnRP2  | TnRP1  | TnRP0  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7  TnPAU:TMn計數器暫停控制位
// 			0:  運行
//			1:  暫停
// BIT 6~4  TnCK2~TnCK0:選擇TMn計數時鐘
// 			000:  fsys/4   001:  fsys   010:   fh/16
// 			011:  fh/64    100:  ftbc   101:   保留位
// 			110:  TCKn上升沿    111:  TCKn下降沿
// BIT 3  TnON:TMn計數器on/off控制位
// 			0:  off
//			1:  on
// BIT 2~0:
// @CTM/ETM(TM0,TM1,TM3)
//	    TnRP2~TnRP0:TMn CCRP 3bit寄存器，與TMn計數器bit9~bit7比較器P匹配週期/時鐘週期
// 			000:  1024   001:  128   010:   256
// 			011:  384    100:  512   101:   640
// 			110:  768    111:  896
// @STM/(TM2)    未定義
#define TM0C0_Default		0x00
#define TM1C0_Default		0x00
#define TM2C0_Default		0x00
#define TM3C0_Default		0x00
//                           @--------------TMnC1---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TnM1  |  TnM0  |  TnIO1 |  TnIO0 |  TnOC  | TnPOL  | TnDPX  | TnCCLR |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~6  TnM1~TnM0:選擇TMn工作模式位
// 		00:  比較器匹配輸出模式   							  01:未定義模式(CTM)  輸入捕捉模式(STM)
//		10:  PWM模式(CTM)  PWM模式/單脈衝輸出模式(STM&ETM)    11:定時/計數器模式
// BIT 5~4  TnIO1~TnIO0:選擇TPn_0，TPn_1輸出功能位
//比較匹配輸出模式
// 			00:  無變化          01:  輸出低
//			10:  輸出高          11:  輸出翻轉
//PWM模式
// 			00:  強制無效狀態    01:  強制有效狀態
//			10:  PWM輸出         11:  未定義(CTM)  單脈衝輸出(STM)
//輸入捕捉模式:(STM)
//			00:在TPn_0,TPn_1上升沿輸入捕捉		01:在TPn_0,TPn_1下升沿輸入捕捉
//			10:在TPn_0,TPn_1雙沿輸入捕捉		11:輸入捕捉除能
//計數器/定時模式: 未定義
//
// BIT 3  TnOC
// 比較匹配輸出模式             PWM模式
// 			0:  初始低             0:  低有效
//			1:  初始高             1:  高有效
// BIT 2  TnPOL:TPn_0,TPn_1輸出極性控制位
// 			0:  同相
//			1:  反相
// BIT 1  TnDPX: TMn PWM週期/占空比控制位
// 			0:  CCRP-週期   ;CCRA-占空比
//			1:  CCRP-占空比 ;CCRP-週期
// BIT 0  TnCCLR:選擇TMn計數器清零條件位
// 			0:  TMn比較器P匹配
//			1:  TMn比較器A匹配
#define TM0C1_Default		0xC1	//定時模式,A匹配中斷
#define TM2C1_Default		0xC1
#define TM3C1_Default		0xC1	//定時模式,A匹配中斷
//                           @--------------TM1C1---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  T1AM1 |  T1AM0 | T1AIO1 | T1AIO0 |  T1AOC | T1APOL | T1CDN  | T1CCLR |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~6  T1AM1~T1AM0:選擇TM1 CCRA工作模式位
//	 		00:  比較器匹配輸出模式   	   01:輸入捕捉模式
//			10:  PWM模式/單脈衝輸出模式    11:定時/計數器模式
// BIT 5~4  T1AIO1~T1AIO0:選擇TP1A輸出功能位
//比較匹配輸出模式
// 			00:  無變化          01:  輸出低
//			10:  輸出高          11:  輸出翻轉
//PWM模式
// 			00:  強制無效狀態    01:  強制有效狀態
//			10:  PWM輸出         11:  單脈衝輸出
//輸入捕捉模式:(STM)
//			00:在TP1A上升沿輸入捕捉		01:在TP1A下升沿輸入捕捉
//			10:在TP1A雙沿輸入捕捉		11:輸入捕捉除能
//計數器/定時模式: 未定義
//
// BIT 3  T1AOC
// 比較匹配輸出模式             PWM模式
// 			0:  初始低             0:  低有效
//			1:  初始高             1:  高有效
// BIT 2  T1APOL:TP1A輸出極性控制位
// 			0:  同相
//			1:  反相
// BIT 1  T1CDN: TM1計數器向上/向下計數標誌位
// 			0:  向上計數
//			1:  向下計數
// BIT 0  T1CCLR:選擇TM1計數器清零條件位
// 			0:  TM1比較器P匹配
//			1:  TM1比較器A匹配
#define TM1C1_Default		0xC1 // only for ETM  TM1
//                           @--------------TM1C2---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  T1BM1 |  T1BM0 | T1BIO1 | T1BIO0 |  T1BOC | T1BPOL | T1PWM1 | T1PWM0 |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~6  T1BM1~T1BM0:選擇TM1 CCRB工作模式位
//	 		00:  比較器匹配輸出模式   	   01:輸入捕捉模式
//			10:  PWM模式/單脈衝輸出模式    11:定時/計數器模式
// BIT 5~4  T1BIO1~T1BIO0:選擇TP1A輸出功能位
//比較匹配輸出模式
// 			00:  無變化          01:  輸出低
//			10:  輸出高          11:  輸出翻轉
//PWM模式
// 			00:  強制無效狀態    01:  強制有效狀態
//			10:  PWM輸出         11:  單脈衝輸出
//輸入捕捉模式:(STM)
//			00:在TP1B_0.TP1B_1,TP1B_2上升沿輸入捕捉		01:在TP1B_0.TP1B_1,TP1B_2下升沿輸入捕捉
//			10:在TP1B_0.TP1B_1,TP1B_2雙沿輸入捕捉		11:輸入捕捉除能
//計數器/定時模式: 未定義
//
// BIT 3  T1BOC
// 比較匹配輸出模式             PWM模式
// 			0:  初始低             0:  低有效
//			1:  初始高             1:  高有效
// BIT 2  T1BPOL:TP1A輸出極性控制位
// 			0:  同相
//			1:  反相
// BIT 1  T1PWM1~T1PWM0:選擇PWM模式位
// 			00:  邊沿對齊          					01: 中心對齊,向上計數比較匹配
//			10:  中心對齊,向下計數比較匹配          11:  中心對齊,向上/下計數比較匹配
#define TM1C2_Default		0xC1 // only for ETM  TM1
//                           @--------------TMnRP---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |   D7   |   D6   |   D5   |   D4   |   D3   |   D2   |   D1   |   D0   |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~0  D7~D0:TMn CCRP高字節暫存器Bit7~Bit0
//          TMn CCRP 8 位暫存器,與TMn計數器Bit15~bit8比較.比較器P匹配週期
// 			0:  65536個TMn時鐘週期
//			1~255: 256X(1~255)個TMn時鐘週期
#define TM2RP_Default       0x00 	// only for STM TM2
// for Hijack TX
#define TM0AL_Default		HiajackCnt0%255
#define TM0AH_Default		HiajackCnt0/255

#define TM1AL_Default		0x00
#define TM1AH_Default		0x00
#define TM1BL_Default		0x00 	// only for  HT45F66/HT45F67 ETM
#define TM1BH_Default		0x00    // only for  HT45F66/HT45F67 ETM
#define TM2AL_Default		0x00
#define TM2AH_Default		0x00
// for Hijack RX
#define TM3AL_Default		0xFF
#define TM3AH_Default		0xFF
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
// BIT 7  TBON:TB0和TB1控制位
// 			0:  Disable
//			1:  Enable
// BIT 6  TBCK:選擇ftb時鐘位
// 			0:  fsub
//			1:  fsys/4
// BIT 5~4  TB11~TB10:TimeBase1溢出週期
// 			00:  2^12/ftb   01:  2^13/ftb
//			10:  2^14/ftb   11:  2^15/ftb
// BIT 3  LXTLP:LXT低功耗控制位
// 			0:  快速啟動模式
//			1:  低功耗模式
// BIT 2~0  TB02~TB00：TimeBase0溢出週期
// 			000:  2^8/ftb    001:  2^9/ftb    010:  2^10/ftb
// 			011:  2^11/ftb   100:  2^12/ftb   101:  2^13/ftb
// 			110:  2^14/ftb   111:  2^15/ftb

#define TimeBase_Default 	0B10110000	//TimeBase1 1S   TimeBase 0  7.8ms

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ADC @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Setting in ADC.h

//					@-------Temperature config-----------@
//Setting in Others file  when need

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ SIM @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Setting in SIM.h

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ UART @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Setting in UART.h
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ INTO @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//                           @--------------INTEG---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |   -    |   -    |   -    |   -    | INT1S1 | INT1S0 | INT0S1 | INT0S0 |
// |______________________________________________________________________________
// | POR  |   -    |   -    |   -    |   -    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~4  未使用,讀為0
// BIT 3~2  INT1S1,INT1S0:INT1腳中斷邊沿控制位
// 			00:  除能     01:  上升沿
//			10:  下降沿   11:  雙邊沿
// BIT 1~0  INT1S1,INT1S0:INT0腳中斷邊沿控制位
// 			00:  除能     01:  上升沿
//			10:  下降沿   11:  雙邊沿
#define INT0_Disable	0b00000000
#define INT0_Rising		0b00000001
#define INT0_Falling	0b00000010
#define INT0_Double		0b00000011
#define INT0_Defualt	INT0_Double

#define INT1_Disable	0b00000000
#define INT1_Rising		0b00000100
#define INT1_Falling	0b00001000
#define INT1_Double		0b00001100
#define INT1_Defualt	INT1_Disable
#endif
