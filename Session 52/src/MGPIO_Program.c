/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 18 Aug 2022                                                                     */
/* Description       : MGPIO_Program.c --> implementations                                             */
/* Module  Features  :                                                                                 */
/*      01- MGPIO_voidSetPinMode()                                                                     */
/*      02- MGPIO_voidSetOutputType()                                                                  */
/*      03- MGPIO_voidSetOutputSpeed()                                                                 */
/*      04- MGPIO_voidSetPullState()                                                                   */
/*      05- MGPIO_u8GetPInValue()                                                                      */
/*      06- MGPIO_voidSetPinValue()                                                                    */
/*      07- MGPIO_voidDirectSetReset()                                                                 */
/*      08- MGPIO_voidPinLock()                                                                        */
/*      09- MGPIO_voidSetPinAltFun()                                                                   */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MGPIO_voidSetPinMode                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set The Mode Of Pin Mode Take 2Bits                             */
/*                                                                                                     */
/*      1- MODE_INPUT                                                                                  */
/*      2- MODE_OUTPUT                                                                                 */
/*      3- MODE_ALTF                                                                                   */
/*      4- MODE_ANALOG                                                                                 */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8Mod                         */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  )
{
	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : MGPIOA->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOB_PORT : MGPIOB->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOC_PORT : MGPIOC->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOD_PORT : MGPIOD->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOE_PORT : MGPIOE->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOH_PORT : MGPIOH->MODER |= (u32)(Copy_u8Mode << (2U * Copy_u8PinNum ))  ; break ;

	default :  /*Error*/   break ;
	}	
}


/*******************************************************************************************************/
/*                                      02- MGPIO_voidSetOutputType                                    */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set The output type Of Pin  Take Bits                           */
/*                                                                                                     */
/*      1- PUSH_PULL                                                                                   */
/*      2- OPEN_DRAIN                                                                                  */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8OutTypeMode                 */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutTypeMode ) 
{
	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : MGPIOA->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOB_PORT : MGPIOB->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOC_PORT : MGPIOC->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOD_PORT : MGPIOD->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOE_PORT : MGPIOE->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;
	case MGPIOH_PORT : MGPIOH->OTYPER |= (u32)(Copy_u8OutTypeMode << (Copy_u8PinNum ))  ; break ;

	default :  /*Error*/   break ;
	}	

}

/*******************************************************************************************************/
/*                                      03- MGPIO_voidSetOutputSpeed                                   */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set The output speed  Of Pin Mode Take 2Bits                    */
/*                                                                                                     */
/*      1- LOW_SPEED                                                                                   */
/*      2- MEDUIM_SPEED                                                                                */
/*      3- HIGH_SPEED                                                                                  */
/*      4- VERY_HIGH_SPEED                                                                             */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8SpeedMode                   */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetOutputSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8SpeedMode  )
{

	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : MGPIOA->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOB_PORT : MGPIOB->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOC_PORT : MGPIOC->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOD_PORT : MGPIOD->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOE_PORT : MGPIOE->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOH_PORT : MGPIOH->OSPEEDR |= (u32)(Copy_u8SpeedMode << (2U * Copy_u8PinNum ))  ; break ;

	default :  /*Error*/   break ;
	}	
}


/*******************************************************************************************************/
/*                                      04- MGPIO_voidSetPullState                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set The Resistor connection state of pin Take 2Bits             */
/*                                                                                                     */
/*      1- PULL_FLOAT                                                                                  */
/*      2- PULL_UP                                                                                     */
/*      3- PULL_DOWN                                                                                   */
/*      4- RESERVED                                                                                    */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8PullType                    */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPullState(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType  )
{
	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : MGPIOA->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOB_PORT : MGPIOB->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOC_PORT : MGPIOC->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOD_PORT : MGPIOD->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOE_PORT : MGPIOE->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;
	case MGPIOH_PORT : MGPIOH->PUPDR |= (u32)(Copy_u8PullType << (2U * Copy_u8PinNum ))  ; break ;

	default :  /*Error*/   break ;
	}	
}


/*******************************************************************************************************/
/*                                      05- MGPIO_u8GetPInValue                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Read Data from IDR Register                                     */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum                                        */                   
/* 3- Function Return      -> Pin State Value                                                          */
/*******************************************************************************************************/

