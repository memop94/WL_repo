/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: WL_AppLayer.c $
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
 * $Log: WL_AppLayer.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "API/WL_AppLayer.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/
volatile T_SWORD rsw_WindowPos = 0;

T_UWORD ruw_AntiPinchCon = 1;

static T_ULONG lul_ValidTime = 0;
static T_ULONG lul_PressTime = 0;

T_ULONG lul_TimeCounterUp = 400;
T_ULONG lul_TimeCounterDw = 400;

extern T_UBYTE state_flag;

static T_UBYTE lub_ValidMA = 0;

/* Private functions prototypes */
/*============================================================================*/


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/
T_ULONG WL_CheckValid(T_UBYTE channel)
{  /* ------------------------------------------------------------------------
	*  Name                 :  	WL_CheckValid  
	*  Description          :  	Check if counter has reached 10 clock tick of
	*  							the scheduler
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	static T_UBYTE lub_Valid = 0;
	
	if(GPIO_GetState(channel) == 1)
	{
		if (lul_ValidTime >= 10)
		{
			lub_Valid = 1;
			lul_ValidTime = 0;
		}
		else
		{
			lul_ValidTime++;
			lub_Valid = 0;
		}
	}
	else{};
	

	return lub_Valid;
}

T_ULONG WL_CheckAutoManual(T_UBYTE channel)
{  /* ------------------------------------------------------------------------
	*  Name                 :  	WL_CheckAutoManual
	*  Description          :  	Check if the movement will be Auto or Manual
	*  						   	lub_Valid return 0 if AUTO, 1 if manual
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	
	if (GPIO_GetState(channel) == 1 && lub_ValidMA == 0)
	{
		if (lul_PressTime >= 490)
			{
				lub_ValidMA = 1;
				lul_PressTime = 0;
			}
		else
			{
				lub_ValidMA = 0;
				lul_PressTime++;
			}
	}
	return lub_ValidMA;
}

void WL_WinMUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos > NUMLEDS)
	{
		rsw_WindowPos = NUMLEDS;
		GPIO_SetState(LED_UP, 0);
		state_flag = E_DEFAULT;
	}
	
	else
	{
		if (GPIO_GetState(SW_UP)){
			if (lul_TimeCounterUp >= 400)
			{
				GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 1);
				if (rsw_WindowPos < NUMLEDS){
					GPIO_SetState(LED_UP, 1);
				}
				else{}
				lul_TimeCounterUp = 1;
				rsw_WindowPos++;
			}
			else
			{
				lul_TimeCounterUp++;
			}
		}
		else
		{
			state_flag = E_DEFAULT;
			lub_ValidMA = 0;
		}
	}
}

void WL_WinAUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos > NUMLEDS)
	{
		state_flag = E_DEFAULT;
		rsw_WindowPos = NUMLEDS;
		GPIO_SetState(LED_UP, 0);
	}
	else
	{
		if (lul_TimeCounterUp >= 400)
		{
			GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 1);
			if (rsw_WindowPos <= NUMLEDS)
			{
				GPIO_SetState(LED_UP, 1);
			}
			else
			{
				/*DO NOTHING*/
			}
			lul_TimeCounterUp = 1;
			rsw_WindowPos++;
		}
		else
		{
			lul_TimeCounterUp++;
		}
	}
}

void WL_WinMDw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos < 0)
	{
		rsw_WindowPos = 0;
		GPIO_SetState(LED_DOWN, 0);
		state_flag = E_DEFAULT;
	}
	else
	{
		if (GPIO_GetState(SW_DOWN)){
			if (lul_TimeCounterDw >= 400)
			{
					GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 0);
					if (rsw_WindowPos >= 0){
						GPIO_SetState(LED_DOWN, 1);
					}
					else{}
					lul_TimeCounterDw = 1;
					rsw_WindowPos--;
			}
			else
			{
				lul_TimeCounterDw++;
			}
		}
		else
		{
			state_flag = E_DEFAULT;
			lub_ValidMA = 0;
		}
	}
}

void WL_WinADw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos < 0)
	{
		state_flag = E_DEFAULT;
		rsw_WindowPos = 0;
		GPIO_SetState(LED_DOWN, 0);
	}
	else
	{
		if (lul_TimeCounterDw >= 400)
		{
			GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 0);
			if (rsw_WindowPos >= 0){
				GPIO_SetState(LED_DOWN, 1);
			}
			else{}
			lul_TimeCounterDw = 1;
			rsw_WindowPos--;
		}
		else
		{
			lul_TimeCounterDw++;
		}
	}
}

void WL_A_Pinch(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	GPIO_SetState(LED_UP, 0);
	if(rsw_WindowPos >= 0)
	{
		WL_WinADw();
	}
	else{
		blockButtons();
	}
}

void blockButtons()
{
	GPIO_SetState(LED_DOWN, 0);
	
	//disable buttons
	GPIO_En(SW_UP,  0x0000); 	 /* disable pin of SW2	*/
	GPIO_En(SW_DOWN,  0x0000); 	 /* disable pin of SW1  */
	
	wait5seconds();
}

void wait5seconds()
{
	static T_ULONG lul_Counter = 0;
	
	if (lul_Counter <= 5000){
		state_flag = E_ANTIPINCH;
		lul_Counter++;
	}
	else{
		lul_Counter = 0;
		
		//enable buttons
		GPIO_En(SW_UP,  0x0100); 	 /* enable pin of SW2	*/
		GPIO_En(SW_DOWN,  0x0100); 	 /* enable pin of SW1  */
		
		state_flag = E_DEFAULT;
	}
}

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
