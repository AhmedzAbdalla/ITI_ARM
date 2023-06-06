/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : NVIC_Program.c --> implementations                                              */
/* Module  Features  :                                                                                 */
/*      01-                                                                                            */
/*      02-                                                                                            */
/*      03-                                                                                            */
/*      04-                                                                                            */
/*      05-                                                                                            */
/*      06-                                                                                            */
/*      07-                                                                                            */
/*      08-                                                                                            */
/*******************************************************************************************************/


/*#####################################################################################################*/
/*#####################################################################################################*/

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

#include "MNVIC_Private.h"
#include "MNVIC_Interface.h"
#include "MNVIC_Config.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/



void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos)
{

   MNVIC_REG->ISER[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPos)
{

	 MNVIC_REG->ICER[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
void MNVIC_voidEnableInterruptPending  (u8 Copy_u8IntPos)
{

	 MNVIC_REG->ISPR[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
void MNVIC_voidDisableInterruptPending  (u8 Copy_u8IntPos)
{

	 MNVIC_REG->ICPR[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
u8 MNVIC_u8IsInterruptActive (u8 Copy_u8IntPos)
{
     return  GET_BIT(MNVIC_REG->IABR[Copy_u8IntPos/32],(Copy_u8IntPos % 32 )) ;
}
void MNVIC_voidSetInterruptPriority  (u8 Copy_u8IntPos ,MNVIC_GroupMode_t Copy_uddtGroupMode,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum )
{

 u8 LOC_u8PrioValue = 0 ;
  switch(Copy_uddtGroupMode)
  {
  case MNVIC_GROUPMODE_G0S16 :  LOC_u8PrioValue = Copy_u8SubGroupNum  ;  break ;
  case MNVIC_GROUPMODE_G16S0 :  LOC_u8PrioValue = Copy_u8GroupNum     ;  break ;
  case MNVIC_GROUPMODE_G4S4 :   LOC_u8PrioValue = (Copy_u8GroupNum<<2) | Copy_u8SubGroupNum    ;  break ;
  case MNVIC_GROUPMODE_G2S8 :   LOC_u8PrioValue = (Copy_u8GroupNum<<3) | Copy_u8SubGroupNum    ;  break ;
  case MNVIC_GROUPMODE_G8S2 :   LOC_u8PrioValue = (Copy_u8GroupNum<<1) | Copy_u8SubGroupNum    ;  break ;
  }


  MNVIC_REG->IPR[Copy_u8IntPos] = (LOC_u8PrioValue<<4) ;
}

void MNVIC_voidSetInterruptGroupMode(MNVIC_GroupMode_t Copy_uddtGroupMode)
{
	MSCB_AIRCR  = MNVIC_VECTKEY  ;   //reset the register first
	MSCB_AIRCR = MNVIC_VECTKEY | (Copy_uddtGroupMode<<8 ) ;
}

