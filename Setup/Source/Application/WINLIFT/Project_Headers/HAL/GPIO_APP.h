/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO_APP.h $
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
 * $Log: GPIO_APP.h  $
  ============================================================================*/
#ifndef GPIO_APP_H
#define GPIO_APP_H

/* Includes */
/*============================================================================*/
#include "driver_channel_MPC5606B.h"
#include "MPC5606B.h"
#include "stdtypedef.h"

/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void LED_TOGGLE(T_UWORD);
uint8_t GPIO_GetState (uint16_t);
void GPIO_SetState (uint16_t ch, uint8_t value);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
