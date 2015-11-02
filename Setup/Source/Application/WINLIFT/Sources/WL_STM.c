/*
 *      File        : WL_STM.c
 *      Created on  : Oct 26, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter STM Intialization and Functions
 */

#include "WL_STM.h"
#include "GPIO_State.h"
#define SWITCH_INTERR_FLAG SIU.ISR.B.EIF21
#define t10ms 0x9C400
#define t500ms 0x1E84800

enum E_WINDOWSTATE {OPEN, CLOSE, LIFTING} e_wstate; 

volatile T_SWORD WindowPos = 0;
int AntiPinchCon = 1;

void WL_STM_init(void)
{
    STM.CR.B.TEN        = 0x0;
    STM.CR.B.FRZ        = 0x1;
    STM.CR.B.CPS        = 0;         /* Configure Counter Prescaler, Counter Prescaler is 1     */
    
    STM.CH[0].CMP.R     = 0x9C400;   /* Compare with 640KHz = 10 msec*/      
    STM.CH[0].CCR.B.CEN = 0x1;       /* System Timer Channel 0: ENABLE                          */
    
    STM.CH[1].CMP.R     = 0x1E84800; /* Compare with 32MHz - 500 msec*/      
    STM.CH[1].CCR.B.CEN = 0x1;       /* System Timer Channel 1: ENABLE                          */
    
    STM.CH[2].CMP.R     = 0x186A000; /* Compare with 25.6MHz - 400 msec*/      
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
	
	static T_ULONG PressTime = 0;
	static T_UBYTE valid = 0;
	
	PressTime = STM.CNT.R;
	valid = 0;
	
	while (valid == 0)
	{
		if (PressTime >= t10ms)
		{
			
			STM.CNT.R = 0;
			valid = 1;
			
		}
	}
	return valid;
}

T_ULONG WL_CheckAutoManualUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckAutoManual
	*  Description          :  Check if the movement will be Auto or Manual
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	static T_ULONG PressTime = 0;
	static T_UBYTE valid = 0;
	
	STM.CNT.R = 0; 				/* Reset counter */
	
	PressTime = STM.CNT.R;
	
	valid = 0;
	
	while (GPIO_GetState(SW_UP) && valid == 0)
	{
		
		PressTime = STM.CNT.R;
		
		if (PressTime >= t500ms)
		{
			
			STM.CNT.R = 0;
			valid = 1;
			
		}
		else
		{
		  /*DO NOTHING*/
		}
	}
	return valid;
}

T_ULONG WL_CheckAutoManualDw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckAutoManual
	*  Description          :  Check if the movement will be Auto or Manual
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	static T_ULONG PressTime = 0;
	static T_UBYTE valid = 0;
	STM.CNT.R = 0; 				/* Reset counter */
	PressTime = STM.CNT.R;
	valid = 0;
	while (GPIO_GetState(SW_DOWN) && valid == 0)
	{
		PressTime = STM.CNT.R;
		if (PressTime >= 0x1E84800)
		{
			STM.CNT.R = 0;
			valid = 1;
		}
		else
		{
		  /*DO NOTHING*/
		}
	}
	return valid;
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
		GPIO_SetState(LED_BAR_0 + WindowPos, 1);
		GPIO_SetState(LED_UP, 1);
		STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
		WindowPos++;
		e_wstate = LIFTING;	
		if (WindowPos > 9)
		{
			WindowPos = 9;
			e_wstate = CLOSE;
		}
		else
		{	
			/*DO NOTHING*/
		}
	}
	else
	{
		/*DO NOTHING*/
	}
	e_wstate = CLOSE;
}

void WL_WinAUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window automatically
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	AntiPinchCon = 1;
	while(WindowPos <= 9 && AntiPinchCon == 1)
	{
		if (STM.CH[2].CIR.B.CIF)
		{
			GPIO_SetState(LED_BAR_0 + WindowPos, 1);
			GPIO_SetState(LED_UP, 1);
			GPIO_SetState(LED_DOWN, 0);
			STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
			STM.CNT.R = 0; 				/*Reset counter*/
			WindowPos++;
			e_wstate = LIFTING;
		}
		else
		{
		  /*DO NOTHING*/
		}
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
		if (WindowPos <= 0)
		{
			WindowPos = 0;
			GPIO_SetState(LED_DOWN, 0);
		}
		else
		{
			GPIO_SetState(LED_DOWN, 1);
		}
		GPIO_SetState(LED_BAR_0 + WindowPos, 0);
		STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
		WindowPos--;
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

	while(WindowPos >= 0)
	{
		if (STM.CH[2].CIR.B.CIF)
		{
			GPIO_SetState(LED_BAR_0 + WindowPos, 0);
			GPIO_SetState(LED_DOWN, 1);
			GPIO_SetState(LED_UP, 0);
			STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
			STM.CNT.R = 0; 				/*Reset counter*/
			WindowPos--;
		}
		else
		{
		  /*DO NOTHING*/
		}
	}
}

void WL_A_Pinch(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_A_Pinch
	*  Description          :  Close the window automatically
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	if (e_wstate == LIFTING)
	{
		while (SWITCH_INTERR_FLAG)
		{
			while(WindowPos >= 0)
			{
				if (STM.CH[2].CIR.B.CIF)
				{
					GPIO_SetState(LED_BAR_0 + WindowPos, 0);
					GPIO_SetState(LED_DOWN, 1);
					GPIO_SetState(LED_UP, 0);
					STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
					SWITCH_INTERR_FLAG = 1;
					STM.CNT.R = 0; 				/*Reset counter*/
					AntiPinchCon = 2;
					WindowPos--;
				}
				else
				{
				  /*DO NOTHING*/
				}
			}
			e_wstate = OPEN;
			blockButtons();
		}
	}
	else
	{
	  /*DO NOTHING*/
	}
	SWITCH_INTERR_FLAG = 1;
}
