#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MSPI_Interface.h"
#include "HTFT_Interface.h"
#include "image.h"


void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);

	/*Step 3 : Enable SPI1 Peripherial Clock */
	MRCC_voidEnablePeripheralClock(APB2,MRCC_PERIPHERAL_EN_SPI1);

	/*Step 4 : Set Pin Direction ->> Output [CS - RST - A0]*/
	for(u8 i = 0 ; i < 3 ; i++)
	{
		MGPIO_voidSetPinMode(MGPIOA_PORT,i,MGPIO_MODE_OUTPUT) ;
		/*Set Pin Speed*/
		MGPIO_voidSetOutputSpeed(MGPIOA_PORT,i,MGPIO_OUTPUT_SPEED_MEDUIM) ;
		/*Pull Output Type*/
		MGPIO_voidSetOutputType(MGPIOA_PORT,i,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	}


	/*Step 5 : Configure SPI PIN*/
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN5,MGPIO_MODE_ALTF) ;  // SPI1 serial clock
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN7,MGPIO_MODE_ALTF) ;  // SPI1 MOSI


	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN5,MGPIO_ALTFN_5) ;  // SPI1 serial clock
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN7,MGPIO_ALTFN_5) ;  // SPI1 MOSI


	/*Step 6 : init SPI */
	MSPI_voidInit() ;

	/*Step 7 : init TFT */
	HTFT_voidInit() ;


   /*Step 8 : Display Image*/
	HTFT_voidDisplayImage(image_arr) ;


	/* Loop forever */
	while(1)
	{

	}

}

