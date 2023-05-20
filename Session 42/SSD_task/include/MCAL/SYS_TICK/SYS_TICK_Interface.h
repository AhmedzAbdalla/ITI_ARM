#ifndef SYS_TICK_INTERFACE_H
#define SYS_TICK_INTERFACE_H

void SYS_TICK_void_Init(void);
void SYS_TICK_void_Set_Busy_Wait(u32 Copy_u32_Ticks);
void SYS_TICK_void_Set_Interval_Single(u32 Copy_u32_Ticks , void (*Copy_ptr)(void));
void SYS_TICK_void_Set_Interval_Periodic(u32 Copy_u32_Ticks , void (*Copy_ptr)(void));
u32 SYS_TICK_u32_Get_Elapsed_Time(void);
u32 SYS_TICK_u32_Get_Remaining_Time(void);

#endif //SYS_TICK_INTERFACE_H
