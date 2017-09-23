#ifndef __MYSTEER_H__
#define __MYSTEER_H__


#define S3010_FTM   FTM2 //FTMÄ£¿é
#define S3010_CH    FTM_CH1 //Í¨µÀ
#define S3010_HZ    50
void SteerInit();
void CalculateCurrentError();
void DirectionDecision();
void DirectionControl();

#endif
