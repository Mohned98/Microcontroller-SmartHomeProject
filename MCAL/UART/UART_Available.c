/**
  * @brief This function Checks whether the targeted UART is Available for transaction or not
  * @param UartNum indicating the selected UART to be checked
  * @retval u8 to return 0 if available 1 if not available
  */
u8 UART_Available(UARTNUM UartNum){
	switch(UartNum){
		case 0:
			return ((UART0_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
		
		case 1:
			return ((UART1_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
		
		case 2:
			return ((UART2_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
		
		case 3:
			return ((UART3_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
		
		case 4:
			return ((UART4_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
		
		case 5:
			return ((UART5_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
		
		case 6:
			return ((UART6_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
		
		case 7:
			return ((UART7_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
		break;
	}
}