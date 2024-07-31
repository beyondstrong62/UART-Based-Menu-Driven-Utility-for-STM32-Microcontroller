/*
 * adc.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Abhisek
 */

/*
 * adc.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Rana
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f446xx.h"
#include<stdio.h>

// Function Prototype to initialize the ADC peripheral
void adc_init(void);

// Function Prototype to initialize ADC interrupt
void adc_int_init(void);

// Function Prototype to start ADC conversion
void adc_start_conversion(void);

// Function Prototype to read the ADC conversion result
uint32_t adc_read(void);

// Function Prototype to ADC interrupt handler
void ADC_IRQHandler(void);

#endif /* ADC_H_ */


