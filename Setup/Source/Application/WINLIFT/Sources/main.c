#include "MPC5606B.h"
#include "driver_channel_MPC5606B.h"
#include "stdtypedef.h"
#include "WL_GPIO.h"
#include "WL_SYS_INIT.h"
#include "WL_EIRQ.h"
#include "WL_STM.h"
#include "IntcInterrupts.h"
#include "GPIO_State.h"
#include "external_interrupts.h"
#include "WL_WinProcessing.h"

/*AUTO Y DESPUED MANUAL DEL INVERSO
 *SE PRENDE EL LED ABAJO EN RESET*/

int main(void) {
	
	volatile T_ULONG lul_InfLoop = 0;
	volatile T_ULONG lul_Validate = 0;
	volatile T_ULONG lul_ValidateUp = 0;
	volatile T_ULONG lul_ValidateDw = 0;
	
	T_UWORD luw_SwDwState;
	T_UWORD luw_SwUpState;
	
	WL_initModesAndClock();
	WL_EIRQ_Init();
	WL_STM_init();
	WL_GPIO_Init();
	init_ext_ints();
	init_PIT();
	
	asm(" wrteei 1");

   	INTC_InstallINTCInterruptHandler(WL_A_Pinch,EIRQ_2,1); /* vector 32 for STM[2] */
	INTC.CPR.R = 0;
  	  

  /* Loop forever */
  for (;;) {
	  /*------------------------------*/
	  luw_SwDwState = GPIO_GetState(SW_DOWN);
	  
	  if (luw_SwDwState == 1)
	  {
		  lul_Validate = WL_CheckValid();
		  if (lul_Validate == 1)
		  {
			  lul_ValidateDw = WL_CheckAutoManualDw();
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
	  while (luw_SwDwState == 1){
		  
		  if (lul_ValidateDw == 1)
		  {
			  WL_WinMDw();
		  }
		  else
		  {
			  /*DO NOTHING*/
		  }
		  
		  if (lul_ValidateDw == 0)
		  {
			  WL_WinADw();
		  }
		  else
		  {
			  /*DO NOTHING*/
		  }
		  
		  luw_SwDwState = GPIO_GetState(SW_DOWN);
	  }
	  
	  /*------------------------------*/
	  luw_SwUpState = GPIO_GetState(SW_UP);
	  
	  if (luw_SwUpState == 1)
	  {
		  lul_Validate = WL_CheckValid();
		  if (lul_Validate == 1)
		  {
			  lul_ValidateUp = WL_CheckAutoManualUp();
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
	  
	  while (luw_SwUpState == 1){
		  
		  if (lul_ValidateUp == 1)
		  {
			  WL_WinMUp();
		  }
		  else
		  {
			  /*DO NOTHING*/
		  }
		  
		  if (lul_ValidateUp == 0)
		  {
			  WL_WinAUp();
		  }
		  else
		  {
			  /*DO NOTHING*/
		  }
		  
		  luw_SwUpState = GPIO_GetState(SW_UP);
	  }
	  
	  GPIO_SetState(LED_DOWN, 0);
	  GPIO_SetState(LED_UP, 0);
	  
	  lul_InfLoop++;
	  
	  WL_SetState();
  }
}


