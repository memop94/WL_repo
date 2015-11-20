/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Global_Init.c $
 * $Revision: 1.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 13/11/2015 $
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
 * $Log: Global_Init.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/Global_Init.h"
#include "driver_channel_MPC5606B.h"



/* Constants and types  */
/*============================================================================*/
#define SWITCH_INTERR_FLAG SIU.ISR.B.EIF21
/* 10 miliseconds in a frequency of 16MHz*/
#define T10MS 0x9C400
/*400 miliseconds in a frequency of 16MHz*/
#define T400MS 0x186A000
/*500 miliseconds in a frequency of 16MHz*/
#define T500MS 0x1E84800
/*10 miliseconds in a frequency of 16MHz*/
#define T1MS 0xFA00
/*Number of Leds, note that it is counted from 0 to 9: ten elements*/
#define NUMLEDS 9


/* Variables */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/
void Global_Init(void)
{
	/* --------------------------------------------------------------------------
	*  Name                 :  Global_Init
	*  Description          :  Initialise the system resources
	*  Parameters           :  void 
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	STM_init();
	initModesAndClock();
	GPIO_Init();
	INTC_init();
}

void INTC_init(void){
	INTC.CPR.R = 0;
}

void STM_init(void)
{
	/* --------------------------------------------------------------------------
	*  Name                 :  STM_init
	*  Description          :  Configured the STM options and its channels
	*  Parameters           :  void 
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
    STM.CR.B.TEN        = 0x0;
    STM.CR.B.FRZ        = 0x1;
    STM.CR.B.CPS        = 0;        /* Configure Counter Prescaler, Counter Prescaler is 1     */
        
    STM.CH[0].CMP.R     = 0xFA00;   	/* Compare with 640KHz = 10 msec*/      
    STM.CH[0].CCR.B.CEN = 0x1;      /* System Timer Channel 0: ENABLE                          */

    STM.CR.B.TEN        = 0x1;      /* Enable System Timer Module                              */
}

void initModesAndClock(void) 
{
  	ME.MER.R = 0x0000001D;               /* Enable DRUN, RUN0, SAFE, RESET modes              */
    
  	/* Initialize PLL before turning it on:              */
   	CGM.FMPLL_CR.R = 0x02400100;         /* 8 MHz xtal: Set PLL0 to 64 MHz                    */   
   	
   	ME.RUN[0].R = 0x001F0074;            /* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL0     */
   	
   	ME.RUNPC[1].R = 0x00000010; 	     /* Peri. Cfg. 1 settings: only run in RUN0 mode      */
   	
   	ME.PCTL[LED1].R = 0x01;
   	ME.PCTL[LED2].R = 0x01;
   	ME.PCTL[LED3].R = 0x01;
   	ME.PCTL[LED4].R = 0x01;
   	
                                         
   	/* Mode Transition to enter RUN0 mode:               */
   	ME.MCTL.R = 0x40005AF0;              /* Enter RUN0 Mode & Key                             */
   	ME.MCTL.R = 0x4000A50F;              /* Enter RUN0 Mode & Inverted Key                    */  
   	while (ME.GS.B.S_MTRANS) {}          /* Wait for mode transition to complete              */    
    
   	/* Note: could wait here using timer and/or I_TC IRQ */
   	while(ME.GS.B.S_CURRENTMODE != 4) {} /* Verify RUN0 is the current mode                   */
}

void GPIO_Init(void)
{
	/* ------------------------------------------------------------------------
	 *  Name                 :	GPIO_Init
	 *  Description          :  Call GPIO_En for the ports that will be used
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------*/	
	GPIO_En(LED_BAR_0,  0x0200); /* Program the drive enable pin of LED1 (PE4) as output       */
	GPIO_En(LED_BAR_1,  0x0200); /* Program the drive enable pin of LED2 (PE5) as output       */
	GPIO_En(LED_BAR_2,  0x0200); /* Program the drive enable pin of LED3 (PE6) as output       */
	GPIO_En(LED_BAR_3,  0x0200); /* Program the drive enable pin of LED4 (PE7) as output       */
	GPIO_En(LED_BAR_4,  0x0200); /* Program the drive enable pin of LED1 (PE4) as output       */
	GPIO_En(LED_BAR_5,  0x0200); /* Program the drive enable pin of LED2 (PE5) as output       */
	GPIO_En(LED_BAR_6,  0x0200); /* Program the drive enable pin of LED3 (PE6) as output       */
	GPIO_En(LED_BAR_7,  0x0200); /* Program the drive enable pin of LED4 (PE7) as output       */
	GPIO_En(LED_BAR_8,  0x0200); /* Program the drive enable pin of LED3 (PE6) as output       */
	GPIO_En(LED_BAR_9,  0x0200); /* Program the drive enable pin of LED4 (PE7) as output       */
	
	GPIO_En(LED_DOWN,  0x0200);	 /* Program the drive enable pin of LED3 (PE6) as output       */
	GPIO_En(LED_UP,  0x0200); 	 /* Program the drive enable pin of LED4 (PE7) as output       */
	
	GPIO_En(SW_UP,  0x0100); 	 /* Program the drive enable pin of LED3 (PE6) as output       */
	GPIO_En(SW_DOWN,  0x0100); 	 /* Program the drive enable pin of LED4 (PE7) as output       */
	GPIO_En(SW_A_PINCH,  0x0100);/* Program the drive enable pin of LED4 (PE7) as output       */
}

void GPIO_En(T_SWORD lsw_ch, T_UWORD luw_state)   
{	/* ------------------------------------------------------------------------
     *  Name                 :	Init_GPIO_En
     *  Description          :  Enable the pin
     *  Parameters           :  T_SWORD ch, T_ULONG state
     *  Return               :  void
     *  -----------------------------------------------------------------------
	 * state = 0x0200 -> enable as output                   
	 * state = 0x0100 -> enable as input                    
	 * state = 0x0103 -> enable as input, Pull - up
	 * state = 0x2000 -> enable as APC "Analog Pad Control" or ANP "Analog Port"
	 */
	 
	SIU.PCR[lsw_ch].R = luw_state;				
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */
