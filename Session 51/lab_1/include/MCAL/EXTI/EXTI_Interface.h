/*
 * EXTI_Interface.h
 *
 *  Created on: MAY 20, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*Trigger selection of the interrupt lines*/
typedef enum 
{
    RISING_EDGE = 0,
    FALLING_EDGE,
    ON_CHANGE
}Trigger_selection_t;


/*Select External Interrupt Source Line */
typedef enum
{
    EXTI_0 = 0,
    EXTI_1,
    EXTI_2,
    EXTI_3,
    EXTI_4,
    EXTI_5,
    EXTI_6,
    EXTI_7,
    EXTI_8,
    EXTI_9,
    EXTI_10,
    EXTI_11,
    EXTI_12,
    EXTI_13,
    EXTI_14,
    EXTI_15,
}EXTIx_t;

typedef enum
{
    Maskable = 0,
    Unmaskable
}Mask_t;

typedef enum
{
    EXTI_SOURCE_GPIOA = 0b0000, // pinx at PORTA will be external interrupt source
    EXTI_SOURCE_GPIOB = 0b0001,     // pinx at PORTB will be external interrupt source
    EXTI_SOURCE_GPIOC = 0b0010

}EXTIx_Source_INP_t;

typedef struct 
{
    EXTIx_t EXTI : 5;
    Trigger_selection_t Trigger : 2;
    Mask_t EXTI_MASK : 1;
    EXTIx_Source_INP_t EXTI_SRC_Port : 2;
}EXTI_t;

void EXTI_void_EXTI_init(void);
void EXTI_void_EXTIx_enable( EXTI_t * REF_EXTI_t_EXTI_X);
void EXTI_void_EXTIx_disable(u8 Copy_u8_EXTI_ID );
void EXTI_void_EXTI_clear_flags(void);

/*
void set_EXTI_0_handler(void (*pf) (void));
void set_EXTI_1_handler(void (*pf) (void));
void set_EXTI_2_handler(void (*pf) (void));
*/

#endif /* EXTI_INTERFACE_H_ */
