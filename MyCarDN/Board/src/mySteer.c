#include "include.h"


/*************************************************************************
*  �������ƣ�SteerInit
*  ����˵���������ʼ��
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-08-28
*  ��    ע��
*************************************************************************/
void SteerInit()
{
  ftm_pwm_init(S3010_FTM, S3010_CH,S3010_HZ,steer.SteerMid);  
}

/*************************************************************************
*  �������ƣ�CalculateCurrentError
*  ����˵����ƫ�����
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-08-28
*  ��    ע������ƫ����ת
*************************************************************************/
void CalculateCurrentError()
{
//     if(flag.CircleFlag==0)//���
//     {
//         steer.DirectionPianCha[0]=10.0*inductor.CurrentHorMid/100-10;//ƫ�� -9 ~0
//     }
//     if (flag.StraightFlag==1)//ֱ��
//     {
//          steer.DirectionPianCha[0]= 0.7*(10.0*inductor.CurrentHorMid/100-10);
//      }
//     if(flag.RampFlag==1)//�µ�
//     {
//          steer.DirectionPianCha[0]= 0.3*(10.0*inductor.CurrentHorMid/100-10);
//     }
//     if(flag.CircleFlag==1)//Բ��
//     {
//         //  if(inductor.CurrentHorMid>45)    //Բ���ڸı��׼ֵ
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
*  �������ƣ�DirectionDecision
*  ����˵��������ѡ��
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-08-28
*  ��    ע������ƫ����ת
*************************************************************************/
void DirectionDecision()
{   
   //ƫ��Ϊ������ת(Ĭ��)��ֻҪ������ת
  //  if(flag.CircleFlag==0) ///��Բ���ڵķ������
   // {
       if(ABS(steer.DirectionPianCha[1]>=7))
       {
            if(steer.DirectionPianCha[1]>0)
            {
             steer.DirectionPianCha[0]=ABS(steer.DirectionPianCha[0]);
             flag.DirFlag=2;//��
            }
       }
       
       else if(inductor.CurrentHorRight>inductor.CurrentHorLeft)
       {
             steer.DirectionPianCha[0]=ABS(steer.DirectionPianCha[0]);
             flag.DirFlag=2;//��
       }
       else if((inductor.CurrentHorRight==inductor.CurrentHorLeft)&&(flag.DirFlag==2))//�����ֱ��
       {

             steer.DirectionPianCha[0]=ABS(steer.DirectionPianCha[0]);
             flag.DirFlag=0;//ֱ����������־
       }         
    //}
    
    
    
//    else if(flag.CircleFlag==1)//Բ���ڵķ������
//    {
//         if(flag.CircleLeft==0&&flag.CircleRight==0&&flag.CircleDir[0]==0&&flag.CircleDir[1]==0)//�뻷��������뻷ǰƫ��ѡ��
//         {   //�жϳ�����̬
//             if(steer->DirectionPianCha[1]>0)//�뻷ǰ����ƫ����ת״̬���ҽ�Բ��
//             {
//                 flag.CircleRight=1;
//                 flag.CircleDir[0]=2;//��
//                 steer->CurrentError=ABS(steer->CurrentError);
//                 
//             }  
//             else//�뻷ǰ����ƫ����ת״̬�����Բ��
//             {
//                 flag.CircleLeft=1;
//                 flag.CircleDir[0]=1;//��
//                 steer->CurrentError=-ABS(steer->CurrentError);    
//             }
//         }
//               
//               
//          if(flag.CircleDir[0]!=flag.CircleDir[1])//�ı��˷���,ƫ��Ҳ����
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
*  �������ƣ�DirectionControl()
*  ����˵�����������
*  ����˵����
*  �������أ���
*  �޸�ʱ�䣺2017-08-28
*  ��    ע��
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
  
      //�������޷�
      if(steer.SteeringZkb>steer.SteerRightMax)
       steer.SteeringZkb=steer.SteerRightMax;        
      else if(steer.SteeringZkb<steer.SteerLeftMax)
       steer.SteeringZkb=steer.SteerLeftMax;
      
      
      ftm_pwm_duty(S3010_FTM,S3010_CH,steer.SteeringZkb); 
}




      
