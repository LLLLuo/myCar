#include "include.h"

/*************************************************************************
*  函数名称：InductorInit()
*  功能说明：Inductor初始化
*  参数说明：
*  函数返回：无
*  修改时间：2018-08-28
*  备    注：
*************************************************************************/
void InductorInit(void)
{ 
//            adc_init (ADC1_SE10 );//B4
//            adc_init (ADC1_SE11 );//B5
//            adc_init (ADC1_SE12 );//B6
//            adc_init (ADC1_SE13 );//B7
//            adc_init (ADC1_SE14 );//B10  
//            adc_init (ADC1_SE15);//B11
            adc_init (ADC1_SE17);//电压

}

/*************************************************************************
*  函数名称：InductorAdData()
*  功能说明：InductorAdData初始化
*  参数说明：
*  函数返回：无
*  修改时间：2018-08-28
*  备    注：
*************************************************************************/
void InductorAdData()
{   //uint8 count;
//    for(count=5; count>=1; count--)
//    {
//         inductor.HorLeft[count]=inductor.HorLeft[count-1];
//         inductor.HorMid[count]=inductor.HorMid[count-1];
//         inductor.HorRight[count]=inductor.HorRight[count-1];
//         inductor.VerLeft[count]=inductor.VerLeft[count-1];
//         inductor.VerMid[count]=inductor.VerMid[count-1];
//         inductor.VerRight[count]=inductor.VerRight[count-1];
//    }
//    
//    inductor.HorLeft[0]=ad_ave(ADC1_SE10, ADC_8bit,15);//水平左
//    inductor.HorMid[0]=ad_ave(ADC1_SE11, ADC_8bit,15);//水平中
//    inductor.HorRight[0]=ad_ave(ADC1_SE13, ADC_8bit,15);//水平右
//
//  
//    inductor.VerLeft[0]=ad_ave(ADC1_SE12, ADC_8bit,15);//垂直左 
//    inductor.VerMid[0]=ad_ave(ADC1_SE14, ADC_8bit,15);//垂直中间
//    inductor.VerRight[0]=ad_ave(ADC1_SE15, ADC_8bit,15);//垂直右
//    
//    inductor.CircleHorMid=45;//圆环偏差基准电感值
//      
//    inductor.HorLeft[0]=inductor.HorLeft[0]*0.7+inductor.HorLeft[1]*0.2+inductor.HorLeft[2]*0.1;
//    inductor.HorMid[0]=inductor.HorMid[0]*0.7+inductor.HorMid[1]*0.2+inductor.HorMid[2]*0.1;
//    inductor.HorRight[0]=inductor.HorRight[0]*0.7+inductor.HorRight[1]*0.2+inductor.HorRight[2]*0.1;
//    inductor.VerLeft[0]=inductor.VerLeft[0]*0.7+inductor.VerLeft[1]*0.2+inductor.VerLeft[2]*0.1;
//    inductor.VerMid[0]=inductor.VerMid[0]*0.7+inductor.VerMid[1]*0.2+inductor.VerMid[2]*0.1;
//    inductor.VerRight[0]=inductor.VerRight[0]*0.7+inductor.VerRight[1]*0.2+inductor.VerRight[2]*0.1;
//     
// 
//
//    //电感采回值最大最小限幅
//    if(inductor.HorLeft[0]<10) inductor.HorLeft[0]=10;
//    if(inductor.HorLeft[0]>100) inductor.HorLeft[0]=100;
//    
//    if(inductor.HorMid[0]<10) inductor.HorMid[0]=10;
//    if(inductor.HorMid[0]>100) inductor.HorMid[0]=100;
//    
//    if(inductor.HorRight[0]<10) inductor.HorRight[0]=10;
//    if(inductor.HorRight[0]>100) inductor.HorRight[0]=100;
//    
//    if(inductor.VerLeft[0]<10) inductor.VerLeft[0]=10;
//    if(inductor.VerLeft[0]>100) inductor.VerLeft[0]=100;
//    
//    if(inductor.VerMid[0]<10) inductor.VerMid[0]=10;
//    if(inductor.VerMid[0]>100) inductor.VerMid[0]=100;
//    
//    if(inductor.VerRight[0]<10) inductor.VerRight[0]=10;
//    if(inductor.VerRight[0]>100) inductor.VerRight[0]=100;
//    
//    inductor.CurrentHorLeft=inductor.HorLeft[0];
//    inductor.CurrentHorMid=inductor.HorMid[0];
//    inductor.CurrentHorRight=inductor.HorRight[0];
//    inductor.CurrentVerLeft=inductor.VerLeft[0];
//    inductor.CurrentVerMid=inductor.VerMid[0];
//    inductor.CurrentVerRight=inductor.VerRight[0];
    
    
    flag.Vt=ad_ave(ADC1_SE17,ADC_8bit,10)*0.4031749;
    
    
}


