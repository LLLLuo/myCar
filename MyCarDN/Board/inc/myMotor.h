#ifndef __MYMOTOR_H__
#define __MYMOTOR_H__
/************�������**************/
//���ǰ����FTMģ��
//#define MOTOR_A_FTM FTM0
//#define MOTOR_A_CH  FTM_CH5    
//
////������˵�FTMģ��
//#define MOTOR_B_FTM FTM0
//#define MOTOR_B_CH  FTM_CH4     

//���� ������ ����
#define LEFT_ENCODER_DMA_CH       DMA_CH1          //�������������DMA�ɼ�ͨ��
#define LEFT_ENCODER_COUNT        PTB9             //�������������DMA��������
#define LEFT_ENCODER_DIRECTION    PTB3             //�������������DMA�ɼ���������
#define RIGHT_ENCODER_DMA_CH      DMA_CH2          //�����ұ�������DMA�ɼ�ͨ��
#define RIGHT_ENCODER_COUNT       PTC13           //�����ұ�������DMA��������
#define RIGHT_ENCODER_DIRECTION   PTC12           //�����ұ�������DMA�ɼ���������







//����ǰ����FTMģ��
#define Left_GO_FTM  FTM0
#define Left_GO_CH   FTM_CH5   

//�������˵�FTMģ��
#define Left_BACK_FTM  FTM0
#define Left_BACK_CH   FTM_CH4   

//�ҵ��ǰ����FTMģ��
#define Right_GO_FTM  FTM0
#define Right_GO_CH   FTM_CH7   

//�ҵ�����˵�FTMģ��
#define Right_BACK_FTM  FTM0
#define Right_BACK_CH   FTM_CH6 

//�������Ƶ��
#define MOTOR_FRE 10000
//���������ʼ����ռ�ձȣ���ǿ��Ҫ��Ϊ��0����
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
