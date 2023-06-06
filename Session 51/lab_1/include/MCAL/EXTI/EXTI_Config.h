/*
 * EXTI_Config.h
 *
 *  Created on: MAY 20, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

#define INT0                      0
#define INT1                      1
#define INT2                      2

#define FALLING_EDGE              0
#define RISING_EDGE               1
#define LOW_LEVEL                 2
#define ON_CHANGE                 3




/*Config Macros*/
#define INT_ENABLE				INT1
#define INT_SENSE_CONTROL          RISING_EDGE
#endif /* EXTI_CONFIG_H_ */
