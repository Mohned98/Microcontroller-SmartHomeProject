#include "ADC.h"

void ADC_init(ADC_Channel Channel)
{
int PinNumber = 0;
// .Enable the clock to the ADC
SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;
switch (Channel)
{
    case AN0:
    case AN1:
    case AN2:
    case AN3:
    case AN8:
    case AN9:
            // AN0 is PE3 and AN1 is PE2 qnd AN2 is PE1 and AN3 is PE0   
            // Pin Number = 4 - Channel for channel AIN0 to AIN3 and  = 14 - Channel for  channel AIN8 to AIN9 and
            PinNumber = (Channel > 5 ) ? (3 - Channel) : (13 - Channel);
            // Enabling GPIO PortE and the PIN to Input  
            DIO_Init(PORTE,PinNumber);
            //Set the GPIOAFSEL (GPIO alternate function) bit for ADC input pin to 1
            SET_BIT(GPIO_PORTE_AFSEL_R,PinNumber);
            //Configure AINx signal to be used as analog input by clearing the bit in the GPIODEN (GPIO Digital enable) register.
            CLEAR_BIT(GPIO_PORTE_DEN_R,PinNumber);
            // Disable the Analog isolation circuit for ADC input pins by writing a 1 to the GPIOAMSEL register.
            SET_BIT(GPIO_PORTE_AMSEL_R,PinNumber);            
        break;

    case AN4:
    case AN5:
    case AN6:
    case AN7:
            // AN0 is PE3 and AN1 is PE2 qnd AN2 is PE1 and AN3 is PE0   
            // Pin Number = 4 - Channel
            PinNumber = (3 - Channel);
            // Enabling GPIO PortE and the PIN to Input  
           DIO_Init(PORTD,PinNumber);
            //Set the GPIOAFSEL (GPIO alternate function) bit for ADC input pin to 1
            SET_BIT(GPIO_PORTD_AFSEL_R,PinNumber);
            //Configure AINx signal to be used as analog input by clearing the bit in the GPIODEN (GPIO Digital enable) register.
            CLEAR_BIT(GPIO_PORTD_DEN_R,PinNumber);
            // Disable the Analog isolation circuit for ADC input pins by writing a 1 to the GPIOAMSEL register.
            SET_BIT(GPIO_PORTD_AMSEL_R,PinNumber);            
        break;
    
    case AN10:
    case AN11:
            // AN0 is PE3 and AN1 is PE2 qnd AN2 is PE1 and AN3 is PE0   
            // Pin Number = Channel - 5
            PinNumber = (Channel - 6);
            // Enabling GPIO PortE and the PIN to Input  
            DIO_Init(PORTB,PinNumber);
            //Set the GPIOAFSEL (GPIO alternate function) bit for ADC input pin to 1
            SET_BIT(GPIO_PORTB_AFSEL_R,PinNumber);
            //Configure AINx signal to be used as analog input by clearing the bit in the GPIODEN (GPIO Digital enable) register.
            CLEAR_BIT(GPIO_PORTB_DEN_R,PinNumber);
            // Disable the Analog isolation circuit for ADC input pins by writing a 1 to the GPIOAMSEL register.
            SET_BIT(GPIO_PORTB_AMSEL_R,PinNumber);            
        break;


}
}


float ADC_read(ADC_Channel Channel)
{	
//make sure the gpio is ready
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
// seqncer 
ADC0_SSPRI_R = (ADC0_SS3_PRI | ADC0_SS2_PRI | ADC0_SS1_PRI | ADC0_SS0_PRI);
// .Enable the clock to the ADC
SET_BIT(SYSCTL_RCGCADC_R,0);
//Select start conversion trigger method .e.g. using software trigger
ADC0_EMUX_R = ~0xF000;
//Set Sample Sequencer Control characteristics
ADC0_SSCTL3_R |= 6; // single-ended, one-conversion and raw interrupt
//Enable Sample Sequencer
ADC0_ACTSS_R |= 8;
//Disable Sample Sequencer before making changes
ADC0_ACTSS_R &= ~0x8;
//Select ADC input channel
ADC0_SSMUX3_R = Channel;
//Enable Sample Sequencer before making changes
ADC0_ACTSS_R |= 0x8;
//start
ADC0_PSSI_R |= 8;
//wait for the flag
while(IS_BIT_SET(ADC0_RIS_R,0x08));
//clear the flag
ADC0_ISC_R =8;
//return the result
return ADC0_SSFIFO3_R&0xFFF;

}





