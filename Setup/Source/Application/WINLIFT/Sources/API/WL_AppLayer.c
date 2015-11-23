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
    THIS FILE CONTAINS THE FUNCTIONS THAT ARE DIRECTLY RELATED WITH THE 
    FUNCTIONALITIES OF THE WINDOW LIFTER.
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
	*  Description          :  	As long as a button is press, check if the button 
	*  							press is valid (to avoid debounce), the button  
	*  							verified is the one specified in channel. If it 
	*  							have not reached yet increase the lul_ValidTime 
	*  							by one, every time that the function is called, 
	*  							and returns a invalid value in the lub_Valid 
	*  							variable. When the counter reach 10, lub_Valid 
	*  							return a valid value
	*  Parameters           :  	T_UBYTE 
	*  Return               :  	T_ULONG
	*  -----------------------------------------------------------------------
	*/
	static T_UBYTE lub_Valid = 0;
	
	if(GPIO_GetState(channel) != OFF)
	{
		if (lul_ValidTime >= VALID_TIME)
		{
			lub_Valid = VALID;
			lul_ValidTime = 0;
		}
		else
		{
			lul_ValidTime++;
			lub_Valid = INVALID;
		}
	}
	else{};
	
	return lub_Valid;
}

T_ULONG WL_CheckAutoManual(T_UBYTE channel)
{  /* ------------------------------------------------------------------------
	*  Name                 :  	WL_CheckAutoManual
	*  Description          :  	As long as a button is press, and it has been 
	*  							validated, check if the routine to execute is   
	*  							manual or automatic, this will be for the
	*  							movement specified in channel (Up or Down). 
	*  							If the counter (lul_PressTime) donot reached 490 
	*  							counts (which will be 500 when the 10 in WL_CheckValid()
	*  							are counted) is AUTO. But if the counter (lul_PressTime)
	*  							reached 490 counts it will be manual.
	*  Parameters           :  	T_UBYTE 
	*  Return               :  	T_ULONG
	*  -----------------------------------------------------------------------
	*/
	
	if (GPIO_GetState(channel) != OFF && lub_ValidMA == AUTO)
	{
		if (lul_PressTime >= MANUAL_TIME)
			{
				lub_ValidMA = MANUAL;
				lul_PressTime = 0;
			}
		else
			{
				lub_ValidMA = AUTO;
				lul_PressTime++;
			}
	}
	return lub_ValidMA;
}

