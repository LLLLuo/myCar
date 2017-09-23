/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,山外科技
 *     All rights reserved.
 *     技术讨论：山外论坛 http://www.vcan123.com
 *
 *     除注明出处外，以下所有内容版权均属山外科技所有，未经允许，不得用于商业用途，
 *     修改内容时必须保留山外科技的版权声明。
 *
 * @file       MK60_i2c.c
 * @brief      i2c驱动函数
 * @author     山外科技
 * @version    v5.0
 * @date       2013-07-12
 */

#include "varInit.h"
#include "MPU6050.h"

//延时函数
void tly_delay(uint16 k)		 
{
    uint8 i;	 

    while(--k)
    {
        for(i=0;i<200;i++); //延时时间长短，0--255可选
    }
}


void nops()		 
{
    uint8 k=50;	 
    while(--k);
}

void nops_1us()		 
{
    uint8 k=10;	 
    while(--k);
}

//*************************************************
//字节发送程序
//发送c(可以是数据也可是地址)，送完后接收从应答
//不考虑从应答位
void send_byte(uint8 c)
{
	uint8 i;
	for(i=0;i<8;i++)
	{
		SCL0;
                nops_1us();
		nops();
		if((c<<i) & 0x80)
		{
		  SDA1; //判断发送位
		}
		else 
		{
		  SDA0;
		}
		nops_1us();
		SCL1;
		nops();	
		SCL0;
	}
	nops();
	SDA1; //发送完8bit，释放总线准备接收应答位
	nops();
	SCL1;
	nops_1us();	
	nops();//sda上数据即是从应答位              
	SCL0; //不考虑从应答位|但要控制好时序
}
//**************************************************
//字节接收程序
//接收器件传来的数据，此程序应配合|主应答函数|IIC_ack_main()使用
//return: uchar型1字节
//SCL低电平持续最小4.7us，高电平持续时间最小4us
uint8 read_byte(void)
{
    uint8 i;
    uint8 c;
	c=0;
	SCL0;
        nops_1us();
	nops();
	SDA1; //置数据线为输入方式
	nops();
	DIR0;
	for(i=0;i<8;i++)
	{
		nops();
		SCL0; //置时钟线为低，准备接收数据位
                nops_1us();
		nops();//数据建立时间最小250ns
		SCL1; //置时钟线为高，使数据线上数据有效
		nops();//数据保存时间最大3.45us
		c<<=1;
		if(SDAIN)
		  c+=1; //读数据位，将接收的数据存c
	}
	SCL0;
        nops_1us();
	nops();
	DIR1;
	return c;
}

void IIC_start(void)
{
	SCL0;	
	DELAY_US(1);
	SDA1;
	DELAY_US(1);
	SCL1;
	nops();
	SDA0;
        nops();
	SCL0;
}
//************************************************
//送停止位 SDA=0->1
void IIC_stop(void)
{
	SCL0;
	DELAY_US(1);
	SDA0;
	DELAY_US(1);
	SCL1;
        nops();
	SDA1;
        nops();
	SCL0;
}

//读取L3G4200的1个字节
uint8 MPU6050_readbyte(uint8 address)
{
	uint8 ret;
	IIC_start();		//启动
	send_byte(SlaveAddress);	//写入设备ID及写信号
	send_byte(address);	//X地址
	IIC_start();		//重新发送开始
	send_byte(SlaveAddress+1);	//写入设备ID及读信
	ret = read_byte();	//读取一字节
	IIC_stop();

	return ret;
}
void MPU6050_writebyte(uint8 address, uint8 thedata)
{
	IIC_start();		//启动
	send_byte(SlaveAddress);	//写入设备ID及写信号
	send_byte(address);	//X地址
	send_byte(thedata);	//写入设备ID及读信
	IIC_stop();
}


//初始化模拟iic
void IMU_IIC_Init()
{
     gpio_init(IMU_SCL, GPO, 1); //初始化SCL0
     gpio_init(IMU_SDA, GPO, 1); //初始化SDA0
    
     port_init_NoALT(IMU_SCL,ODO);
     port_init_NoALT(IMU_SDA,ODO);

}

//初始化MPU6050，根据需要请参考pdf进行修改************************
void MPU6050_Init()
{
   while(MPU6050_readbyte(MPU6050_WHO_AM_I)!=0x68);
   tly_delay(10);
   MPU6050_writebyte(PWR_MGMT_1, 0x00);  // 0x8B和0x9B还行，传输越快容易出错
   tly_delay(20);
   MPU6050_writebyte(CONFIG, 0x06);   //低通滤波器带宽5Hz
   tly_delay(10);
   MPU6050_writebyte(SMPLRT_DIV, 0x07);   //低通滤波器带宽5Hz
   tly_delay(10);
   MPU6050_writebyte(GYRO_CONFIG, 0x018);  //+-2000dps
   tly_delay(10);
   MPU6050_writebyte(ACCEL_CONFIG, 0x01);
   tly_delay(10);
}

int16 MPU6050_GetResult(uint8 Regs_Addr) 
{
  int16 result,temp;
  
  if(Regs_Addr>GYRO_ZOUT_L)
    return 0;
  
  result= MPU6050_readbyte( Regs_Addr);
  temp  = MPU6050_readbyte( Regs_Addr+1);
  result=result<<8;
  result=result|temp;
  
  return result;//
}
