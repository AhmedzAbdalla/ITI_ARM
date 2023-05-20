#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_void_Init_Sys_Clk(void);  //Select System Clk

/*Copy_u8BusId: AHB1, AHB2, APB1, APB2, Copy_u8_Peripheral_Id: 0->31*/
void RCC_void_Enable_Peripheral_Clk(u8 Copy_u8_Bus_Id, u8 Copy_u8_Peripheral_Id);

/*Copy_u8BusId: AHB1, AHB2, APB1, APB2, Copy_u8_Peripheral_Id: 0->31*/
void RCC_void_Disable_Peripheral_Clk(u8 Copy_u8_Bus_Id, u8 Copy_u8_Peripheral_Id);




#endif //RCC_INTERFACE_H
