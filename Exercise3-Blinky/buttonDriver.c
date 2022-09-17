/*
 * buttonDriver.c
 *
 *  Created on: 17 Sep 2022
 *      Author: 44747
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "tm4c_cmsis.h"
#include "Utility.h"

#include "buttonDriver.h"

/*...*/
void configureBtn(void){
    /*could use the ROM variant of these GPIO functions which are fetched more conveniently from 'nearer' memory*/
    /*the vendor (TI) provided driverlib/gpio.h could be used instead but I prefer this because there aren't too many registers to set - still readable/manageable*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;

    GPIODirModeSet(GPIO_PORTF_BASE, BTN_2, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, BTN_2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}

/*...*/
bool isBtn2Pressed(void){
    static uint32_t debounceCount = 0U;
    /*switch is open (1) by default*/
    static int32_t prevstate = 1;
    static bool risingDetect = false;

    /*active low*/
    int32_t currstate = GPIOPinRead(GPIO_PORTF_BASE, BTN_2);

    /*detect rising edge (button up) with debounce*/
    if(!prevstate && currstate){
        risingDetect = true;
    }
    if(risingDetect && currstate){
        debounceCount++;
        DelayMs(10);
    }
    prevstate = currstate;

    /*check 5 times over 50ms*/
    if(debounceCount >= 5){
        debounceCount = 0;
        risingDetect = false;
        return 1;
    }
    return 0;
}

