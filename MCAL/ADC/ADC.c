void ADC_init(ADC_Channel Channel)
{
int PinNumber = 0;

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
            PinNumber = (Channel > 5 ) ? 1<<(4 - Channel) : 1<<(14 - Channel);
            // Enabling GPIO PortE and the PIN to Input  
            DIO_Init(GPIOE,PinNumber);
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
            PinNumber = 1<<(4 - Channel)
            // Enabling GPIO PortE and the PIN to Input  
            DIO_Init(GPIOD,PinNumber);
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
            PinNumber = 1<<(Channel - 5)
            // Enabling GPIO PortE and the PIN to Input  
            DIO_Init(GPIOB,PinNumber);
            //Set the GPIOAFSEL (GPIO alternate function) bit for ADC input pin to 1
            SET_BIT(GPIO_PORTB_AFSEL_R,PinNumber);
            //Configure AINx signal to be used as analog input by clearing the bit in the GPIODEN (GPIO Digital enable) register.
            CLEAR_BIT(GPIO_PORTB_DEN_R,PinNumber);
            // Disable the Analog isolation circuit for ADC input pins by writing a 1 to the GPIOAMSEL register.
            SET_BIT(GPIO_PORTB_AMSEL_R,PinNumber);            
        break;

}

}