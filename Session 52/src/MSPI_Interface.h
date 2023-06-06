/*
 * MSPI_Interface.h
 *
 *  Created on: Sep 5, 2022
 *      Author: ahmed.hammad
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_


void MSPI_voidInit(void);

u8 MSPI_u8SendReceive(u8 Copy_u8Data) ;

void MSPI1_voidSetCallBack(void(*Fptr)(void)) ;

#endif /* MSPI_INTERFACE_H_ */
