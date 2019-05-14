#include "Temp_Sensor.h"

void LM35TS_init(ADC_Channel Channel)
{
	ADC_init(Channel);
}

uint16 LM35TS_read (ADC_Channel Channel)
{ 
    uint16 read;
    read = ADC_read(Channel);
    read = read / 12.41;
    return read;
}


uint16 InternalTempSensor_read()
{	
uint16 result;
//Make sure the gpio is ready
SYSCTL_RCGCGPIO_R |= (0 <= 3 || 0 == 8 || 0 == 9)? SYSCTL_RCGCGPIO_R4:(0 >= 4 && 0 <= 7)? SYSCTL_RCGCGPIO_R3 : SYSCTL_RCGCGPIO_R1;
// seqncer 
ADC0_SSPRI_R = (ADC0_SS3_PRI);
//Select start conversion trigger method .e.g. using software trigger
ADC0_EMUX_R = ~0xF000;
//Set Sample Sequencer Control characteristics
ADC0_SSCTL3_R |= 0x0e; // single-ended, one-conversion and raw interrupt
//Enable Sample Sequencer
ADC0_ACTSS_R |= 8;
//Disable Sample Sequencer before making changes
ADC0_ACTSS_R &= ~0x8;
//Select ADC input channel
ADC0_SSMUX3_R = 0;
//Enable Sample Sequencer before making changes
ADC0_ACTSS_R |= 0x8;
//start
ADC0_PSSI_R |= 8;
//wait for the flag
while(IS_BIT_SET(ADC0_RIS_R,0x08));
//clear the flag
result = ADC0_SSFIFO3_R&0xFFF;
//
ADC0_ISC_R =8;
//return the result
result = (uint16)(147.5 - (75.0*3.3 *result) / 4096.0);

return result;
}

