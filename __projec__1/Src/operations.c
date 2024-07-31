/*
 * operations.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Rana Sujeet
 */

#include "operations.h"
#include "usart.h"
#include "adc.h"
#include "interrupt.h"  // Include the header for interrupt functions

void print_menu(void) {
    UART2_SendString("======================================== \r\n");
    UART2_SendString("|                PROJECT - 1           | \r\n");
    UART2_SendString("======================================== \r\n");
    UART2_SendString("|      1. Start ADC Conversion         | \r\n");
    UART2_SendString("|      2. Trigger Interrupt            | \r\n");
    UART2_SendString("|           3. Exit                    | \r\n");
    UART2_SendString("======================================== \r\n");
    UART2_SendString("\r\n");

}

void print_interrupt_menu(void) {
    UART2_SendString("\r\n");
    UART2_SendString("Select Interrupt to Trigger:\r\n");
    UART2_SendString("1. Timer Interrupt\r\n");
    UART2_SendString("2. External Interrupt\r\n");
    UART2_SendString("\r\n");

}

void handle_option(char option) {
    switch (option) {
        case '1':
            start_adc_conversion();
            break;
        case '2':
            trigger_interrupt();
            break;
        case '3':
            exit_program();
            break;
        default:
            UART2_SendString("Invalid Option! Please enter '1', '2', or '3'\r\n");
            break;
    }
}

void start_adc_conversion(void) {
    UART2_SendString("\r\n");
    UART2_SendString("Starting ADC Conversion...\r\n");
    adc_init();
    adc_start_conversion();
    uint32_t value = adc_read();
    char buffer[10];
    sprintf(buffer, "%lu\n\r", value);
    UART2_SendString(buffer);

    while (1)
    {
        UART2_SendString("Do you want to Continue ADC Conversion? (Y/N): ");
        char continue_option = receiverdata();
        UART2_SendChar(continue_option);
        UART2_SendString("\r\n");
        if (continue_option == 'N') {
            break;
        }
        else if (continue_option == 'Y') {
            adc_start_conversion();
            value = adc_read();
            sprintf(buffer, "%lu\n\r", value);
            UART2_SendString(buffer);
        }
        else
        {
            UART2_SendString("Invalid Option! Please enter 'y' or 'n'\r\n");
        }
    }
}

void trigger_interrupt(void) {
    UART2_SendString("\r\n");

    print_interrupt_menu();

    char interrupt_option = receiverdata();

    UART2_SendChar(interrupt_option);

    UART2_SendString("\r\n");

    if (interrupt_option == '1') {
        UART2_SendString("\r\n");
        UART2_SendString("Triggering Timer Interrupt...\r\n");

        Timer2_init();


    }
    else if (interrupt_option == '2') {
        UART2_SendString("\r\n");
        UART2_SendString("Triggering External Interrupt...\r\n");

        EXTI15_10_init();

        while(1);



    }
    else {
        UART2_SendString("\r\n");
        UART2_SendString("Invalid Option! Please enter '1' or '2'\r\n");
    }
}

void exit_program(void) {

    UART2_SendString("Exiting..............................\r\n");

    while (1);
}
