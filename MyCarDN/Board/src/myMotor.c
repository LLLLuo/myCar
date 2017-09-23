#include "include.h"

/***********************电机控制-增量式pid*****************************************/

/*************************************************************************
*  函数名称：myMotor_UpdateEncoder
*  功能说明：编码器相关数据更新
*  参数说明：
*  函数返回：无
*  修改时间：2016-4-21    
*  备    注：朱朝阳
*************************************************************************/

void myMotor_GetEncoder(void)
{
  
    uint8 L,R;
    L=gpio_get(LEFT_ENCODER_DIRECTION);
    R=gpio_get(RIGHT_ENCODER_DIRECTION);
    if(L==0)
    motor.RealSpeedLeft= DMA_count_get(LEFT_ENCODER_DMA_CH);
    else
    motor.RealSpeedLeft=-DMA_count_get(LEFT_ENCODER_DMA_CH); 
    if(R==0)
    motor.RealSpeedRight=-DMA_count_get(RIGHT_ENCODER_DMA_CH);
    else                                                                                                                                                                                   
    motor.RealSpeedRight= DMA_count_get(RIGHT_ENCODER_DMA_CH); 
    
    DMA_count_reset(LEFT_ENCODER_DMA_CH);
    DMA_count_reset(LEFT_ENCODER_DMA_CH);
    DMA_count_reset(RIGHT_ENCODER_DMA_CH);
    DMA_count_reset(RIGHT_ENCODER_DMA_CH);
    filter_speed_L();
    filter_speed_R();
  
}
  
//获取左右电机速度，滤波
#define LAG 40.0 //滞后系数 越小越滞后
void filter_speed_L()
{
    static float a = 0;
    float speed_error ;
 //   motor.speed_L=FTM2_Speed_get();
    speed_error = motor.RealSpeedLeft - motor.SpeedErrorSaveLeft[0];
    a = speed_error/LAG ;                //a是系数
    if(a < 0)
      a = -a ;
    if(a > 0.85)
      a = 0.85 ;
  //速度滤波，一阶滞后滤波算法
  motor.RealSpeedLeft = (int16)(motor.RealSpeedLeft * (1-a) + (motor.SpeedErrorSaveLeft[0]+motor.SpeedErrorSaveLeft[1]+motor.SpeedErrorSaveLeft[2])*a/3);//(motor.speed_L * (1-a) + (motor.speed_L_save[0]+motor.speed_L_save[1]+motor.speed_L_save[2]+motor.speed_L_save[3]+motor.speed_L_save[4]+motor.speed_L_save[5]+motor.speed_L_save[6]+motor.speed_L_save[7]+motor.speed_L_save[8]+motor.speed_L_save[9])*a/10);// car.speed_new * 0.1 +  
  
  motor.SpeedErrorSaveLeft[2] = motor.SpeedErrorSaveLeft[1] ;
  motor.SpeedErrorSaveLeft[1] = motor.SpeedErrorSaveLeft[0] ;
  motor.SpeedErrorSaveLeft[0] = motor.RealSpeedLeft ;
//  car.speed_error = car.speed_new - car.speed_old;
//  car.speed_old = car.speed_new ; 
}

void filter_speed_R()
{
    static float a = 0;
    float speed_error ;
 //   motor.speed_L=FTM2_Speed_get();
    speed_error = motor.RealSpeedRight - motor.SpeedErrorSaveRight[0];
    a = speed_error/LAG ;                //a是系数
    if(a < 0)
      a = -a ;
    if(a > 0.85)
      a = 0.85 ;
  //速度滤波，一阶滞后滤波算法
  motor.RealSpeedRight = (int16)(motor.RealSpeedRight * (1-a) + (motor.SpeedErrorSaveRight[0]+motor.SpeedErrorSaveRight[1]+motor.SpeedErrorSaveRight[2])*a/3);//(motor.speed_R * (1-a) + (motor.speed_R_save[0]+motor.speed_R_save[1]+motor.speed_R_save[2]+motor.speed_R_save[3]+motor.speed_R_save[4]+motor.speed_R_save[5]+motor.speed_R_save[6]+motor.speed_R_save[7]+motor.speed_R_save[8]+motor.speed_R_save[9])*a/10);// car.speed_new * 0.1 +  
  
  motor.SpeedErrorSaveRight[2] = motor.SpeedErrorSaveRight[1] ;
  motor.SpeedErrorSaveRight[1] = motor.SpeedErrorSaveRight[0] ;
  motor.SpeedErrorSaveRight[0] = motor.RealSpeedRight ;
//  car.speed_error = car.speed_new - car.speed_old;
//  car.speed_old = car.speed_new ; 
}
        


