/*
 * tim.c
 *
 *  Created on: Apr 5, 2025
 *      Author: david
 */

#include "tim.h"

void __attribute__((weak)) vTim_softwareTimersInit ()
{
    __NOP();
}

const u8 bTim_isRunning ( const tim_softwareTimer_t* pTimer )
{
    return (pTimer->state == TIM_RUNNING);
}

const u8 bTim_isTimeout ( const tim_softwareTimer_t* pTimer )
{
    return (pTimer->state == TIM_TIMEOUT);
}

const tim_softwareTimerState_e xTim_getState ( const tim_softwareTimer_t* pTimer )
{
    return pTimer->state;
}

const u16 uTim_getCounter ( const tim_softwareTimer_t* pTimer )
{
    return (pTimer->counter);
}

const u16 uTim_getTimeout ( const tim_softwareTimer_t* pTimer )
{
    return (pTimer->timeout);
}

void vTim_resetTimer ( tim_softwareTimer_t* pTimer )
{
    pTimer->counter = 0;
    pTimer->state = TIM_RUNNING;
}

void vTim_startTimer ( tim_softwareTimer_t* pTimer )
{
    pTimer->state = TIM_RUNNING;
}

void vTim_stopTimer ( tim_softwareTimer_t* pTimer )
{
    pTimer->state = TIM_STOP;
}

void vTim_updateCounter ( tim_softwareTimer_t* pTimer )
{
    pTimer->counter++;

    if ( pTimer->counter == pTimer->timeout )
    {
        pTimer->state = TIM_TIMEOUT;
    }
}

void vTim_resetCounter ( tim_softwareTimer_t* pTimer )
{
    pTimer->counter = 0;
}

void vTim_setTimeout ( tim_softwareTimer_t* pTimer, u16 timeout )
{
    pTimer->timeout = timeout;
}

//void __attribute__((weak)) vTim_sysTickHandler ( void )
//{
//    __NOP();
//}

void vTim_sysTickInit ()
{
    SysTick->SR &= ~(1 << 0); //clear State flag
    SysTick->CMP = uTim_ms2ticks( 1 );
    SysTick->CNT = 0;
    SysTick->CTLR = 0xF;

    NVIC_SetPriority( SysTicK_IRQn, 15 );
    NVIC_EnableIRQ( SysTicK_IRQn );
}

u_int64_t uTim_ms2ticks ( u_int64_t ms )
{
    return (ms * ((SystemCoreClock - 1) / 1000));
}

