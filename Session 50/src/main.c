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

void App_delayMs(u32 Copy_u32Delay);

void play(void);
void app_init(void);

u32 counter = 0;

int main()
{


	app_init();

  while (1)
    {


    }



  return 0;
}



void app_init(void)
{
	RCC_void_Init_Sys_Clk();

	RCC_void_Enable_Peripheral_Clk( AHB1,  RCC_AHB1ENR_GPIOAEN);
	RCC_void_Enable_Peripheral_Clk( AHB1,  RCC_AHB1ENR_GPIOBEN);

	for(u8 i = 0; i<= 7 ; i++)
	{
		GPIO_void_Set_Pin_Mode(GPIOA , i, OUTPUT);
		GPIO_void_Set_Pin_Type(GPIOA , i,push_pull);
		GPIO_void_Set_Pin_Speed(GPIOA ,i , Medium_speed);
	}

	MSTK_void_Init();
	MSTK_void_Set_Interval_Periodic(250 ,&play );

}


void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay*300; Local_u32Counter++)
	{
		asm("NOP");
	}
}

void play(void)
{
	(*((volatile u32 *)(0x40020000 + 0X14))) = gaaani_raw[counter];
	counter++;

	if(counter == 45014)
	{
		counter = 0;
	}
}
