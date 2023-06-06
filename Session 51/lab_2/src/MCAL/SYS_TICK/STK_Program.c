#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_Types.h"

#include "../../include/MCAL/SYS_TICK/STK_Config.h"
#include "../../include/MCAL/SYS_TICK/STK_Private.h"
#include "../../include/MCAL/SYS_TICK/STK_Interface.h"


/* Define Callback Global Variable */
static void (*MSTK_CallBack) (void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_void_Init(void)
{
	#if MSTK_CLK_SRC == MSTK_SRC_AHB
	    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
		MSTK -> CTRL = 0x00000004;
	#else
	    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
		MSTK -> CTRL = 0;
	#endif


}

void MSTK_void_Set_Busy_Wait( u32 Copy_u32Ticks )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	
	/* Wait till flag is raised */
	while( (READ_BIT(MSTK->CTRL,16)) == 0);
	
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

void MSTK_void_Set_Interval_Single  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*Disable Timer*/
	CLR_BIT(MSTK -> CTRL,0);
	MSTK -> VAL = 0;

	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
}

void MSTK_void_Set_Interval_Periodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*Disable Timer*/
	CLR_BIT(MSTK -> CTRL,0);
	MSTK -> VAL = 0;

	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks ;
	

	/* Save CallBack */
	if(NULL != Copy_ptr)
	{
		MSTK_CallBack = Copy_ptr;
	}
	
	/* Set Mode to Periodic */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	
	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);

	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
}

void MSTK_void_Stop_Interval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL, 1);
	
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

u32  MSTK_u32_Get_Elapsed_Time(void)
{
	u32 Local_u32ElapsedTime;
	
	Local_u32ElapsedTime = (MSTK -> LOAD) - (MSTK -> VAL) ;
	
	return Local_u32ElapsedTime;
}

u32  MSTK_u32_Get_Remaining_Time(void)
{
	u32 Local_u32RemainTime;
	
	Local_u32RemainTime = (MSTK -> VAL) ;
	
	return Local_u32RemainTime;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary=0;
	
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK->CTRL, 1);
		/* Stop Timer */
		CLR_BIT(MSTK->CTRL, 0);
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}
	
	/* Callback notification */

	MSTK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = READ_BIT(MSTK->CTRL,16);
}
