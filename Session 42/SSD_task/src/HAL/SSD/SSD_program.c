/*
 * 7_segment.h
 *
 *  Created on: Mar 27, 2023
 *  Author       : Ahmed Abdalla
 */

/********************Includes********************/
#include  "../../include/LIB/STD_Types.h"
#include  "../../include/LIB/BIT_MATH.h"



#include "../../include/HAL/SSD/SSD_Interface.h"
#include "../../include/HAL/SSD/SSD_cfg.h"

#include "../../include/MCAL/GPIO/GPIO_Config.h"

void SSD_void_Initialize()
{
	//configuring pins as output
	GPIO_void_Set_Pin_Mode( DATA_PORT , DATA_BIT0 , OUTPUT);
	GPIO_void_Set_Pin_Mode( DATA_PORT , DATA_BIT1 , OUTPUT);
	GPIO_void_Set_Pin_Mode( DATA_PORT , DATA_BIT2 , OUTPUT);
	GPIO_void_Set_Pin_Mode( DATA_PORT , DATA_BIT3 , OUTPUT);

	//configuring pins as push pull
	GPIO_void_Set_Pin_Type(DATA_PORT , DATA_BIT0 , push_pull);
	GPIO_void_Set_Pin_Type(DATA_PORT , DATA_BIT1 , push_pull);
	GPIO_void_Set_Pin_Type(DATA_PORT , DATA_BIT2 , push_pull);
	GPIO_void_Set_Pin_Type(DATA_PORT , DATA_BIT3 , push_pull);

	//configuring pins output speed
//	GPIO_void_Set_Pin_Speed(DATA_PORT , DATA_BIT0 , High_speed);
//	GPIO_void_Set_Pin_Speed(DATA_PORT , DATA_BIT1 , High_speed);
//	GPIO_void_Set_Pin_Speed(DATA_PORT , DATA_BIT2 , High_speed);
//	GPIO_void_Set_Pin_Speed(DATA_PORT , DATA_BIT3 , High_speed);

}


void SSD_void_write(const u8 Copy_u8val)
{
	GPIO_void_Set_Pin_Value_Atomic(DATA_PORT , DATA_BIT0 , Copy_u8val & 0x01);
	GPIO_void_Set_Pin_Value_Atomic(DATA_PORT , DATA_BIT1 , (Copy_u8val >> 1) & 0x01);
	GPIO_void_Set_Pin_Value_Atomic(DATA_PORT , DATA_BIT2 , (Copy_u8val >> 2) & 0x01);
	GPIO_void_Set_Pin_Value_Atomic(DATA_PORT , DATA_BIT3 , (Copy_u8val >> 3) & 0x01);
}

