#ifndef ADC_H_
#define ADC_H_

#include "STANDARD_TYPES.h"
#include "SysTick.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "MACROS.h"



#define ADC0_SS0_PRI 			0x3
#define ADC0_SS1_PRI 			(0x2 << 4)
#define ADC0_SS2_PRI 			(0x1 << 8)
#define ADC0_SS3_PRI 			(0x0 << 12)



typedef enum {
 AN0,AN1,AN2,AN3,AN4,AN5,AN6,AN7,AN8,AN9,AN10,AN11
} ADC_Channel;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ADC_init(ADC_Channel Channel);

float ADC_read(ADC_Channel Channel);

#endif /* ADC_H_ */
