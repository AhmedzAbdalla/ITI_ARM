#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*Function Protoypes*/

void GPIO_void_Set_Pin_Mode(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_mode );
void GPIO_void_Set_Pin_Type(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Type );
void GPIO_void_Set_Pin_Speed(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Speed );


void GPIO_void_Set_Pin_Pull_State(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pull_State );

void GPIO_void_Set_Pin_Value_Non_Atomic(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Sense_level );
void GPIO_void_Set_Pin_Value_Atomic(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Sense_level );

u8 GPIO_u8_Set_Pin_Get_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID );


//PINS INDEX
#define PIN_0            0 
#define PIN_1            1
#define PIN_2            2
#define PIN_3            3
#define PIN_4            4
#define PIN_5            5
#define PIN_6            6
#define PIN_7            7
#define PIN_8            8
#define PIN_9            9
#define PIN_10           10
#define PIN_11           11
#define PIN_12           12
#define PIN_13           13
#define PIN_14           14
#define PIN_15           15
 
// PORT INDEX
#define GPIOA           0
#define GPIOB           1
#define GPIOC           2


//PIN STATES
#define INPUT           0
#define OUTPUT          1
#define AF              2
#define ANALOG          3

//Pin output states
#define push_pull       0
#define open_drain      1

//I/O Input pins State
#define FLOATING        0 // No pull-up, pull-down
#define PULL_UP         1
#define PULL_DOWN       2


//I/O output pins speed
#define Low_speed       0
#define Medium_speed    1
#define High_speed      2
#define Very_high_speed 3


// I/O output pins Sense level
#define SET             1
#define RST             0

#endif //GPIO_INTERFACE_H
