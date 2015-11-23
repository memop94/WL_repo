/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO_APP.c $
 * $Revision: 1.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 17/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** This file contains the function that directly interact with the pins, to 
 * read their status or to write it.
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
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/GPIO_APP.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/
T_UBYTE GPIO_GetState (T_UWORD ch)
{
	/* --------------------------------------------------------------------------
	*  Name                 :  GPIO_GetState
	*  Description          :  Get the state of a pin, the pin is defined in ch
	*  Parameters           :  T_UWORD 
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	T_UBYTE result;

    result = (T_UBYTE)SIU.GPDI[ch].B.PDI;

    return(result);
}

void GPIO_SetState (T_UWORD ch, T_UBYTE value)
{/* --------------------------------------------------------------------------
	*  Name                 :  GPIO_SetState
	*  Description          :  Set the value received to the pin specified in ch
	*  Parameters           :  T_UWORD, T_UBYTE
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
    SIU.GPDO[ch].B.PDO = value;
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
