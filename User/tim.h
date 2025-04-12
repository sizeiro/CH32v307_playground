/*
 * tim.h
 *
 *  Created on: Apr 5, 2025
 *      Author: david
 */

#ifndef USER_TIM_H_
#define USER_TIM_H_

#include "ch32v30x.h"
#include "ch32v30x_it.h"


typedef enum
{
    TIM_STOP = 0x00U,
    TIM_RUNNING = 0x01U,
    TIM_TIMEOUT = 0x02U
} tim_softwareTimerState_e;

typedef struct
{
    u16 counter;    ///< Current time count in ms
    u16 timeout; ///< Time for timeout in ms
    tim_softwareTimerState_e state; ///< Current state of the timer
}tim_softwareTimer_t;


/**
 * SYSTICK TIMER IRQ HANDLER
 * */
//extern void vTim_sysTickHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
extern void vTim_sysTickInit();

/**
 * SOFTWARE TIMERS FUNCTION
 * */
extern void vTim_softwareTimersInit();

extern const u8 bTim_isRunning(const tim_softwareTimer_t*);
extern const u8 bTim_isTimeout(const tim_softwareTimer_t*);
extern const tim_softwareTimerState_e xTim_getState(const tim_softwareTimer_t*);
extern const u16 uTim_getCounter(const tim_softwareTimer_t*);
extern const u16 uTim_getTimeout(const tim_softwareTimer_t*);

extern void vTim_resetTimer(tim_softwareTimer_t*);
extern void vTim_startTimer(tim_softwareTimer_t*);
extern void vTim_stopTimer(tim_softwareTimer_t*);
extern void vTim_updateCounter(tim_softwareTimer_t*);
extern void vTim_resetCounter(tim_softwareTimer_t*);
extern void vTim_setTimeout(tim_softwareTimer_t*, u16 timeout);

extern u_int64_t uTim_ms2ticks(u_int64_t ms);


#endif /* USER_TIM_H_ */
