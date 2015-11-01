/*
 * winlift.h
 *
 *  Created on: Oct 29, 2015
 *      Author: x
 */

#ifndef WINLIFT_H_
#define WINLIFT_H_
#include "gpio_drv.h"

enum windowState {CLOSED, OPEN, LIFTING }e_wState;

void closeWindow();
void openWindow(); 
void blueLed_close(T_UBYTE ledState);
void greenLed_open(T_UBYTE ledState);
void antipinch(); 
T_UBYTE validateButtonPress();
T_UWORD countPressTime( ); 
void blockButtons(); //not totally implemented
void wait5seconds(); //not implemented

#endif /* WINLIFT_H_ */

