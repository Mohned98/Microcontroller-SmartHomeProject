#ifndef TempSensor_H_
#define TempSensor_H_

#include "ADC.h"

void LM35TS_init (ADC_Channel Channel);
uint16 LM35TS_read (ADC_Channel Channel);
uint16 InternalTempSensor_read();

#endif /* TempSensor_H_ */
