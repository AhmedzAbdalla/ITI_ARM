#include "../include/LIB/STD_Types.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/RCC/RCC_Private.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/SYS_TICK/SYS_TICK_Interface.h"
#include "../include/MCAL/NVIC/NVIC_Interface.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"

#include "../include/HAL/SSD/SSD_Interface.h"
#include "../include/HAL/Dot_Matrix/Dot_Matrix_Interface.h"

void App_delayMs(u32 Copy_u32Delay);
void app_init(void);
/*
u8 GLOB_u8DataArr[88] = {

		0, 124, 18, 18, 18, 124, // A
				0, 126, 72, 72, 48,  //b
				0, 0, 48, 72, 72, 127, 0, 0, //d
				48, 72, 72, 240, 128,//a
				0, 126, 128, 0, 126, 128, 0, 0, //ll
				48, 72, 72, 240, 128, 0, 0, 0,//a
		//=========

		0, 124, 18, 18, 18, 124, 0, 0, // A
		0, 126, 8, 8, 120, 0,  //h
		4, 120, 8, 120, 8, 8, 120, 0, //m
		60, 82, 146, 12, // e
		0, 0, 48, 72, 72, 127, //d


};
*/

 u8 GLOB_u8DataArr[88] = {

		 0, 124, 18, 18, 18, 124, 0, 0, // A
		0, 126, 8, 8, 120, 0, 0, 0, //h
		4, 120, 8, 120, 8, 8, 120, 0, //m
		60, 82, 146, 12, 0, 0, 0, 0, // e
		0, 0, 48, 72, 72, 127, 0, 0, //d
		//==================================
			0, 124, 18, 18, 18, 124, 0, 0, // A
			0, 126, 72, 72, 48, 0, 0, 0, //b
			0, 0, 48, 72, 72, 127, 0, 0, //d
			48, 72, 72, 240, 128, 0, 0, 0,//a
			0, 126, 128, 0, 126, 128, 0, 0, //ll
			48, 72, 72, 240, 128, 0, 0, 0,//a




};


int main()
{
	app_init();

  while (1)
    {

	  Dot_Matrix_void_Display_sliding(GLOB_u8DataArr);

	  //Dot_Matrix_void_Display_sliding(GLOB_u8DataArr_2);



    }



  return 0;
}



void app_init(void)
{
	RCC_void_Init_Sys_Clk();

	RCC_void_Enable_Peripheral_Clk( AHB1,  RCC_AHB1ENR_GPIOAEN);
	RCC_void_Enable_Peripheral_Clk( AHB1,  RCC_AHB1ENR_GPIOBEN);

	Dot_Matrix_void_Init();
	//SYS_TICK_void_Init();

	//NVIC_void_set_Priority_Config(NVIC_Priority_4G_4SG);
	//USART1 in group
	//NVIC_void_Set_Priority(37 , 3 , 2);


	//NVIC_void_Set_Priority(4, 1 , 0);


	//SSD_void_Initialize();
	//NVIC_void_Enable_PerInt(6);
	//NVIC_void_Enable_PerInt(37);

	//EXTI_void_EXTI_init();
}


void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay*300; Local_u32Counter++)
	{
		asm("NOP");
	}
}


