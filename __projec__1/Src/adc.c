/*
 * adc.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Rana Sujeet
 *
 */


#include "adc.h"
#include "usart.h"

// ADC Configuration and functions

// Define PA0 pin mode as ADC mode (analog mode)
#define PA0_ADC_MODE (3 << 0)

// Define ADC sequence length of 1
#define ADC_SEQ_LEN_1 0

// Function to initialize the ADC peripheral
void adc_init(void) {
    // Set PA0 to analog mode
    GPIOA->MODER |= PA0_ADC_MODE;

    // Enable the clock for ADC1
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    // Configure ADC sequence length to 1
    ADC1->SQR1 = ADC_SEQ_LEN_1;

    // Enable the ADC peripheral
    ADC1->CR2 |= ADC_CR2_ADON;
}

// Function to initialize ADC interrupt
void adc_int_init(void) {
    // Enable ADC end-of-conversion interrupt
    ADC1->CR1 |= ADC_CR1_EOCIE;

    // Enable ADC interrupt in NVIC
    NVIC_EnableIRQ(ADC_IRQn);
}

// Function to start ADC conversion
void adc_start_conversion(void) {
    // Start ADC conversion
    ADC1->CR2 |= ADC_CR2_SWSTART;
}

// Function to read the ADC conversion result
uint32_t adc_read(void) {
    // Wait until conversion is complete
    while (!(ADC1->SR & ADC_SR_EOC));

    // Read and return ADC data register value
    return (ADC1->DR);
}

// ADC interrupt handler
void ADC_IRQHandler(void) {
    // Check if end-of-conversion flag is set
    if ((ADC1->SR & ADC_SR_EOC) != 0) {
        // Clear the end-of-conversion flag
        ADC1->SR &= ~ADC_SR_EOC;

        // Read the ADC data register value
        volatile uint32_t value = ADC1->DR;

        // Prepare the value to be sent over UART
        char buffer[10];
        sprintf(buffer, "%lu\n\r", value);

        // Send the value over UART
        UART2_SendString(buffer);
    }
}

// Function to send a character via UART (used by printf)
int __io_putchar(int ch) {
    // Send a character via UART2
    UART2_SendChar(ch);
    return ch;
}
