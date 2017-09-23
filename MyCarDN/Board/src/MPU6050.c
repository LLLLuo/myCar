/*!
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2013,ɽ��Ƽ�
 *     All rights reserved.
 *     �������ۣ�ɽ����̳ http://www.vcan123.com
 *
 *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
 *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
 *
 * @file       MK60_i2c.c
 * @brief      i2c��������
 * @author     ɽ��Ƽ�
 * @version    v5.0
 * @date       2013-07-12
 */

#include "varInit.h"
#include "MPU6050.h"

//��ʱ����
void tly_delay(uint16 k)		 
{
    uint8 i;	 

    while(--k)
    {
        for(i=0;i<200;i++); //��ʱʱ�䳤�̣�0--255��ѡ
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
//�ֽڷ��ͳ���
//����c(����������Ҳ���ǵ�ַ)���������մ�Ӧ��
//�����Ǵ�Ӧ��λ
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
		  SDA1; //�жϷ���λ
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
	SDA1; //������8bit���ͷ�����׼������Ӧ��λ
	nops();
	SCL1;
	nops_1us();	
	nops();//sda�����ݼ��Ǵ�Ӧ��λ              
	SCL0; //�����Ǵ�Ӧ��λ|��Ҫ���ƺ�ʱ��
}
//**************************************************
//�ֽڽ��ճ���
//�����������������ݣ��˳���Ӧ���|��Ӧ����|IIC_ack_main()ʹ��
//return: uchar��1�ֽ�
//SCL�͵�ƽ������С4.7us���ߵ�ƽ����ʱ����С4us
uint8 read_byte(void)
{
    uint8 i;
    uint8 c;
	c=0;
	SCL0;
        nops_1us();
	nops();
	SDA1; //��������Ϊ���뷽ʽ
	nops();
	DIR0;
	for(i=0;i<8;i++)
	{
		nops();
		SCL0; //��ʱ����Ϊ�ͣ�׼����������λ
                nops_1us();
		nops();//���ݽ���ʱ����С250ns
		SCL1; //��ʱ����Ϊ�ߣ�ʹ��������������Ч
		nops();//���ݱ���ʱ�����3.45us
		c<<=1;
		if(SDAIN)
		  c+=1; //������λ�������յ����ݴ�c
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
//��ֹͣλ SDA=0->1
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

//��ȡL3G4200��1���ֽ�
uint8 MPU6050_readbyte(uint8 address)
{
	uint8 ret;
	IIC_start();		//����
	send_byte(SlaveAddress);	//д���豸ID��д�ź�
	send_byte(address);	//X��ַ
	IIC_start();		//���·��Ϳ�ʼ
	send_byte(SlaveAddress+1);	//д���豸ID������
	ret = read_byte();	//��ȡһ�ֽ�
	IIC_stop();

	return ret;
}
void MPU6050_writebyte(uint8 address, uint8 thedata)
{
	IIC_start();		//����
	send_byte(SlaveAddress);	//д���豸ID��д�ź�
	send_byte(address);	//X��ַ
	send_byte(thedata);	//д���豸ID������
	IIC_stop();
}


//��ʼ��ģ��iic
void IMU_IIC_Init()
{
     gpio_init(IMU_SCL, GPO, 1); //��ʼ��SCL0
     gpio_init(IMU_SDA, GPO, 1); //��ʼ��SDA0
    
     port_init_NoALT(IMU_SCL,ODO);
     port_init_NoALT(IMU_SDA,ODO);

}

//��ʼ��MPU6050��������Ҫ��ο�pdf�����޸�************************
void MPU6050_Init()
{
   while(MPU6050_readbyte(MPU6050_WHO_AM_I)!=0x68);
   tly_delay(10);
   MPU6050_writebyte(PWR_MGMT_1, 0x00);  // 0x8B��0x9B���У�����Խ�����׳���
   tly_delay(20);
   MPU6050_writebyte(CONFIG, 0x06);   //��ͨ�˲�������5Hz
   tly_delay(10);
   MPU6050_writebyte(SMPLRT_DIV, 0x07);   //��ͨ�˲�������5Hz
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
