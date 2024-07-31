/*
 * interrupt.h
 *
 *  Created on: Jul 29, 2024
 *      Author: RanaS
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "stm32f446xx.h"  // Include device-specific header file for STM32F446xx

// Define the bit mask for the button connected to pin 13
#define BUTTON_PIN  (1U << 13)
// Define the EXTI configuration for line 13
#define EXTI_C13    (2 << 4)
// Function to initialize Timer 2
void Timer2_init(void);

// Timer 2 interrupt handler
void TIM2_IRQHandler(void);

// Function to initialize External Interrupt for lines 15 to 10
void EXTI15_10_init(void);

// External Interrupt 15 to 10 handler
void EXTI15_10_IRQHandler(void);



#endif /* INTERRUPT_H_ */
