/*
 * HSTP_Program.c
 *
 *  Created on: Sep 1, 2022
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
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

#include "HSTP_Config.h"
#include "HSTP_Interface.h"


/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/


void HSTP_voidSendData(u8 Copy_u8DataToSend)
{
	u8 LOC_u8Bit = 0 ;
	s8 i  ;

	for(i = 7 ; i >= 0 ; i--)
	{
		/*Send bit by starting  MSB first*/
		LOC_u8Bit = GET_BIT(Copy_u8DataToSend,i) ;
		MGPIO_voidSetPinValue(HSTP_DATA_LINE,LOC_u8Bit);
		/*Send Pulse to Shift Clock*/
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLK,MGPIO_HIGH);
		MSTK_voidDelayUs(10) ;
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLK,MGPIO_LOW);
		MSTK_voidDelayUs(10) ;
	}

	/*Send Pulse to Storage Clock*/
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLK,MGPIO_HIGH);
	MSTK_voidDelayUs(10) ;
	MGPIO_voidSetPinValue(HSTP_STORAGE_CLK,MGPIO_LOW);
	MSTK_voidDelayUs(10) ;
}

