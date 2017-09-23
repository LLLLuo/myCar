
/*!
 * 
 * ���������뿪�أ��ɻɹܳ���
 *
 */
   
#include "include.h"


void myBsp_Init(void)
{ 
  
  gpio_init(PTE10,GPO,HIGH); //LED
 // gpio_init(PTE12,GPO,HIGH);


  //����
  port_init(PTC3, ALT1 | IRQ_FALLING | PULLUP );       //��ʼ�� PTD7 �ܽţ����ù���ΪGPIO ���½��ش����жϣ���������
  port_init(PTC4, ALT1 | IRQ_FALLING | PULLUP );       //��ʼ�� PTD7 �ܽţ����ù���ΪGPIO ���½��ش����жϣ���������
  port_init(PTC5, ALT1 | IRQ_FALLING | PULLUP );       //��ʼ�� PTD7 �ܽţ����ù���ΪGPIO ���½��ش����жϣ���������
  port_init(PTC7, ALT1 | IRQ_FALLING | PULLUP );       //��ʼ�� PTD7 �ܽţ����ù���ΪGPIO ���½��ش����жϣ���������
    
  adc_init(ADC1_SE13); //��ѹ B11
  
      gpio_init (PTB18, GPI,0);
      gpio_init (PTB19, GPI,0);
      gpio_init (PTB20, GPI,0);
      gpio_init (PTB21, GPI,0);        
      gpio_init (PTB22, GPI,0);
      gpio_init (PTB23, GPI,0);

      port_init_NoALT (PTB18,  PULLUP );     
      port_init_NoALT (PTB19,  PULLUP );      //�ڲ�����
      port_init_NoALT (PTB20,  PULLUP );     
      port_init_NoALT (PTB21,  PULLUP );     
      port_init_NoALT (PTB22,  PULLUP );     
      port_init_NoALT (PTB23,  PULLUP );      //�ڲ�����



 

  
   
//  gpio_init(PTA12,GPI,1); //���ܺ���
//  gpio_init(PTA10,GPI,1);
//  gpio_init(PTA8,GPI,1);
//  gpio_init(PTA6,GPI,1);
//  port_init_NoALT (PTA12, PULLDOWN); //����
//   port_init_NoALT (PTA10, PULLDOWN); //����
//    port_init_NoALT (PTA8, PULLDOWN); //����
//     port_init_NoALT (PTA6, PULLDOWN); //����
  
  //������
  gpio_init(PTA5,GPO,LOW);
  
  //�����ж�
//  port_init(PTB20, ALT1 | IRQ_FALLING | PULLUP );   //��ʼ�� PTC1 �ܽţ����ù���ΪGPIO ���½��ش����жϣ���������
//  set_vector_handler(PORTB_VECTORn,PORTB_IRQHandler);   // �����жϸ�λ�������ж��������� 
//  port_init(PTB3, ALT1 | IRQ_FALLING | PULLUP );   
//  set_vector_handler(PORTB_VECTORn,PORTB_IRQHandler2); 
// port_init(PTB4, ALT1 | IRQ_FALLING | PULLUP );   
// set_vector_handler(PORTB_VECTORn,PORTB_IRQHandler3); 
// port_init(PTB5, ALT1 | IRQ_FALLING | PULLUP );    
// set_vector_handler(PORTB_VECTORn,PORTB_IRQHandler4); 
//  gpio_init(PTB22,GPI,0);
//  gpio_init(PTC0,GPI,0);
//  gpio_init(PTC2,GPI,0);
// 
}
/********************��λ����*************************/

