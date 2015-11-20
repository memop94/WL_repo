/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: OS_Init.c $
 * $Revision: 1.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 13/11/2015 $
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
/*                     |   FirstScheduler   |             1.0                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: OS_Init.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "OS_Init.h"

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/
T_UBYTE ub_TickFlag;

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
void Tick_Flag(void)
{  /* --------------------------------------------------------------------------
	*  Name                 :  Tick_Flag
	*  Description          :  Check if the channel 0 of the STM as reached 10ms
	*  						   and raise a flag when reached
	*  Parameters           :  void 
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	if (STM.CH[0].CIR.B.CIF)
	{
		ub_TickFlag = 1;
		STM.CH[0].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
	}
}

/* Exported functions */
/*============================================================================*/


/* Notice: the file ends with a blank new line to avoid compiler warnings */
