/*
 * ledDriver.h
 *
 *  Created on: 17 Sep 2022
 *      Author: 44747
 */

#ifndef LEDDRIVER_H_
#define LEDDRIVER_H_

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define PORT_F    (1U << 5) //32


void configureLED(void);
void ToggleLEDBlue(void);
void ToggleLEDRed(void);
void ToggleLEDGreen(void);


#endif /* LEDDRIVER_H_ */
