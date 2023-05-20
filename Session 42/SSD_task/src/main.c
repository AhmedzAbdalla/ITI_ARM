#include "../include/LIB/STD_Types.h"
#include "../include/LIB/BIT_MATH.h"


#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/MCAL/RCC/RCC_Private.h"
#include "../include/MCAL/GPIO/GPIO_Interface.h"
#include "../include/MCAL/SYS_TICK/SYS_TICK_Interface.h"
#include "../include/MCAL/NVIC/NVIC_Interface.h"

#include "../include/HAL/SSD/SSD_Interface.h"

void app_init(void);



int main()
{
	app_init();


	for(u8 i = 0 ; i< 10 ; i ++)
	{
		SSD_void_write(i);
		SYS_TICK_void_Set_Busy_Wait(10000000);
	}

  while (1)
    {

    }



  return 0;
}



void app_init(void)
{
	RCC_void_Init_Sys_Clk();

	RCC_void_Enable_Peripheral_Clk( AHB1,  RCC_AHB1ENR_GPIOAEN);

	SYS_TICK_void_Init();


	SSD_void_Initialize();
	//NVIC_void_Enable_PerInt(6);
}

