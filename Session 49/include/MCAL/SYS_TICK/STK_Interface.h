#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* Apply Clock choice from configuration file 
   Disable SysTick interrupt 
   Disable Systick                          */
void MSTK_void_Init(void);
void MSTK_void_Set_Busy_Wait( u32 Copy_u32Ticks );
void MSTK_void_Set_Interval_Single  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_void_Set_Interval_Periodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_void_Stop_Interval(void);
u32  MSTK_u32_Get_Elapsed_Time(void);
u32  MSTK_u32_Get_Remaining_Time(void);

#endif
