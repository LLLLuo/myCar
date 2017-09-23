#ifndef __MYINDUCTOR_H__
#define __MYINDUCTOR_H__


//#define SI1_SetVal()   PTA27_OUT = 1 ;
//#define SI1_ClrVal()   PTA27_OUT = 0 ;
//#define CLK1_ClrVal()  PTA25_OUT = 0 ;
//#define CLK1_SetVal()  PTA25_OUT = 1 ;

//#define SI2_SetVal()   PTB3_OUT = 1 ;
//#define SI2_ClrVal()   PTB3_OUT = 0 ;
//#define CLK2_ClrVal()  PTA29_OUT = 0 ;
//#define CLK2_SetVal()  PTA29_OUT = 1 ;

#define ADCOUT  10
extern void InductorInit();//adc管脚初始化
extern void InductorAdData();//采值更新
extern void CircleCheck();//圆环检测
extern void RampCheck();
extern void StraightCheck();//直道检测

void SendHex(uint8 hex) ;
void SendImageData(uint8 NO) ;
void SamplingDelay(void) ;
#endif
