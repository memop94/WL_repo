/*
 * WL_WinProcessing.h
 *
 *  Created on: Nov 1, 2015
 *      Author: x
 */
#include "MPC5606B.h"
#include "stdtypedef.h"
#include "driver_channel_MPC5606B.h"
#include "GPIO_State.h"
#ifndef WL_WINPROCESSING_H_
#define WL_WINPROCESSING_H_


//enum windowState {CLOSED, OPEN, LIFTING }e_wState;
void init_PIT();
T_ULONG countPressTime( ); 
void blockButtons(); 
void wait5seconds(); 

#endif /* WL_WINPROCESSING_H_ */
