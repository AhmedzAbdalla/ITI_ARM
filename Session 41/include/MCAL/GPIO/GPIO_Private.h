#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

#define GPIOA_MODER         (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X00)))
#define GPIOA_OTYPER        (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X04)))
#define GPIOA_OSPEEDER      (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X08)))
#define GPIOA_PUPDR         (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X0C)))
#define GPIOA_IDR           (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X10)))
#define GPIOA_ODR           (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X14)))
#define GPIOA_BSRR          (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X18)))
#define GPIOA_LCKR          (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X1C)))
#define GPIOA_AFRL          (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X20)))
#define GPIOA_AFRH          (*((volatile u32 *)(GPIOA_BASE_ADDRESS + 0X24)))


#define GPIOB_MODER         (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X00)))
#define GPIOB_OTYPER        (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X04)))
#define GPIOB_OSPEEDER      (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X08)))
#define GPIOB_PUPDR         (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X0C)))
#define GPIOB_IDR           (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X10)))
#define GPIOB_ODR           (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X14)))
#define GPIOB_BSRR          (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X18)))
#define GPIOB_LCKR          (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X1C)))
#define GPIOB_AFRL          (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X20)))
#define GPIOB_AFRH          (*((volatile u32 *)(GPIOB_BASE_ADDRESS + 0X24)))


#define GPIOC_MODER         (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X00)))
#define GPIOC_OTYPER        (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X04)))
#define GPIOC_OSPEEDER      (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X08)))
#define GPIOC_PUPDR         (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X0C)))
#define GPIOC_IDR           (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X10)))
#define GPIOC_ODR           (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X14)))
#define GPIOC_BSRR          (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X18)))
#define GPIOC_LCKR          (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X1C)))
#define GPIOC_AFRL          (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X20)))
#define GPIOC_AFRH          (*((volatile u32 *)(GPIOC_BASE_ADDRESS + 0X24)))



            
#endif //GPIO_PRIVATE_H
