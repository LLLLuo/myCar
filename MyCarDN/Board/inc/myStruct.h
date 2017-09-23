 /*!
  * @file       myStruct.h
  * @brief      定义结构体头文件
  * @author     
  * @version    v5.0
  * @date       2017-08-28
  */

#ifndef __MYSTRUCT_H__
#define __MYSTRUCT_H__

#define SPEED_FIFO_LENGTH (20) //保存速度

typedef struct Bsp_status
{
    uint8 Gear1; //拨码开关
    uint8 Gear2;
    uint8 Gear3;
    uint8 Gear4;
    uint8 Gear5;
    uint8 Gear6;
}Bsp_status;

typedef struct Inductor//--------------------------------------电感采值
{  
    //电感值存放
    uint8 HorLeft[6];    //水平左电感
    uint8 HorMid[6];  //水平中间电感
    uint8 HorRight[6];   //水平右电感   
    uint8 VerLeft[6];    //垂直左电感
    uint8 VerMid[6];      //垂直中间电感
    uint8 VerRight[6];    //垂直右电感
    /* 用于存放当前各个电感的值*/
    uint8 CurrentHorLeft;
    uint8 CurrentHorMid; 
    uint8 CurrentHorRight;
    uint8 CurrentVerLeft;
    uint8 CurrentVerMid; 
    uint8 CurrentVerRight;
    //圆环水平中间电感基准值
    uint8 CircleHorMid;
   //电感最大值（限幅） 
//    uint8 HorLeftMax;
//    uint8 HorMidMax;  
//    uint8 HorRightMax;
//    uint8 VerLeftMax;
//    uint8 VerMidMax;
//    uint8 VerRightMax;
}Inductor;

typedef struct Steer//--------------------------------------舵机
{

  float Kp;  //P
  float Ki;  //I  
  float Kd;  //D
  float FuzzyP;//模糊PD
  float FuzzyD;
  uint16 SteeringZkb;   //输出占空比
  uint16 DirectionOffset;   // 占空比变化量
  float CurrentError;      //当前偏差
  float DirectionPianCha[10];   //存储偏差
  float DoubleError;    //偏差变化率
  float TrackComplexity; 
  float ProspectSee;  
  
  //舵机限幅
  int32 SteerMid;	 			
  int32 SteerLeftMax;				
  int32 SteerRightMax; 
}Steer;





typedef struct Motor//-------------------------------------------------速度
{

  float Kp;  //P
  float Ki;  //I  
  float Kd;  //D
  
  
  
  float StraightKP; //直道PID参数，类似鲁棒效果
  float StraightKI;
  float StraightKD;
  
  int16 CircleSpeed;   //圆环速度
  int16 RealSpeedLeft;  // DMA 左轮
  int16 RealSpeedRight;  // DMA 左轮
  int16 AveSpeed;  //平均速度
  
  int16 RealSpeedSaveLeft[10]; //存储速度 
  int16 RealSpeedSaveRight[10]; //存储速度 
  
  int16 SpeedErrorLeft; //左轮速度误差
  int16 SpeedErrorRight; //右轮速度误差
  
  int16 SpeedErrorSaveLeft[3];  //存放左轮速度误差
  int16 SpeedErrorSaveRight[3];  //存放右轮速度误差
  
  
  int16 MotorOutputDutyLeft; //输出占空比
  int16 MotorOutputDutyRight; //输出占空比

  
  
 // float TrackComplexity; //ABS(CurrentError*10)
 // float ProspectSee;  //ABS(DoubleError*100)
  int16 TargetSpeedLeft;//预设速度
  int16 TargetSpeedRight;//预设速度
 
//限速
  int16 LeftMaxSpeed;
  int16 LeftMinSpeed;
  int16 RightMaxSpeed;
  int16 RightMinSpeed;
  
}Motor;  
    




typedef struct Flag//-------------------------------------------------标志    
{
  //发车标志
   uint8 Start;
   
//停车标志
   uint8 Stop;
     
//直道计数和直道标志
   uint8 StraightCount;
   uint8 StraightFlag; //出弯标志，进直道
   uint8 LongStraitFlag;//长直道标志
  
//非圆环方向标志
   uint8 DirFlag;// 0:初值 1：左转  2：右转
   
//圆环标志
   uint8 CircleFlag;//圆环标志   
   uint8 CircleNum;//记录目前是第几个圆环
   uint16 CircleFlagCount;//圆环内计数
   uint8 CircleLeft;//1:左入圆环
   uint8 CircleRight;//1:右入圆环
   uint8 CircleDir[2];//入圆环方向标志 0:初值 1：左转  2：右转
//坡道标志
   uint8 RampCount;//坡道计数,用于判断坡道标志
   uint8 RampFlag; //坡道标志
   uint16 InRampCount;//进入坡道后计数
   uint8 RampStart;//标志 我感觉定义了没用到
   float Vt;//电压
}Flag;

/*
typedef struct Parameter//------------------------------------------一些参数
{
  float	Time;						//行驶时间(秒)
  uint16 roadlong; //赛道长度
  int32 num;
  uint16 start_flag;
  uint8  start;
  
}Parameter;

*/
#endif
