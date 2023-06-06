/*
 * STP_Program.c
 *
 *  Created on: June 02, 2023
 *  Author       : Ahmed Abdalla
 */


/*Standard Libraries include*/
#include  "../../include/LIB/STD_Types.h"
#include  "../../include/LIB/BIT_MATH.h"


/*HAL Includes*/
#include "../../include/HAL/STP/STP_Interface.h"
#include "../../include/HAL/STP/STP_cfg.h"
#include "../../include/HAL/STP/STP_Private.h"

/*MCAL Includes*/
#include "../../include/MCAL/GPIO/GPIO_Interface.h"
#include "../../include/MCAL/SYS_TICK/STK_Interface.h"


void STP_void_init(void)
{
    GPIO_void_Set_Pin_Mode(GPIOA, PIN_0 , OUTPUT);
    GPIO_void_Set_Pin_Mode(GPIOA, PIN_1 , OUTPUT);
    GPIO_void_Set_Pin_Mode(GPIOA, PIN_2 , OUTPUT);

    GPIO_void_Set_Pin_Type(GPIOA, PIN_0 , push_pull);
    GPIO_void_Set_Pin_Type(GPIOA, PIN_1 , push_pull);
    GPIO_void_Set_Pin_Type(GPIOA, PIN_2 , push_pull);

    GPIO_void_Set_Pin_Speed(GPIOA, PIN_0 , High_speed);
    GPIO_void_Set_Pin_Speed(GPIOA, PIN_1 , High_speed);
    GPIO_void_Set_Pin_Speed(GPIOA, PIN_2 , High_speed);


}


void STP_void_Send_Synchronous(u8 Copy_to_be_sent)
{
    s8 l_u8_counter = 0;
    u8 l_u8_bit = 0;

    for(l_u8_counter = 7; l_u8_counter<=0 ; l_u8_counter++)
    {
        l_u8_bit = READ_BIT(Copy_to_be_sent , l_u8_counter);

        GPIO_void_Set_Pin_Value_Atomic(GPIOB , PIN_0 , l_u8_bit);

        GPIO_void_Set_Pin_Value_Atomic(GPIOA , PIN_2 , SET);
        MSTK_void_Set_Busy_Wait(1);
        GPIO_void_Set_Pin_Value_Atomic(GPIOA , PIN_2 , RST);
        MSTK_void_Set_Busy_Wait(1);

    }

    GPIO_void_Set_Pin_Value_Atomic(GPIOA , PIN_1 , SET);
        MSTK_void_Set_Busy_Wait(1);
        GPIO_void_Set_Pin_Value_Atomic(GPIOA , PIN_1 , RST);
        MSTK_void_Set_Busy_Wait(1);
}
