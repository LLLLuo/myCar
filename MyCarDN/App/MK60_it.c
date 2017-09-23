/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_it.c
 * @brief      山外K60 平台中断服务函数
 * @author     山外科技
 * @version    v5.0
 * @date       2013-06-26
 */

#include    "MK60_it.h"
#include    "include.h"

uint16 TimeCount = 0 ; //计时
uint32 Timestart;//发车计时
//定时器中断
void PIT0_IRQHandler(void)
{
    PIT_Flag_Clear(PIT0);
    TimeCount ++ ;
    if(TimeCount == 1 )
    {

    }
    else if(TimeCount == 2 ){
     InductorAdData();   

    }
     else if(TimeCount == 3 ){
    // StraightCheck(&flag);
    // CircleCheck(&flag);
    // RampCheck(&flag);
    }
     else if(TimeCount == 4 ){
     CalculateCurrentError();//偏差计算
     //DirectionDecision();//方向选择
    }
     else if(TimeCount == 5 ){
     // DirectionControl();//方向控制
    }
     else if(TimeCount == 6 ){ 
           myMotor_GetEncoder();
      //myMotor_GetEncoder();//获取速度
    }
     else if(TimeCount == 7 ){  
      if(flag.Start==1){
     // myMotor_Control(); 
      } 
       else if (flag.Stop==1){
        //myMotor_Setspeed(0);
       }//速度控制
    }
     else if(TimeCount == 8 ){
       
    }
     else if(TimeCount == 9 ){
       
    }
     
    else if(TimeCount == 10 ){
       TimeCount=0; 
 
    }          
}


//uint8 oledchange=0; //用于oled切换
//uint8 oleschangeclear=0;
//按键中断
//void PORTB_IRQHandler(void) //按键1
//{
//    uint8  n=20;      //引脚号
//    
//    if(PORTB_ISFR & (1<<n))           //PTA25触发menu中断
//    {
//       PORTB_ISFR  |= (1<<n);          //写1清中断标志位                
//     
//    }  
//    
//    oledchange=oledchange+1;
//    if(oledchange==5)
//      oledchange=0;
//    
//    oleschangeclear=1;
//      
//}


