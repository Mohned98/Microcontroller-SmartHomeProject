#include "UART.h"
void Uart_Print (UARTNUM UartNum, const char *Str){
	uint8 i = 0;
	
	switch(UartNum){
		case uart0:	
			while(Str[i] != '\0'){
				UART_Write(uart0,Str[i]);
				i++;
			}
		break;
		
		case uart1:
			while(Str[i] != '\0'){
				UART_Write(uart1,Str[i]);
				i++;
			}
		break;
		
		case uart2:
			while(Str[i] != '\0'){
				UART_Write(uart2,Str[i]);
				i++;
			}
		break;
		
		case uart3:
			while(Str[i] != '\0'){
				UART_Write(uart3,Str[i]);
				i++;
			}	
		break;
		
		case uart4:
			while(Str[i] != '\0'){
				UART_Write(uart4,Str[i]);
				i++;
			}
		break;
		
		case uart5:
			while(Str[i] != '\0'){
				UART_Write(uart5,Str[i]);
				i++;
			}	
		break;
		
		case uart6:
			while(Str[i] != '\0'){
				UART_Write(uart6,Str[i]);
				i++;
			}
		break;
		
		case uart7:
			while(Str[i] != '\0'){
				UART_Write(uart7,Str[i]);
				i++;
			}	
		break;
	}
}
