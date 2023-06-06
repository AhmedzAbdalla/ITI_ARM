/*
 * EXTI_Program.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Ahmed Abdalla
 */

#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_Types.h"

#include "../../include/MCAL/NVIC/NVIC_Interface.h"
#include "../../include/MCAL/RCC/RCC_Interface.h"

#include "../../include/MCAL/EXTI/EXTI_Interface.h"
#include "../../include/MCAL/EXTI/EXTI_Private.h"
#include "../../include/MCAL/EXTI/EXTI_Config.h"

static volatile u32* SYSCFG_EXTICRx[4] = { (u32*)0x40013804 ,(u32*)0x40013808 ,(u32*)0x4001380C ,(u32*)0x40013810 };
static u8 shift_amount = 0;

void EXTI_void_EXTI_init(void)
{
    //init NVIC , init RCC for syscfg,
    /*
    NVIC_void_Enable_PerInt(7);  //EXTI1
    NVIC_void_Enable_PerInt(6);  //EXTI0
    NVIC_void_Enable_PerInt(8);  //EXTI2
    NVIC_void_Enable_PerInt(9);  //EXTI3
    NVIC_void_Enable_PerInt(10); ////EXTI4 
    */
   RCC_void_Enable_Peripheral_Clk( 3 , 0x0E);
}

void EXTI_void_EXTIx_enable( EXTI_t * REF_EXTI_t_EXTI_X)
{
    if(NULL == REF_EXTI_t_EXTI_X)
    {
        /*Nothing*/
    }
    else
    {
        if(REF_EXTI_t_EXTI_X ->EXTI < 15 )
        {
            //configuring Maskability of EXTI
            switch (REF_EXTI_t_EXTI_X ->EXTI_MASK)
            {
                case 0: //Maskable
                    CLR_BIT(EXTI_IMR , REF_EXTI_t_EXTI_X ->EXTI);
                    break;
                case 1: // non Maskable
                    SET_BIT(EXTI_IMR , REF_EXTI_t_EXTI_X ->EXTI);
                    break;

                default:
                    break;
            }

            //configuring trigger selection
            switch (REF_EXTI_t_EXTI_X -> Trigger)
            {
                case 0: //RISING_EDGE
                    SET_BIT(EXTI_RTSR , REF_EXTI_t_EXTI_X -> EXTI);
                    CLR_BIT(EXTI_FTSR , REF_EXTI_t_EXTI_X -> EXTI);
                    break;
                case 1: //FALLING_EDGE
                    CLR_BIT(EXTI_RTSR , REF_EXTI_t_EXTI_X -> EXTI);
                    SET_BIT(EXTI_FTSR , REF_EXTI_t_EXTI_X -> EXTI);
                    break;
                case 2: //ON_CHANGE
                    SET_BIT(EXTI_RTSR , REF_EXTI_t_EXTI_X -> EXTI);
                    SET_BIT(EXTI_FTSR , REF_EXTI_t_EXTI_X -> EXTI);
                    break;

                default:
                    break;
            }

            //Configuring SYSCFG_EXTICRx
            if(((REF_EXTI_t_EXTI_X -> EXTI) == 0) || ((REF_EXTI_t_EXTI_X -> EXTI) == 4) ||((REF_EXTI_t_EXTI_X -> EXTI) == 8) ||((REF_EXTI_t_EXTI_X -> EXTI) == 12) )
            {
                shift_amount = 0;
            }
            else if(((REF_EXTI_t_EXTI_X -> EXTI) == 1) || ((REF_EXTI_t_EXTI_X -> EXTI) == 5) ||((REF_EXTI_t_EXTI_X -> EXTI) == 9) ||((REF_EXTI_t_EXTI_X -> EXTI) == 13))
            {
                shift_amount = 4 ;
            }
            else if(((REF_EXTI_t_EXTI_X -> EXTI) == 2) || ((REF_EXTI_t_EXTI_X -> EXTI) == 6) ||((REF_EXTI_t_EXTI_X -> EXTI) == 10) ||((REF_EXTI_t_EXTI_X -> EXTI) == 14))
            {
                shift_amount = 8;
            }
            else if(((REF_EXTI_t_EXTI_X -> EXTI) == 3) || ((REF_EXTI_t_EXTI_X -> EXTI) == 7) ||((REF_EXTI_t_EXTI_X -> EXTI) == 11) ||((REF_EXTI_t_EXTI_X -> EXTI) == 15))
            {
                shift_amount = 12;
            }

            //*(SYSCFG_EXTICRx[(u8)(REF_EXTI_t_EXTI_X -> EXTI) / 4]) = REF_EXTI_t_EXTI_X->EXTI_SRC_Port << shift_amount;
            *(u32*)0x40013804 = REF_EXTI_t_EXTI_X->EXTI_SRC_Port << shift_amount;

            //Configuring NVIC for EXTI
            if(REF_EXTI_t_EXTI_X -> EXTI < 5)
            {
                if(REF_EXTI_t_EXTI_X -> EXTI == 0)
                {
                    NVIC_void_Enable_PerInt(6);  //EXTI0
                }
                else if(REF_EXTI_t_EXTI_X -> EXTI == 1)
                {
                    NVIC_void_Enable_PerInt(7);  //EXTI1
                }
                else if(REF_EXTI_t_EXTI_X -> EXTI == 2)
                {
                    NVIC_void_Enable_PerInt(8);  //EXTI2
                }
                else if(REF_EXTI_t_EXTI_X -> EXTI == 3)
                {
                    NVIC_void_Enable_PerInt(9);  //EXTI3
                }
                else if(REF_EXTI_t_EXTI_X -> EXTI == 4)
                {
                    NVIC_void_Enable_PerInt(10);  //EXTI4
                }
                else
                {
                    /*Nothing*/
                }
                 
            }
            else if (( REF_EXTI_t_EXTI_X -> EXTI >= 5) && (REF_EXTI_t_EXTI_X -> EXTI <= 9))
            {
                NVIC_void_Enable_PerInt(23);  //EXTI5 : EXTI9
            }

            else if (( REF_EXTI_t_EXTI_X -> EXTI >= 10) && (REF_EXTI_t_EXTI_X -> EXTI <= 15))
            {
                NVIC_void_Enable_PerInt(40);  //EXTI10 : EXTI15
            }
            else
            {
                /*Nothing*/
            }
            
        }
        else
        {
            /*Nothing*/
            //NULL pointer
        }
    }

}


