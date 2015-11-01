#include "MPC5606B.h"
#include "gpio_drv.h"
#include "sys_init.h"
#include "IntcInterrupts.h"


int main(void) {
	sys_init_fnc();
  volatile int i = 0;
  


  /* Loop forever */
  for (;;) {
    i++;
  }
}



