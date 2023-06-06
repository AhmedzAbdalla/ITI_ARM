/*
 * MDMA_Program.c
 *
 *  Created on: Sep 5, 2022
 *      Author: ahmed.hammad
 */




/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "MDMA_Interface.h"
#include "MDMA_Private.h"
#include "MDMA_Config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/


static void (*MDMA_CAllBackPtr)(void) = NULL ;

/*DMA Init */
void MDMA_voidInit(u8 Copy_u8StremId)
{


	/*Step1 : Befor Any Configuration The Bit OF EN must be = 0 */
	/*If Enable Bit = 1*/
	if((GET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,0)) == 1)
	{
		/*Disable it */
		CLR_BIT(MDMA2->STREAM[Copy_u8StremId].CR,0) ;
	}
	else {/*Do Nothing For Misra*/}

	/*Step 2 : Select The Channel(Used for Connect Peripherial To memory) In Stream but From M2M Not Used*/


	/*Step 3 : Set SoftWare Priority Stream : {LOW - Meduim - High - Very High} Bit (16 , 17) --> very High*/

	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,16);
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,17);

	/*Step 4 : Set DIR Mode : {(MTM) , (PTM), (MTP)} --> BIT(6,7)  -->DIR [MTM -->(0,1)]*/
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,7);
	CLR_BIT(MDMA2->STREAM[Copy_u8StremId].CR,6);

	/*Step 5 : Select Circular Mode  BIT(8) */
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,8);

	/*Step 6 : Set Source Size and Destination Size for Elements : {Byte - HalfWord - Word}*/

	/*As word 32 for source  as Memory*/
	CLR_BIT(MDMA2->STREAM[Copy_u8StremId].CR,11);
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,12);

	/*As word 32 for Destination as memory*/
	CLR_BIT(MDMA2->STREAM[Copy_u8StremId].CR,13);
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,14);

    /*Step 7 : Disable Direct Mode*/
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].FCR,2);

	/*Step 8 : Set Threshold (1/4),(1/2),(3/4),(4/4)}*/
	/*Use Full*/
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].FCR,0);
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].FCR,0);

	/*Step 8 : SRC & DIS Increament for Both*/
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,9);
	SET_BIT(MDMA2->STREAM[Copy_u8StremId].CR,10);

	/*Step 9 : Enable Interrupt of Transfer Complete*/
	MDMA2->STREAM[Copy_u8StremId].CR |= (1<<4U) ;

}


void MDMA_voidStreamEnable(u8 Copy_u8StreamId)
{
	/*All Flags Clear*/
	MDMA_voidClearFlagChannel0()  ;
	/*Enable Stream 0*/
	SET_BIT(MDMA2->STREAM[Copy_u8StreamId].CR,0);
}

/*SET Address*/
void MDMA_voidSetAddress(u32 *Copy_u32SrcAddress,u32 *Copy_u32DestAddress,u32 Copy_u32Length,u8 Copy_u8StreamId)
{

MDMA2->STREAM[Copy_u8StreamId].PAR  = (u32)  Copy_u32SrcAddress  ;
MDMA2->STREAM[Copy_u8StreamId].M0AR = (u32)  Copy_u32DestAddress ;
MDMA2->STREAM[Copy_u8StreamId].NDTR =  Copy_u32Length;

}


/*Function To Clear Flag For Channel*/
void MDMA_voidClearFlagChannel0(void)
{
	/*Must Be clear The Flag Transfer Complete= 5 -->Bit[4]*/
  MDMA2->LIFCR |=((1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5)) ;        //   0x0000003D
}



/*Call Back Function for DMA*/
void MDMA_voidCallBack(void(*Fptr)(void))
{
	MDMA_CAllBackPtr = Fptr ;
	/*Clear Flags*/
}


/*DMA2 Stream 0 -->Handler*/
void DMA2_Stream0_IRQHandler(void)
{
	MDMA_CAllBackPtr() ;
	/*Clear Flags*/
}


