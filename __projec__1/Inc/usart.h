/*
 * usart.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Rana Sujeet
 *
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f446xx.h"
#include <string.h>       // Include standard string library
#include <stdint.h>       // Include standard integer types

// Function Prototype to send a single character over UART2
void UART2_SendChar(char ch);

// Function Prototype to send a string over UART2
void UART2_SendString(char *string);

// Function Prototype to configure USART2 settings
void Usart2_config(void);

// Function Prototype to receive data from USART2
uint8_t receiverdata(void);

#endif /* USART_H_ */
