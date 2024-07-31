/*
 * usart.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Rana Sujeet
 */


#include<usart.h>

// UART Configuration and functions
void UART2_SendChar(char ch) {
    USART2->DR = ch;
    while (!(USART2->SR & (1 << 6))); // Wait for TC bit to set
}

void UART2_SendString(char *string) {
    while (*string != '\0') {
        UART2_SendChar(*string);
        string++;
    }
}

void Usart2_config(void) {
    RCC->AHB1ENR |= (1 << 0);  // GPIOA enabled
    RCC->APB1ENR |= (1 << 17); // USART2 enabled

    GPIOA->MODER |= (2 << 4);  // Alternate function for PA2
    GPIOA->MODER |= (2 << 6);  // Alternate function for PA3

    GPIOA->OSPEEDR |= (3 << 4);
    GPIOA->OSPEEDR |= (3 << 6);

    GPIOA->AFR[0] |= (7 << 8);  // AF7 for PA2
    GPIOA->AFR[0] |= (7 << 12); // AF7 for PA3

    USART2->CR1 = 0x00;        // Clear all
    USART2->CR1 |= (1 << 13);  // Enable USART2
    USART2->CR1 &= ~(1 << 12); // M bit in USART_CR1 to define the word length
    USART2->BRR |= (1 << 0);   // USART_BRR register
    USART2->BRR |= (24 << 4);  // USART_BRR register -> 11000
    USART2->CR1 |= (1 << 2);   // Receiver RE enabled
    USART2->CR1 |= (1 << 3);   // Transmitter TE enabled
}

uint8_t receiverdata(void) {
    while (!(USART2->SR & (1 << 5))); // Wait for RXNE bit to set
    uint8_t data = USART2->DR;
    return data;
}