/*************************************************************************
*  函数名称：myMotor_Control
*  功能说明：电机PID算法控制
*  参数说明：uint8 load_type  道路类型
*  函数返回：无
*  修改时间：2017-08-29    
*  备    注：
*************************************************************************/
void myMotor_Control(void) 
{  
 

     

 
}



/*************************************************************************
*  函数名称：myMotor_Setspeed
*  功能说明：电机输出、带限幅
*  参数说明：
*  函数返回：无
*  修改时间：2016-4-21    
*  备    注：后轮左右轮的距离为13.7cm，前后轮的距离为19.8cm
*************************************************************************/
void myMotor_Setspeed(int16 PWM_R,int16 PWM_L)//给速度
{    
    if(PWM_L>motor.LeftMaxSpeed) PWM_L=motor.LeftMaxSpeed;
    if(PWM_L<motor.LeftMinSpeed) PWM_L=motor.LeftMinSpeed;
    if(PWM_R>motor.LeftMaxSpeed) PWM_R=motor.LeftMaxSpeed;
    if(PWM_R<motor.LeftMinSpeed) PWM_R=motor.LeftMinSpeed;
  //左
  if(PWM_L>=0)
    {
      ftm_pwm_duty(Left_BACK_FTM,Left_BACK_CH,0);
      ftm_pwm_duty(Left_GO_FTM,Left_GO_CH,(uint32)(PWM_L));
    }
  else
    {
      ftm_pwm_duty(Left_GO_FTM,Left_GO_CH,0);
      ftm_pwm_duty(Left_BACK_FTM,Left_BACK_CH,(uint32)(-PWM_L));
    } 
  //右
  if(PWM_R>=0)
    {
      ftm_pwm_duty(Right_BACK_FTM,Right_BACK_CH,0);
      ftm_pwm_duty(Right_GO_FTM,Right_GO_CH,(uint32)(PWM_R));
    }
  else
    {
      ftm_pwm_duty(Right_GO_FTM,Right_GO_CH,0);
      ftm_pwm_duty(Right_BACK_FTM,Right_BACK_CH,(uint32)(-PWM_R));
    }
  
}
   