/*************************************************************************
*  函数名称：CircleCheck(struct Flag *flag)
*  功能说明：圆环检测条件和清除圆环条件
*  参数说明：
*  函数返回：无
*  修改时间：2018-08-28
*  备    注：圆环识别
*************************************************************************/
void CircleCheck()    //left 27  28 22  25 12 22    right 18  27  28  14 10 28  
{     //圆环判断条件//&&flag.RampFlag==0&&flag.RampStart==0
  if((inductor.HorLeft[0]<inductor.HorLeft[2])&&(inductor.HorMid[0]<inductor.HorMid[2])&&(inductor.HorRight[0]<inductor.HorRight[2]))
  {      
      if((inductor.VerLeft[0]>inductor.VerLeft[2])&&(inductor.VerRight[0]>inductor.VerRight[2]))
      {  flag.CircleFlag=1;
         if(inductor.CurrentHorLeft<=70&&inductor.CurrentHorMid<=60&&inductor.CurrentHorRight<=70)
         {  
          if(inductor.CurrentHorLeft>=40&&inductor.CurrentHorRight>=40)
          {
               if(inductor.CurrentVerLeft<=35&&inductor.CurrentVerMid<=16&&inductor.CurrentVerRight<=20)
               {
                    if(flag.CircleFlag==0)
                    {
                        
                        flag.CircleNum++;
                    }
               }
          }
          }
  
      }
  }
     //清除圆环标志条件
 if((inductor.CurrentHorMid>=80||inductor.CurrentVerMid>=35)&&flag.CircleFlag==1)
     {
         flag.CircleFlag=0;
         flag.CircleFlagCount=0;
         flag.CircleLeft=0;
         flag.CircleRight=0;
         flag.CircleDir[0]=0;
         flag.CircleDir[1]=0;
     
     }


}

  
  
  
        
       
     
     

     



/*************************************************************************
*  函数名称：RampCheck(Flag *flag)
*  功能说明：坡道识别和坡道解除条件
*  参数说明：
*  函数返回：无
*  修改时间：2018-08-28
*  备    注：坡道
*************************************************************************/
void RampCheck()
{   //入坡道计数，用于判断坡道
    if((inductor.CurrentHorMid>=150||inductor.CurrentHorLeft>=120||inductor.CurrentHorRight>=120)&&inductor.CurrentVerMid<=15&&flag.RampFlag==0&&flag.CircleFlag==0&&flag.StraightFlag==1)
    {
         flag.RampCount++;
    }
    else
    {
         flag.RampCount=0;    
    }
    
    //坡道判断
    if(flag.RampCount>=3&&flag.RampFlag==0&&flag.InRampCount==0)
    {
         flag.RampFlag=1;
         flag.RampStart=1;
         flag.RampCount=0;
    }
    

    //坡道计数，防止下坡道判圆环
    //清除坡道标志
    if(flag.RampStart==1)
    {
         flag.InRampCount++;
    }
    if(flag.InRampCount>=230)
    {
         flag.RampFlag=0;
    }
    if(flag.InRampCount>=400)
    {
         flag.InRampCount=0;
         flag.RampStart=0;
    }
    


}

/*************************************************************************
*  函数名称：StrightCheck(Flag *flag)
*  功能说明：直道识别
*  参数说明：
*  函数返回：无
*  修改时间：2018-08-28
*  备    注：
*************************************************************************/
void StraightCheck(Flag *flag)
{  //直道计数
   if(inductor.CurrentHorMid>=80&&flag->RampFlag==0&&flag->CircleFlag==0)
   {
        flag->StraightCount++;
        if(flag->StraightCount>30)
        flag->StraightCount=30;
   }
   else//取消直道标志
   {
        flag->StraightCount=0;
        flag->StraightFlag=0;
   }
   //直道判断
   if(flag->StraightCount>=8&&flag->StraightFlag==0)
    flag->StraightFlag=1;
}







/*************************************************************************                        
*  函数名称：SendHex
*  功能说明：采集发数程序
*  参数说明：
*  函数返回：无
*  修改时间：2012-10-20
*  备    注：
*************************************************************************/
/*
void SendHex(uint8 hex) {
  uint8_t temp;
  temp = hex >> 4;
  if(temp < 10) {
    uart_putchar(UART0,temp + '0');
  } else {
    uart_putchar(UART0,temp - 10 + 'A');
  }
  temp = hex & 0x0F;
  if(temp < 10) {
    uart_putchar(UART0,temp + '0');
  } else {
   uart_putchar(UART0,temp - 10 + 'A');
  }
}*/

/*************************************************************************
*  函数名称：SendImageData
*  功能说明：
*  参数说明：
*  函数返回：无
*  修改时间：2012-10-20
*  备    注：
*************************************************************************/
/*
void SendImageData(uint8 NO) {

    uint8 i;
    uint8 crc = 0;
  //  Send Data 
    uart_putchar(UART0,'*');
    uart_putchar(UART0,'L');
    uart_putchar(UART0,'D');

    SendHex(0);
    SendHex(0);
    SendHex(0);
    SendHex(0);
      if(NO==1)
      {
       for(i=0; i<128; i++) 
       {
       SendHex(ccd1.Pixel[i]);//car.angle
       }
      }
      if(NO==2)
      {
       for(i=0; i<128; i++) 
       {
       SendHex(ccd2.Pixel[i]);//car.angle
       } 
      }
    SendHex(crc);
    uart_putchar(UART0,'#');
}
*/
/*************************************************************************
*  函数名称：SamplingDelay
*  功能说明：CCD延时程序 200ns
*  参数说明：
*  函数返回：无
*  修改时间：2012-10-20
*  备    注：
*************************************************************************/
/*
void SamplingDelay(void){
   vuint8 i ;
   for(i=0;i<1;i++)
   {
    asm("nop");
    asm("nop");
   }
}*/
