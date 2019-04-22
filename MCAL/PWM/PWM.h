#ifndef PWM_H_
#define PWM_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "tm4c123gh6pm.h"


// Names of the PWM channels
typedef enum {
	PWM0 = 0,
	PWM1 = 1,
	PWM2 = 2,
	PWM3 = 3,
	PWM4 = 4,
	PWM5 = 5,
	PWM6 = 6,
	PWM7 = 7,
} PWMChannel;

// Names of the PWM modules.
typedef enum {
	PWMModule0 = 0,
	PWMModule1 = 1
} PWMModule;


//----------------------- PWM_Init --------------------------
// Enables the specified PWM module/channel with a given period 
//	and duty cycle.
// Inputs:  module - the PWM module name.
//          channel - the PWM channel name.
//          period - the pulse period.
//          duty - the number of cycles for initial duty cycle 
// Outputs:  void.
void PWM_Init(PWMModule module, PWMChannel channel, uint16 period, uint16 duty);


//----------------------- PWM_SetDuty --------------------------
// Set the duty cycle of an enabled PWM module/channel
// Inputs:  module - the PWM module name.
//          channel - the PWM channel name.
//          duty - the number of cycles for the duty cycle.
// Outputs:  void.
void PWM_SetDuty(PWMModule module, PWMChannel channel, uint16 duty);




#endif

