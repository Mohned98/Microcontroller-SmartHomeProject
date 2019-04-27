#ifndef __UART_H__
#define	__UART_H__


#define boudRateDivider = 16
#define Clk = 80000000 
#define BAUDRATE(BaudRate) (Clk / (BaudRate*boudRateDivider)) 


typedef enum {
 uart0,uart1,uart2,uart3,uart4,uart5,uart6,uart7
} UARTNUM;


typedef enum {
 OFF , ON
} PARITY;


typedef enum {
 OFF , ON
} INTERRUPT;


void UART_Init(UARTNUM UartNum , uint32 BaudRate , PARITY Parity , INTERRUPT interrupt );


uint8 UART_Available(UARTNUM UartNum);


uint8 UART_Read(UARTNUM UartNum);


void UART_Write(UARTNUM UartNum,uint8 data);

void UART_Print (UARTNUM UartNum,uint8 data)

#endif // __UART_H__

