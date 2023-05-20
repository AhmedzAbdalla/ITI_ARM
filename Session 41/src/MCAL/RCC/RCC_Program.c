#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_Types.h"


#include "../../include/MCAL/RCC/RCC_Config.h"
#include "../../include/MCAL/RCC/RCC_Private.h"
#include "../../include/MCAL/RCC/RCC_Interface.h"


void RCC_void_Init_Sys_Clk(void)
{

    #if SYS_CLK == HSI
        /*Enable HSI*/
        SET_BIT(RCC_CR , RCC_CR_HSION);

        /*Configuring system clock*/
        CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);
        CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);
    #elif SYS_CLK == HSE_CRYSTAL
        /*Enable HSE*/
        SET_BIT(RCC_CR , RCC_CR_HSEON);

        //disable bypass
        CLR_BIT(RCC_CR , RCC_CR_HSEBYP);
        //CLR_BIT(RCC_CR , 24);

        /*Configuring system clock*/
        SET_BIT(RCC_CFGR , RCC_CFGR_SW0);
        CLR_BIT(RCC_CFGR , RCC_CFGR_SW1);
    #elif SYS_CLK == HSE_RC
        /*Enable HSE*/
        SET_BIT(RCC_CR , RCC_CR_HSEON);

        //disable bypass
        SET_BIT(RCC_CR , RCC_CR_HSEBYP);

        /*Configuring system clock*/
        CLR_BIT(RCC_CFGR , RCC_CFGR_SW0);
        SET_BIT(RCC_CFGR , RCC_CFGR_SW1);
    #elif SYS_CLK == PLL
    /**/
    #endif
}

void RCC_void_Enable_Peripheral_Clk(u8 Copy_u8_Bus_Id, u8 Copy_u8_Peripheral_Id)
{
    if((Copy_u8_Peripheral_Id > 31) || (Copy_u8_Bus_Id > 4))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Bus_Id)
        {
        case AHB1:
            SET_BIT(RCC_AHB1ENR , Copy_u8_Peripheral_Id );
            break;
        case AHB2:
            SET_BIT(RCC_AHB2ENR , Copy_u8_Peripheral_Id );
            break;
        case APB1:
            SET_BIT(RCC_APB1ENR , Copy_u8_Peripheral_Id );
            break;
        case APB2:
            SET_BIT(RCC_APB2ENR , Copy_u8_Peripheral_Id );
            break;
        
        default:
            break;
        }
    }
}



/*Copy_u8BusId: AHB1, AHB2, APB1, APB2, Copy_u8_Peripheral_Id: 0->31*/
void RCC_void_Disable_Peripheral_Clk(u8 Copy_u8_Bus_Id, u8 Copy_u8_Peripheral_Id)
{
    if((Copy_u8_Peripheral_Id > 31) || (Copy_u8_Bus_Id > 4))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Bus_Id)
        {
        case AHB1:
            CLR_BIT(RCC_AHB1ENR , Copy_u8_Peripheral_Id );
            break;
        case AHB2:
            CLR_BIT(RCC_AHB2ENR , Copy_u8_Peripheral_Id );
            break;
        case APB1:
            CLR_BIT(RCC_APB1ENR , Copy_u8_Peripheral_Id );
            break;
        case APB2:
            CLR_BIT(RCC_APB2ENR , Copy_u8_Peripheral_Id );
            break;
        
        default:
            break;
        }
    }
}
