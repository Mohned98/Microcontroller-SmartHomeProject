/*
 * MACROS.h
 *
 * Created: 9/1/2018 5:26:23 PM
 *  Author: mohned
 */ 


#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(reg,bit)     reg|=(1<<bit)
#define CLEAR_BIT(reg,bit)   reg &=~(1<<bit)
#define TOGGLE_BIT(reg,bit)  (reg^=(1<<bit))
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))
#define IS_BIT_CLEAR(reg,bit)  !(reg&(1<<bit))




#endif /* MACROS_H_ */
