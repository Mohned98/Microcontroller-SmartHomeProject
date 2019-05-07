#include "UART.h"


void UART_Init(UARTNUM UartNum , uint32 BaudRate , PARITY Parity , INTERRUPT interrupt ){
	float BRD = (float) BAUDRATE(BaudRate);																		//Calculate total BAUDRATE
	int DIVINT = (int) BRD;																										//Calculate Integer BAUDRATE
	int DIVFRAC = (int) (((BRD - DIVINT) * 64) + 0.5);												//Calculate Fraction BAUDRATE
	
	switch(UartNum){
		case uart0:{																														//PA0 and PA1
			SET_BIT(SYSCTL_RCGCUART_R,0);																					//Enable UART0 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,0);																					//Enable GPIOA clock
			
			CLEAR_BIT(UART0_CTL_R,0);																							//Disable UART0
			UART0_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART0_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART0_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART0_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN0_R,5);																							//Enable UART0 Interrupt 5
				SET_BIT(NVIC_PRI1_R,13); 																						//Set UART0 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI1_R,14);
				CLEAR_BIT(NVIC_PRI1_R,15);
				UART0_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN0_R,5);																						//Disable UART0 Interrupt
			
			UART0_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART0_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART0, Transmit and Receive
			
			GPIO_PORTA_AFSEL_R |= ((1<<0) | (1<<1));															//Enable the alternative function of Port A pins 0:1
			GPIO_PORTA_PCTL_R = ((GPIO_PORTA_PCTL_R & 0xFFFFFF00) | 0x11);				//Port A pins 0:1 will work as RX and TX
			GPIO_PORTA_DEN_R |= ((1<<0) | (1<<1));																//Port A pin 0:1 are now digital
			break;
		}
		case uart1:{																														//PB0 and PB1
			SET_BIT(SYSCTL_RCGCUART_R,1);																					//Enable UART1 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,1);																					//Enable GPIOB clock
			
			CLEAR_BIT(UART1_CTL_R,0);																							//Disable UART1
			UART1_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART1_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART1_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART1_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN0_R,6);																							//Enable UART1 Interrupt 6
				SET_BIT(NVIC_PRI1_R,21); 																						//Set UART1 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI1_R,22);
				CLEAR_BIT(NVIC_PRI1_R,23);
				UART1_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN0_R,6);																						//Disable UART1 Interrupt
			
			UART1_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART1_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART1, Transmit and Receive
			
			GPIO_PORTB_AFSEL_R |= ((1<<0) | (1<<1));															//Enable the alternative function of Port B pins 0:1
			GPIO_PORTB_PCTL_R = ((GPIO_PORTB_PCTL_R & 0xFFFFFF00) | 0x11);				//Port B pins 0:1 will work as RX and TX
			GPIO_PORTB_DEN_R |= ((1<<0) | (1<<1));																//Port B pin 0:1 are now digital
			break;
		}
		case uart2:{																														//PD6 and PD7
			SET_BIT(SYSCTL_RCGCUART_R,2);																					//Enable UART2 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,3);																					//Enable GPIOD clock
			
			CLEAR_BIT(UART2_CTL_R,0);																							//Disable UART2
			UART2_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART2_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART2_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART2_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN1_R,1);																							//Enable UART2 Interrupt 33
				SET_BIT(NVIC_PRI8_R,13); 																						//Set UART2 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI8_R,14);
				CLEAR_BIT(NVIC_PRI8_R,15);
				UART2_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN1_R,1);																						//Disable UART2 Interrupt
			
			UART2_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART2_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART2, Transmit and Receive
			
			GPIO_PORTD_AFSEL_R |= ((1<<6) | (1<<7));															//Enable the alternative function of Port D pins 6:7
			GPIO_PORTD_PCTL_R = ((GPIO_PORTD_PCTL_R & 0x00FFFFFF) | 0x11000000);	//Port D pins 6:7 will work as RX and TX
			GPIO_PORTD_DEN_R |= ((1<<6) | (1<<7));																//Port D pin 6:7 are now digital
			break;
		}
		case uart3:{																														//PC6 and PC7
			SET_BIT(SYSCTL_RCGCUART_R,3);																					//Enable UART3 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,2);																					//Enable GPIOC clock
			
			CLEAR_BIT(UART3_CTL_R,0);																							//Disable UART3
			UART3_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART3_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART3_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART3_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN1_R,27);																							//Enable UART3 Interrupt 59
				SET_BIT(NVIC_PRI14_R,29); 																					//Set UART3 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI14_R,30);
				CLEAR_BIT(NVIC_PRI14_R,31);
				UART3_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN1_R,27);																						//Disable UART3 Interrupt
			
			UART3_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART3_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART3, Transmit and Receive
			
			GPIO_PORTC_AFSEL_R |= ((1<<6) | (1<<7));															//Enable the alternative function of Port C pins 6:7
			GPIO_PORTC_PCTL_R = ((GPIO_PORTC_PCTL_R & 0x00FFFFFF) | 0x11000000);	//Port C pins 6:7 will work as RX and TX
			GPIO_PORTC_DEN_R |= ((1<<6) | (1<<7));																//Port C pin 6:7 are now digital
			break;
		}
		case uart4:{																														//PC4 and PC5
			SET_BIT(SYSCTL_RCGCUART_R,4);																					//Enable UART4 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,2);																					//Enable GPIOC clock
			
			CLEAR_BIT(UART4_CTL_R,0);																							//Disable UART4
			UART4_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART4_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART4_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART4_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN1_R,28);																							//Enable UART4 Interrupt 60
				SET_BIT(NVIC_PRI15_R,5); 																						//Set UART4 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI15_R,6);
				CLEAR_BIT(NVIC_PRI15_R,7);
				UART4_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN1_R,28);																						//Disable UART4 Interrupt
			
			UART4_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART4_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART4, Transmit and Receive
			
			GPIO_PORTC_AFSEL_R |= ((1<<4) | (1<<5));															//Enable the alternative function of Port C pins 4:5
			GPIO_PORTC_PCTL_R = ((GPIO_PORTC_PCTL_R & 0xFF00FFFF) | 0x110000);		//Port C pins 4:5 will work as RX and TX
			GPIO_PORTC_DEN_R |= ((1<<4) | (1<<5));																//Port C pin 4:5 are now digital
			break;
		}
		case uart5:{																														//PE4 and PE5
			SET_BIT(SYSCTL_RCGCUART_R,5);																					//Enable UART5 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,4);																					//Enable GPIOE clock
			
			CLEAR_BIT(UART5_CTL_R,0);																							//Disable UART5
			UART5_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART5_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART5_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART5_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN1_R,29);																							//Enable UART5 Interrupt 61
				SET_BIT(NVIC_PRI15_R,13); 																					//Set UART5 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI15_R,14);
				CLEAR_BIT(NVIC_PRI15_R,15);	
				UART5_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN1_R,29);																						//Disable UART5 Interrupt
			
			UART5_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART5_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART5, Transmit and Receive
			
			GPIO_PORTE_AFSEL_R |= ((1<<4) | (1<<5));															//Enable the alternative function of Port E pins 4:5
			GPIO_PORTE_PCTL_R = ((GPIO_PORTE_PCTL_R & 0xFF00FFFF) | 0x110000);		//Port E pins 4:5 will work as RX and TX				
			GPIO_PORTE_DEN_R |= ((1<<4) | (1<<5));																//Port E pin 4:5 are now digital
			break;
		}
		case uart6:{																														//PD4 and PD5
			SET_BIT(SYSCTL_RCGCUART_R,6);																					//Enable UART5 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,3);																					//Enable GPIOD clock
			
			CLEAR_BIT(UART6_CTL_R,0);																							//Disable UART6
			UART6_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART6_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART6_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART6_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN1_R,30);																							//Enable UART6 Interrupt 62
				SET_BIT(NVIC_PRI15_R,21); 																					//Set UART6 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI15_R,22);
				CLEAR_BIT(NVIC_PRI15_R,23);
				UART6_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN1_R,30);																						//Disable UART5 Interrupt
			
			UART6_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART6_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART6, Transmit and Receive
			
			GPIO_PORTD_AFSEL_R |= ((1<<4) | (1<<5));															//Enable the alternative function of Port D pins 4:5
			GPIO_PORTD_PCTL_R = ((GPIO_PORTD_PCTL_R & 0xFF00FFFF) | 0x110000);		//Port D pins 4:5 will work as RX and TX			
			GPIO_PORTD_DEN_R |= ((1<<4) | (1<<5));																//Port D pin 4:5 are now digital
			break;
		}
		case uart7:{																														//PE0 and PE1
			SET_BIT(SYSCTL_RCGCUART_R,7);																					//Enable UART7 clock
			SET_BIT(SYSCTL_RCGCGPIO_R,4);																					//Enable GPIOE clock
			
			CLEAR_BIT(UART7_CTL_R,0);																							//Disable UART7
			UART7_IBRD_R = DIVINT;																								//Configure Integer BAUDRATE
			UART7_FBRD_R = DIVFRAC;																								//Configure Fraction BAUDRATE
			if(Parity)
				SET_BIT(UART7_LCRH_R,1);																						//Enable Parity
			else
				CLEAR_BIT(UART7_LCRH_R,1);																					//Disable Parity
			
			if(interrupt){
				__enable_irq();																											//Enable general Interrupt (I think i should remove it)
				SET_BIT(NVIC_EN1_R,31);																							//Enable UART7 Interrupt 63
				SET_BIT(NVIC_PRI15_R,29); 																					//Set UART7 Interrupt priority to 1
				CLEAR_BIT(NVIC_PRI15_R,30);
				CLEAR_BIT(NVIC_PRI15_R,31);
				UART7_IFLS_R = 0x00;																								//Interrupt when RX FIFO ≥ 1/8 full and TX FIFO ≤ 1/8 empty
			}
			else
				CLEAR_BIT(NVIC_EN1_R,31);																						//Disable UART7 Interrupt
			
			UART7_LCRH_R |= ((1<<4) | (1<<5) | (1<<6));														//Enable FIFO and Set 8 Bits word length
			UART7_CTL_R |= ((1<<0) | (1<<8) | (1<<9));														//Enable UART7, Transmit and Receive
			
			GPIO_PORTE_AFSEL_R |= ((1<<0) | (1<<1));															//Enable the alternative function of Port E pins 0:1
			GPIO_PORTE_PCTL_R = ((GPIO_PORTE_PCTL_R & 0xFFFFFF00) | 0x11);				//Port E pins 0:1 will work as RX and TX			
			GPIO_PORTE_DEN_R |= ((1<<0) | (1<<1));																//Port E pin 0:1 are now digital
			break;
		}
	}
	
}
