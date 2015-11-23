/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: TASK_Init.c $
 * $Revision: 3.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 21/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** In this function the task of the scheduler are defined and configured
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     |    			    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: TASK_Init.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "TASK_Init.h"


/* Constants and types  */
/*============================================================================*/
/*- The period 0 means that the functions will be called in each tick clock - */

#define taskPeriod1 0
#define taskPeriod2 0
#define taskPeriod3 0
#define taskPeriod4 0

#define taskOffset1 0
#define taskOffset2 1
#define taskOffset3 2
#define taskOffset4 3

const S_TASK cas_TaskList[E_TASK_NUM] = {
  /*{Pointer to the function, Period, Offset}*/
	{VALIDATE  			, 	taskPeriod1, 	taskOffset1	},
	{CHECK_MANUAL_AUTO	, 	taskPeriod2, 	taskOffset2	},
	{ANTI_PINCH			, 	taskPeriod3, 	taskOffset3	},
	{STATE_MACHINE		, 	taskPeriod4, 	taskOffset4	}
};
 
/* Variables */
/*============================================================================*/
T_ULONG ValidUp = 0;
T_ULONG ValidDw = 0;
T_ULONG ValidAP = 0;

extern T_UBYTE state_flag;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* ============= The functions of the tasks must be defined here ============ */
void VALIDATE(void)
{ /* ------------------------------------------------------------------------
	*  Name                 :  	VALIDATE  
	*  Description          :  	Read the state of the UP and DOWN switches, if
	*  							one of them is on it will call the WL_CheckValid
	*  							function to verify if its valid. This will happen
	*  							as long as the state_flag is E_DEFAULT, this to 
	*  							prevent that the function is called once it had been
	*  							validated and the window is in movement.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	if (state_flag == E_DEFAULT)
	{
		if(GPIO_GetState(SW_UP)){
			ValidUp = WL_CheckValid(SW_UP);
		}
		else{
			if(GPIO_GetState(SW_DOWN)){
				ValidDw = WL_CheckValid(SW_DOWN);
			}
			else{
					ValidUp = INVALID;
					ValidDw = INVALID;
				}
			}	
		}
	else{}
}
void CHECK_MANUAL_AUTO(void)
{ /* ------------------------------------------------------------------------
	*  Name                 :  	CHECK_MANUAL_AUTO  
	*  Description          :  	Once the button had been validated, read the state 
	*  							to verify that is still on, if one of them is on 
	*  							it will call the WL_CheckAutoManual	To change the
	*  							state_flag to the corresponding MANUAL or AUTO routine. 
	*  							This will happen as long as the state_flag is different
	*  							from E_ANTIPINCH, this to prevent that the function is 
	*  							called during the anti-pinch routine.
	*  Parameters           :  	void 
	*  Return               :  	void
	* 
    */
	if (state_flag != E_ANTIPINCH){
		if (ValidUp != INVALID){
			if (WL_CheckAutoManual(SW_UP)){
				state_flag = E_MANUAL_UP;
			}
			else{
				state_flag = E_AUTO_UP;
			}
		}
		else{}
		
		if (ValidDw != INVALID){
			if (WL_CheckAutoManual(SW_DOWN)){
				state_flag = E_MANUAL_DW;
			}
			else {
				state_flag = E_AUTO_DW;
			}
		}
		else{}
	}
	else{}	
}
void ANTI_PINCH(void)
{ /* ------------------------------------------------------------------------
	*  Name                 :  	ANTI_PINCH  
	*  Description          :  	This function can only be called if the window is
	*  							moving up (closing), or if the anti-pinch has already
	*  							been activated. It will read the state of the SW_A_PINCH
	*  							if its on, it check if its a valid press. Once it has been 
	*  							validated it will change the state_flag to E_ANTIPINCH
	*  Parameters           :  	void 
	*  Return               :  	void
	* 
    */
	
	if(state_flag == E_MANUAL_UP || state_flag == E_AUTO_UP || state_flag == E_ANTIPINCH)
	{
		if(GPIO_GetState(SW_A_PINCH))
		{
			ValidAP = WL_CheckValid(SW_A_PINCH);
		}
		else{
			ValidAP = INVALID;
		}
		
		if (ValidAP){
			state_flag = E_ANTIPINCH;
		}
		else{
			
		}
	}
	else {}
}
void STATE_MACHINE(void)
{ /* ------------------------------------------------------------------------
	*  Name                 :  	STATE_MACHINE  
	*  Description          :  	This function calls the state machine that controls
	*  							the window movement, depending on the flags defined
	*  							by the previous functions. It will always be called. 
	*  Parameters           :  	void 
	*  Return               :  	void
	* 
    */
	
	StateMachine ();
	
}

/* Exported functions */
/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
