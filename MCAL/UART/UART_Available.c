/**
  * @brief This function Checks whether the targeted UART selected by UartNum is Available to read from or not 
	*	       (Receiver  FIFO is empty or not)
  * @param UartNum indicating the selected UART to be checked
  * @retval uint8 to return 1 if available 0 if not available
  */
	
#include "UART.h"

uint8 UART_Available(UARTNUM UartNum){
	uint8 available;
	switch(UartNum){
		case uart0:
		((UART0_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
		
		case uart1:
		((UART1_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
		
		case uart2:
		((UART2_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
		
		case uart3:
		((UART3_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
		
		case uart4:
		((UART4_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
		
		case uart5:
		((UART5_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
		
		case uart6:
		((UART6_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
		
		case uart7:
		((UART7_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? (available = 0) : (available = 1);
		break;
	}
	return available;
}
