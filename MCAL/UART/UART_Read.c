#include "UART.h"
u8 UART_Read(UARTNUM UartNum)
{
switch (UARTNUM){
	case 0:
		while (UART_Available(0)!=1);
		return (uint8_t)(UART0_DR_R&0xFF);
		break;
	
	case 1:
		while (UART_Available(1)!=1);
		return (uint8_t)(UART1_DR_R&0xFF);
		break;
	
	case 2:
		while (UART_Available(2)!=1);
		return (uint8_t)(UART2_DR_R&0xFF);
		break;
	
	case 3:
		while (UART_Available(3)!=1);
		return (uint8_t)(UART3_DR_R&0xFF);
		break;
	
	case 4:
		while (UART_Available(4)!=1);
		return (uint8_t)(UART4_DR_R&0xFF);
		break;
	
	case 5:
		while (UART_Available(5)!=1);
		return (uint8_t)(UART5_DR_R&0xFF);
		break;
	
	case 6:
		while (UART_Available(6)!=1);
		return (uint8_t)(UART6_DR_R&0xFF);
		break;
	
	case 7:
		while (UART_Available(7)!=1);
		return (uint8_t)(UART7_DR_R&0xFF);
		break;
}	
}