/*************************************************************************
*  函数名称：Motor_PID_control
*  功能说明：电机PID算法控制
*  参数说明：uint8 load_type  道路类型
*  函数返回：无
*  修改时间：2016-4-21    
*  备    注：后轮左右轮的距离为13.7cm，前后轮的距离为19.8cm
*************************************************************************/
void myMotor_Init(void)
{
    DMA_count_Init(LEFT_ENCODER_DMA_CH,LEFT_ENCODER_COUNT, 0x7FFF,DMA_rising);//左编码器
    DMA_count_Init(RIGHT_ENCODER_DMA_CH,RIGHT_ENCODER_COUNT, 0x7FFF,DMA_rising);//右编码器
    gpio_init(LEFT_ENCODER_DIRECTION,GPI,1);
    gpio_init(RIGHT_ENCODER_DIRECTION,GPI,1); 
  
    ftm_pwm_init(Left_GO_FTM,Left_GO_CH,MOTOR_FRE,INIT_DUTY);
    ftm_pwm_init(Left_BACK_FTM,Left_BACK_CH,MOTOR_FRE,INIT_DUTY);
    ftm_pwm_init(Right_GO_FTM,Right_GO_CH,MOTOR_FRE,INIT_DUTY);
    ftm_pwm_init(Right_BACK_FTM,Right_BACK_CH,MOTOR_FRE,INIT_DUTY);

}
//{     
//  if(Bsp.gear4==1)
//  {
//   speed.R_TargetSpeed= speed.kspeed;
//   speed.L_TargetSpeed= speed.kspeed;
//  }
//  else
//  {
//     speed.R_TargetSpeed= speed.SetSpeed;
//     speed.L_TargetSpeed= speed.SetSpeed;
//  }
//  //根据舵机pwm来设定差速值
//  if((steer.Steer_PWMOutputDuty-steer.Steer_Center)>=30) //向左打角， 
//  {
//    speed.R_TargetSpeed=(int16)(speed.R_TargetSpeed*(2/(1+Leftchasu(steer.Steer_PWMOutputDuty-steer.Steer_Center))));//右边加
//    speed.L_TargetSpeed=(int16)(speed.L_TargetSpeed*(2*Leftchasu(steer.Steer_PWMOutputDuty-steer.Steer_Center))/(1+Leftchasu(steer.Steer_PWMOutputDuty-steer.Steer_Center))); //左边减
//  }
//  else if((steer.Steer_PWMOutputDuty-steer.Steer_Center)<=-30) //向右打角,右轮减速
//  {
//    speed.L_TargetSpeed=(int16)(speed.L_TargetSpeed*(2/(1+Rightchasu((steer.Steer_PWMOutputDuty-steer.Steer_Center)))));//左边加
//    speed.R_TargetSpeed=(int16)(speed.R_TargetSpeed*(2*Rightchasu((steer.Steer_PWMOutputDuty-steer.Steer_Center)))/(1+Rightchasu(steer.Steer_PWMOutputDuty-steer.Steer_Center))); //右边减
//  }
//  
//  speed.L_Speednow=speed.speed_Lnum; //左电机速度
//  speed.R_Speednow=speed.speed_Rnum; //右电机速度
//   
//  speed.avg_speed= (speed.L_Speednow+ speed.R_Speednow)/2; //平均速度
//   
//  speed.Left_err[2]=speed.Left_err[1];
//  speed.Left_err[1]=speed.Left_err[0];
//  speed.Left_err[0]=speed.L_TargetSpeed-(int16)(speed.L_Speednow);   
//    
//  speed.Right_err[2]=speed.Right_err[1];
//  speed.Right_err[1]=speed.Right_err[0]; 
//  speed.Right_err[0]=speed.R_TargetSpeed-(int16)(speed.R_Speednow); 
//    
//  speed.L_PWMOutputDuty= speed.L_PWMOutputDuty + (int32)(motor.KP*(speed.Left_err[0]-speed.Left_err[1])+motor.KI*speed.Left_err[0]+motor.KD*(speed.Left_err[0]-2*speed.Left_err[1]+speed.Left_err[2]));
//  speed.R_PWMOutputDuty= speed.R_PWMOutputDuty + (int32)(motor.KP*(speed.Right_err[0]-speed.Right_err[1])+motor.KI*speed.Right_err[0]+motor.KD*(speed.Right_err[0]-2*speed.Right_err[1]+speed.Right_err[2]));
//
//#if 1 
//   if(ABS(ccd1.CURRENT_ERROR) <= 15 && ABS(ccd1.LAST_ERROR[1]) <=15 && ABS(ccd1.LAST_ERROR[2]) <=15)  //在直道上
//   {
//      if(speed.avg_speed < (speed.SetSpeed-20) )
//      {
//        speed.BBcontrol=1; //棒棒加速
//        speed.L_PWMOutputDuty=motor.Speed_MAX;
//        speed.R_PWMOutputDuty=motor.Speed_MAX;
//       }
//      else if(speed.avg_speed >190 && speed.longStraight_flag==1 && speed.ruwan_flag==1) //？有问题，用模糊的话
//      {
//           speed.BBcontrol=2; //棒棒减速
//           speed.L_PWMOutputDuty=motor.Speed_MIN;
//           speed.R_PWMOutputDuty=motor.Speed_MIN;
//      }
//      else
//      {
//        if(speed.BBcontrol==1)
//        {
//           speed.L_PWMOutputDuty=9000;
//           speed.R_PWMOutputDuty=9000;
//        }
//        else if(speed.BBcontrol==2)
//        {
//           speed.L_PWMOutputDuty=-9000;
//           speed.R_PWMOutputDuty=-9000;
//        }
//        speed.BBcontrol=0;
//      }
//   }
//   else
//   {
//     if(speed.BBcontrol==1)
//     {
//         speed.L_PWMOutputDuty=7000;
//         speed.R_PWMOutputDuty=7000;
//      }
//     else if(speed.BBcontrol==2)
//     {
//         speed.L_PWMOutputDuty=-7000;
//         speed.R_PWMOutputDuty=-7000;
//     }
//     speed.BBcontrol=0;
//     beep=0;
//   }
//#else 
//  if(ABS(ccd1.CURRENT_ERROR) <= 10 && ABS(ccd1.LAST_ERROR[1]) <=10 && ABS(ccd1.LAST_ERROR[2]) <=10)  //在直道上
//  {
//     if(speed.avg_speed < (speed.SetSpeed-30) )
//     {
//       speed.BBcontrol=1; //棒棒加速
//       beep=1;
//      }
//     else if(speed.avg_speed > (speed.SetSpeed+30))
//     {
//       speed.BBcontrol=2; //棒棒减速
//       beep=1;
//     }
//     else
//     {
//       speed.BBcontrol=0;
//       beep=0;
//     }
//  }
//  else
//  {
//    speed.BBcontrol=0;
//    beep=0;
//  }
//#endif
//  
// //限幅  
//    if(speed.L_PWMOutputDuty>motor.Speed_MAX) speed.L_PWMOutputDuty=motor.Speed_MAX;
//    if(speed.L_PWMOutputDuty<motor.Speed_MIN) speed.L_PWMOutputDuty=motor.Speed_MIN;
//    if(speed.R_PWMOutputDuty>motor.Speed_MAX) speed.R_PWMOutputDuty=motor.Speed_MAX;
//    if(speed.R_PWMOutputDuty<motor.Speed_MIN) speed.R_PWMOutputDuty=motor.Speed_MIN;
//
//    if(speed.BBcontrol==1)
//        myMotor_Setspeed(motor.Speed_MAX,motor.Speed_MAX);
//    else if(speed.BBcontrol==2)
//        myMotor_Setspeed(motor.Speed_MIN,motor.Speed_MIN);
//    else
//        myMotor_Setspeed(speed.L_PWMOutputDuty,speed.R_PWMOutputDuty);





