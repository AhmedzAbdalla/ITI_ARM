/*
 * Dot_Matrix_Program.c
 *
 *  Created on: May 23, 2023
 *  Author       : Ahmed Abdalla
 */


/*Standard Libraries include*/
#include  "../../include/LIB/STD_Types.h"
#include  "../../include/LIB/BIT_MATH.h"


/*HAL Includes*/
#include "../../include/HAL/Dot_Matrix/Dot_Matrix_Interface.h"
#include "../../include/HAL/Dot_Matrix/Dot_Matrix_cfg.h"
#include "../../include/HAL/Dot_Matrix/Dot_Matrix_Private.h"

/*MCAL Includes*/
#include "../../include/MCAL/GPIO/GPIO_Interface.h"


void Dot_Matrix_void_Init(void)
{
    //configuring output pins for Rows
	for(u8 l_u8_counter = ROWS_R0 ; l_u8_counter <= ROWS_R7 ; l_u8_counter++)
	{
        //Configuring pins as output
		GPIO_void_Set_Pin_Mode(ROW_PORT , l_u8_counter , OUTPUT);
        //Configuring pins as output push pull
		GPIO_void_Set_Pin_Type(ROW_PORT , l_u8_counter , push_pull);
        //Configuring output pins Speed
		GPIO_void_Set_Pin_Speed(ROW_PORT , l_u8_counter , Medium_speed );
	}

    //configuring output pins for Columns
    for(u8 l_u8_counter = COLUMNS_C0 ; l_u8_counter <= COLUMNS_C7 ; l_u8_counter++)
	{
        //Configuring pins as output
		GPIO_void_Set_Pin_Mode(COLUMN_PORT , l_u8_counter , OUTPUT);
        //Configuring pins as output push pull
		GPIO_void_Set_Pin_Type(COLUMN_PORT , l_u8_counter , push_pull);
        //Configuring output pins Speed
		GPIO_void_Set_Pin_Speed(COLUMN_PORT , l_u8_counter , Medium_speed );
	}

}

void Dot_Matrix_void_Display(u8 *Ref_u8_char)
{
    for(u8 l_u8_counter = 0 ; l_u8_counter < DOT_MATRIX_NO_OF_COLUMNS ; l_u8_counter++)
	{
        // Disable All Columns
        Dot_Matrix_void_Col_disable();

        //Write value to Rows
        Dot_Matrix_void_Set_Row_Val(*(Ref_u8_char + l_u8_counter));

        //Activating the column
        GPIO_void_Set_Pin_Value_Atomic(COLUMN_PORT , l_u8_counter , RST );

        // delay
        for(u32 Local_u32Counter = 0; Local_u32Counter < 5000; Local_u32Counter++)
	    {
	    	asm("NOP");
	    }
	}
}


void Dot_Matrix_void_Display_sliding(u8 *Ref_u8_char)
{

    for(s8 l_u8_counter_1 = 88  ; l_u8_counter_1 >0 ; l_u8_counter_1--)
    {
        for(u8 l_u8_counter_2 = 0 ; l_u8_counter_2 < 10 ; l_u8_counter_2++)
        {
            u8 c = 0;
            for(u8 l_u8_counter = 0 ; l_u8_counter < 88 ; l_u8_counter++)
	        {
                c = l_u8_counter;
                if(c == 8)
                {
                    c = 0;
                }
                // Disable All Columns
                Dot_Matrix_void_Col_disable();

                //Write value to Rows
                Dot_Matrix_void_Set_Row_Val(*(Ref_u8_char + l_u8_counter ));

                //Activating the column
                GPIO_void_Set_Pin_Value_Atomic(COLUMN_PORT , (c + (l_u8_counter_1 - 72 ) - 8 ) , RST ); //(c + (l_u8_counter_1 - 16 ) - 8 )

                // delay
                for(u32 Local_u32Counter = 0; Local_u32Counter < 3500; Local_u32Counter++)
	            {
	            	asm("NOP");
	            }
	        }
        }
    }

}





//===================================================================
static void Dot_Matrix_void_Col_disable(void)
{
    for(u8 l_u8_counter = COLUMNS_C0 ; l_u8_counter <= COLUMNS_C7 ; l_u8_counter++)
	{
        GPIO_void_Set_Pin_Value_Atomic(COLUMN_PORT , l_u8_counter , SET );
	}
}


static void Dot_Matrix_void_Set_Row_Val(u8 Copy_u8_Row_Val)
{
    for(u8 l_u8_counter = COLUMNS_C0 ; l_u8_counter <= COLUMNS_C7 ; l_u8_counter++)
	{
        GPIO_void_Set_Pin_Value_Atomic(ROW_PORT , l_u8_counter , (Copy_u8_Row_Val >> l_u8_counter) & 0x01 );
	}
}
