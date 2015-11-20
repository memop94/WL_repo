/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.x $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
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
 * $Log: State_Machine.h  $
  ============================================================================*/
#ifndef State_Machine_H
#define State_Machine_H

/* Includes */
/*============================================================================*/
#include "stdtypedef.h"
#include "driver_channel_MPC5606B.h"
#include "OS_Init.h"
#include "HAL/GPIO_APP.h"
#include "API/WL_AppLayer.h"

/* Constants and types */
/*============================================================================*/
extern enum
{
	E_MANUAL_UP, 
	E_AUTO_UP,
	E_MANUAL_DW, 
	E_AUTO_DW,
	E_ANTIPINCH,
	E_DEFAULT
};

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
void StateMachine (void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
