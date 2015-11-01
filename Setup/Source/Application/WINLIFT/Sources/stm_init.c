/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : Training_LED_Example
 *
 * Project File           : Training_LED_Example.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.2.1.5
 *
 * file                   : stm_init.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5606B
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 29-Oct-2013 14:07:38
 *
 * Created on Date        : 29-Oct-2013 14:07:39
 *
 * Brief Description      : STM Initialization file
 *
 ******************************************************************************** 
 *
 * Detail Description     : File contains definition for System Timer Module
 *                         (STM) initialization function. The function
 *                         configures STM parameters such as STM module status,
 *                         Counter pre-scalar, Individual Channel status &
 *                         compare value.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "stm_init.h"




/********************* Initialization Function(s) *********************** */


void stm_init_fnc(void)
{
	STM.CR.B.TEN = 0; 
        /* Disable System Timer Module for initialization          */

/* ----------------------------------------------------------- */
/*                     Configure Counter Prescaler                */
/* ----------------------------------------------------------- */

	STM.CR.B.CPS = 0;
        /* Counter Prescaler is 1        */

/* ----------------------------------------------------------- */
/*                     Configure System Timer Registers                */
/* ----------------------------------------------------------- */
	STM.CH[0].CMP.R = 0x00f42400;
    //STM.CMP0.R =0x00f42400;    
        /* System Timer Channel 0's Compare value is :0    */
	STM.CH[0].CCR.B.CEN = 1;
    //STM.CCR0.B.CEN =0x1;    
        /* System Timer Channel 0: Enabled    */
    
	STM.CH[1].CMP.R = 0x00000000;    
        /* System Timer Channel 1's Compare value is :0    */
    
	STM.CH[1].CCR.B.CEN =0x0;    
        /* System Timer Channel 1: Disabled    */
    
	STM.CH[2].CMP.R = 0x00000000;    
        /* System Timer Channel 2's Compare value is :0    */
    
    STM.CH[2].CCR.B.CEN =0x0;    
        /* System Timer Channel 2: Disabled    */
    
    STM.CH[3].CMP.R  =0x00000000;    
        /* System Timer Channel 3's Compare value is :0    */
    
    STM.CH[3].CCR.B.CEN =0x0;    
        /* System Timer Channel 3: Disabled    */
    


    STM.CR.B.TEN = 1;    
        /* System Timer Module is:  Enabled        */

}

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

