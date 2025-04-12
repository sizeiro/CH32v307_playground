/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2021/06/06
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 USART Print debugging routine:
 USART1_Tx(PA9).
 This example demonstrates using USART1(PA9) as a print debug port output.

 */

#include "debug.h"
#include "gpio.h"
#include "tim.h"

/* Global typedef */

/* Global define */

/* Global Variable */

tim_softwareTimer_t lLed2Timer;

void SysTick_Handler ( void ) __attribute__((interrupt));

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main ( void )
{
    NVIC_PriorityGroupConfig( NVIC_PriorityGroup_2 );
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init( 115200 );
    vTim_sysTickInit();
    vTim_softwareTimersInit();
    vGPIO_led2Init( GPIO_Speed_50MHz );

    while(1)
    {
        if(bTim_isTimeout(&lLed2Timer))
        {
            xGPIO_togglePin(LED2_PORT, LED2_PIN);
            vTim_resetTimer(&lLed2Timer);
        }
    }
}

__attribute__((interrupt)) void SysTick_Handler ( void )
{
    if ( SysTick->SR == 1 )
    {
        SysTick->SR = 0; //clear State flag
        if ( bTim_isRunning( &lLed2Timer ) )
        {
            vTim_updateCounter( &lLed2Timer );
        }
    }

}

void vTim_softwareTimersInit ()
{
    vTim_setTimeout( &lLed2Timer, 1000);
    vTim_startTimer( &lLed2Timer );
}

