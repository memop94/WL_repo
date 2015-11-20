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
void LED_TOGGLE(T_UWORD ch)
{
		SIU.GPDO[ch].B.PDO ^= 1;
}

uint8_t GPIO_GetState (uint16_t ch)
{
    uint8_t result;

    result = (uint8_t)SIU.GPDI[ch].B.PDI;

    return(result);
}

void GPIO_SetState (uint16_t ch, uint8_t value)
{
    SIU.GPDO[ch].B.PDO = value;
}



/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not

uint8 algreqg_olp_CheckOLPAllow(uint8 ReqestedAction_u8,       /**< the requested action to be performed (e.g. unlock) 
                                uint16 RequestedComponent_u16  /**< the mask of the doors which motors to be activated (e.g. front doors) 
                                )
{
	return 0;
}
*/

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
