#ifndef __VARINIT__
#define __VARINIT__
#include "include.h"

extern struct Inductor inductor;   
extern struct Flag flag;
extern struct Motor motor;
extern struct Bsp_status bsp;
extern struct Steer steer;

//extern struct Parameter parameter;

//void MyMain_ParametersInit(void);
void MyBspDataInit(void);
void MySteerDataInit(void);
void MyInductorDataInit(void) ;
void MyMotorSpeedDataInit(void);
void MyFlagDataInit(void);
#endif
