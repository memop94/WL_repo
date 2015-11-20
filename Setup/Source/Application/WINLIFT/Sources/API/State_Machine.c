/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: State_Machine.c $
 * $Revision: 1 $
 * $Author: Guillermo Ramirez $
 * $Date: 19/11/2015 $
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
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: State_Machine.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "API/State_Machine.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
T_UBYTE state_flag = E_DEFAULT;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
void StateMachine (void){
	switch(state_flag){
	
		case E_MANUAL_UP :
			WL_WinMUp();
			break;
		
		case E_AUTO_UP :
			WL_WinAUp();
			break;
				
		case E_MANUAL_DW :
			WL_WinMDw();
			break;
				
		case E_AUTO_DW :
			WL_WinADw();
			break;
		
		case E_ANTIPINCH :
			WL_A_Pinch();
			break;
		
		case E_DEFAULT :
			GPIO_SetState(LED_UP, 0);
			GPIO_SetState(LED_DOWN, 0);
			break;
			
		default :
			break;
	}
}


/* Exported functions */
/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
