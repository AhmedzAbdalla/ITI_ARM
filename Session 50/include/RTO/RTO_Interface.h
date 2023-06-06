/*
 * RTO_Interface.h
 *
 *  Created on: MAY 24, 2023
 *      Author: Ahmed Abdalla
 */
#ifndef RTO_INTERFACE_H
#define RTO_INTERFACE_H


typedef struct
{
	u32 First_Delay;
	u32 Periodcicity;
	void (*pf) (void);
}RTO_TCB_T;


void RTO_init(void);

u8 RTO_Create_Task(RTO_TCB_T * my_task , u8 Copy_u8_Priority);


#endif //RTO_INTERFACE_H
