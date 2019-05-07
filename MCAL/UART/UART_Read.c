#include "UART.h"
#define one 1
uint8 UART_Read(UARTNUM UartNum)
{
	uint8 value;
switch (UARTNUM){
	case uart0:
		while (UART_Available(uart0)!=one);
		value = (uint8)(UART0_DR_R&0xFF);
		break;
	
	case uart1:
		while (UART_Available(uart1)!=one);
		value = (uint8)(UART1_DR_R&0xFF);
		break;
	
	case uart2:
		while (UART_Available(uart2)!=one);
		value = (uint8)(UART2_DR_R&0xFF);
		break;
	
	case uart3:
		while (UART_Available(uart3)!=one);
		value = (uint8)(UART3_DR_R&0xFF);
		break;
	
	case uart4:
		while (UART_Available(uart4)!=one);
		value = (uint8)(UART4_DR_R&0xFF);
		break;
	
	case uart5:
		while (UART_Available(uart5)!=one);
		value = (uint8)(UART5_DR_R&0xFF);
		break;
	
	case uart6:
		while (UART_Available(uart6)!=one);
		value = (uint8)(UART6_DR_R&0xFF);
		break;
	
	case uart7:
		while (UART_Available(uart7)!=one);
		value = (uint8)(UART7_DR_R&0xFF);
		break;
	}		
return value;
}	

