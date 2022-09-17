/*
 * clockDriver.c
 *
 *  Created on: 17 Sep 2022
 *      Author: 44747
 */
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"

void configureClock(void){
    /*16M crystal down to 1M*/
    SysCtlClockSet(SYSCTL_SYSDIV_16 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
}
