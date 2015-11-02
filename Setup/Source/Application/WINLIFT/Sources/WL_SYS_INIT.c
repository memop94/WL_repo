/*
 *      File        : WL_SYS_INIT.h
 *      Created on  : Oct 20, 2015
 *      Author      : Luis Fernando Alvarez Guerrero
 *      Description : Window Lifter System Initialization
 */
#include "WL_SYS_INIT.h"

void WL_initModesAndClock(void) 

  {
  	ME.MER.R = 0x0000001D;               /* Enable DRUN, RUN0, SAFE, RESET modes              */
    
  	/* Initialize PLL before turning it on:              */
   	CGM.FMPLL_CR.R = 0x02400100;         /* 8 MHz xtal: Set PLL0 to 64 MHz                    */   
   	
   	ME.RUN[0].R = 0x001F0074;            /* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL0     */
   	
   	ME.RUNPC[1].R = 0x00000010; 	     /* Peri. Cfg. 1 settings: only run in RUN0 mode      */
   	
   	ME.PCTL[LED_BAR_0].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_0             */
   	ME.PCTL[LED_BAR_1].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_1             */
   	ME.PCTL[LED_BAR_2].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_2             */
   	ME.PCTL[LED_BAR_3].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_3             */
   	ME.PCTL[LED_BAR_4].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_4             */
   	ME.PCTL[LED_BAR_5].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_5             */
   	ME.PCTL[LED_BAR_6].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_6             */
   	ME.PCTL[LED_BAR_7].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_7             */
   	ME.PCTL[LED_BAR_8].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_8             */
   	ME.PCTL[LED_BAR_9].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_BAR_9             */
   	ME.PCTL[LED_DOWN].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_DOWN              */
   	ME.PCTL[LED_UP].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for LED_UP                */
   	ME.PCTL[SW_A_PINCH].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for SW_DOWN               */
   	ME.PCTL[SW_DOWN].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for SW_UP                 */
   	ME.PCTL[SW_UP].R = 0x01; 	     /* SIU: select ME.RUNPC[1] for SW_A_PINCH            */
   	ME.PCTL[68].R = 0x01;
   	ME.PCTL[69].R = 0x01;
   	ME.PCTL[70].R = 0x01;
   	ME.PCTL[71].R = 0x01;
   	
                                         
   	/* Mode Transition to enter RUN0 mode:               */
   	ME.MCTL.R = 0x40005AF0;              /* Enter RUN0 Mode & Key                             */
   	ME.MCTL.R = 0x4000A50F;              /* Enter RUN0 Mode & Inverted Key                    */  
   	while (ME.GS.B.S_MTRANS) {}          /* Wait for mode transition to complete              */    
    
   	/* Note: could wait here using timer and/or I_TC IRQ */
   	while(ME.GS.B.S_CURRENTMODE != 4) {} /* Verify RUN0 is the current mode                   */
  
  }



  

