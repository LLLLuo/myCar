#ifndef __MYMOTOR_H__
#define __MYMOTOR_H__
/************电机配置**************/
//电机前进的FTM模块
//#define MOTOR_A_FTM FTM0
//#define MOTOR_A_CH  FTM_CH5    
//
////电机后退的FTM模块
//#define MOTOR_B_FTM FTM0
//#define MOTOR_B_CH  FTM_CH4     

//配置 编码器 参数
#define LEFT_ENCODER_DMA_CH       DMA_CH1          //定义左编码器的DMA采集通道
#define LEFT_ENCODER_COUNT        PTB9             //定义左编码器的DMA计数引脚
#define LEFT_ENCODER_DIRECTION    PTB3             //定义左编码器的DMA采集正负引脚
#define RIGHT_ENCODER_DMA_CH      DMA_CH2          //定义右编码器的DMA采集通道
#define RIGHT_ENCODER_COUNT       PTC13           //定义右编码器的DMA计数引脚
#define RIGHT_ENCODER_DIRECTION   PTC12           //定义右编码器的DMA采集正负引脚







//左电机前进的FTM模块
#define Left_GO_FTM  FTM0
#define Left_GO_CH   FTM_CH5   

//左电机后退的FTM模块
#define Left_BACK_FTM  FTM0
#define Left_BACK_CH   FTM_CH4   

//右电机前进的FTM模块
#define Right_GO_FTM  FTM0
#define Right_GO_CH   FTM_CH7   

//右电机后退的FTM模块
#define Right_BACK_FTM  FTM0
#define Right_BACK_CH   FTM_CH6 

//电机驱动频率
#define MOTOR_FRE 10000
//电机驱动初始化的占空比，【强烈要求为【0】】
#define INIT_DUTY 0
void filter_speed_L();
void filter_speed_R();
void myMotor_Init(void);
void myMotor_Control(void);
//float Leftchasu(int16 num);
//float Rightchasu(int16 num);
void myMotor_Setspeed(int16 PWM_R,int16 PWM_L);
void myMotor_GetEncoder(void);
#endif
