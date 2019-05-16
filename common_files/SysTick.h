#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "tm4c123gh6pm.h"
#include <math.h>

#define FREQUENCY 							80000000
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Counter load value

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void);

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 20 nsec for 50 MHz clock)
void SysTick_delay(uint32 delay);

// Time delay using busy wait.
void SysTick_delay_ms(uint32 delay_in_ms);

#endif /*SYSTICK_H_*/
