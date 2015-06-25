//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : HT45F75Config.c
// Description: HT45F75�����������O��
//Targer Board: HT45F75 BodyFat-ESK00
//   MCU      : HT45F75
//   Author   : ChenTing
//   Date     : 2015/05/26
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef _PROJECT_H_
#define _PROJECT_H_

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ׃���� @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//#define gbv_KeyLongPress	gu8v_Flag0.bits.b0 		// ���I�L�����Iλ
//#define gbv_PowerOn			gu8v_Flag0.bits.b1 		// ��һ����늘��Iλ
//#define gbv_KeyPress		gu8v_Flag0.bits.b2		// ���I�����Iλ,�M�밴�IDebounce
//#define gbv_BalanceOK		gu8v_Flag0.bits.b3		//
//#define gbv_ADDGetDataOK	gu8v_Flag0.bits.b4		// �õ�һ�PADCֵ
//#define gbv_ADC_Locking		gu8v_Flag0.bits.b5  	// ADCֵ̎춷�����B��,��߀�]���i��,�˕r�ӑB��������ֵ
//#define gbv_7_8ms			gu8v_Flag0.bits.b6		// TimeBase0 7.8ms���Iλ,��춰��I�ɜy�Ȅ���
//#define gbv_LedPoint		gu8v_Flag0.bits.b7 		// ����߶Δ��a���@ʾС���c���Iλ
//
//#define gbv_Get_Impedance_Error	gu8v_Flag1.bits.b0 	// �迹���y�e�`���Iλ
//#define gbv_CALing				gu8v_Flag1.bits.b1  // ̎�У��ģʽ���Iλ,��춹̶��r�gδ�ɜy����ЧУ�������t�M���迹���y
//#define gbv_WeighOk				gu8v_Flag1.bits.b2 	// ����������yok,�@ʾ��ǰ�����̶��r�g��,�M���迹���yģʽ
//#define gbv_ImpedanceOk			gu8v_Flag1.bits.b3  // �迹���yok,�@ʾ��ǰ�迹�̶��r�g��,�M������ǰȡ���cģʽ
//#define gbv_HeavierLeft			gu8v_Flag1.bits.b4  // ƽ���Д���߅���ؘ��Iλ
//#define gbv_HeavierRight		gu8v_Flag1.bits.b5  // ƽ���Д���߅���ؘ��Iλ
//#define gbv_HeavierAbove		gu8v_Flag1.bits.b6  // ƽ���Д���߅���ؘ��Iλ
//#define gbv_HeavierBelow		gu8v_Flag1.bits.b7  // ƽ���Д���߅���ؘ��Iλ

#define WEIGHMODE 			1
#define IMPEDANCEMODE       2
#define HALTMODE            3
#define GETZEROMODE         4
#define AUTOWEIGHMODE       5
#define BalanceMODE       	6
// ϵ�y�Ԅ����ߕr�g�O��
#define TimeBaseCycle    	1000 	// ms
#define HaltTime60S			60000/TimeBaseCycle
#define HaltTime30S			30000/TimeBaseCycle
#define HaltTime10S			10000/TimeBaseCycle
#define HaltTime5S			5000/TimeBaseCycle
#define HaltTime3S			3000/TimeBaseCycle
#define HaltTime2S			2000/TimeBaseCycle
#define HaltTime1S			1000/TimeBaseCycle
#define HaltTime_Default	HaltTime60S

#endif
