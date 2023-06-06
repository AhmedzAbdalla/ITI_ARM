/***********************************************************************/
/*Auther        : Ahmed Khaled                                         */
/*Version       : V0.0.0                                               */
/*Data          : 16 Aug 2022                                          */
/*Description   : MRCC_Privaite.h --> Register Defintions              */
/***********************************************************************/


/***********************************************************************/
/*             guard of file will call one time in .c file             */
/***********************************************************************/

             
#ifndef MRCC_PRIVAITE_H_
#define MRCC_PRIVAITE_H_

/*#####################################################################*/
/*                        Register Defintions                          */
/*---------------------------------------------------------------------*/
/*     -Developer Can't Edit in                                        */
/*     -Register Defination                                            */
/*     -Desgin :                                                       */
/*                - #define    : YES                                   */
/*                - Struct     : NO                                    */
/*#####################################################################*/

/***********************************************************************/
/*                  Macros Of Base Adress of RCC Registers             */
/***********************************************************************/


#define  MRCC_BASE_ADRESS      0x40023800


/***********************************************************************/
/*                     Macros Of RCC Registers  Map                    */
/***********************************************************************/


#define    RCC_CR                  (*((volatile u32*)(MRCC_BASE_ADRESS + 0x00 )))
#define    RCC_PLLCFGR             (*((volatile u32*)(MRCC_BASE_ADRESS + 0x04 )))
#define    RCC_CFGR                (*((volatile u32*)(MRCC_BASE_ADRESS + 0x08 )))
#define    RCC_CIR                 (*((volatile u32*)(MRCC_BASE_ADRESS + 0x0C )))
#define    RCC_AHB1RSTR            (*((volatile u32*)(MRCC_BASE_ADRESS + 0x10 )))
#define    RCC_AHB2RSTR            (*((volatile u32*)(MRCC_BASE_ADRESS + 0x14 )))
#define    RCC_APB1RSTR            (*((volatile u32*)(MRCC_BASE_ADRESS + 0x20 )))
#define    RCC_APB2RSTR            (*((volatile u32*)(MRCC_BASE_ADRESS + 0x24 )))
#define    RCC_AHB1ENR             (*((volatile u32*)(MRCC_BASE_ADRESS + 0x30 )))
#define    RCC_AHB2ENR             (*((volatile u32*)(MRCC_BASE_ADRESS + 0x34 )))
#define    RCC_APB1ENR             (*((volatile u32*)(MRCC_BASE_ADRESS + 0x40 )))
#define    RCC_APB2ENR             (*((volatile u32*)(MRCC_BASE_ADRESS + 0x44 )))
#define    RCC_AHB1LPENR           (*((volatile u32*)(MRCC_BASE_ADRESS + 0x50 )))
#define    RCC_AHB2LPENR           (*((volatile u32*)(MRCC_BASE_ADRESS + 0x54 )))
#define    RCC_APB1LPENR           (*((volatile u32*)(MRCC_BASE_ADRESS + 0x60 )))
#define    RCC_APB2LPENR           (*((volatile u32*)(MRCC_BASE_ADRESS + 0x64 )))
#define    RCC_BDCR                (*((volatile u32*)(MRCC_BASE_ADRESS + 0x70 )))
#define    RCC_CSR                 (*((volatile u32*)(MRCC_BASE_ADRESS + 0x74 )))
#define    RCC_SSCGR               (*((volatile u32*)(MRCC_BASE_ADRESS + 0x80 )))
#define    RCC_PLLI2SCFGR          (*((volatile u32*)(MRCC_BASE_ADRESS + 0x84 )))
#define    RCC_DCKCFGR             (*((volatile u32*)(MRCC_BASE_ADRESS + 0x8C )))


/***********************************************************************/
/*                     Macros for User Configuration                   */
/***********************************************************************/

/*#####################################################################*/
/*
   - Select The Clock Source from The Following Options : 
*/
         
#define HSI             0U
#define HSE             1U
#define PLL             2U

/*#####################################################################*/
/*
   - Select The  Source of HSE from The Following Options : 
*/

#define HSE_CRYSTAL    0U
#define HSE_RC         1U

/*#####################################################################*/

/*
   - Select The  Source of PLL from The Following Options : 
*/

#define HSE_PLL        0U
#define HSI_PLL        1U


/*#####################################################################*/
/*                     THE END OF PRIVAITE FILE                        */
/*#####################################################################*/


#endif /*MRCC_PRIVAITE_H_*/

