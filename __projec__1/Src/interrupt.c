/*
 * interrupt.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Abhisek
 */

#include "interrupt.h"
#include "usart.h"

// Function to initialize Timer 2
void Timer2_init(void) {
    // Enable TIM2 clock
    RCC->APB1ENR |= (1U << 0);

    // Set the prescaler value
    TIM2->PSC = 16000 - 1;

    // Set the auto-reload value
    TIM2->ARR = 2000 - 1;

    // Reset counter
    TIM2->CNT = 0;

    // Enable update interrupt
    TIM2->DIER |= TIM_DIER_UIE;

    // Enable TIM2 interrupt in NVIC
    NVIC_EnableIRQ(TIM2_IRQn);

    // Enable TIM2
    TIM2->CR1 = (1U << 0);
}

// Timer 2 interrupt handler
void TIM2_IRQHandler(void) {
    // Check if update interrupt flag is set
    if (TIM2->SR & (1U << 0)) {
        // Clear update interrupt flag
        TIM2->SR &= ~(1U << 0);

        // Send message over UART
        UART2_SendString("\r\nTimer 2 Interrupt\r\n");
        UART2_SendString("Press RESET Button to return to main menu...\r\n");
    }
}

// Function to initialize External Interrupt for lines 15 to 10
void EXTI15_10_init(void) {
    // Enable GPIOC clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Enable SYSCFG clock
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // Disable global interrupts
    __disable_irq();

    // Map EXTI line 13 to PC13
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;

    // Unmask EXTI line 13
    EXTI->IMR |= BUTTON_PIN;

    // Trigger on falling edge
    EXTI->FTSR |= BUTTON_PIN;

    // Enable EXTI line 15 to 10 interrupt in NVIC
    NVIC_EnableIRQ(EXTI15_10_IRQn);

    // Enable global interrupts
    __enable_irq();
}

// External Interrupt 15 to 10 handler
void EXTI15_10_IRQHandler(void) {
    // Check if the interrupt was from line 13
    if (EXTI->PR & BUTTON_PIN) {
        // Clear the pending interrupt flag
        EXTI->PR |= BUTTON_PIN;

        // Send message over UART
        UART2_SendString("\r\nExternal Interrupt\r\n");
        UART2_SendString("Press RESET Button to return to main menu...\r\n");
    }
}
