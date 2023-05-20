#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


#define NVIC_Priority_16G_0SG   0b011
#define NVIC_Priority_8G_2SG    0b100
#define NVIC_Priority_4G_4SG    0b101
#define NVIC_Priority_2G_8SG    0b110
#define NVIC_Priority_0G_16SG   0b111


void NVIC_void_Enable_PerInt(u8 Copy_INT_ID); 
void NVIC_void_Disable_PerInt(u8 Copy_INT_ID); 
void NVIC_void_Set_pending_Flag(u8 Copy_INT_ID); 
void NVIC_void_CLR_Pending_Flag(u8 Copy_INT_ID); 
void NVIC_void_set_Priority_Config(u8 Copy_PriorityOption); 
void NVIC_void_Set_Priority(u8 Copy_INT_ID , u8 Copy_group , u8 Copy_u8_Sub_Group); 




#endif //NVIC_INTERFACE_H
