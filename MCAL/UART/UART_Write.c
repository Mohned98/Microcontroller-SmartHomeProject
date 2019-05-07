#include "UART.h"

#define zero 0

void UART_Write(UARTNUM UartNum,uint8 data){
	switch(UartNum){
		case 0:
			while((UART0_FR_R&UART_FR_TXFF) != zero);
				UART0_DR_R = data;
		break;
		
		case 1:
			while((UART1_FR_R&UART_FR_TXFF) != zero);
				UART1_DR_R = data;
		break;
		
		case 2:
			while((UART2_FR_R&UART_FR_TXFF) != zero);
				UART2_DR_R = data;
		break;
		
		case 3:
			while((UART3_FR_R&UART_FR_TXFF) != zero);
				UART3_DR_R = data;
		break;
		
		case 4:
			while((UART4_FR_R&UART_FR_TXFF) != zero);
				UART4_DR_R = data;
		break;
		
		case 5:
			while((UART5_FR_R&UART_FR_TXFF) != zero);
				UART5_DR_R = data;
		break;
		
		case 6:
			while((UART6_FR_R&UART_FR_TXFF) != zero);
				UART6_DR_R = data;
		break;
		
		case 7:
			while((UART7_FR_R&UART_FR_TXFF) != zero);
				UART7_DR_R = data;
		break;
	}
}
