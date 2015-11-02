/*
 *      File        : WL_STM.h
 *      Created on  : Oct 26, 2015
 *      Authors     : Oscar Miranda, Guillermo Ramirez
 *      Description : Window Lifter STM Intialization and Functions
 */


#ifndef WL_STM_H_
#define WL_STM_H_

#include "MPC5606B.h"
#include "stdtypedef.h"
#include "IntcInterrupts.h"
#include "WL_FUNCTIONS.h"
#include "WL_WinProcessing.h"

void WL_STM_init(void);

T_ULONG WL_CheckValid(void);

T_ULONG WL_CheckAutoManualUp(void);
T_ULONG WL_CheckAutoManualDw(void);

void WL_WinMUp(void);
void WL_WinAUp(void);
void WL_WinMDw(void);
void WL_WinADw(void);

void WL_A_Pinch(void);

#endif /* WL_STM_H_ */
