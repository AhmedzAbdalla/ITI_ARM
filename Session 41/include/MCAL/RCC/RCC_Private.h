#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define RCC_Base_address        0x40023800 

#define RCC_CR          (*(volatile u32*)(RCC_Base_address + 0x00))
#define RCC_PLLCFGR     (*(volatile u32*)(RCC_Base_address + 0x04))
#define RCC_CFGR        (*(volatile u32*)(RCC_Base_address + 0x08))
#define RCC_AHB1ENR     (*(volatile u32*)(RCC_Base_address + 0x30))
#define RCC_AHB2ENR     (*(volatile u32*)(RCC_Base_address + 0x34))
#define RCC_APB1ENR     (*(volatile u32*)(RCC_Base_address + 0x40))
#define RCC_APB2ENR     (*(volatile u32*)(RCC_Base_address + 0x44))


/**** R/W bits in RCC_CR *******/

#define RCC_CR_HSION      0x00
#define RCC_CR_HSEON      0x10
#define RCC_CR_HSEBYP     0x12
#define RCC_CR_CSSON      0x13
#define RCC_CR_PLLON      0x18
#define RCC_CR_PLLI2SON   0x1A

/**** END of R/W bits in RCC_CR *******/

/**** R/W bits in RCC_CFGR *******/
#define RCC_CFGR_SW0      0x00
#define RCC_CFGR_SW1      0x01

/**** END of R/W bits in RCC_CFGR *******/

/**** R/W bits in RCC_AHB1ENR *******/

#define RCC_AHB1ENR_GPIOAEN     0x00
#define RCC_AHB1ENR_GPIOBEN     0x01
#define RCC_AHB1ENR_GPIOCEN     0x02
#define RCC_AHB1ENR_GPIODEN     0x03
#define RCC_AHB1ENR_GPIOEEN     0x04

#define RCC_AHB1ENR_CRCEN       0x0c

#define RCC_AHB1ENR_DMA1EN      0x15
#define RCC_AHB1ENR_DMA2EN      0x16

/**** END of R/W bits in RCC_AHB1ENR *******/

/**** R/W bits in RCC_AHB2ENR *******/

#define RCC_AHB2ENR_OTGFSEN     0x07

/**** END of R/W bits in RCC_AHB2ENR *******/


/**** R/W bits in RCC_APB1ENR *******/

#define RCC_APB1ENR_TIM2EN     0x00
#define RCC_APB1ENR_TIM3EN     0x01
#define RCC_APB1ENR_TIM4EN     0x02
#define RCC_APB1ENR_TIM5EN     0x03
#define RCC_APB1ENR_WWDGEN     0x0B
#define RCC_APB1ENR_SPI2EN     0x0E
#define RCC_APB1ENR_SPI3EN     0x0F
#define RCC_APB1ENR_USART2EN   0x11
#define RCC_APB1ENR_I2C1EN     0x15
#define RCC_APB1ENR_I2C2EN     0x16
#define RCC_APB1ENR_I2C3EN     0x17
#define RCC_APB1ENR_PWREN      0x1C

/**** END of R/W bits in RCC_APB1ENR *******/

/**** R/W bits in RCC_APB2ENR *******/

#define RCC_APB2ENR_TIM1EN      0x00

#define RCC_APB2ENR_USART1EN    0x04
#define RCC_APB2ENR_USART6EN    0x05

#define RCC_APB2ENR_ADC1EN      0x08

#define RCC_APB2ENR_SDIOEN      0x0B

#define RCC_APB2ENR_SPI1EN      0x0C
#define RCC_APB2ENR_SPI4EN      0x0D

#define RCC_APB2ENR_SYSCFGEN    0x0E

#define RCC_APB2ENR_TIM9EN      0x10
#define RCC_APB2ENR_TIM10EN     0x11
#define RCC_APB2ENR_TIM11EN     0x12


#define AHB1             0
#define AHB2             1
#define APB1             2
#define APB2             3

#endif //RCC_PRIVATE_H
