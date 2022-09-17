/*
 * Utility.c
 *
 *  Created on: 17 Sep 2022
 *      Author: 44747
 */
#include "Utility.h"

void Delay(void)
{
    uint32_t counter = 0;
    while (counter < 1000000)
        ++counter;
}

void DelayMs(uint32_t ms)
{
    uint32_t counter = 0;
    while (counter < (1000 * ms)){
        ++counter;
    }
}



