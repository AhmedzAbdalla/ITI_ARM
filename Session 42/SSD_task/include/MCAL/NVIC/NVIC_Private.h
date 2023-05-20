#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


#define NVIC_Base_address        0xE000E100 

typedef struct
{
    volatile u32 NVIC_ISERx[32];
    volatile u32 NVIC_ICERx[32];
    volatile u32 NVIC_ISPRx[32];
    volatile u32 NVIC_ICPRx[32];
    volatile u32 NVIC_IABRx[32];    
    volatile u32 reserved[32];    
    volatile u8 NVIC_IPRx[90];

}NVIC_t;

#define MY_NVIC		((volatile NVIC_t* )NVIC_Base_address)


//SCB Base Address --> 0xE000ED00
typedef struct
{
    volatile u32 CPUID;
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;			
    volatile u32 SCR;
    volatile u32 CCR;
    volatile u32 SHPR[3];
    volatile u32 SHCSR;
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;
}SCB_t;

#define SCB		((volatile SCB_t*)0xE000ED00)


#define VECTKEY     0x05FA0000

#endif //NVIC_PRIVATE_H
