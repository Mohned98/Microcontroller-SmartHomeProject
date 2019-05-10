/******************************************************************************
 *
 * Module: TS
 *
 * File Name: TS.h
 *
 * Description: Header file for the TS driver
 *
 *******************************************************************************/

#ifndef TS_H_
#define TS_H_

#include "DIO.h"
#include "SysTick.h"
#include "ADC.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LM35TS_init(UARTNUM uartnum);
float LM35TS_READ(UARTNUM uartnum); 

#endif /* TS_H_ */
