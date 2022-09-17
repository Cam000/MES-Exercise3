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
#include "driverlib/interrupt.h"
#include "Utility.h"

#include "buttonDriver.h"

#define TARGET_COUNT    5

/*ISR*/
void Btn2Released(void){

    uint32_t debounceCount = 0U;

    /*note: should not be busy-waiting inside of an ISR...*/
    /*poll the btn for 50 ms*/
    uint32_t pinread = GPIOPinRead(GPIO_PORTF_BASE, BTN_2);
    while(pinread){
        debounceCount++;
        DelayMs(10);
        if(debounceCount >= TARGET_COUNT){
            ToggleLEDRed();
            break;
        }
    }

    GPIOIntClear(GPIO_PORTF_BASE, BTN_2);  // Clear interrupt flag
}


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

    /*enable interrupt globally*/
    IntMasterEnable();

    /*disable to configure*/
    GPIOIntDisable(GPIO_PORTF_BASE, BTN_2);

    /*clear any interrupts*/
    GPIOIntClear(GPIO_PORTF_BASE, BTN_2);

    /*register ISR*/
    GPIOIntRegister(GPIO_PORTF_BASE, Btn2Released);

    /*set rising edge (button up)*/
    GPIOIntTypeSet(GPIO_PORTF_BASE, BTN_2, GPIO_RISING_EDGE);

    /*re-enable interrupt*/
    GPIOIntEnable(GPIO_PORTF_BASE, BTN_2);

}

