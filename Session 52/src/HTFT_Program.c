/*
 * HTFT_Program.c
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
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"
#include "MSPI_Interface.h"


/*******************************************************************************************************/
/*                                      HAL Components                                                */
/*******************************************************************************************************/
#include "HTFT_Interface.h"
#include "HTFT_Config.h"
#include "HTFT_Private.h"





/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

void HTFT_voidInit(void)
{
	/*Rest Pulse*/
	MGPIO_voidSetPinValue(HTFT_RST_PIN,MGPIO_HIGH ) ;
	MSTK_voidDelayMs(100) ;
	MGPIO_voidSetPinValue(HTFT_RST_PIN,MGPIO_LOW) ;
	MSTK_voidDelayMs(1) ;
	MGPIO_voidSetPinValue(HTFT_RST_PIN,MGPIO_HIGH ) ;
	MSTK_voidDelayMs(100) ;
	MGPIO_voidSetPinValue(HTFT_RST_PIN,MGPIO_LOW) ;
	MSTK_voidDelayMs(100) ;
	MGPIO_voidSetPinValue(HTFT_RST_PIN,MGPIO_HIGH ) ;
	MSTK_voidDelayMs(120) ;

	/*Send Command Sleep Out*/
	HTFT_voidWriteCommand(0x11) ;

	/*wait 150 ms*/
	MSTK_voidDelayMs(150) ;

	/*color mode Command*/
	HTFT_voidWriteCommand(0x3A) ;
	HTFT_voidWriteData(0x05) ; //RGB565

	/*Display Command*/
	HTFT_voidWriteCommand(0x29) ;
}

void HTFT_voidDisplayImage(const u16* Copy_ptrImage)
{
	u16 counter ;
	u8 Data ;
	/*Set X Address*/
	HTFT_voidWriteCommand(0x2A) ;
	/*start*/
	HTFT_voidWriteData(0) ;
	HTFT_voidWriteData(0) ;
	/*stop*/
	HTFT_voidWriteData(0) ;
	HTFT_voidWriteData(127) ;

	/*Set y Address*/
	HTFT_voidWriteCommand(0x2B) ;
	/*start*/
	HTFT_voidWriteData(0) ;
	HTFT_voidWriteData(0) ;
	/*stop*/
	HTFT_voidWriteData(0) ;
	HTFT_voidWriteData(159) ;

	/*RAM Write Command*/
	HTFT_voidWriteCommand(0x2C) ;
	/*Display Image*/
	for(counter = 0 ; counter < 20480 ; counter++)
	{
		Data  = Copy_ptrImage[counter] >> 8 ;
		/*write for high byte -->MSB*/
		HTFT_voidWriteData(Data) ;

		Data  = Copy_ptrImage[counter] & 0x00FF ;
		/*write for high Low*/
		HTFT_voidWriteData(Data) ;
	}

}


static void  HTFT_voidWriteCommand(u8 Copy_u8Comand)
{
	/*Set Pin A0 in TFT to Low*/
	MGPIO_voidSetPinValue(HTFT_A0_PIN,MGPIO_LOW) ;
	/*Send Data over SPI*/
	MSPI_u8SendReceive(Copy_u8Comand) ;

}


static void  HTFT_voidWriteData(u8 Copy_u8Data)
{

	/*Set Pin A0 in TFT to HIGH*/
	MGPIO_voidSetPinValue(HTFT_A0_PIN,MGPIO_HIGH) ;
	/*Send Data over SPI*/
	MSPI_u8SendReceive(Copy_u8Data) ;


}


