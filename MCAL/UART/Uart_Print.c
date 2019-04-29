#include "UART.h"
void Uart_Print (UARTNUM UartNum, const char *Str)
{
		

	uint8 i = 0;
	switch(UartNum){
		
		case 0:	
		while(Str[i] != '\0')
		{
		UART_Write(0,Str[i]);
		i++;
		}
		break;
		
		case 1:
			while(Str[i] != '\0')
		{
		UART_Write(1,Str[i]);
		i++;
		}
		break;
		
		case 2:
			while(Str[i] != '\0')
		{
		UART_Write(2,Str[i]);
		i++;
		}
		break;
		
		case 3:
		while(Str[i] != '\0')
		{
		UART_Write(3,Str[i]);
		i++;
		}	
		break;
		
		case 4:
		while(Str[i] != '\0')
		{
		UART_Write(4,Str[i]);
		i++;
		}
		break;
		
		case 5:
		while(Str[i] != '\0')
		{
		UART_Write(5,Str[i]);
		i++;
		}	
		break;
		
		case 6:
		while(Str[i] != '\0')
		{
		UART_Write(6,Str[i]);
		i++;
		}
		break;
		
		case 7:
		while(Str[i] != '\0')
		{
		UART_Write(7,Str[i]);
		i++;
		}	
		break;
	}
}