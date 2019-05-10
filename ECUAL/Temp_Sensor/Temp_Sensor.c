#include "TS.h"

void LM35TS_init(UARTNUM uartnum)
{
ADC_init(uartnum) 
}

float LM35TS_READ(UARTNUM uartnum)
{ 
    float read;
    read = ADC_read(uartnum);
    read = read / 12.41;
    return read;
}

