#include <usart.h>        // Include USART (Universal Synchronous/Asynchronous Receiver/Transmitter) header
#include <scc.h>          // Include System Clock Configuration header
#include <operations.h>   // Include operations header for various functions

int main(void) {
    SysClockConfig();     // Configure the system clock
    Usart2_config();      // Configure USART2 for communication

    while (1) {           // Infinite loop to keep the program running
        print_menu();     // Display the menu to the user

        char option = receiverdata();  // Receive user input
        UART2_SendChar(option);        // Echo the received character back to the user
        UART2_SendString("\r\n");      // Send a newline and carriage return for better readability

        handle_option(option);         // Handle the user's option
    }

    return 0;             // Return 0 to indicate successful execution (although this line will never be reached)
}
