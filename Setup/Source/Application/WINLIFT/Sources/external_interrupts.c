/*
 * external_interrupts.c
 *
 *  Created on: Nov 1, 2015
 *      Author: x
 */
#define "external_interrupts.h"

void init_ext_ints()
{
	
		SIU.IRER.B.IRE21 = 1; //Enables the the 3rd Switch (PCR[66])
		SIU.IREER.B.IFEE21 = 1; // Falling edge event
}

