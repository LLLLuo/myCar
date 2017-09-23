#ifndef  __MYBSP_H__
#define  __MYBSP_H__

#define beep PTA5_OUT  

#define  KEY1 PTC3_IN
#define  KEY2 PTC4_IN
#define  KEY3 PTC5_IN
#define  KEY4 PTC7_IN
   
#define  LED1 PTE10_OUT
#define  LED2 PTE12_OUT
//#define  LED3 PTE2_OUT
//#define  LED4 PTE0_OUT

//#define  RED1 PTA12_IN
//#define  RED2 PTA10_IN
//#define  RED3 PTA8_IN
//#define  RED4 PTA6_IN

uint8 myKEY_Scan(uint8 mode);
void myGear_Get(void);
void myBsp_Init(void);
void myBeep_Set(void);
void Stop_find();
extern void OledDisplay();
extern void SendData();


#endif