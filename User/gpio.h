/*
 * gpio.h
 *
 *  Created on: Apr 5, 2025
 *      Author: david
 */

#ifndef USER_GPIO_H_
#define USER_GPIO_H_

#include "ch32v30x.h"
#include "ch32v30x_gpio.h"

#define LED2_PORT                  (GPIO_TypeDef*) GPIOC_BASE
#define LED2_PIN                   GPIO_Pin_0
#define LED2_RCC_BUS               RCC_APB2Periph_GPIOC

extern void vGPIO_led2Init(GPIOSpeed_TypeDef);

extern BitAction xGPIO_togglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif /* USER_GPIO_H_ */
