/*
 * winlift.c
 *
 *  Created on: Oct 31, 2015
 *      Author: x
 */
#include "winlift.h"

//pcr[1-9] barra de leds
//pcr[10] open
//pcr[11] close
//switches pcr[66(close)-67(open)]

//Lifts the window
void closeWindow() //not totally implemented
{	
	if (e_wState == OPEN)
	{
		e_wState = LIFTING;
		blueLed_close(0);
		//here goes code to simulate the transition of the window
		blueLed_close(1);
		e_wState = CLOSED;
	}
}

//Lowers the window
void openWindow()//not totally implemented
{
	if (e_wState == CLOSED)
	{
		greenLed_close(0);
		//here goes code to simulate the transition of the window
		greenLed_close(1);
		e_wState = OPEN;
	}
}

//Turns on/off the blue Led (close window)
//ledState == 0 turns on the led
//ledState != 0 turns off the led
void blueLed_close(T_UBYTE ledState)
{
	if(0!=ledState)
	{
		SIU.GPDO[11].B.PDO = 1;
	}
	else
	{
		SIU.GPDO[11].B.PDO = 0;
	}
}

//Turns on/off the green Led (closing window)
//ledState == 0 turns on the led
//ledState != 0 turns off the led
void greenLed_open(T_UBYTE ledState )
{
	if(0!=ledState)
	{
		SIU.GPDO[10].B.PDO = 1;
	}
	else
	{
		SIU.GPDO[10].B.PDO = 0;
	}
}

//It validates the time press button (time press > 10 ms)
//And choose a manual or automatic action 
T_UBYTE validateButtonPress(){}

//Stops and lowers the window, and block the inputs
void antipinch()//not totally implemented
{
	if(validate())
	{
		openWindow(); 
		blockButtons();
	}
}

//It counts the time of a button press 
T_UWORD countPressTime( ){}

//This function disable all the buttons for 5 seconds
void blockButtons()//not totally implemented
{
	//disable buttons
	SIU.PCR[66].B.IBE = 0;
	SIU.PCR[67].B.IBE = 0;
	
	openWindow();
	wait5seconds();
	
	//enable buttons
	SIU.PCR[66].B.IBE = 1;
	SIU.PCR[66].B.IBE = 1;
}

void wait5seconds(){}
