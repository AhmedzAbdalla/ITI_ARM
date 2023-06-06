/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : LBIT_MATH.h                                                                     */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                            guard of file will call one time in .c file	                           */
/*******************************************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*******************************************************************************************************/
/*                                        Function Like Macros	     	                               */
/*******************************************************************************************************/


 #define SET_BIT(REG , BITNUM)         (REG) |=  (1U << (BITNUM))
 #define CLR_BIT(REG , BITNUM)         (REG) &= ~(1U << (BITNUM))
 #define TOG_BIT(REG , BITNUM)         (REG) ^=  (1U << (BITNUM))
 #define GET_BIT(REG , BITNUM)         ((REG)>> (BITNUM) & 1U )

 #define Set_ALL_BITS(REG)			   (REG)  = (0xFFFFFFFF)   // (REG) = (~0) 
 #define Clr_ALL_BITS(REG)			   (REG)  = (0x00000000)
 #define Toggle_ALL_BITS(REG)		   (REG) ^= (0xFFFFFFFF)


 #endif /* BIT_MATH_H_ */