/*************************************************************************
*  函数名称：Rightchasu
*  功能说明：查表法差速
*  参数说明：uint8 load_type  道路类型
*  函数返回：无
*  修改时间：2016-4-21    
*  备    注：以内轮为目标，右内轮，向右拐弯
*************************************************************************/
//float Rightchasu(int16 num)  //num<0 ,从-0-- -220
//{
//    float K_right;
//    int16 i;
//    i=num;
//    
//  float  a0 =      0.7642;
//  float  a1 =     0.07438;
//  float  b1 =     -0.1496;
//  float  a2 =     0.05218;
//  float  b2 =    -0.02744;
//  float  a3 =     0.01709;
//  float  b3 =   0.0003328;
//  float  w =     0.02249 ;
//
//
//    K_right=  a0 + a1*cos(i*w) + b1*sin(i*w) + a2*cos(2*i*w) + b2*sin(2*i*w) + a3*cos(3*i*w) + b3*sin(3*i*w);   
//    return (K_right);
//}

/*************************************************************************
*  函数名称：Leftchasu
*  功能说明：查表法差速
*  参数说明：uint8 load_type  道路类型
*  函数返回：无
*  修改时间：2016-4-21    
*  备    注：以内轮为目标，左内轮，向左拐弯
*************************************************************************/
//float Leftchasu(int16 num)   //num>0 ,从-0--  -220
//{
//    float K_left;
//    int16 i;
//    i=num;
//   float  a0 =      0.8042 ;
//   float  a1 =      0.1922 ;
//   float  b1 =    -0.06874 ;
//   float  a2 =     -0.0488 ;
//   float  b2 =   0.0005826 ;
//   float  a3 =     0.01633 ;
//   float  b3 =     0.01035 ;
//   float  w =     0.01327  ;
//
//    
//    K_left=  a0 + a1*cos(i*w) + b1*sin(i*w) + a2*cos(2*i*w) + b2*sin(2*i*w) + a3*cos(3*i*w) + b3*sin(3*i*w);   
//    return (K_left);
//}

