#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_Types.h"


#include "../../include/MCAL/SYS_TICK/SYS_TICK_Config.h"
#include "../../include/MCAL/SYS_TICK/SYS_TICK_Private.h"
#include "../../include/MCAL/SYS_TICK/SYS_TICK_Interface.h"

static void (*SYS_TICK_CallBack)(void);

static u8 SYS_TICK_Interval_Mode = 0;

void SYS_TICK_void_Init(void)
{
    #if CLK_SOURCE == AHB_8_CLOCK
        CLR_BIT(STK_CTRL_reg , STK_CTRL_CLKSOURCE);
    #elif CLK_SOURCE == AHB_CLOCK
        SET_BIT(STK_CTRL_reg , STK_CTRL_CLKSOURCE);
    #endif
}
void SYS_TICK_void_Set_Busy_Wait(u32 Copy_u32_Ticks)
{
    /*Load register value */
    STK_LOAD_reg = Copy_u32_Ticks;

    /*Enable SYS TICK*/
    SET_BIT(STK_CTRL_reg , STK_CTRL_ENABLE);

    //polling until the COUNTFLAG is raised
    while (READ_BIT(STK_CTRL_reg , STK_CTRL_COUNTFLAG) == 0);
    
    /*Disable SYS TICK*/
    CLR_BIT(STK_CTRL_reg , STK_CTRL_ENABLE);

    /*clear the load register*/
    STK_LOAD_reg = 0;

    /*clear the value register*/
    STK_VAL_reg = 0;

}
void SYS_TICK_void_Set_Interval_Single(u32 Copy_u32_Ticks , void (*Copy_ptr)(void))
{
    //disable SYS_TICK
    CLR_BIT(STK_CTRL_reg , STK_CTRL_ENABLE);

    /*clear the load register*/
    STK_LOAD_reg = 0;

    /*Load register value */
    STK_LOAD_reg = Copy_u32_Ticks;

    /*Enable SYS TICK*/
    SET_BIT(STK_CTRL_reg , STK_CTRL_ENABLE);

    //set inrerval mode
    SYS_TICK_Interval_Mode = STK_CTRL_SINGLE_INTERVAL;

    //set Call Back
    SYS_TICK_CallBack = Copy_ptr;

    //Enable SYS_TICK Interrupt
    SET_BIT(STK_CTRL_reg , STK_CTRL_TICKINT);

}
void SYS_TICK_void_Set_Interval_Periodic(u32 Copy_u32_Ticks , void (*Copy_ptr)(void))
{
    /*Datasheet:
    The RELOAD value can be any value in the range 0x00000001-0x00FFFFFF. A start value of 
    0 is possible, but has no effect because the SysTick exception request and COUNTFLAG are 
    activated when counting from 1 to 0.
    */
    /*Load register value */
    STK_LOAD_reg = Copy_u32_Ticks;

    /*Enable SYS TICK*/
    SET_BIT(STK_CTRL_reg , STK_CTRL_ENABLE);

    //set inrerval mode
    SYS_TICK_Interval_Mode = STK_CTRL_PERIODIC_INTERVAL;

    //set Call Back
    SYS_TICK_CallBack = Copy_ptr;

    //Enable SYS_TICK Interrupt
    SET_BIT(STK_CTRL_reg , STK_CTRL_TICKINT);
}


u32 SYS_TICK_u32_Get_Elapsed_Time(void)
{
    return STK_LOAD_reg - STK_VAL_reg;
}
u32 SYS_TICK_u32_Get_Remaining_Time(void)
{
    return STK_VAL_reg;
}

void SysTick_Handler(void)
{
    //used to read STK_CTRL_COUNTFLAG bit to clear it
    u8 Local_u8_Temp = 0;

    if(SYS_TICK_Interval_Mode == STK_CTRL_SINGLE_INTERVAL)
    {
        ////disable SYS_TICK
        CLR_BIT(STK_CTRL_reg , STK_CTRL_ENABLE);

        /*clear the load register*/
        STK_LOAD_reg = 0;

        /*clear the value register*/
        STK_VAL_reg = 0;
    }

    //callback function
    SYS_TICK_CallBack();

    //clear STK_CTRL_COUNTFLAG by reading it
    Local_u8_Temp = READ_BIT(STK_CTRL_reg , STK_CTRL_COUNTFLAG);
}
