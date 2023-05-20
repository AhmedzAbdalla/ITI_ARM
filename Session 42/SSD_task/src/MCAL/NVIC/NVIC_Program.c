#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_Types.h"


#include "../../include/MCAL/NVIC/NVIC_Config.h"
#include "../../include/MCAL/NVIC/NVIC_Private.h"
#include "../../include/MCAL/NVIC/NVIC_Interface.h"

static u8 Static_Global_u8_Priority_Config;

void NVIC_void_Enable_PerInt(u8 Copy_INT_ID)
{
    MY_NVIC->NVIC_ISERx[Copy_INT_ID / 32] =  1 << (Copy_INT_ID % 32);
} 
void NVIC_void_Disable_PerInt(u8 Copy_INT_ID)
{
    MY_NVIC->NVIC_ICERx[Copy_INT_ID / 32] =  1 << (Copy_INT_ID % 32);
}  
void NVIC_void_Set_pending_Flag(u8 Copy_INT_ID)
{
    MY_NVIC->NVIC_ISPRx[Copy_INT_ID / 32] =  1 << (Copy_INT_ID % 32);
}  
void NVIC_void_CLR_Pending_Flag(u8 Copy_INT_ID)
{
    MY_NVIC->NVIC_ICPRx[Copy_INT_ID / 32] =  1 << (Copy_INT_ID % 32);
}  
void NVIC_void_set_Priority_Config(u8 Copy_PriorityOption)
{
    Static_Global_u8_Priority_Config = Copy_PriorityOption << 8;
    SCB ->AIRCR =  Static_Global_u8_Priority_Config;
}  
void NVIC_void_Set_Priority(u8 Copy_INT_ID , u8 Copy_group , u8 Copy_u8_Sub_Group)
{
    u8 Local_u8_Priority = Copy_u8_Sub_Group | (Copy_group << ((Static_Global_u8_Priority_Config - 0x05FA0300) / 256));
    MY_NVIC -> NVIC_IPRx[Copy_INT_ID] = (Local_u8_Priority << 4);
} 
