/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: WL_AppLayer.h $
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
 * $Log: WL_AppLayer.h  $
  ============================================================================*/
#ifndef WL_AppLayer_H
#define WL_AppLayer_H

/* Includes */
/*============================================================================*/
#include "stdtypedef.h"
#include "driver_channel_MPC5606B.h"
#include "HAL/Global_Init.h"
#include "HAL/GPIO_APP.h"
#include "API/State_Machine.h"

/* Constants and types */
/*============================================================================*/
#define SWITCH_INTERR_FLAG SIU.ISR.B.EIF21
/* 10 miliseconds in a frequency of 16MHz*/
#define T10MS 0x9C400
/*400 miliseconds in a frequency of 16MHz*/
#define T400MS 0x186A000
/*500 miliseconds in a frequency of 16MHz*/
#define T500MS 0x1E84800
/*Number of Leds, note that it is counted from 0 to 9: ten elements*/
#define NUMLEDS 9

/* Exported Variables */
/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/
T_ULONG WL_CheckValid(T_UBYTE);

T_ULONG WL_CheckAutoManual(T_UBYTE);

void WL_WinMUp(void);
void WL_WinAUp(void);
void WL_WinMDw(void);
void WL_WinADw(void);

void WL_A_Pinch(void);

void blockButtons(); 
void wait5seconds(); 

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
