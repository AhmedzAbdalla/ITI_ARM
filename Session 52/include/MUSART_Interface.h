/*
 * MUSART_Interface.h
 *
 *  Created on: Sep 4, 2022
 *      Author: ahmed.hammad
 */

#ifndef MUSART_INTERFACE_H_
#define MUSART_INTERFACE_H_

void MUSART_voidInit(void) ;

void MUSART_voidSendData(u8* copy_u8Data,u8 Copy_u8Len);

u8 MUSART_u8ReadData(void) ;

void MUSART_voidEnable(void) ;

void MUSART_voidDisable(void) ;

void MUSART_voidCallBack(void(*Fptr)(void)) ;


#endif /* MUSART_INTERFACE_H_ */
