/*
 * buttonDriver.h
 *
 *  Created on: 17 Sep 2022
 *      Author: 44747
 */

#ifndef BUTTONDRIVER_H_
#define BUTTONDRIVER_H_

#define BTN_2       (1U)        //pin 0
#define PORT_F      (1U << 5)   //32

void configureBtn(void);
bool isBtn2Pressed(void);

#endif /* BUTTONDRIVER_H_ */