void myGear_Get(void)
{
  if(PTB18_IN==1) //���뿪��1
  {  bsp.Gear1=0;} 
  else 
  { bsp.Gear1=1;} 
  
  if(PTB19_IN==1) //���뿪��2
  { bsp.Gear2=0;}
  
  else 
  {  bsp.Gear2=1;}
 
  if(PTB20_IN == 1 )//���뿪��3
  {   bsp.Gear3 = 0;}
  else 
  {  bsp.Gear3 = 1;}
 
  if(PTB21_IN == 1 )//���뿪��4
  {  bsp.Gear4 = 0;}
  else 
  { bsp.Gear4 = 1; } 
 
  if(PTB22_IN == 1 )//���뿪��5
  {   bsp.Gear5 = 0;}
  else 
  {  bsp.Gear5 = 1; }
  
  if(PTB23_IN == 1 )//���뿪��6
  { bsp.Gear6 = 0;}
  else 
  {  bsp.Gear6 = 1; }
  
  
//  if(Bsp.gear1==1)  //1��
//  {
//      UFF=UFF1;
//  }
//  else if(Bsp.gear2==1)  //1��
//  {
//      UFF=UFF2;
//  }
//   else if(Bsp.gear3==1)  //1��
//  {
//      UFF=UFF3;
//  }
  
}



void OledDisplay()
{          
// if(page==1)
// {

  LED_PrintValueF(0, 0,inductor.CurrentHorLeft,1);  //�ô���ʾ����Ҫ�ص�FPU�������ܷ�
  LED_PrintValueF(45, 0,inductor.CurrentHorMid,1);  
  LED_PrintValueF(90, 0,inductor.CurrentHorRight, 1);
  LED_PrintValueF(0, 2,motor.RealSpeedLeft, 1);
  LED_PrintValueF(45,2,motor.RealSpeedRight, 1);
  LED_PrintValueF(90, 2,flag.Vt,1);  //�ô���ʾ����Ҫ�ص�FPU�������ܷ�
//  LED_PrintValueF(45, 1,flag.CircleFlag,1);  
//  LED_PrintValueF(90, 1,flag.CircleFlag, 1);
//  LED_PrintValueF(0, 3,steer.DirectionPianCha[0], 1);
//  LED_PrintValueF(45, 3,steer.SteeringZkb, 1);
//  LED_PrintValueF(90, 3,flag.Vt, 1);
  
//  LCD_P6x8Str(0,2,"Err:");
//  LED_PrintValueF(25, 2, steer.CurrentError,1);
//  LCD_P6x8Str(78,2,"Y:");
//  LED_PrintValueF(95, 2, flag.CircleNum,1);//Ramp_flag circle_level 
//  LCD_P6x8Str(0,3,"OT:");  
//  LED_PrintValueF(20, 3,overtake_mode,1);
//  LED_PrintValueF(75, 3,zhidao_OT,1);
//  LCD_P6x8Str(0,4,"BMQ:");
//  LED_PrintValueF(25,4,realSpeed, 1);
//  LCD_P6x8Str(65,4,"Dis:");
//   LED_PrintValueF(90, 4,ABDistance,1);
//  LCD_P6x8Str(0,5,"Power:");
//  LED_PrintValueF(35,5,dianya, 2);
//   LCD_P6x8Str(70,5,"host:");  
//  LED_PrintValueF(100, 5,host_flag,1); 
//  LCD_P6x8Str(0,6,"Steer:");
//  LED_PrintValueF(40,6,P_level, 1);
//  LED_PrintValueF(80,6,Steer_P, 1);
//  LCD_P6x8Str(0,7,"Speed:");
//  LED_PrintValueF(40,7,sp_level, 1);
//  LED_PrintValueF(80,7,TargetSpeed, 1);
 //}
//else if(page==2)
//{
 
// LCD_P6x8Str(0,0,"zhi:");
// LED_PrintValueF(30,0,Straight_flag, 1);
//  LCD_P6x8Str(0,1,"ru:");
// LED_PrintValueF(30,1,ruwan_flag, 1);
//  LCD_P6x8Str(0,2,"wan:");
// LED_PrintValueF(30,2,wandao_flag, 1);
// 
//  LED_PrintValueF(0,3,circle_ready_rx, 1);
// LED_PrintValueF(0,4,back_car_dir_rx, 1);
// LED_PrintValueF(0,5,takeoff_over_rx, 1);
// LED_PrintValueF(0,6,rxbuf[4], 1);
//}
//   if(KEY2==0)
//   { 
//     LCD_Fill(0x00);
//    page++;
//    if(page>2)
//      page=1;
//    DELAY_MS(200);
//   }



}







