#ifndef ADC_H_
#define ADC_H_

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "SysTick.h"
#include "tm4c123gh6pm.h"
#include "ADC.h"
#include "DIO.h"

typedef enum {
 AN0,AN1,AN2,AN3,AN4,AN5,AN6,AN7,AN8,AN9,AN10,AN11
} ADC_Channel;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init(void);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
