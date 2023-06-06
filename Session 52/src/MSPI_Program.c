/*
 * MSPI_Program.c
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

#include "MSPI_Interface.h"
#include "MSPI_Private.h"
#include "MSPI_Config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

static void (*MSPI1_CallBack)(void) = NULL  ;


void MSPI_voidInit(void)
{
  /*SPI Configuration
   * 1- Master Mode
   * 2- Clk Frequancy [bouad rate]
   * 3- CPOL = 1
   * 4- CPHA = 1
   * 5- MSB First
   * 6- Data Size
   * 6- SPI Enable
   * */
	MSPI1->CR1 = 0x0347 ;
}

u8 MSPI_u8SendReceive(u8 Copy_u8Data)
{

  /*Clear for Slave Select*/
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_LOW) ;
  /*Send Data*/
	MSPI1->DR = Copy_u8Data ;
  /*wait Busy flag to finish*/
	while(GET_BIT(MSPI1->SR,7)) ;
	/*Set for Slave Select*/
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_HIGH) ;
	/*return to data register*/
	return (u8)MSPI1->DR ;
}

void MSPI1_voidSetCallBack(void(*Fptr)(void))
{

   MSPI1_CallBack = Fptr ;

}


void SPI1_IRQHandler(void)
{

	MSPI1_CallBack() ;
}