void WL_WinMUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  	WL_WinMUp
	*  Description          :  	Close the window manually by making a "sweep" 
	*  							through the LED_BAR, as long as rsw_WindowPos
	*  							is bigger than NUMLEDS, which means that the window
	*  							is not completely close yet. As long as the SW_UP
	*  							button is pressed the sweep will turn on a LED 
	*  							every 400 counts of lul_TimeCounterUp. Once it reaches
	*  							400 the counter is reseted and rsw_WindowPos increase by 
	*  							one, to turn on a different LED the next time.
	*  							While the button is pressed, state_flag, will be E_MANUAL_UP,
	*  							but when is completely close, or the button is not pressed any
	*  							more, state_flag will be E_DEFAULT.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos > NUMLEDS)
	{
		rsw_WindowPos = NUMLEDS;
		GPIO_SetState(LED_UP, OFF);
		state_flag = E_DEFAULT;
	}
	
	else
	{
		if (GPIO_GetState(SW_UP) != OFF)
		{
			if (lul_TimeCounterUp == TRANSITION_TIME)
			{
				GPIO_SetState(LED_BAR_0 + rsw_WindowPos, ON);
				if (rsw_WindowPos < NUMLEDS){
					GPIO_SetState(LED_UP, ON);
				}
				else{}
				lul_TimeCounterUp = 0;
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
	*  Name                 :  	WL_WinMUp
	*  Description          :  	Close the window automatically by making a "sweep" 
	*  							through the LED_BAR, as long as rsw_WindowPos
	*  							is bigger than NUMLEDS, which means that the window
	*  							is not completely close yet. It will turn on a LED 
	*  							every 400 counts of lul_TimeCounterUp. Once it reaches
	*  							400 the counter is reseted and rsw_WindowPos increase by 
	*  							one, to turn on a different LED the next time.
	*  							While the window is not close yet, state_flag, will be E_MANUAL_UP,
	*  							but when is completely close, state_flag will be E_DEFAULT.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos > NUMLEDS)
	{
		state_flag = E_DEFAULT;
		rsw_WindowPos = NUMLEDS;
		GPIO_SetState(LED_UP, OFF);
	}
	else
	{
		if (lul_TimeCounterUp >= TRANSITION_TIME)
		{
			GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 1);
			if (rsw_WindowPos <= NUMLEDS)
			{
				GPIO_SetState(LED_UP, ON);
			}
			else
			{
				/*DO NOTHING*/
			}
			lul_TimeCounterUp = 0;
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
	*  Name                 :  	WL_WinMUp
	*  Description          :  	Open the window manually by making a "sweep" 
	*  							through the LED_BAR, as long as rsw_WindowPos
	*  							is minor than NUMLEDS, which means that the window
	*  							is not completely open yet. As long as the SW_DOWN
	*  							button is pressed the sweep will turn off a LED 
	*  							every 400 counts of lul_TimeCounterDw. Once it reaches
	*  							400 the counter is reseted and rsw_WindowPos decrease by 
	*  							one, to turn off a different LED the next time.
	*  							While the button is pressed, state_flag, will be E_MANUAL_DW,
	*  							but when is completely open, or the button is not pressed any
	*  							more, state_flag will be E_DEFAULT.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos < 0)
	{
		rsw_WindowPos = 0;
		GPIO_SetState(LED_DOWN, OFF);
		state_flag = E_DEFAULT;
	}
	else
	{
		if (GPIO_GetState(SW_DOWN)){
			if (lul_TimeCounterDw >= TRANSITION_TIME)
			{
					GPIO_SetState(LED_BAR_0 + rsw_WindowPos, OFF);
					if (rsw_WindowPos >= 0){
						GPIO_SetState(LED_DOWN, ON);
					}
					else{}
					lul_TimeCounterDw = 0;
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
	*  Name                 : 	WL_WinMUp
	*  Description          :  	Open the window automatically by making a "sweep" 
	*  							through the LED_BAR, as long as rsw_WindowPos
	*  							is minor than NUMLEDS, which means that the window
	*  							is not completely open yet. It will turn on a LED 
	*  							every 400 counts of lul_TimeCounterDw. Once it reaches
	*  							400 the counter is reseted and rsw_WindowPos decrease by 
	*  							one, to turn off a different LED the next time.
	*  							While the window is not open yet, state_flag, will be E_MANUAL_DW,
	*  							but when is completely open, state_flag will be E_DEFAULT.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	if (rsw_WindowPos < 0)
	{
		state_flag = E_DEFAULT;
		rsw_WindowPos = 0;
		GPIO_SetState(LED_DOWN, OFF);
	}
	else
	{
		if (lul_TimeCounterDw >= TRANSITION_TIME)
		{
			GPIO_SetState(LED_BAR_0 + rsw_WindowPos, OFF);
			if (rsw_WindowPos >= 0){
				GPIO_SetState(LED_DOWN, ON);
			}
			else{}
			lul_TimeCounterDw = 0;
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
	*  Name                 :  	WL_WinMUp
	*  Description          :  	This function can only be called when the window is
	*  							going up, it ensures that the LED_UP is turned off.
	*  							Then open the window automatically using WL_WinADw, when 
	*  							the window is completely open calls the blockButtons
	*  							function.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	GPIO_SetState(LED_UP, OFF);
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
	/* ------------------------------------------------------------------------
	*  Name                 :  	blockButtons
	*  Description          :  	Disable the inputs buttons and creates and wait 5s
	*  							before re-enable them. Every time the function is called
	*  							lul_Counter will increase by one, if it has not reached
	*  							5s (or 5000 counts) state_flag will be E_ANTIPINCH. When
	*  							it reached the 5s the buttons re-enable and state_flag changes
	*  							to E_DEFAULT.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	static T_ULONG lul_Counter = 0;
	GPIO_SetState(LED_DOWN, OFF);
	
	//disable buttons
	GPIO_En(SW_UP,  DISABLE); 	 /* disable pin of SW2	*/
	GPIO_En(SW_DOWN,  DISABLE); 	 /* disable pin of SW1  */
	
	if (lul_Counter <= STAND_BY_TIME){
		state_flag = E_ANTIPINCH;
		lul_Counter++;
	}
	else{
		lul_Counter = 0;
		
		//enable buttons
		GPIO_En(SW_UP,  ENABLE); 	 /* enable pin of SW2	*/
		GPIO_En(SW_DOWN,  ENABLE); 	 /* enable pin of SW1  	*/
		
		state_flag = E_DEFAULT;
	}
}

/* Exported functions */
/*============================================================================*/


/* Notice: the file ends with a blank new line to avoid compiler warnings */
