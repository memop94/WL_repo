/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: TASK_Init.c $
 * $Revision: 2.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 17/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
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
/*                     |    FirstScheduler  |                                 */
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
void VALIDATE(void){
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
					ValidUp = 0;
					ValidDw = 0;
				}
			}	
		}
	else{}
}
void CHECK_MANUAL_AUTO(void){
	if (state_flag != E_ANTIPINCH){
		if (ValidUp == 1){
			if (WL_CheckAutoManual(SW_UP)){
				state_flag = E_MANUAL_UP;
			}
			else{
				state_flag = E_AUTO_UP;
			}
		}
		else{}
		
		if (ValidDw == 1){
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
void ANTI_PINCH(void){
	
	if(state_flag == E_MANUAL_UP || state_flag == E_AUTO_UP || state_flag == E_ANTIPINCH)
	{
		if(GPIO_GetState(SW_A_PINCH))
		{
			ValidAP = WL_CheckValid(SW_A_PINCH);
		}
		else{
			ValidAP = 0;
		}
		
		if (ValidAP){
			state_flag = E_ANTIPINCH;
		}
		else{
			
		}
	}
	else {}
}
void STATE_MACHINE(void){
	
	StateMachine ();
	
}

/* Exported functions */
/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
