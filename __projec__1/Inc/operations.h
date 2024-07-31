/*
 * operations.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Rana Sujeet
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

// Function to print the menu options
void print_menu(void);

// Function to handle user-selected menu options
void handle_option(char option);

// Function to start ADC conversion process
void start_adc_conversion(void);

// Function to trigger an interrupt
void trigger_interrupt(void);

// Function to exit the program
void exit_program(void);

#endif /* OPERATIONS_H_ */
