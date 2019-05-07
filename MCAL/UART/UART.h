#ifndef __UART_H__
#define	__UART_H__

#include "MACROS.h"
#include "STANDARD_TYPES.h"
#include "SysTick.h"
#include "tm4c123gh6pm.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/*Macros for UART initialization*/
#define boudRateDivider  16
#define Clk  80000000 
#define BAUDRATE(BaudRate) (Clk / (BaudRate*boudRateDivider)) 

/*Macros for reading using interrupts*/
#define Read_from_uart0 (uint8)(UART0_DR_R&0xFF)
#define Read_from_uart1 (uint8)(UART1_DR_R&0xFF)
#define Read_from_uart2 (uint8)(UART2_DR_R&0xFF)
#define Read_from_uart3 (uint8)(UART3_DR_R&0xFF)
#define Read_from_uart4 (uint8)(UART4_DR_R&0xFF)
#define Read_from_uart5 (uint8)(UART5_DR_R&0xFF)
#define Read_from_uart6 (uint8)(UART6_DR_R&0xFF)
#define Read_from_uart7 (uint8)(UART7_DR_R&0xFF)

//useful enums
typedef enum {
 uart0,uart1,uart2,uart3,uart4,uart5,uart6,uart7
} UARTNUM;

typedef enum {
 Parity_OFF , Parity_ON
} PARITY;

typedef enum {
 Interrupt_OFF , Interrupt_ON
} INTERRUPT;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void UART_Init(UARTNUM UartNum , uint32 BaudRate , PARITY Parity , INTERRUPT interrupt );

uint8 UART_Available(UARTNUM UartNum);

uint8 UART_Read(UARTNUM UartNum);

void UART_Write(UARTNUM UartNum,uint8 data);

void UART_Print (UARTNUM UartNum,const char *Str);

#endif // __UART_H__

