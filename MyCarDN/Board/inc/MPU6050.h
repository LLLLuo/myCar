#ifndef __MPU6050_H_
#define __MPU6050_H_

//#include "MK60_gpio_cfg.h"


#define IMU_SDA PTD9//SDA IO
#define IMU_SCL PTD8//SCL IO

#define SMPLRT_DIV      0x19    //陀螺仪采样率，典型值：0x07(125Hz)
#define CONFIG          0x1A    //低通滤波频率，典型值：0x06(5Hz)
#define GYRO_CONFIG     0x1B    //陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
#define ACCEL_CONFIG    0x1C    //加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
#define ACCEL_XOUT_H    0x3B
#define ACCEL_XOUT_L    0x3C
#define ACCEL_YOUT_H    0x3D
#define ACCEL_YOUT_L    0x3E
#define ACCEL_ZOUT_H    0x3F
#define ACCEL_ZOUT_L    0x40
#define TEMP_OUT_H      0x41
#define TEMP_OUT_L      0x42
#define GYRO_XOUT_H     0x43
#define GYRO_XOUT_L     0x44    
#define GYRO_YOUT_H     0x45
#define GYRO_YOUT_L     0x46
#define GYRO_ZOUT_H     0x47
#define GYRO_ZOUT_L     0x48
#define PWR_MGMT_1      0x6B    //电源管理，典型值：0x00(正常启用)
#define PWR_MGMT_2      0x6C    //电源管理，典型值：0x00(正常启用)
#define MPU6050_WHO_AM_I            0x75    //IIC地址寄存器(默认数值0x68，只读)
#define SlaveAddress    0xD0    //IIC写入时的地址字节数据，+1为读取


#define SDAIN   PTXn_T(IMU_SDA,IN)
#define SDA1    PTXn_T(IMU_SDA,OUT) = 1;
#define SCL1    PTXn_T(IMU_SCL,OUT) = 1;//
#define DIR1    PTXn_T(IMU_SDA,DDR) = 1;
#define SDA0    PTXn_T(IMU_SDA,OUT) = 0;
#define SCL0    PTXn_T(IMU_SCL,OUT) = 0;
#define DIR0    PTXn_T(IMU_SDA,DDR) = 0;

void MPU6050_Init();
void IMU_IIC_Init();
int16 MPU6050_GetResult(uint8 Regs_Addr);
#endif /* _MPU6050_H_ */