#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include  "common.h"

/*
 * Include 用户自定义的头文件
 */
#include  "MK60_wdog.h"
#include  "MK60_gpio.h"      //IO口操作
#include  "MK60_uart.h"      //串口
#include  "MK60_SysTick.h"
#include  "MK60_lptmr.h"     //低功耗定时器(延时)
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
 *  用户头文件

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
//最新