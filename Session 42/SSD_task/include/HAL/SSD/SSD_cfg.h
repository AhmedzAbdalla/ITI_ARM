/*
 * 7_segment.h
 *
 *  Created on: Mar 27, 2023
 *  Author       : Ahmed Abdalla
 */
#ifndef SSD_CFG_H_
#define SSD_CFG_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"

//PORT CONFIGURATION
/*
#define  GPIOA      0x00      
#define  GPIOB      0x01      
*/
#define DATA_PORT      GPIOA


//OUTPUT PINS
#define DATA_BIT0      PIN_0
#define DATA_BIT1      PIN_1
#define DATA_BIT2      PIN_2
#define DATA_BIT3      PIN_3



#endif /* SSD_CFG_H_ */
