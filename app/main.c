/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x.h"
#include "includes.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static OS_STK Start_Task_Array[APP_TASK_START_STK_SIZE];

static OS_STK Task1_Array[APP_TASK1_STK_SIZE];
static OS_STK Task2_Array[APP_TASK2_STK_SIZE];
static OS_STK Task3_Array[APP_TASK3_STK_SIZE];

/* Private function prototypes -----------------------------------------------*/
static void App_TaskStart(void *p_arg);
static  void App_TaskCreate(void);

static void App_Task1(void *p_arg);
static void App_Task2(void *p_arg);
static void App_Task3(void *p_arg);
/* Private functions ---------------------------------------------------------*/
int main()
{

    BSP_IntDisAll();                                            /* Disable all ints until we are ready to accept them.  */

    OSInit();                                                   /* Initialize "uC/OS-II, The Real-Time Kernel".         */

    OSTaskCreate((void (*)(void *))App_TaskStart, (void *)0,          /* Create the start task.                               */
                &Start_Task_Array[APP_TASK_START_STK_SIZE - 1], APP_TASK_START_PRIO);


    OSStart();                                                  /* Start multitasking (i.e. give control to uC/OS-II).  */
    
}

static void App_TaskStart(void *p_arg)
{
    BSP_Init();

    
    OS_CPU_SysTickInit();

    App_TaskCreate();            //建立其他的任务

}


/****************************************************************************
* 名    称：static  void App_TaskCreate(void)
* 功    能：建立其余任务的函数
* 入口参数：无
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/
static  void App_TaskCreate(void)
{
    OSTaskCreate((void (*)(void *))App_Task1, (void *)0,
                 &Task1_Array[APP_TASK1_STK_SIZE - 1], APP_TASK1_PRIO);
    
    OSTaskCreate((void (*)(void *))App_Task2, (void *)0,          
                 &Task2_Array[APP_TASK2_STK_SIZE - 1], APP_TASK2_PRIO);
    
    OSTaskCreate((void (*)(void *))App_Task3, (void *)0,          
                 &Task3_Array[APP_TASK3_STK_SIZE - 1], APP_TASK3_PRIO);
    while(1)
    {
        printf("start++++++r\n");
        OSTimeDlyHMSM(0, 0, 0, 20);

    }
}



static void App_Task1(void *p_arg)
{
    while(1)
    {
        printf("task1------r\n");
        OSTimeDlyHMSM(0, 0, 0, 20);
        
    }
}


static void App_Task2(void *p_arg)
{

    while(1)
    {
        printf("task2******r\n");
        OSTimeDlyHMSM(0, 0, 0, 20);
        
    }
}


static void App_Task3(void *p_arg)
{

    while(1)
    {
        printf("task3......r\n");
        OSTimeDlyHMSM(0, 0, 0, 20);
        
    }
}



/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
