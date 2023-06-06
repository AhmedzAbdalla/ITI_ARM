#include "../include/LIB/STD_Types.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/RCC/RCC_Private.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/SYS_TICK/SYS_TICK_Interface.h"
#include "../include/MCAL/NVIC/NVIC_Interface.h"

void app_init(void);

//#define GPIOA_MODER		*((volatile u32*)0x40020000)
#define GPIOA_ODR		*((volatile u32*)0x40020014)

void App_delayMs(u32 Copy_u32Delay);

int main()
{
	app_init();


	RCC_void_Enable_Peripheral_Clk(AHB1, RCC_AHB1ENR_GPIOAEN);
	RCC_void_Enable_Peripheral_Clk(AHB1, RCC_AHB1ENR_GPIOBEN);


	//output pins
	GPIO_void_Set_Pin_Mode(GPIOA ,  PIN_13 , OUTPUT);
	GPIO_void_Set_Pin_Type(GPIOA ,  PIN_13  , push_pull);
	GPIO_void_Set_Pin_Speed(GPIOA , PIN_13 , High_speed);
	//GPIO_void_Set_Pin_Value_Atomic(GPIOA , PIN_15 , SET);

	GPIO_void_Set_Pin_Mode(GPIOB , PIN_15 , OUTPUT);
	GPIO_void_Set_Pin_Type(GPIOB , PIN_15  , push_pull);
	GPIO_void_Set_Pin_Speed(GPIOB , PIN_15 , High_speed);
	//GPIO_void_Set_Pin_Value_Atomic(GPIOB , PIN_15 , SET);

	//input pins
	//GPIO_void_Set_Pin_Mode(GPIOB ,  PIN_3 , INPUT);
	//GPIO_void_Set_Pin_Pull_State(GPIOB ,  PIN_3 , PULL_UP);


	//GPIO_void_Set_Pin_Mode(GPIOA ,  PIN_3 , INPUT);
	//GPIO_void_Set_Pin_Pull_State(GPIOA ,  PIN_3 , FLOATING);
	//SET_BIT(GPIOA_MODER, 2);

  // Infinite loop
  while (1)
    {
       // Add your code here.
	  //CLR_BIT(GPIOA_ODR, 1);

	  NVIC_void_Set_pending_Flag(6);



	  //App_delayMs(10000);
	  //SET_BIT(GPIOA_ODR, 1);

	  //App_delayMs(10000);
    }



  return 0;
}

void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay*300; Local_u32Counter++)
	{
		asm("NOP");
	}
}

void app_init(void)
{
	RCC_void_Init_Sys_Clk();
	SYS_TICK_void_Init();

	NVIC_void_Enable_PerInt(6);
}

EXTI0_IRQHandler()
{
	  GPIO_void_Set_Pin_Value_Atomic(GPIOA , PIN_13 , SET);
	  GPIO_void_Set_Pin_Value_Atomic(GPIOB , PIN_15 , SET);

	  SYS_TICK_void_Set_Busy_Wait(95500);

	  GPIO_void_Set_Pin_Value_Atomic(GPIOA , PIN_13 , RST);
	  	 GPIO_void_Set_Pin_Value_Atomic(GPIOB , PIN_15 , RST);

	  	SYS_TICK_void_Set_Busy_Wait(555500);
}
