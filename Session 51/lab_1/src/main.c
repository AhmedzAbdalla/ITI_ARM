#include "../include/LIB/STD_Types.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/RCC/RCC_Private.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/SYS_TICK/STK_Interface.h"
#include "../include/MCAL/NVIC/NVIC_Interface.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"

#include "gani_gani.h"
#include "gaaani.h"


#include "../include/RTO/RTO_Interface.h"



#include "../include/HAL/SSD/SSD_Interface.h"
#include "../include/HAL/Dot_Matrix/Dot_Matrix_Interface.h"
#include "../include/HAL/STP/STP_Interface.h"


void app_init(void);

int main()
{


	app_init();



  while (1)
    {

	  STP_void_Send_Synchronous(0x55);
	  MSTK_void_Set_Busy_Wait(2000000);
	  STP_void_Send_Synchronous(0x00);
	  MSTK_void_Set_Busy_Wait(2000000);
	  STP_void_Send_Synchronous(0xaa);
	  MSTK_void_Set_Busy_Wait(2000000);
	  STP_void_Send_Synchronous(0x00);
	  MSTK_void_Set_Busy_Wait(2000000);


    }



  return 0;
}



void app_init(void)
{
	RCC_void_Init_Sys_Clk();

	RCC_void_Enable_Peripheral_Clk( AHB1,  RCC_AHB1ENR_GPIOAEN);
	RCC_void_Enable_Peripheral_Clk( AHB1,  RCC_AHB1ENR_GPIOBEN);


	MSTK_void_Init();

	STP_void_init();
}


void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay*300; Local_u32Counter++)
	{
		asm("NOP");
	}
}