float var[8];
void SendData()
{
        var[0] =inductor.CurrentHorLeft;
        var[1] =inductor.CurrentHorMid;
        var[2] =inductor.CurrentHorRight;
        var[3] =inductor.CurrentVerLeft;
        var[4] =inductor.CurrentVerMid;//DoubleError*100;circle_flag_count ABDistance_set
        var[5] =inductor.CurrentVerRight;//ABD_err realSpeed host_flag
        var[6] = flag.CircleFlag*100;//Steer_P*10 TargetSpeed circle_flag
         var[7] = steer.CurrentError*10;//direction_offset  Motor_Duty ABDistance dir_change

      vcan_sendware(var, sizeof(var));
}







void myBeep_Set(void)
{
  //�µ�����
//#if 1
 // if(flag.RampFlag==1)
    // beep=1;��
  //else
    // beep=0;
//#endif
  
  //�������ƾ���
//#if 0
//  
//  if(speed.BBcontrol==1)
//    beep=1;
//  else if(speed.BBcontrol==2)
//    beep=0;
//  else
//    beep=0;
//  
//#endif
  
  //�ϰ�����
//#if 0
//  
//  if(ccd1.BarrierNum==1)
//    beep=1;
//  else
//    beep=0;
//  
//#endif  

//#if 0
//  if(flag.CircleFlag==1)
//    beep=1;
//  else
//    beep=0;
//#endif
  
  

}
/******************��������*****************************/

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY1����
//2��KEY2����
//3��KEY3���� 
//4��KEY4����
//ע��˺�������Ӧ���ȼ�,KEY1>KEY2>KEY3>KEY4!!
uint8 myKEY_Scan(uint8 mode)
{	 
	static uint8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		DELAY_MS(10);//ȥ���� 
		key_up=0;
		if(KEY1==0)return 1;
		else if(KEY2==0)return 2;
		else if(KEY3==0)return 3;
		else if(KEY4==0)return 4;
	}
        else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==0)
          key_up=1; 	    
 	return 0;// �ް�������
}





//uint16 stop_time=0;
//uint8 stop_time1;
//uint8 stop_time2;
//uint8 stop_maybe;
void Stop_find()
{
  
  // if((PTA12_IN==1 || PTA10_IN==1 ) && ( PTA8_IN==1 || PTA6_IN==1 ) && ccd1.Rampflag==0 && ccd1.BarrierNum==0) 
   //  {   
         //speed.start_flag=1;
   //  }
   
   
    //if((PTA12_IN==0 || PTA10_IN==0)&&(PTA8_IN==1 ||PTA6_IN==1))
//    
//    if((PTA12_IN==0 && PTA10_IN==0) && ccd1.Rampflag==0 && stop_maybe==0) //����ͬʱ��⵽����   
//    {
//       if(PTA8_IN==1) //
//       {
//          stop_time1=0;
//          stop_maybe=1;
//       }
//       else if(PTA6_IN==1)
//       {
//          stop_time2=0;
//          stop_maybe=2;
//       }
//     }  
//    if(stop_maybe==1 && (PTA12_IN==0 && PTA10_IN==0) )
//    {
//      stop_time1++;
//      if(stop_time1>10)
//      {
//        stop_maybe=0;
//        stop_time1=10;
//        speed.start_flag=0;
//      }
//      if( PTA6_IN==1 && stop_time1<2 )
//             speed.start_flag=1; 
//    }
//    else if(stop_maybe==2 && (PTA12_IN==0 && PTA10_IN==0) )
//    {
//       stop_time2++;
//      if(stop_time2>10)
//      {
//        speed.start_flag=0;
//        stop_time2=10;
//        stop_maybe=0;
//      }
//      if( PTA8_IN==1 && stop_time2<2 )
//        speed.start_flag=1; 
//    }

}
