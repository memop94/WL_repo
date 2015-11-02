/*
 * WL_WinProcessing.c
 *
 *  Created on: Nov 1, 2015
 *      Author: x
 */

#include "WL_WinProcessing.h"
void init_PIT()
{
	PIT.PITMCR.B.MDIS = 0 ;
}
//It counts the time of a button press 
T_ULONG countPressTime( )
{
	T_ULONG lul_TimeCounter;
	STM.CNT.R = 0;
	if(GPIO_GetState(SW_UP))
	{
		while(GPIO_GetState(SW_UP))
		{
			
		}
		lul_TimeCounter = STM.CNT.R;
		return lul_TimeCounter;
	}
	
	if(GPIO_GetState(SW_DOWN))
	{
		while(GPIO_GetState(SW_DOWN))
		{
			
		}
		lul_TimeCounter = STM.CNT.R;
		return lul_TimeCounter;
	}
	
	return 0;
}

//This function disable all the buttons for 5 seconds
void blockButtons()
{
	//disable buttons
	SIU.PCR[66].B.IBE = 0;
	SIU.PCR[67].B.IBE = 0;
	
	wait5seconds();
	
	//enable buttons
	SIU.PCR[66].B.IBE = 1;
	SIU.PCR[66].B.IBE = 1;
}

void wait5seconds()
{
	STM.CNT.R = 0x00000000; 
	while(0x1312d000 > STM.CNT.R)//5 sec
	{
	}
	STM.CNT.R = 0x00000000; 
}

