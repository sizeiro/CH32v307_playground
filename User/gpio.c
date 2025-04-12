/*
 * gpio.c
 *
 *  Created on: Apr 5, 2025
 *      Author: david
 */

#include "gpio.h"

void vGPIO_led2Init(const GPIOSpeed_TypeDef speed)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(LED2_RCC_BUS, ENABLE);
    GPIO_InitStructure.GPIO_Pin = LED2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = speed;
    GPIO_Init(LED2_PORT, &GPIO_InitStructure);
}

BitAction xGPIO_togglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    BitAction bit_state = Bit_RESET;

    if(GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin) == Bit_RESET)
    {
        bit_state = Bit_SET;
    }

    GPIO_WriteBit(GPIOx, GPIO_Pin, bit_state);

    return bit_state;
}
