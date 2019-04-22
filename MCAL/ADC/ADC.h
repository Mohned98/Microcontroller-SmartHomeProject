#ifndef ADC_H_
#define ADC_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "SysTick.h"
#include "tm4c123gh6pm.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init(void);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
