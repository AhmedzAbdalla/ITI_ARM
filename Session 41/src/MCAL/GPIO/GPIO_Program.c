#include "../../include/LIB/BIT_MATH.h"
#include "../../include/LIB/STD_Types.h"


#include "../../include/MCAL/GPIO/GPIO_Config.h"
#include "../../include/MCAL/GPIO/GPIO_Private.h"
#include "../../include/MCAL/GPIO/GPIO_Interface.h"

/*Copy_u8_Port_ID: GPIOA, GPIOB, GPIOC */
/*Copy_u8_Pin_ID : PIN0 : PIN31 */
/*Copy_u8_mode: INPUT, OUTPUT, AF, ANALOG */
void GPIO_void_Set_Pin_Mode(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_mode )
{
    if((Copy_u8_Port_ID > GPIOC) || (Copy_u8_Pin_ID > PIN_15))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Port_ID)
        {
            case GPIOA:
                switch (Copy_u8_mode)
                {
                    case INPUT:
                    CLR_BIT(GPIOA_MODER , 2 * Copy_u8_Pin_ID );
                    CLR_BIT(GPIOA_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case OUTPUT:
                    SET_BIT(GPIOA_MODER , 2 * Copy_u8_Pin_ID );
                    CLR_BIT(GPIOA_MODER , ( (2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case AF:
                    CLR_BIT(GPIOA_MODER , 2 * Copy_u8_Pin_ID );
                    SET_BIT(GPIOA_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case ANALOG:
                    SET_BIT(GPIOA_MODER , 2 * Copy_u8_Pin_ID );
                    SET_BIT(GPIOA_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                
                    default:
                    /*Nothing*/
                        break;
                }
                break;
            case GPIOB:
                switch (Copy_u8_mode)
                {
                    case INPUT:
                    CLR_BIT(GPIOB_MODER , 2 * Copy_u8_Pin_ID );
                    CLR_BIT(GPIOB_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case OUTPUT:
                    SET_BIT(GPIOB_MODER , 2 * Copy_u8_Pin_ID );
                    CLR_BIT(GPIOB_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case AF:
                    CLR_BIT(GPIOB_MODER , 2 * Copy_u8_Pin_ID );
                    CLR_BIT(GPIOB_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case ANALOG:
                    SET_BIT(GPIOB_MODER , 2 * Copy_u8_Pin_ID );
                    SET_BIT(GPIOB_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                
                    default:
                    /*Nothing*/
                        break;
                }
                break;
            case GPIOC:
                switch (Copy_u8_mode)
                {
                    case INPUT:
                    CLR_BIT(GPIOC_MODER , 2 * Copy_u8_Pin_ID );
                    CLR_BIT(GPIOC_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case OUTPUT:
                    SET_BIT(GPIOC_MODER , 2 * Copy_u8_Pin_ID );
                    CLR_BIT(GPIOC_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                    case AF:
                    CLR_BIT(GPIOC_MODER , 2 * Copy_u8_Pin_ID );
                    SET_BIT(GPIOC_MODER , (((2 * Copy_u8_Pin_ID) + 0x01)) );
                    break;
                    case ANALOG:
                    SET_BIT(GPIOC_MODER , 2 * Copy_u8_Pin_ID );
                    SET_BIT(GPIOC_MODER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                    break;
                
                    default:
                    /*Nothing*/
                        break;
                }
                break;

            default:
            /*Nothing*/
                break;
        }
    }
}


/*Description: Setting the output type if specific pin */

/*Copy_u8_Port_ID: GPIOA, GPIOB, GPIOC */
/*Copy_u8_Pin_ID : PIN0 : PIN31 */
/*Copy_u8_Type   : push_pull , open_drain */
void GPIO_void_Set_Pin_Type(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Type )
{
    if((Copy_u8_Port_ID > GPIOC) || (Copy_u8_Pin_ID > PIN_15))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Port_ID)
        {
            case GPIOA:
                switch (Copy_u8_Type)
                {
                    case push_pull:
                        CLR_BIT(GPIOA_OTYPER ,Copy_u8_Pin_ID );
                        break;
                    case open_drain:
                        SET_BIT(GPIOA_OTYPER ,Copy_u8_Pin_ID );
                        break;
                    default:
                        break;
                }
                break;
            case GPIOB:
                switch (Copy_u8_Type)
                {
                    case push_pull:
                        CLR_BIT(GPIOB_OTYPER ,Copy_u8_Pin_ID );
                        break;
                    case open_drain:
                        SET_BIT(GPIOB_OTYPER ,Copy_u8_Pin_ID );
                        break;
                    default:
                        break;
                }
                break;
            case GPIOC:
                switch (Copy_u8_Type)
                {
                    case push_pull:
                        CLR_BIT(GPIOC_OTYPER ,Copy_u8_Pin_ID );
                        break;
                    case open_drain:
                        SET_BIT(GPIOC_OTYPER ,Copy_u8_Pin_ID );
                        break;
                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

/*Description: Setting the output PIN SPEED */

/*Copy_u8_Port_ID: GPIOA, GPIOB, GPIOC */
/*Copy_u8_Pin_ID : PIN0 : PIN31 */
/*Copy_u8_Type   : Low_speed, Medium_speed, High_speed, Very_high_speed */
void GPIO_void_Set_Pin_Speed(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Speed )
{
    if((Copy_u8_Port_ID > GPIOC) || (Copy_u8_Pin_ID > PIN_15))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Port_ID)
        {
            case GPIOA:
                switch (Copy_u8_Speed)
                {
                    case Low_speed:
                        CLR_BIT(GPIOA_OSPEEDER , Copy_u8_Pin_ID );
                        CLR_BIT(GPIOA_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case Medium_speed:
                        SET_BIT(GPIOA_OSPEEDER , Copy_u8_Pin_ID );
                        CLR_BIT(GPIOA_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case High_speed:
                        CLR_BIT(GPIOA_OSPEEDER , Copy_u8_Pin_ID );
                        SET_BIT(GPIOA_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case Very_high_speed:
                        SET_BIT(GPIOA_OSPEEDER , Copy_u8_Pin_ID );
                        SET_BIT(GPIOA_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;

                    default:
                        break;
                }
                break;
            case GPIOB:
                switch (Copy_u8_Speed)
                {
                    case Low_speed:
                        CLR_BIT(GPIOB_OSPEEDER , Copy_u8_Pin_ID );
                        CLR_BIT(GPIOB_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case Medium_speed:
                        SET_BIT(GPIOB_OSPEEDER , Copy_u8_Pin_ID );
                        CLR_BIT(GPIOB_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case High_speed:
                        CLR_BIT(GPIOB_OSPEEDER , Copy_u8_Pin_ID );
                        SET_BIT(GPIOB_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case Very_high_speed:
                        SET_BIT(GPIOB_OSPEEDER , Copy_u8_Pin_ID );
                        SET_BIT(GPIOB_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;

                    default:
                        break;
                }
                break;
            case GPIOC:
                switch (Copy_u8_Speed)
                {
                    case Low_speed:
                        CLR_BIT(GPIOC_OSPEEDER , Copy_u8_Pin_ID );
                        CLR_BIT(GPIOC_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case Medium_speed:
                        SET_BIT(GPIOC_OSPEEDER , Copy_u8_Pin_ID );
                        CLR_BIT(GPIOC_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case High_speed:
                        CLR_BIT(GPIOC_OSPEEDER , Copy_u8_Pin_ID );
                        SET_BIT(GPIOC_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;
                    case Very_high_speed:
                        SET_BIT(GPIOC_OSPEEDER , Copy_u8_Pin_ID );
                        SET_BIT(GPIOC_OSPEEDER , ((2 * Copy_u8_Pin_ID) + 0x01) );
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}


/*Description: Setting the input PIN state */

/*Copy_u8_Port_ID: GPIOA, GPIOB, GPIOC */
/*Copy_u8_Pin_ID : PIN0 : PIN31 */
/*Copy_u8_Type   : FLOATING, PULL_OP, PULL_DOWN */
void GPIO_void_Set_Pin_Pull_State(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Pull_State )
{
    if((Copy_u8_Port_ID > GPIOC) || (Copy_u8_Pin_ID > PIN_15))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Port_ID)
        {
            case GPIOA:
                switch (Copy_u8_Pull_State)
                {
                    case FLOATING:
                        CLR_BIT(GPIOA_PUPDR , Copy_u8_Pin_ID);
                        CLR_BIT(GPIOA_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;
                    case PULL_UP:
                        SET_BIT(GPIOA_PUPDR , Copy_u8_Pin_ID);
                        CLR_BIT(GPIOA_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;
                    case PULL_DOWN:
                        CLR_BIT(GPIOA_PUPDR , Copy_u8_Pin_ID);
                        SET_BIT(GPIOA_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;

                    default:
                        break;
                }
                break;
            case GPIOB:
                switch (Copy_u8_Pull_State)
                {
                    case FLOATING:
                        CLR_BIT(GPIOB_PUPDR , Copy_u8_Pin_ID);
                        CLR_BIT(GPIOB_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;
                    case PULL_UP:
                        SET_BIT(GPIOB_PUPDR , Copy_u8_Pin_ID);
                        CLR_BIT(GPIOB_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;
                    case PULL_DOWN:
                        CLR_BIT(GPIOB_PUPDR , Copy_u8_Pin_ID);
                        SET_BIT(GPIOB_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;

                    default:
                        break;
                }
                break;
            case GPIOC:
                switch (Copy_u8_Pull_State)
                {
                    case FLOATING:
                        CLR_BIT(GPIOC_PUPDR , Copy_u8_Pin_ID);
                        CLR_BIT(GPIOC_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;
                    case PULL_UP:
                        SET_BIT(GPIOC_PUPDR , Copy_u8_Pin_ID);
                        CLR_BIT(GPIOC_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;
                    case PULL_DOWN:
                        CLR_BIT(GPIOC_PUPDR , Copy_u8_Pin_ID);
                        SET_BIT(GPIOC_PUPDR , ((2 * Copy_u8_Pin_ID) + 0x01));
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}

/*Description: Setting the output PIN Non Atomic (Read - Modify - Write) */

/*Copy_u8_Port_ID: GPIOA, GPIOB, GPIOC */
/*Copy_u8_Pin_ID : PIN0 : PIN31 */
/*Copy_u8_Type   : FLOATING, PULL_OP, PULL_DOWN */
void GPIO_void_Set_Pin_Value_Non_Atomic(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Sense_level )
{
    if((Copy_u8_Port_ID > GPIOC) || (Copy_u8_Pin_ID > PIN_15))
    {
        /*Nothing*/
    }
    else
    {
        
    }
}

/*Description: Setting the output PIN Non Atomic (Read - Modify - Write) */

/*Copy_u8_Port_ID: GPIOA, GPIOB, GPIOC */
/*Copy_u8_Pin_ID : PIN0 : PIN31 */
/*Copy_u8_Type   : FLOATING, PULL_OP, PULL_DOWN */
void GPIO_void_Set_Pin_Value_Atomic(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID, u8 Copy_u8_Sense_level )
{
    if((Copy_u8_Port_ID > GPIOC) || (Copy_u8_Pin_ID > PIN_15))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Port_ID)
        {
            case GPIOA:
                switch (Copy_u8_Sense_level)
                {
                    case SET:
                        GPIOA_BSRR = (1 << Copy_u8_Pin_ID);
                        break;
                    case RST:
                        GPIOA_BSRR = (1 << (Copy_u8_Pin_ID + 16));
                        break;

                    default:
                        break;
                }
                break;
            case GPIOB:
                switch (Copy_u8_Sense_level)
                {
                    case SET:
                        GPIOB_BSRR = (1 << Copy_u8_Pin_ID);
                        break;
                    case RST:
                        GPIOB_BSRR = (1 << (Copy_u8_Pin_ID + 16));
                        break;

                    default:
                        break;
                }
                break;
            case GPIOC:
                switch (Copy_u8_Sense_level)
                {
                    case SET:
                        GPIOC_BSRR = (1 << Copy_u8_Pin_ID);
                        break;
                    case RST:
                        GPIOC_BSRR = (1 << (Copy_u8_Pin_ID + 16));
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }
}
u8 GPIO_u8_Set_Pin_Get_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID )
{
    u8 Local_u8_Ret = 0;
    if((Copy_u8_Port_ID > GPIOC) || (Copy_u8_Pin_ID > PIN_15))
    {
        /*Nothing*/
    }
    else
    {
        switch (Copy_u8_Port_ID)
        {
            case GPIOA:
                Local_u8_Ret = READ_BIT(GPIOA_IDR , Copy_u8_Pin_ID);
                break;
            case GPIOB:
                Local_u8_Ret = READ_BIT(GPIOB_IDR , Copy_u8_Pin_ID);
                break;
            case GPIOC:
                Local_u8_Ret = READ_BIT(GPIOC_IDR , Copy_u8_Pin_ID);
                break;

            default:
                break;
        }
    }
    return Local_u8_Ret;
}
