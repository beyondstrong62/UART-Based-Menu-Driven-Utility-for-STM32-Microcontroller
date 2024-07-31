/*
 * scc.h
 *
 *  Created on: Jul 28, 2024
 *      Author: Abhisek
 */

#ifndef SCC_H_
#define SCC_H_

#include "stm32f446xx.h"

// PLL (Phase-Locked Loop) configuration parameters
#define PLL_M     4     // PLLM: Division factor for the main PLL (PLL) entry clock
#define PLL_N     180   // PLLN: Multiplication factor for the main PLL (PLL) entry clock
#define PLL_P     0     // PLLP: Division factor for the main PLL (PLL) output clock, 0 corresponds to PLLP = 2

// Function prototype to configure the system clock
void SysClockConfig(void);

#endif /* SCC_H_ */


