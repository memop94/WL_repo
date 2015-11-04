/*
 *      File        : WL_STM.c
 *      Created on  : Oct 26, 2015
 *      Authors     : Oscar Miranda, Guillermo Ramirez
 *      Description : Window Lifter STM Intialization and Functions
 */

#include "WL_STM.h"
#include "GPIO_State.h"

#define SWITCH_INTERR_FLAG SIU.ISR.B.EIF21
/* 10 miliseconds in a frequency of 16MHz*/
#define T10MS 0x9C400
/*400 miliseconds in a frequency of 16MHz*/
#define T400MS 0x186A000
/*500 miliseconds in a frequency of 16MHz*/
#define T500MS 0x1E84800
/*Number of Leds, note that it is counted from 0 to 9: ten elements*/
#define NUMLEDS 9

enum E_WINDOWSTATE {OPEN, CLOSE, LIFTING} e_wstate; 

volatile T_SWORD rsw_WindowPos = 0;
T_UWORD ruw_AntiPinchCon = 1;

void WL_SetState()
{
	e_wstate = CLOSE;	
}

void WL_STM_init(void)
{
    STM.CR.B.TEN        = 0x0;
    STM.CR.B.FRZ        = 0x1;
    STM.CR.B.CPS        = 0;         /* Configure Counter Prescaler, Counter Prescaler is 1     */
    
    STM.CH[0].CMP.R     = T10MS;   /* Compare with 640KHz = 10 msec*/      
    STM.CH[0].CCR.B.CEN = 0x1;       /* System Timer Channel 0: ENABLE                          */
    
    STM.CH[1].CMP.R     = T500MS; /* Compare with 32MHz - 500 msec*/      
    STM.CH[1].CCR.B.CEN = 0x1;       /* System Timer Channel 1: ENABLE                          */
    
    STM.CH[2].CMP.R     = T400MS; /* Compare with 25.6MHz - 400 msec*/      
    STM.CH[2].CCR.B.CEN = 0x1;       /* System Timer Channel 1: ENABLE                          */
    
    STM.CR.B.TEN        = 0x1;       /* Enable System Timer Module                              */
}

T_ULONG WL_CheckValid(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckValid  
	*  Description          :  Check if counter has reached 10msec
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	
	static T_ULONG lul_PressTime = 0;
	static T_UBYTE lub_Valid = 0;
	
	STM.CNT.R = 0;
	lul_PressTime = STM.CNT.R;
	lub_Valid = 0;
	
	while (lub_Valid == 0)
	{
		if (lul_PressTime >= T10MS)
		{
			STM.CNT.R = 0;
			lub_Valid = 1;
		}
		lul_PressTime = STM.CNT.R;
	}
	return lub_Valid;
}

T_ULONG WL_CheckAutoManualUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckAutoManual
	*  Description          :  Check if the movement will be Auto or Manual
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	static T_ULONG lul_PressTime = 0;
	static T_UBYTE lub_Valid = 0;
	
	STM.CNT.R = 0; 				/* Reset counter */
	
	lul_PressTime = STM.CNT.R;
	
	lub_Valid = 0;
	
	while (GPIO_GetState(SW_UP) && lub_Valid == 0)
	{
		
		lul_PressTime = STM.CNT.R;
		
		if (lul_PressTime >= T500MS)
		{
			
			STM.CNT.R = 0;
			lub_Valid = 1;
			
		}
		else
		{
		  /*DO NOTHING*/
		}
	}
	return lub_Valid;
}

T_ULONG WL_CheckAutoManualDw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckAutoManual
	*  Description          :  Check if the movement will be Auto or Manual
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	static T_ULONG lul_PressTime = 0;
	static T_UBYTE lub_Valid = 0;
	STM.CNT.R = 0; 				/* Reset counter */
	lul_PressTime = STM.CNT.R;
	lub_Valid = 0;
	while (GPIO_GetState(SW_DOWN) && lub_Valid == 0)
	{
		lul_PressTime = STM.CNT.R;
		if (lul_PressTime >= T500MS)
		{
			STM.CNT.R = 0;
			lub_Valid = 1;
		}
		else
		{
		  /*DO NOTHING*/
		}
	}
	return lub_Valid;
}

void WL_WinMUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	
	if (STM.CH[2].CIR.B.CIF)
	{
		GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 1);
		STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
		rsw_WindowPos++;
		e_wstate = LIFTING;
		GPIO_SetState(LED_UP, 1);
	}
	else
	{
		/*DO NOTHING*/
	}
	if (rsw_WindowPos > NUMLEDS)
	{
		rsw_WindowPos = NUMLEDS;
		e_wstate = CLOSE;
		GPIO_SetState(LED_UP, 0);
	}
	else
	{
		/*DO NOTHING*/
	}
}

void WL_WinAUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window automatically
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	ruw_AntiPinchCon = 1;
	while(rsw_WindowPos <= NUMLEDS && ruw_AntiPinchCon == 1)
	{
		if (STM.CH[2].CIR.B.CIF)
		{
			GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 1);
			GPIO_SetState(LED_UP, 1);
			GPIO_SetState(LED_DOWN, 0);
			STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
			STM.CNT.R = 0; 				/*Reset counter*/
			rsw_WindowPos++;
			e_wstate = LIFTING;
		}
		else
		{
		  /*DO NOTHING*/
		}
	}
	if (rsw_WindowPos >= NUMLEDS)
	{
		rsw_WindowPos = NUMLEDS;
	}
	e_wstate = CLOSE;
}

void WL_WinMDw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMDw
	*  Description          :  Close the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	if (STM.CH[2].CIR.B.CIF)
	{
		GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 0);
		if (rsw_WindowPos < 1)
		{
			rsw_WindowPos = 0;
			GPIO_SetState(LED_DOWN, 0);
		}
		else
		{
			GPIO_SetState(LED_DOWN, 1);
		}
		STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
		rsw_WindowPos--;
	}
	else
	{
	  /*DO NOTHING*/
	}
}

void WL_WinADw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMDw
	*  Description          :  Close the window automatically
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	while(rsw_WindowPos >= 0)
	{
		if (STM.CH[2].CIR.B.CIF)
		{
			GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 0);
			GPIO_SetState(LED_DOWN, 1);
			GPIO_SetState(LED_UP, 0);
			STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
			STM.CNT.R = 0; 				/*Reset counter*/
			rsw_WindowPos--;
		}
		else
		{
		  /*DO NOTHING*/
		}
	}
	GPIO_SetState(LED_DOWN, 0);
}

void WL_A_Pinch(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_A_Pinch
	*  Description          :  Close the window automatically
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	if (SWITCH_INTERR_FLAG)
	{
		while (e_wstate == LIFTING)
		{
			while(rsw_WindowPos >= 0)
			{
				if (STM.CH[2].CIR.B.CIF)
				{
					GPIO_SetState(LED_BAR_0 + rsw_WindowPos, 0);
					GPIO_SetState(LED_DOWN, 1);
					GPIO_SetState(LED_UP, 0);
					STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
					SWITCH_INTERR_FLAG = 1;
					STM.CNT.R = 0; 				/*Reset counter*/
					ruw_AntiPinchCon = 2;
					rsw_WindowPos--;
				}
				else
				{
				  /*DO NOTHING*/
				}
			}
			blockButtons();
			e_wstate = OPEN;
		}
	}
	else
	{
	  /*DO NOTHING*/
	}
	SWITCH_INTERR_FLAG = 1;
}
