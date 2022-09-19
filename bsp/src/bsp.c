/*
*********************************************************************************************************
*                                     MICIRUM BOARD SUPPORT PACKAGE
*
*                            (c) Copyright 2007-2008; Micrium, Inc.; Weston, FL
*
*                   All rights reserved.  Protected by international copyright laws.
*                   Knowledge of the source code may not be used to write a similar
*                   product.  This file may only be used in accordance with a license
*                   and should not be redistributed in any way.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                        BOARD SUPPORT PACKAGE
*
*                                     ST Microelectronics STM32
*                                              with the
*                                   STM3210E-EVAL Evaluation Board
*
* Filename      : bsp.c
* Version       : V1.00
* Programmer(s) : BAN
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/


#include "bsp.h"  

#include "stm32f10x.h"
#include "gpio.h"
#include <ucos_ii.h>

void  CPU_IntDis(void);
void  CPU_IntEn (void);


void RCC_Configuration(void)
{
        
    SystemInit();
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); //重定义开启
}

void NVIC_Configuration(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
}



void BSP_Init(void)
{
    RCC_Configuration();
    NVIC_Configuration();
    UsartInit();
    
}

void  OS_CPU_SysTickInit (void)
{

    RCC_ClocksTypeDef RCC_Clocks;
    
    RCC_GetClocksFreq(&RCC_Clocks);
    
    SysTick_Config(RCC_Clocks.HCLK_Frequency / OS_TICKS_PER_SEC);
    
    SysTick->CTRL |= 0x05;
    
    SysTick->CTRL |= 0x02;

}

void  BSP_IntDisAll (void)
{
    CPU_IntDis();
}











/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