u8 MGPIO_u8GetPInValue(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{

	u8 LOC_u8PinValue = 0 ; 
	switch(Copy_u8PortName)
	{
	case MGPIOA_PORT : LOC_u8PinValue = GET_BIT(MGPIOA->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOB_PORT : LOC_u8PinValue = GET_BIT(MGPIOB->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOC_PORT : LOC_u8PinValue = GET_BIT(MGPIOC->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOD_PORT : LOC_u8PinValue = GET_BIT(MGPIOD->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOE_PORT : LOC_u8PinValue = GET_BIT(MGPIOE->IDR,Copy_u8PinNum)  ; break ;
	case MGPIOH_PORT : LOC_u8PinValue = GET_BIT(MGPIOH->IDR,Copy_u8PinNum)  ; break ;

	default :  /*Error*/   break ;
	}	

	return LOC_u8PinValue ; 
}

/*******************************************************************************************************/
/*                                      06- MGPIO_voidSetPinValue                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set Pin Value At  ODR Register                                  */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8PinValue                     */                   
/* 3- Function Return      -> NO THING                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinValue(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8PinValue)
{
	if(Copy_u8PinValue == MGPIO_HIGH)
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : SET_BIT(MGPIOA->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOB_PORT : SET_BIT(MGPIOB->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : SET_BIT(MGPIOC->ODR,Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : SET_BIT(MGPIOD->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : SET_BIT(MGPIOE->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : SET_BIT(MGPIOH->ODR,Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : CLR_BIT(MGPIOA->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOB_PORT : CLR_BIT(MGPIOB->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : CLR_BIT(MGPIOC->ODR,Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : CLR_BIT(MGPIOD->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : CLR_BIT(MGPIOE->ODR,Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : CLR_BIT(MGPIOH->ODR,Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}
}

/*******************************************************************************************************/
/*                                      07- MGPIO_voidDirectSetReset                                   */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set and Reset Dirct for crossponding Pin Value At  BSRR Register*/
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8PinValue                     */                   
/* 3- Function Return      -> NO THING                                                                 */
/*******************************************************************************************************/

void MGPIO_voidDirectSetReset(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8PinValue)
{

	if(Copy_u8PinValue == MGPIO_HIGH)
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : MGPIOA->BSRR = (1U<<Copy_u8PinNum)  ; break ;                                         
		case MGPIOB_PORT : MGPIOB->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : MGPIOC->BSRR = (1U<<Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : MGPIOD->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : MGPIOE->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : MGPIOH->BSRR = (1U<<Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}
	else
	{
		Copy_u8PinNum += 16 ;
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT : MGPIOA->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOB_PORT : MGPIOB->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOC_PORT : MGPIOC->BSRR = (1U<<Copy_u8PinNum)  ; break ;
		case MGPIOD_PORT : MGPIOD->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOE_PORT : MGPIOE->BSRR = (1U<<Copy_u8PinNum)  ; break ; 
		case MGPIOH_PORT : MGPIOH->BSRR = (1U<<Copy_u8PinNum)  ; break ; 	
		default :  /*Error*/   break ; 
		}
	}


}



/*******************************************************************************************************/
/*                                      08- MGPIO_voidPinLock                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Lock At pin :                                                   */
/*                               1 - Set PIN                                                           */
/*                               2 - Set PIN 16                                                        */
/*                               3 - Clr PIN 16                                                        */
/*                               4 - Set PIN 16                                                        */
/*                               5 - wait bit 16 = High                                                */ 
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum                                        */                   
/* 3- Function Return      -> NO THING                                                                 */
/*******************************************************************************************************/

void MGPIO_voidPinLock(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	//TODO: 
}

/*******************************************************************************************************/
/*                                      09- MGPIO_voidSetPinAltFun                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set pin Alternative :                                           */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8AlFun                        */                   
/* 3- Function Return      -> NO THING                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8AlFun)
{
	if(Copy_u8PinNum <=7U)
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT:MGPIOA->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case MGPIOB_PORT:MGPIOB->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case MGPIOC_PORT:MGPIOC->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		default : break ;
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT:MGPIOA->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case MGPIOB_PORT:MGPIOB->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case MGPIOC_PORT:MGPIOC->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		default : break ;
		}

	}
}


/*#####################################################################################################*/
/*                                              END OF FUNCTIONS                                       */
/*#####################################################################################################*/

