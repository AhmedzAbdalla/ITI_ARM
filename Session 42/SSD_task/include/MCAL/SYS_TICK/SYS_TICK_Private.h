#ifndef SYS_TICK_PRIVATE_H
#define SYS_TICK_PRIVATE_H


#define SYS_TICK_Base_address        0xE000E010 

#define STK_CTRL_reg    (*(volatile u32*)( SYS_TICK_Base_address+ 0x00))
#define STK_LOAD_reg    (*(volatile u32*)( SYS_TICK_Base_address+ 0x04))
#define STK_VAL_reg     (*(volatile u32*)( SYS_TICK_Base_address+ 0x08))
#define STK_CALIB_reg   (*(volatile u32*)( SYS_TICK_Base_address+ 0x0C))  



//STK_CTRL_reg Bits

#define STK_CTRL_ENABLE               0x00
#define STK_CTRL_TICKINT              0x01
#define STK_CTRL_CLKSOURCE            0x02 
#define STK_CTRL_COUNTFLAG            0x10
   
#define STK_CTRL_SINGLE_INTERVAL      0X00
#define STK_CTRL_PERIODIC_INTERVAL    0X01

#endif //SYS_TICK_PRIVATE_H
