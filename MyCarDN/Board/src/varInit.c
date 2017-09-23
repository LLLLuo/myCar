#include "varInit.h"

struct Bsp_status bsp; 
struct Inductor inductor;  //电感参数
struct Motor motor;   //所有电机参数
struct Steer steer;   //所有舵机参数
struct Flag flag;   //所有标志位
//struct Parameter parameter;

/*************************************************************************
*  函数名称：myMain_ParametersInit
*  功能说明：一些特殊参数初始化
*  参数说明：无
*  函数返回：无
*  修改时间：2016-4-21
*  备    注：朱朝阳
***********************************void myMain_ParametersInit(void)**************************************/
/*void myMain_ParametersInit(void)
{
  parameter.Time=0;
  parameter.roadlong=0;
  parameter.start_flag=0;
  parameter.start=0;
}*/

/*************************************************************************
*  函数名称：MyMotorSpeedDataInit
*  功能说明：速度参数初始化
*  参数说明：无
*  函数返回：无
*  修改时间：2018-8-28
*  备    注:对motor结构体里面的参数进行初始化
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
  motor.AveSpeed=0;//平均速度
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
  
  //电机限幅
  motor.LeftMaxSpeed=999;
  motor.LeftMinSpeed=-999;
  motor.RightMaxSpeed=999;
  motor.RightMinSpeed=-999;

  
}

/*************************************************************************
*  函数名称：MySteerDataInit
*  功能说明：舵机参数初始化
*  参数说明：
*  函数返回：无
*  修改时间：2017-8-28
*  备    注：
*************************************************************************/
void MySteerDataInit(void) //舵机数据初始化
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
  //舵机限幅
  steer.SteerMid=842; 
  steer.SteerLeftMax=912;
  steer.SteerRightMax=772;
  
  
  steer.TrackComplexity=0; 
  steer.ProspectSee=0; 

}



/*************************************************************************
*  函数名称：MyInductorDataInit
*  功能说明：电感参数初始化
*  参数说明：
*  函数返回：无
*  修改时间：2017-02-28
*  备    注：
*************************************************************************/
void MyInductorDataInit(void) //电感数据初始化
{
  /*当前电感值初始化*/
  uint8 count;
  inductor.CurrentHorLeft=0;   //水平左电感
  inductor.CurrentHorMid=0; //水平中间电感
  inductor.CurrentHorRight=0;    //水平右电感
  
  
  inductor.CurrentVerLeft=0;  //垂直左电感
  inductor.CurrentVerMid=0;   //垂直中间电感
  inductor.CurrentVerRight=0; //垂直右电感
  //电感最大值初始化
//  inductor.HorLeftMax=100;
//  inductor.HorMidMax=100;  
//  inductor.HorRightMax=100;
//  inductor.VerLeftMax=100;
//  inductor.VerMidMax=100;
//  inductor.VerRightMax=100;
  
  
  /*存放电感值的数组初始化*/
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
*  函数名称：myBsp_DataInit
*  功能说明：按键、开关等参数初始化
*  参数说明：
*  函数返回：无
*  修改时间：2017-08-28
*  备    注：
*************************************************************************/
void MyBspDataInit(void)
{
    bsp.Gear1=0; //拨码开关
    bsp.Gear2=0;
    bsp.Gear3=0;
    bsp.Gear4=0;
    bsp.Gear5=0;
    bsp.Gear6=0;
}

/*************************************************************************
*  函数名称：MyFlagDataInit
*  功能说明：直道,圆环，坡道等标志位初始化
*  参数说明：
*  函数返回：无
*  修改时间：2017-08-28
*  备    注：
*************************************************************************/
void MyFlagDataInit(void)
{  //发车
   flag.Start=0;
   //停车
   flag.Stop=0;
   //直道
   flag.StraightCount=0;
   flag.StraightFlag=0;
   flag.LongStraitFlag=0;
   //圆环
   flag.DirFlag=0;
   flag.CircleFlag=0;
   flag.CircleNum=0;
   flag.CircleFlagCount=0;
   flag.CircleLeft=0;
   flag.CircleRight=0;
   flag.CircleDir[0]=0;
   flag.CircleDir[1]=0;
   //坡道
   flag.RampCount=0;
   flag.RampFlag=0;
   flag.InRampCount=0;
   flag.RampStart=0;
   //电压
   flag.Vt=0;
}

