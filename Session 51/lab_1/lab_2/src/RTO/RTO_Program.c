/*
 * RTO_Program.c
 *
 *  Created on: Apr 19, 2023
 *      Author: Ahmed Abdalla
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_MATH.h"




/***********************************MCAL Includes************************************/
#include "../../include/MCAL/SYS_TICK/STK_Interface.h"

#include "../../include/RTO/RTO_Interface.h"
#include "../../include/RTO/RTO_cfg.h"
#include "../../include/RTO/RTO_Private.h"

RTO_TCB_T RTO_ARR_Tasks[RTO_u8_MAX_NUMBER_TASKD];

void RTO_init(void)
{

	//start SYS_TICK
	MSTK_void_Init();

	MSTK_void_Set_Interval_Periodic(2000 , &RTO_void_Schedular);

	//SYS_TICK_void_Set_handler(2000);
}

static void RTO_void_Schedular(void)
{
	u8 local_u8_counter = 0;

	//loop on ready task
	for (local_u8_counter = 0; local_u8_counter < RTO_u8_MAX_NUMBER_TASKD; local_u8_counter++)
	{
		if(RTO_ARR_Tasks[local_u8_counter].First_Delay == 0 && (NULL != RTO_ARR_Tasks[local_u8_counter].pf))
		{
			//call task function
			RTO_ARR_Tasks[local_u8_counter].pf();
			
			//update first delay value by Periodacity
			RTO_ARR_Tasks[local_u8_counter].First_Delay = RTO_ARR_Tasks[local_u8_counter].Periodcicity - 1;
		}
		else
		{
			(RTO_ARR_Tasks[local_u8_counter].First_Delay)--;
		}
	}
	

}


u8 RTO_Create_Task(RTO_TCB_T * ref_RTO_TCB_task_info , u8 Copy_u8_Priority)
{

	if((Copy_u8_Priority > RTO_u8_MAX_NUMBER_TASKD) || (NULL == ref_RTO_TCB_task_info))
	{
		/*nothing*/
	}
	else
	{
		RTO_ARR_Tasks[Copy_u8_Priority].First_Delay = ref_RTO_TCB_task_info->First_Delay;
		RTO_ARR_Tasks[Copy_u8_Priority].Periodcicity = ref_RTO_TCB_task_info->Periodcicity;
		RTO_ARR_Tasks[Copy_u8_Priority].pf = ref_RTO_TCB_task_info->pf;

	}
	return 0;
}
