/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_it.c
 * @brief      ɽ��K60 ƽ̨�жϷ�����
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-06-26
 */

#include    "MK60_it.h"
#include    "include.h"

uint16 TimeCount = 0 ; //��ʱ
uint32 Timestart;//������ʱ
//��ʱ���ж�
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
     CalculateCurrentError();//ƫ�����
     //DirectionDecision();//����ѡ��
    }
     else if(TimeCount == 5 ){
     // DirectionControl();//�������
    }
     else if(TimeCount == 6 ){ 
           myMotor_GetEncoder();
      //myMotor_GetEncoder();//��ȡ�ٶ�
    }
     else if(TimeCount == 7 ){  
      if(flag.Start==1){
     // myMotor_Control(); 
      } 
       else if (flag.Stop==1){
        //myMotor_Setspeed(0);
       }//�ٶȿ���
    }
     else if(TimeCount == 8 ){
       
    }
     else if(TimeCount == 9 ){
       
    }
     
    else if(TimeCount == 10 ){
       TimeCount=0; 
 
    }          
}


//uint8 oledchange=0; //����oled�л�
//uint8 oleschangeclear=0;
//�����ж�
//void PORTB_IRQHandler(void) //����1
//{
//    uint8  n=20;      //���ź�
//    
//    if(PORTB_ISFR & (1<<n))           //PTA25����menu�ж�
//    {
//       PORTB_ISFR  |= (1<<n);          //д1���жϱ�־λ                
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


