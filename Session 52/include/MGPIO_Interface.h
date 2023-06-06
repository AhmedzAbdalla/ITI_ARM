/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 18 Aug 2022                                                                     */
/* Description       : MGPIO_Interface.h --> Prototypes                                                */
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
/*	* What i sell To Customer                                                                          */
/*		*  The Archictect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H


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

#include "MGPIO_private.h"
#include "MGPIO_config.h"

/*******************************************************************************************************/
/*                                      Macros Of Port                                                 */
/*******************************************************************************************************/


#define   MGPIOA_PORT      0U
#define   MGPIOB_PORT      1U
#define   MGPIOC_PORT      2U
#define   MGPIOD_PORT      3U
#define   MGPIOE_PORT      4U
#define   MGPIOH_PORT      5U

/*******************************************************************************************************/
/*                                      Macros Of Pins                                                 */
/*******************************************************************************************************/

#define  MGPIO_PIN0        0U
#define  MGPIO_PIN1        1U
#define  MGPIO_PIN2        2U
#define  MGPIO_PIN3        3U
#define  MGPIO_PIN4        4U
#define  MGPIO_PIN5        5U
#define  MGPIO_PIN6        6U
#define  MGPIO_PIN7        7U
#define  MGPIO_PIN8        8U
#define  MGPIO_PIN9        9U
#define  MGPIO_PIN10      10U
#define  MGPIO_PIN11      11U
#define  MGPIO_PIN12      12U
#define  MGPIO_PIN13      13U
#define  MGPIO_PIN14      14U
#define  MGPIO_PIN15      15U

/*******************************************************************************************************/
/*                                      Macros Of Mode                                                 */
/*******************************************************************************************************/

#define  MGPIO_MODE_INPUT       (0b00)
#define  MGPIO_MODE_OUTPUT      (0b01)
#define  MGPIO_MODE_ALTF        (0b10)
#define  MGPIO_MODE_ANALOG      (0b11)


/*******************************************************************************************************/
/*                                      Macros Of Type                                                 */
/*******************************************************************************************************/

#define   MGPIO_OUTPUT_TYPE_PUSH_PULL          0U
#define   MGPIO_OUTPUT_TYPE_OPEN_DRAIN         1U


/*******************************************************************************************************/
/*                                      Macros Of Speed                                                 */
/*******************************************************************************************************/

#define MGPIO_OUTPUT_SPEED_LOW               (0b00)
#define MGPIO_OUTPUT_SPEED_MEDUIM            (0b01)
#define MGPIO_OUTPUT_SPEED_HIGH              (0b10)
#define MGPIO_OUTPUT_SPEED_VERY_HIGH         (0b11)

/*******************************************************************************************************/
/*                                      Macros Of PULL                                                 */
/*******************************************************************************************************/

#define MGPIO_PULL_FLOATING                   (0b00)
#define MGPIO_PULL_UP                         (0b01)
#define MGPIO_PULL_DOWN                       (0b10)


/*******************************************************************************************************/
/*                                      Macros Write Data                                              */
/*******************************************************************************************************/

#define MGPIO_HIGH                            (1U)
#define MGPIO_LOW                             (0U)

/*******************************************************************************************************/
/*                                      Macros ALTF                                                    */
/*******************************************************************************************************/

 #define MGPIO_ALTFN_0                          (0b0000)         
 #define MGPIO_ALTFN_1                          (0b0001)
 #define MGPIO_ALTFN_2                          (0b0010)
 #define MGPIO_ALTFN_3                          (0b0011)
 #define MGPIO_ALTFN_4                          (0b0100)
 #define MGPIO_ALTFN_5                          (0b0101)
 #define MGPIO_ALTFN_6                          (0b0110)
 #define MGPIO_ALTFN_7                          (0b0111)
 #define MGPIO_ALTFN_8                          (0b1000)
 #define MGPIO_ALTFN_9                          (0b1001)
 #define MGPIO_ALTFN_10                         (0b1010)
 #define MGPIO_ALTFN_11                         (0b1011)
 #define MGPIO_ALTFN_12                         (0b1100)
 #define MGPIO_ALTFN_13                         (0b1101)
 #define MGPIO_ALTFN_14                         (0b1110)
 #define MGPIO_ALTFN_15                         (0b1111)
 
/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
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

void MGPIO_voidSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  );


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

void MGPIO_voidSetOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutTypeMode ) ; 



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

void MGPIO_voidSetOutputSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8SpeedMode  );


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

void MGPIO_voidSetPullState(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8PullType  );


/*******************************************************************************************************/
/*                                      05- MGPIO_u8GetPInValue                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Read Data from IDR Register                                     */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum                                        */                   
/* 3- Function Return      -> Pin State Value                                                          */
/*******************************************************************************************************/

u8 MGPIO_u8GetPInValue(u8 Copy_u8PortName ,u8 Copy_u8PinNum);

/*******************************************************************************************************/
/*                                      06- MGPIO_voidSetPinValue                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set Pin Value At  ODR Register                                  */
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8PinValue                     */                   
/* 3- Function Return      -> NO THING                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinValue(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8PinValue);

/*******************************************************************************************************/
/*                                      07- MGPIO_voidDirectSetReset                                   */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set and Reset Dirct for crossponding Pin Value At  BSRR Register*/
/*                                                                                                     */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8PinValue                     */                   
/* 3- Function Return      -> NO THING                                                                 */
/*******************************************************************************************************/

void MGPIO_voidDirectSetReset(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8PinValue);



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

void MGPIO_voidPinLock(u8 Copy_u8PortName ,u8 Copy_u8PinNum);

/*******************************************************************************************************/
/*                                      09- MGPIO_voidSetPinAltFun                                     */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set pin Alternative :                                           */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  , Copy_u8AlFun                        */                   
/* 3- Function Return      -> NO THING                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8AlFun) ; 




#endif //_GPIO_INTERFACE_H

