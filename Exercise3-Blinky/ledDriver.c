/*
 * ledDriver.c
 *
 *  Created on: 17 Sep 2022
 *      Author: 44747
 */

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "tm4c_cmsis.h"

#include "ledDriver.h"

void configureLED(void){
    /*the vendor (TI) provided driverlib/gpio.h could be used instead but I prefer this because there aren't too many registers to set - still readable/manageable*/
    SYSCTL->RCGC2 = PORT_F;                                                     // enable port f
    GPIOF->DIR |= (LED_RED | LED_BLUE | LED_GREEN);                             // enable output direction on port 7
    GPIOF->DEN |= (LED_RED | LED_BLUE | LED_GREEN);                             // digital enable
}


void ToggleLEDBlue()
{
    GPIOF->DATA ^= LED_BLUE;                                                    // set the LED to blue
}


void ToggleLEDRed()
{
    GPIOF->DATA ^= LED_RED;                                                     // set to red
}


void ToggleLEDGreen()
{
    GPIOF->DATA ^= LED_GREEN;                                                   // set to green
}

