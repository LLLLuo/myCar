/*!
*     COPYRIGHT NOTICE
*     Copyright (c) 2013,ɽ��Ƽ�
*     All rights reserved.
*     �������ۣ�ɽ����̳ http://www.vcan123.com
*
*     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
*     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
*
* @file       main.c
* @brief      ɽ��K60 ƽ̨������
* @author     ɽ��Ƽ�
* @version    v5.3
* @date       2015-04-07
*/
#include "include.h"

void main()
{   
    DisableInterrupts;  
    /*������ʼ��*/
    MyMotorSpeedDataInit();
    MySteerDataInit();
    MyInductorDataInit();  
    MyBspDataInit();   
    MyFlagDataInit();
   /*ģ���ʼ��*/
    myBsp_Init();//���������뿪�ء���������ʼ��
    myGear_Get(); //��ȡ���뿪��״̬
    myBeep_Set();//������
    SteerInit();//�����ʼ��
    myMotor_Init();//�����ʼ��
    InductorInit();//ADC��ʼ��

    LCD_Init();//Һ��
    
    
    pit_init_ms(PIT0,1);//1MS�ж�
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




