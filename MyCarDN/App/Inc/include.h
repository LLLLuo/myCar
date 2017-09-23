#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include  "common.h"

/*
 * Include �û��Զ����ͷ�ļ�
 */
#include  "MK60_wdog.h"
#include  "MK60_gpio.h"      //IO�ڲ���
#include  "MK60_uart.h"      //����
#include  "MK60_SysTick.h"
#include  "MK60_lptmr.h"     //�͹��Ķ�ʱ��(��ʱ)
#include  "MK60_pit.h"       //PIT
#include  "MK60_FLASH.h"     //FLASH
#include  "MK60_FTM.h"       //FTM
#include  "MK60_sdhc.h"      //SDHC
#include  "MK60_spi.h"       //SPI
#include  "MK60_adc.h"       //ADC
#include  "MK60_dma.h"       //DMA
#include  "MK60_i2c.h"       //I2C
#include  "MK60_it.h"        //isr


#include  "VCAN_LED.H"          //LED
#include  "VCAN_KEY.H"          //KEY
#include  "VCAN_NRF24L0.h"           
/*
 *  �û�ͷ�ļ�

 */

#include "myInductor.h"
#include "varInit.h"  
#include "myOled.h"
#include "myStruct.h"
#include "myMotor.h"
#include "FuzzyPid.h"
#include "mySteer.h"
#include "myBsp.h"


#include  "ff.h"                //FatFs




#endif  //__INCLUDE_H__
//����