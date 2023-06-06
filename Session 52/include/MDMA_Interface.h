/*
 * MDMA_Interface.h
 *
 *  Created on: Sep 5, 2022
 *      Author: ahmed.hammad
 */

#ifndef MDMA_INTERFACE_H_
#define MDMA_INTERFACE_H_


/*DMA Init */
void MDMA_voidInit(u8 Copy_u8StremId);

/*SET Address*/
void MDMA_voidSetAddress(u32 *Copy_u32SrcAddress,u32 *Copy_u32DestAddress,u32 Copy_u32Length,u8 Copy_u8StreamId);

/*Enable DMA STREAM*/
void MDMA_voidStreamEnable(u8 Copy_u8StreamId);

/*CALL BACK*/
void MDMA_voidCallBack(void(*Fptr)(void)) ;

/*Function To Clear Flag For Channel*/
void MDMA_voidClearFlagChannel0(void);

#endif /* MDMA_INTERFACE_H_ */
