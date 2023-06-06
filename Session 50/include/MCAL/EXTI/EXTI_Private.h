/*
 * EXTI_Private.h
 *
 *  Created on: MAY 20, 2023
 *      Author: Ahmed Abdalla
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS       0x40013C00

#define EXTI_IMR                (*((volatile u32*)(EXTI_BASE_ADDRESS + 0x00))) //Interrupt mask register
#define EXTI_EMR                (*((volatile u32*)(EXTI_BASE_ADDRESS + 0x04))) //Event mask register
#define EXTI_RTSR               (*((volatile u32*)(EXTI_BASE_ADDRESS + 0x08))) //Rising trigger selection register
#define EXTI_FTSR               (*((volatile u32*)(EXTI_BASE_ADDRESS + 0x0C))) //Falling trigger selection register
#define EXTI_SWIER              (*((volatile u32*)(EXTI_BASE_ADDRESS + 0x10))) //Software interrupt event register
#define EXTI_PR                 (*((volatile u32*)(EXTI_BASE_ADDRESS + 0x14))) //Pending register



#endif /* EXTI_PRIVATE_H_ */
