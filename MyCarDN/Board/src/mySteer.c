#include "include.h"


/*************************************************************************
*  函数名称：SteerInit
*  功能说明：舵机初始化
*  参数说明：
*  函数返回：无
*  修改时间：2017-08-28
*  备    注：
*************************************************************************/
void SteerInit()
{
  ftm_pwm_init(S3010_FTM, S3010_CH,S3010_HZ,steer.SteerMid);  
}

/*************************************************************************
*  函数名称：CalculateCurrentError
*  功能说明：偏差计算
*  参数说明：
*  函数返回：无
*  修改时间：2017-08-28
*  备    注：负的偏差左转
*************************************************************************/
void CalculateCurrentError()
{
//     if(flag.CircleFlag==0)//弯道
//     {
//         steer.DirectionPianCha[0]=10.0*inductor.CurrentHorMid/100-10;//偏差 -9 ~0
//     }
//     if (flag.StraightFlag==1)//直道
//     {
//          steer.DirectionPianCha[0]= 0.7*(10.0*inductor.CurrentHorMid/100-10);
//      }
//     if(flag.RampFlag==1)//坡道
//     {
//          steer.DirectionPianCha[0]= 0.3*(10.0*inductor.CurrentHorMid/100-10);
//     }
//     if(flag.CircleFlag==1)//圆环
//     {
//         //  if(inductor.CurrentHorMid>45)    //圆环内改变基准值
//         //  {
//        //       steer->DirectionPianCha[0]=10.0*inductor.CurrentHorMid/inductor.HorMidMax-10;
//        //   }
//        //   else
//        //   {
//               steer.DirectionPianCha[0]=10.0*inductor.CurrentHorMid/100-10;
//        //   }
//     
//     }

    steer.DirectionPianCha[0]=((float)(1000/inductor.CurrentHorLeft)-(float)(1000/inductor.CurrentHorRight));
}

/*************************************************************************
*  函数名称：DirectionDecision
*  功能说明：方向选择
*  参数说明：
*  函数返回：无
*  修改时间：2017-08-28
*  备    注：负的偏差左转
*************************************************************************/
void DirectionDecision()
{   
   //偏差为负的左转(默认)，只要处理右转
  //  if(flag.CircleFlag==0) ///非圆环内的方向控制
   // {
       if(ABS(steer.DirectionPianCha[1]>=7))
       {
            if(steer.DirectionPianCha[1]>0)
            {
             steer.DirectionPianCha[0]=ABS(steer.DirectionPianCha[0]);
             flag.DirFlag=2;//右
            }
       }
       
       else if(inductor.CurrentHorRight>inductor.CurrentHorLeft)
       {
             steer.DirectionPianCha[0]=ABS(steer.DirectionPianCha[0]);
             flag.DirFlag=2;//右
       }
       else if((inductor.CurrentHorRight==inductor.CurrentHorLeft)&&(flag.DirFlag==2))//右弯进直道
       {

             steer.DirectionPianCha[0]=ABS(steer.DirectionPianCha[0]);
             flag.DirFlag=0;//直道清除方向标志
       }         
    //}
    
    
    
//    else if(flag.CircleFlag==1)//圆环内的方向控制
//    {
//         if(flag.CircleLeft==0&&flag.CircleRight==0&&flag.CircleDir[0]==0&&flag.CircleDir[1]==0)//入环方向根据入环前偏差选择
//         {   //判断车子姿态
//             if(steer->DirectionPianCha[1]>0)//入环前车子偏于右转状态，右进圆环
//             {
//                 flag.CircleRight=1;
//                 flag.CircleDir[0]=2;//右
//                 steer->CurrentError=ABS(steer->CurrentError);
//                 
//             }  
//             else//入环前车子偏于左转状态，左进圆环
//             {
//                 flag.CircleLeft=1;
//                 flag.CircleDir[0]=1;//左
//                 steer->CurrentError=-ABS(steer->CurrentError);    
//             }
//         }
//               
//               
//          if(flag.CircleDir[0]!=flag.CircleDir[1])//改变了方向,偏差也反向
//          {
//                  steer->DirectionPianCha[0]=-steer->DirectionPianCha[0];
//                  flag.CircleFlagCount++;
//          }
//          if(flag.CircleFlagCount==0)
//          {
//                   flag.CircleDir[1]=flag.CircleDir[0];
//           }
//          else if (flag.CircleFlagCount>1)
//          {
//                   flag.CircleFlagCount=0;
//                   flag.CircleDir[1]=flag.CircleDir[0];
//    
//          }
//           
//    
//    }
}


/*************************************************************************
*  函数名称：DirectionControl()
*  功能说明：方向控制
*  参数说明：
*  函数返回：无
*  修改时间：2017-08-28
*  备    注：
*************************************************************************/
void DirectionControl()
{
      steer.Kp=9;
      steer.Ki=0;
      steer.Kd=3;
      
      UP=UP0;
      UD=UD0;
      steer.DoubleError=steer.DirectionPianCha[0]-steer.DirectionPianCha[1];
      
      if(steer.DoubleError >0.5)
      steer.DoubleError=0.5;
      if(steer.DoubleError<-0.5)
      steer.DoubleError=-0.5;

      steer.DirectionPianCha[0] = steer.DirectionPianCha[1]+steer.DoubleError;
      //steer.CurrentError = steer.DirectionPianCha[0];
      
      
      steer.DirectionPianCha[4] = steer.DirectionPianCha[3];
      steer.DirectionPianCha[3] = steer.DirectionPianCha[2];
      steer.DirectionPianCha[2] = steer.DirectionPianCha[1];
      steer.DirectionPianCha[1] = steer.DirectionPianCha[0];
      
      
     // steer.TrackComplexity=ABS(steer.CurrentError*100); 
      //steer.ProspectSee=ABS(steer.DoubleError*100); 
      steer.FuzzyP=Fuzzy_Direction_P(steer.TrackComplexity,steer.ProspectSee)/10;
      steer.FuzzyD=Fuzzy_Direction_D(steer.TrackComplexity,steer.ProspectSee)/1000;
      
      
      steer.SteeringZkb=steer.SteerMid +(int16)((steer.FuzzyP*steer.DirectionPianCha[0])+(steer.FuzzyD*steer.DoubleError));
      steer.DirectionOffset=(int16)((steer.FuzzyP* steer.DirectionPianCha[0]) + (steer.FuzzyD*steer.DoubleError));
  
      //舵机大角限幅
      if(steer.SteeringZkb>steer.SteerRightMax)
       steer.SteeringZkb=steer.SteerRightMax;        
      else if(steer.SteeringZkb<steer.SteerLeftMax)
       steer.SteeringZkb=steer.SteerLeftMax;
      
      
      ftm_pwm_duty(S3010_FTM,S3010_CH,steer.SteeringZkb); 
}




      
