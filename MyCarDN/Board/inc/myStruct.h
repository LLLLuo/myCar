 /*!
  * @file       myStruct.h
  * @brief      ����ṹ��ͷ�ļ�
  * @author     
  * @version    v5.0
  * @date       2017-08-28
  */

#ifndef __MYSTRUCT_H__
#define __MYSTRUCT_H__

#define SPEED_FIFO_LENGTH (20) //�����ٶ�

typedef struct Bsp_status
{
    uint8 Gear1; //���뿪��
    uint8 Gear2;
    uint8 Gear3;
    uint8 Gear4;
    uint8 Gear5;
    uint8 Gear6;
}Bsp_status;

typedef struct Inductor//--------------------------------------��в�ֵ
{  
    //���ֵ���
    uint8 HorLeft[6];    //ˮƽ����
    uint8 HorMid[6];  //ˮƽ�м���
    uint8 HorRight[6];   //ˮƽ�ҵ��   
    uint8 VerLeft[6];    //��ֱ����
    uint8 VerMid[6];      //��ֱ�м���
    uint8 VerRight[6];    //��ֱ�ҵ��
    /* ���ڴ�ŵ�ǰ������е�ֵ*/
    uint8 CurrentHorLeft;
    uint8 CurrentHorMid; 
    uint8 CurrentHorRight;
    uint8 CurrentVerLeft;
    uint8 CurrentVerMid; 
    uint8 CurrentVerRight;
    //Բ��ˮƽ�м��л�׼ֵ
    uint8 CircleHorMid;
   //������ֵ���޷��� 
//    uint8 HorLeftMax;
//    uint8 HorMidMax;  
//    uint8 HorRightMax;
//    uint8 VerLeftMax;
//    uint8 VerMidMax;
//    uint8 VerRightMax;
}Inductor;

typedef struct Steer//--------------------------------------���
{

  float Kp;  //P
  float Ki;  //I  
  float Kd;  //D
  float FuzzyP;//ģ��PD
  float FuzzyD;
  uint16 SteeringZkb;   //���ռ�ձ�
  uint16 DirectionOffset;   // ռ�ձȱ仯��
  float CurrentError;      //��ǰƫ��
  float DirectionPianCha[10];   //�洢ƫ��
  float DoubleError;    //ƫ��仯��
  float TrackComplexity; 
  float ProspectSee;  
  
  //����޷�
  int32 SteerMid;	 			
  int32 SteerLeftMax;				
  int32 SteerRightMax; 
}Steer;





typedef struct Motor//-------------------------------------------------�ٶ�
{

  float Kp;  //P
  float Ki;  //I  
  float Kd;  //D
  
  
  
  float StraightKP; //ֱ��PID����������³��Ч��
  float StraightKI;
  float StraightKD;
  
  int16 CircleSpeed;   //Բ���ٶ�
  int16 RealSpeedLeft;  // DMA ����
  int16 RealSpeedRight;  // DMA ����
  int16 AveSpeed;  //ƽ���ٶ�
  
  int16 RealSpeedSaveLeft[10]; //�洢�ٶ� 
  int16 RealSpeedSaveRight[10]; //�洢�ٶ� 
  
  int16 SpeedErrorLeft; //�����ٶ����
  int16 SpeedErrorRight; //�����ٶ����
  
  int16 SpeedErrorSaveLeft[3];  //��������ٶ����
  int16 SpeedErrorSaveRight[3];  //��������ٶ����
  
  
  int16 MotorOutputDutyLeft; //���ռ�ձ�
  int16 MotorOutputDutyRight; //���ռ�ձ�

  
  
 // float TrackComplexity; //ABS(CurrentError*10)
 // float ProspectSee;  //ABS(DoubleError*100)
  int16 TargetSpeedLeft;//Ԥ���ٶ�
  int16 TargetSpeedRight;//Ԥ���ٶ�
 
//����
  int16 LeftMaxSpeed;
  int16 LeftMinSpeed;
  int16 RightMaxSpeed;
  int16 RightMinSpeed;
  
}Motor;  
    




typedef struct Flag//-------------------------------------------------��־    
{
  //������־
   uint8 Start;
   
//ͣ����־
   uint8 Stop;
     
//ֱ��������ֱ����־
   uint8 StraightCount;
   uint8 StraightFlag; //�����־����ֱ��
   uint8 LongStraitFlag;//��ֱ����־
  
//��Բ�������־
   uint8 DirFlag;// 0:��ֵ 1����ת  2����ת
   
//Բ����־
   uint8 CircleFlag;//Բ����־   
   uint8 CircleNum;//��¼Ŀǰ�ǵڼ���Բ��
   uint16 CircleFlagCount;//Բ���ڼ���
   uint8 CircleLeft;//1:����Բ��
   uint8 CircleRight;//1:����Բ��
   uint8 CircleDir[2];//��Բ�������־ 0:��ֵ 1����ת  2����ת
//�µ���־
   uint8 RampCount;//�µ�����,�����ж��µ���־
   uint8 RampFlag; //�µ���־
   uint16 InRampCount;//�����µ������
   uint8 RampStart;//��־ �Ҹо�������û�õ�
   float Vt;//��ѹ
}Flag;

/*
typedef struct Parameter//------------------------------------------һЩ����
{
  float	Time;						//��ʻʱ��(��)
  uint16 roadlong; //��������
  int32 num;
  uint16 start_flag;
  uint8  start;
  
}Parameter;

*/
#endif
