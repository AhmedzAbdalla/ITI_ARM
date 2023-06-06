#include "../include/LIB/STD_Types.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/RCC/RCC_Private.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/SYS_TICK/STK_Interface.h"
#include "../include/MCAL/NVIC/NVIC_Interface.h"
#include "../include/MCAL/EXTI/EXTI_Interface.h"

#include "../include/RTO/RTO_Interface.h"



#include "../include/HAL/SSD/SSD_Interface.h"
#include "../include/HAL/Dot_Matrix/Dot_Matrix_Interface.h"

void App_delayMs(u32 Copy_u32Delay);
void app_init(void);


void task_1(void);
void task_2(void);
void task_3(void);

RTO_TCB_T t1 = {.First_Delay = 1,
				.Periodcicity = 2000,
				.pf = &task_3
};
RTO_TCB_T t2 = {.First_Delay =2,
				.Periodcicity = 5000,
				.pf = &task_2
};
RTO_TCB_T t3 = {.First_Delay = 0,
				.Periodcicity = 5000,
				.pf = &task_1
};



int main()
{
	RTO_Create_Task(&t1 , 1);
	RTO_Create_Task(&t2 , 2);
	RTO_Create_Task(&t3 , 0);

	app_init();

	//MSTK_void_Set_Interval_Periodic(2000000 , &task_1);
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


	for(u8 i = 0; i< 7 ; i++)
	{
		GPIO_void_Set_Pin_Mode(GPIOA , i, OUTPUT);
		GPIO_void_Set_Pin_Type(GPIOA , i,push_pull);
		GPIO_void_Set_Pin_Speed(GPIOA ,i , Medium_speed);
	}
	for(u8 i = 0; i< 7 ; i++)
		{
			GPIO_void_Set_Pin_Value_Atomic(GPIOA , i, RST);
		}

	RTO_init();


}


void App_delayMs(u32 Copy_u32Delay)
{
	for(u32 Local_u32Counter = 0; Local_u32Counter < Copy_u32Delay*300; Local_u32Counter++)
	{
		asm("NOP");
	}
}

void task_1(void)
{
	Toggle_BIT((*((volatile u32 *)(0x40020000 + 0X14))) , 0);

//	static u8 flag = 0;
//	if(flag ==0)
//	{
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 0, SET);
//		flag = 1;
//	}
//	else if(flag == 1)
//	{
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 0, RST);
//		flag = 0;
//	}


}
void task_2(void)
{
	Toggle_BIT((*((volatile u32 *)(0x40020000 + 0X14))) , 1);
	Toggle_BIT((*((volatile u32 *)(0x40020000 + 0X14))) , 2);

//	static u8 flag = 0;
//		if(flag ==0)
//		{
//			GPIO_void_Set_Pin_Value_Atomic(GPIOA , 1, SET);
//			GPIO_void_Set_Pin_Value_Atomic(GPIOA , 2, SET);
//
//			flag = 1;
//		}
//		else if(flag == 1)
//		{
//			GPIO_void_Set_Pin_Value_Atomic(GPIOA , 1, RST);
//			GPIO_void_Set_Pin_Value_Atomic(GPIOA , 2, RST);
//			//GPIO_void_Set_Pin_Value_Atomic(GPIOA , 6, SET);
//			flag = 0;
//		}
}
void task_3(void)
{
	Toggle_BIT((*((volatile u32 *)(0x40020000 + 0X14))) , 3);
	Toggle_BIT((*((volatile u32 *)(0x40020000 + 0X14))) , 4);
	Toggle_BIT((*((volatile u32 *)(0x40020000 + 0X14))) , 5);

//	static u8 flag = 1;
//	if(flag ==0)
//	{
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 3, RST);
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 4, RST);
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 5, RST);
//
//		flag = 1;
//	}
//	else if(flag == 1)
//	{
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 3, SET);
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 4, SET);
//		GPIO_void_Set_Pin_Value_Atomic(GPIOA , 5, SET);
//		flag = 0;
//	}
}


