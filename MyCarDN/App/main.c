/*!
*     COPYRIGHT NOTICE
*     Copyright (c) 2013,山外科技
*     All rights reserved.
*     技术讨论：山外论坛 http://www.vcan123.com
*
*     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
*     修改内容时必须保留山外科技的版权声明。
*
* @file       main.c
* @brief      山外K60 平台主程序
* @author     山外科技
* @version    v5.3
* @date       2015-04-07
*/
#include "include.h"

void main()
{   
    DisableInterrupts;  
    /*参数初始化*/
    MyMotorSpeedDataInit();
    MySteerDataInit();
    MyInductorDataInit();  
    MyBspDataInit();   
    MyFlagDataInit();
   /*模块初始化*/
    myBsp_Init();//按键、拨码开关、蜂鸣器初始化
    myGear_Get(); //获取拨码开关状态
    myBeep_Set();//蜂鸣器
    SteerInit();//舵机初始化
    myMotor_Init();//电机初始化
    InductorInit();//ADC初始化

    LCD_Init();//液晶
    
    
    pit_init_ms(PIT0,1);//1MS中断
    set_vector_handler(PIT0_VECTORn ,PIT0_IRQHandler);
    EnableInterrupts;
    enable_irq (PIT0_IRQn);
    
    while(1){
    OledDisplay();  
    myMotor_Setspeed(200,100);

//    ftm_pwm_duty(S3010_FTM,S3010_CH,steer.SteerLeftMax);
//    DELAY_MS(1000);
//     ftm_pwm_duty(S3010_FTM,S3010_CH,steer.SteerRightMax); 
//      DELAY_MS(1000);

         
    }
    

}




