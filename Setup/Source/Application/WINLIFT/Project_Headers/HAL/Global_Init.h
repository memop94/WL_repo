/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Global_Init.h $
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
/*                     |    FirstScheduler  |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: Global_init.h  $
  ============================================================================*/
#ifndef Global_Init_H
#define Global_Init_H

/* Includes */
/*============================================================================*/
#include "MPC5606B.h"
#include "stdtypedef.h"
#include "IntcInterrupts.h"

/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
extern void Global_Init(void);
void INTC_init(void);
void STM_init(void);
void initModesAndClock(void);
void GPIO_En(T_SWORD, T_UWORD);
void GPIO_Init(void);


#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
