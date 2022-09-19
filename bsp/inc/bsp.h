
/*
*********************************************************************************************************
*
*                                        BOARD SUPPORT PACKAGE
*
*                                     ST Microelectronics STM32
*                                              with the
*                                   STM3210E-EVAL Evaluation Board
*
* Filename      : bsp.h
* Version       : V1.00
* Programmer(s) : BAN
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               BSP present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  __BSP_H__
#define  __BSP_H__




void BSP_Init(void);
void  BSP_IntDisAll (void);

void RCC_Configuration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);





void  OS_CPU_SysTickInit (void);











#endif



/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/


