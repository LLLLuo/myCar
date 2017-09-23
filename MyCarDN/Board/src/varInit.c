#include "varInit.h"

struct Bsp_status bsp; 
struct Inductor inductor;  //��в���
struct Motor motor;   //���е������
struct Steer steer;   //���ж������
struct Flag flag;   //���б�־λ
//struct Parameter parameter;

/*************************************************************************
*  �������ƣ�myMain_ParametersInit
*  ����˵����һЩ���������ʼ��
*  ����˵������
*  �������أ���
*  �޸�ʱ�䣺2016-4-21
*  ��    ע���쳯��
***********************************void myMain_ParametersInit(void)**************************************/
/*void myMain_ParametersInit(void)
{
  parameter.Time=0;
  parameter.roadlong=0;
  parameter.start_flag=0;
  parameter.start=0;
}*/

/*************************************************************************
*  �������ƣ�MyMotorSpeedDataInit
*  ����˵�����ٶȲ�����ʼ��
*  ����˵������
*  �������أ���
*  �޸�ʱ�䣺2018-8-28
*  ��    ע:��motor�ṹ������Ĳ������г�ʼ��
*************************************************************************/
void MyMotorSpeedDataInit(void)
{ uint8 count;
  motor.Kp=0.0;
  motor.Ki=0.0;
  motor.Kd=0.0;
  motor.StraightKP=0;
  motor.StraightKI=0;
  motor.StraightKD=0;
  motor.CircleSpeed=0;
  motor.TargetSpeedLeft=0;
  motor.TargetSpeedRight=0;
  motor.RealSpeedLeft=0;
  motor.RealSpeedRight=0;
  motor.MotorOutputDutyLeft=0;
  motor.MotorOutputDutyRight=0;
  motor.AveSpeed=0;//ƽ���ٶ�
  motor.SpeedErrorLeft=0;
  motor.SpeedErrorRight=0;
  for(count=0;count<10;count++)
  {
       motor.RealSpeedSaveLeft[count]=0;
        motor.RealSpeedSaveRight[count]=0;
  }
  
  for(count=0;count<3;count++)
  {
       motor.SpeedErrorSaveLeft[count]=0;
       motor.SpeedErrorSaveRight[count]=0;
   }
  motor.MotorOutputDutyLeft=0;
  motor.MotorOutputDutyRight=0;
  //motor.TrackComplexity=0;
  //motor.ProspectSee=0;
  motor.TargetSpeedLeft=0;
  motor.TargetSpeedRight=0;
  
  //����޷�
  motor.LeftMaxSpeed=999;
  motor.LeftMinSpeed=-999;
  motor.RightMaxSpeed=999;
  motor.RightMinSpeed=-999;

  
}

/*************************************************************************
*  �������ƣ�MySteerDataInit
*  ����˵�������������ʼ��
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-8-28
*  ��    ע��
*************************************************************************/
void MySteerDataInit(void) //������ݳ�ʼ��
{ uint8 count;
  steer.Kp=0;
  steer.Ki=0;
  steer.Kd=0;  
  steer.FuzzyP=0;
  steer.FuzzyD=0;
  
  
  steer.SteeringZkb=0;
  steer.DirectionOffset=0;
  steer.CurrentError=0.0;
  steer.DoubleError=0.0;
  for(count=0;count<10;count++)
  {
      steer.DirectionPianCha[count]=0;
  }  
  //����޷�
  steer.SteerMid=842; 
  steer.SteerLeftMax=912;
  steer.SteerRightMax=772;
  
  
  steer.TrackComplexity=0; 
  steer.ProspectSee=0; 

}



/*************************************************************************
*  �������ƣ�MyInductorDataInit
*  ����˵������в�����ʼ��
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-02-28
*  ��    ע��
*************************************************************************/
void MyInductorDataInit(void) //������ݳ�ʼ��
{
  /*��ǰ���ֵ��ʼ��*/
  uint8 count;
  inductor.CurrentHorLeft=0;   //ˮƽ����
  inductor.CurrentHorMid=0; //ˮƽ�м���
  inductor.CurrentHorRight=0;    //ˮƽ�ҵ��
  
  
  inductor.CurrentVerLeft=0;  //��ֱ����
  inductor.CurrentVerMid=0;   //��ֱ�м���
  inductor.CurrentVerRight=0; //��ֱ�ҵ��
  //������ֵ��ʼ��
//  inductor.HorLeftMax=100;
//  inductor.HorMidMax=100;  
//  inductor.HorRightMax=100;
//  inductor.VerLeftMax=100;
//  inductor.VerMidMax=100;
//  inductor.VerRightMax=100;
  
  
  /*��ŵ��ֵ�������ʼ��*/
  for(count=0;count<6;count++)
  {
      inductor.HorLeft[count]=0;
      inductor.HorMid[count]=0;
      inductor.HorRight[count]=0;
      inductor.VerLeft[count]=0;
      inductor.VerMid[count]=0;
      inductor.VerRight[count]=0;            
  }  
}

/*************************************************************************
*  �������ƣ�myBsp_DataInit
*  ����˵�������������صȲ�����ʼ��
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-08-28
*  ��    ע��
*************************************************************************/
void MyBspDataInit(void)
{
    bsp.Gear1=0; //���뿪��
    bsp.Gear2=0;
    bsp.Gear3=0;
    bsp.Gear4=0;
    bsp.Gear5=0;
    bsp.Gear6=0;
}

/*************************************************************************
*  �������ƣ�MyFlagDataInit
*  ����˵����ֱ��,Բ�����µ��ȱ�־λ��ʼ��
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-08-28
*  ��    ע��
*************************************************************************/
void MyFlagDataInit(void)
{  //����
   flag.Start=0;
   //ͣ��
   flag.Stop=0;
   //ֱ��
   flag.StraightCount=0;
   flag.StraightFlag=0;
   flag.LongStraitFlag=0;
   //Բ��
   flag.DirFlag=0;
   flag.CircleFlag=0;
   flag.CircleNum=0;
   flag.CircleFlagCount=0;
   flag.CircleLeft=0;
   flag.CircleRight=0;
   flag.CircleDir[0]=0;
   flag.CircleDir[1]=0;
   //�µ�
   flag.RampCount=0;
   flag.RampFlag=0;
   flag.InRampCount=0;
   flag.RampStart=0;
   //��ѹ
   flag.Vt=0;
}

