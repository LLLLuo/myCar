#ifndef __MYSTEER_H__
#define __MYSTEER_H__


#define S3010_FTM   FTM2 //FTMģ��
#define S3010_CH    FTM_CH1 //ͨ��
#define S3010_HZ    50
void SteerInit();
void CalculateCurrentError();
void DirectionDecision();
void DirectionControl();

#endif
