#ifndef TempSensor_H_
#define TempSensor_H_

#include "ADC.h"
#include "DIO.h"

void TempSensor_Init (ADC_Channel Channel);
float32  TempSensor_read (ADC_Channel Channel);

#endif /* TempSensor_H_ */
