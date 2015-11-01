#include "MPC5606B.h"
#include "gpio_drv.h"
#include "sys_init.h"
#include "IntcInterrupts.h"
#include "winlift.h"


int main(void) {
	sys_init_fnc();
	//defines antiPinch() as an external interrupt function
	INTC_InstallINTCInterruptHandler(antiPinch, EIRQ_2, 5); 
  volatile int i = 0;
  


  /* Loop forever */
  for (;;) {
    i++;
  }
}


