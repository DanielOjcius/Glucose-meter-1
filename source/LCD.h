//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : LCD.h
// Description: LCD顯示相關設定
//Targer Board:
//   MCU      : HT45F6x
//   Author   : ChenTing
//   Date     : 2015/06/29
//   MCU  	    Duty       Bias   Type   WAVE		Point
// HT45F65      1/4 	   1/3     C      A/B       24x4
// HT45F66    1/4,1/6 	   1/3     C      A/B       30x6,32x4
// HT45F67    1/4,1/6 	   1/3     C      A/B       30x6.32x4
//___________________________________________________________________
//___________________________________________________________________
#ifndef LCD_H
#define LCD_H



//                           @--------------LCDC---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TYPE  |   VAS  |   -    |   -    |   -    |   -    |   -    | LCDEN  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   -    |   -    |   -    |   -    |   -    |   0    |
// |_______________________________________________________________________________
// BIT 7  TYPE:LCD類型控制
// 			0:  A型
//			1:  B型
// BIT 6  VAS:C型LCD VA電壓選擇
// 			0:  VA=VDD
//			1:  VA=VDDx1.5
// BIT 5  未定義:HT45F65
//			0: 1/4duty,32SEG*4COM  // for HT45F66 or HT45F67
//			1: 1/6duty,30SEG*6COM
// BIT 4~1  未定義,讀為0
// 			0:  1.05V
//			1:  1.25V
// BIT 0  LVDEN:LCD使能控制位
// 			0:  除能
//			1:  使能
//	在正常,低速和空閒模式下,LCD的開/關可通過此位控制,休眠模式LCD一直關閉
#define LCDC_Default 0x01

#endif
