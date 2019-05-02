#include "tm4c123gh6pm.h"
#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "PWM.h"

//----------------------- PWM_Enable --------------------------
// Enables the specified PWM module/channel with a given period 
//	and duty cycle.
// Inputs:  module - the PWM module name.
//          channel - the PWM channel name.
//          period - the pulse period.
//          duty - the number of bus cycles for initial duty cycle 
// Outputs:  none.
void PWM_Init(PWMModule module, PWMChannel channel, uint16 period, uint16 duty)
{
	switch (module) {
		
		case PWMModule0:
			
			SYSCTL_RCGCPWM_R |= 1;
		
			switch (channel){ 
				SYSCTL_RCGC0_R			|=	0x00100000;//Enable PWM Clock
				
				case PWM0: //PB6	
				 SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
				 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
				 SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
				 SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
				 GPIO_PORTB_AFSEL_R |= 	(0x00000040);//Enable Alternate Function on PB6
				 GPIO_PORTB_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 6
				 GPIO_PORTB_PCTL_R  |=  GPIO_PCTL_PB6_M0PWM0;//PORT MUX CONTROL 6
				 GPIO_PORTB_AMSEL_R &=~ 0x40;//Disable Analogue Functionality
				 GPIO_PORTB_DIR_R		|=	0x00000040;//Make Output
				 GPIO_PORTB_DEN_R 	|=	0x000000FF;// Digital Data is Enabled

					// Disable generator 0 
					PWM0_0_CTL_R = 0;
				
					// Drive PWM0 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_0_GENA_R =  PWM_0_GENA_ACTCMPAD_ZERO | PWM_0_GENA_ACTLOAD_ONE;
				
					// Set the count preset which will determine the period.
					PWM0_0_LOAD_R = period - 1;
				
					// Set the duty cycle count.
					PWM0_0_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_0_CTL_R |= 0x01; 
					
					// Enable PWM0 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM0EN;
				
					break;
				case PWM1://PB7
				 SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
				 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
				 SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
				 SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
				 GPIO_PORTB_AFSEL_R |= 	(0x00000080);//Enable Alternate Function on PB6
				 GPIO_PORTB_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 6
				 GPIO_PORTB_PCTL_R  |=  GPIO_PCTL_PB7_M0PWM1;//PORT MUX CONTROL 6
				 GPIO_PORTB_AMSEL_R &=~ 0x80;//Disable Analogue Functionality
				 GPIO_PORTB_DIR_R		|=	0x00000080;//Make Output
				 GPIO_PORTB_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
					// Disable generator 0 
					PWM0_0_CTL_R = 0;
				
					// Drive PWM1 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_0_GENB_R =  0x0000080C;
				
					// Set the count preset which will determine the period.
					PWM0_0_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM0_0_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_0_CTL_R |= 0x01; 
					
					// Enable PWM1 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM1EN;
				
					break;
				case PWM2: //PB4
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTB_AFSEL_R |= 	(0x00000010);//Enable Alternate Function on PB4
				  GPIO_PORTB_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 4
				  GPIO_PORTB_PCTL_R  |=  GPIO_PCTL_PB4_M0PWM2;//PORT MUX CONTROL 4
				  GPIO_PORTB_AMSEL_R &=~ 0x10;//Disable Analogue Functionality
					GPIO_PORTB_DIR_R		|=	0x00000010;//Make Output
					GPIO_PORTB_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
					// Disable generator 1
					PWM0_1_CTL_R = 0;
				
					// Drive PWM2 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_1_GENA_R =  PWM_1_GENA_ACTCMPAD_ZERO | PWM_1_GENA_ACTLOAD_ONE;
					
					// Set the count preset which will determine the period.
					PWM0_1_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM0_1_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_1_CTL_R |= 0x01; 
					
					// Enable PWM2 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM2EN;
				
					break;
				case PWM3://PB5
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTB_AFSEL_R |= 	(0x00000020);//Enable Alternate Function on PB5
				  GPIO_PORTB_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 5
				  GPIO_PORTB_PCTL_R  |=  GPIO_PCTL_PB5_M0PWM3; //PORT MUX CONTROL 5
				  GPIO_PORTB_AMSEL_R &=~ 0x20;//Disable Analogue Functionality
					GPIO_PORTB_DIR_R		|=	0x00000020;//Make Output
					GPIO_PORTB_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM0_1_CTL_R = 0;
				
					// Drive PWM3 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_1_GENB_R =  0x0000080C;
				
					// Set the count preset which will determine the period.
					PWM0_1_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM0_1_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_1_CTL_R |= 0x01; 
					
					// Enable PWM1 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM3EN;
				
					break;
				case PWM4://PE4
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTE_AFSEL_R |= 	(0x00000010); //Enable Alternate Function on PE4
				  GPIO_PORTE_PCTL_R  &=~ 0x0F000000; //PORT MUX CONTROL 4
				  GPIO_PORTE_PCTL_R  |=  GPIO_PCTL_PE4_M0PWM4; //PORT MUX CONTROL 4
				  GPIO_PORTE_AMSEL_R &=~ 0x10; //Disable Analogue Functionality
					GPIO_PORTE_DIR_R		|=	0x00000010;//Make Output
					GPIO_PORTE_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
					// Disable generator 1
					PWM0_2_CTL_R = 0;
				
					// Drive PWM4 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_2_GENA_R =  PWM_2_GENA_ACTCMPAD_ZERO | PWM_2_GENA_ACTLOAD_ONE;
				
					// Set the count preset which will determine the period.
					PWM0_2_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM0_2_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_2_CTL_R |= 0x01; 
					
					// Enable PWM4 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM4EN;
				
					break;
				case PWM5://PE5
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTE_AFSEL_R |= 	(0x00000020);//Enable Alternate Function on PE5
				  GPIO_PORTE_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 5
				  GPIO_PORTE_PCTL_R  |=  GPIO_PCTL_PE5_M0PWM5; //PORT MUX CONTROL 5
				  GPIO_PORTE_AMSEL_R &=~ 0x20;//Disable Analogue Functionality
					GPIO_PORTE_DIR_R		|=	0x00000020;//Make Output
					GPIO_PORTE_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM0_2_CTL_R = 0;
				
					// Drive PWM5 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_2_GENB_R =  0x0000080C;
				
					// Set the count preset which will determine the period.
					PWM0_2_LOAD_R = period - 1;
						
					// Set the duty cycle count.
					PWM0_2_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_2_CTL_R |= 0x01; 
					
					// Enable PWM5 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM5EN;
				
					break;
				case PWM6://PC4
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTC_AFSEL_R |= 	(0x00000010);//Enable Alternate Function on PC4
				  GPIO_PORTC_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 5
				  GPIO_PORTC_PCTL_R  |=  GPIO_PCTL_PC4_M0PWM6; //PORT MUX CONTROL 5
				  GPIO_PORTC_AMSEL_R &=~ 0x10;//Disable Analogue Functionality
					GPIO_PORTC_DIR_R		|=	0x00000010;//Make Output
					GPIO_PORTC_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
					
					// Disable generator 1
					PWM0_3_CTL_R = 0;
				
					// Drive PWM6 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_3_GENA_R =  PWM_3_GENA_ACTCMPAD_ZERO | PWM_3_GENA_ACTLOAD_ONE;
				
					// Set the count preset which will determine the period.
					PWM0_3_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM0_3_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_3_CTL_R |= 0x01; 
					
					// Enable PWM6 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM6EN;
				
					break;
				case PWM7: //PC5
					
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R0;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTC_AFSEL_R |= 	(0x00000020);//Enable Alternate Function on PC4
				  GPIO_PORTC_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 5
				  GPIO_PORTC_PCTL_R  |=  GPIO_PCTL_PC5_M0PWM7; //PORT MUX CONTROL 5
				  GPIO_PORTC_AMSEL_R &=~ 0x20;//Disable Analogue Functionality
					GPIO_PORTC_DIR_R	|=	0x00000020;//Make Output
					GPIO_PORTC_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM0_3_CTL_R = 0;
				
					// Drive PWM7 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM0_3_GENB_R =  0x0000080C;
					
					// Set the count preset which will determine the period.
					PWM0_3_LOAD_R = period - 1;
				
					// Set the duty cycle count.
					PWM0_3_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM0_3_CTL_R |= 0x01; 
					
					// Enable PWM7 for output pin
					PWM0_ENABLE_R |= PWM_ENABLE_PWM7EN;
				
					break;
				
			};
				
			break;
		
		case PWMModule1:
			SYSCTL_RCGCPWM_R |= 2;
			switch (channel) {
				case PWM0://PD0
					
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTD_AFSEL_R |= 	(0x00000001);//Enable Alternate Function on PD0
				  GPIO_PORTD_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 0
				  GPIO_PORTD_PCTL_R  |=  GPIO_PCTL_PD0_M1PWM0; //PORT MUX CONTROL 0
				  GPIO_PORTD_AMSEL_R &=~ 0x01;//Disable Analogue Functionality
					GPIO_PORTD_DIR_R	|=	0x00000001;//Make Output
					GPIO_PORTD_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 0 
					PWM1_0_CTL_R = 0;
				
					// Drive PWM0 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_0_GENA_R =  PWM_0_GENA_ACTCMPAD_ZERO | PWM_0_GENA_ACTLOAD_ONE;
				
					// Set the count preset which will determine the period.
					PWM1_0_LOAD_R = period - 1;
				
					// Set the duty cycle count.
					PWM1_0_CMPA_R =(uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM1_0_CTL_R |= 0x01; 
					
					// Enable PWM0 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM0EN;
				
					break;
				case PWM1://PD1
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTD_AFSEL_R |= 	(0x00000002);//Enable Alternate Function on PD1
				  GPIO_PORTD_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 1
				  GPIO_PORTD_PCTL_R  |=  GPIO_PCTL_PD1_M1PWM1; //PORT MUX CONTROL 1
				  GPIO_PORTD_AMSEL_R &=~ 0x02;//Disable Analogue Functionality
					GPIO_PORTD_DIR_R	|=	0x00000002;//Make Output
					GPIO_PORTD_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
				
					// Disable generator 0 
					PWM1_0_CTL_R = 0;
				
					// Drive PWM1 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_0_GENB_R =  0x0000080C;
				
					// Set the count preset which will determine the period.
					PWM1_0_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM1_0_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM1_0_CTL_R |= 0x01; 
					
					// Enable PWM1 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM1EN;
				
					break;
				case PWM2://PA6
					
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTA_AFSEL_R |= 	(0x00000040);//Enable Alternate Function on PA6
				  GPIO_PORTA_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 6
				  GPIO_PORTA_PCTL_R  |=  GPIO_PCTL_PA6_M1PWM2; //PORT MUX CONTROL 6
				  GPIO_PORTA_AMSEL_R &=~ 0x40;//Disable Analogue Functionality
					GPIO_PORTA_DIR_R	|=	0x00000040;//Make Output
					GPIO_PORTA_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM1_1_CTL_R = 0;
				
					// Drive PWM2 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_1_GENA_R =  PWM_1_GENA_ACTCMPAD_ZERO | PWM_1_GENA_ACTLOAD_ONE;
					
					// Set the count preset which will determine the period.
					PWM1_1_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM1_1_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM1_1_CTL_R |= 0x01; 
					
					// Enable PWM2 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM2EN;
				
					break;
				case PWM3://PA7
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;//Enable clock to portF
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTA_AFSEL_R |= 	(0x00000080);//Enable Alternate Function on PA6
				  GPIO_PORTA_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 6
				  GPIO_PORTA_PCTL_R  |=  GPIO_PCTL_PA7_M1PWM3; //PORT MUX CONTROL 6
				  GPIO_PORTA_AMSEL_R &=~ 0x80;//Disable Analogue Functionality
					GPIO_PORTA_DIR_R	|=	0x00000080;//Make Output
					GPIO_PORTA_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM1_1_CTL_R = 0;
				
					// Drive PWM3 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_1_GENB_R = 0x0000080C;
				
					// Set the count preset which will determine the period.
					PWM1_1_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM1_1_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM1_1_CTL_R |= 0x01; 
					
					// Enable PWM1 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM3EN;
				
					break;
				case PWM4://PF0
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;//Enable clock to portF
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTF_AFSEL_R |= 	(0x00000001);//Enable Alternate Function on PF0
				  GPIO_PORTF_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 0
				  GPIO_PORTF_PCTL_R  |=  GPIO_PCTL_PF0_M1PWM4; //PORT MUX CONTROL 0
				  GPIO_PORTF_AMSEL_R &=~ 0x01;//Disable Analogue Functionality
					GPIO_PORTF_DIR_R	|=	0x00000001;//Make Output
					GPIO_PORTF_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					
					// Disable generator 1
					PWM1_2_CTL_R = 0;
				
					// Drive PWM4 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_2_GENA_R =  PWM_2_GENA_ACTCMPAD_ZERO | PWM_2_GENA_ACTLOAD_ONE ;
				
					// Set the count preset which will determine the period.
					PWM1_2_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM1_2_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM1_2_CTL_R |= 0x01; 
					
					// Enable PWM4 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM4EN;
				
					break;
				case PWM5://PF1
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;//Enable clock to portF
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTF_AFSEL_R |= 	(0x00000002);//Enable Alternate Function on PF1
				  GPIO_PORTF_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 1
				  GPIO_PORTF_PCTL_R  |=  GPIO_PCTL_PF1_M1PWM5; //PORT MUX CONTROL 1
				  GPIO_PORTF_AMSEL_R &=~ 0x02;//Disable Analogue Functionality
					GPIO_PORTF_DIR_R	|=	0x00000002;//Make Output
					GPIO_PORTF_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM1_2_CTL_R = 0;
				
					// Drive PWM5 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_2_GENB_R =  0x0000080C;
				  
					// Set the count preset which will determine the period.
					PWM1_2_LOAD_R = period - 1;
						
					// Set the duty cycle count.
					PWM1_2_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1);
				
					// Enable the generator, i.e. start the timer.
					PWM1_2_CTL_R |= 0x01; 
					
					// Enable PWM5 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM5EN;
				
					break;
				case PWM6://PF2
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;//Enable clock to portF
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
					GPIO_PORTF_AFSEL_R |= 	(0x00000004);//Enable Alternate Function on PF2
				  GPIO_PORTF_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 1
				  GPIO_PORTF_PCTL_R  |=  GPIO_PCTL_PF2_M1PWM6; //PORT MUX CONTROL 1
				  GPIO_PORTF_AMSEL_R &=~ 0x08;//Disable Analogue Functionality										
					GPIO_PORTF_DIR_R	|=	0x00000004;//Make Output
					GPIO_PORTF_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM1_3_CTL_R = 0;
				
					// Drive PWM6 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_3_GENA_R =  PWM_3_GENA_ACTCMPAD_ZERO | PWM_3_GENA_ACTLOAD_ONE;
					 
					// Set the count preset which will determine the period.
					PWM1_3_LOAD_R = period - 1;
					
					// Set the duty cycle count.
					PWM1_3_CMPA_R = (uint16)(period * (1 - (duty / 100.0)) - 1); 
				
					// Enable the generator, i.e. start the timer.
					PWM1_3_CTL_R |= 0x01; 
					
					// Enable PWM6 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM6EN;
				
					break;
				case PWM7://PF3
					
					SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;//Enable clock to portF
					SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;
					SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
					SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_64; // PWM Clock = 1.25 MHz
				
					GPIO_PORTF_AFSEL_R |= 	(0x00000008);//Enable Alternate Function on PF3
				  GPIO_PORTF_PCTL_R  &=~ 0x0F000000;//PORT MUX CONTROL 1
				  GPIO_PORTF_PCTL_R  |=  GPIO_PCTL_PF3_M1PWM7; //PORT MUX CONTROL 1
				  GPIO_PORTF_AMSEL_R &=~ 0x08;//Disable Analogue Functionality
					GPIO_PORTF_DIR_R	|=	0x00000008;//Make Output
					GPIO_PORTF_DEN_R 	|=	0x000000FF;// Digital Data is Enabled
				
					// Disable generator 1
					PWM1_3_CTL_R = 0;
				
					// Drive PWM7 HIGH when when counter matches comparator A while counting down 
					//	and drive LOW when counter reaches zero.
					PWM1_3_GENB_R = 0x0000080C;
					
					// Set the count preset which will determine the period.
					PWM1_3_LOAD_R = period - 1;
				
					// Set the duty cycle count.
					PWM1_3_CMPB_R = (uint16)(period * (1 - (duty / 100.0)) - 1); 
				
					// Enable the generator, i.e. start the timer.
					PWM1_3_CTL_R |= 0x01; 
					
					// Enable PWM7 for output pin
					PWM1_ENABLE_R |= PWM_ENABLE_PWM7EN;
				
					break;
			};
			
			break;
	};
	
}

