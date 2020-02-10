/*
 * PWM.h
 *
 *  Created on: 12 Oct 2019
 *      Author: Kimo Store
 */

#ifndef PWM_H_
#define PWM_H_

//TCCR0 PINS CONFIG
#define WGM01 3
#define WGM00 6
#define COM00 4
#define COM01 5
#define FOC0 7

// PRESCALAR PINS
#define CS00 0
#define CS01 1
#define CS02 2

//PWM - FAST_PWM
#define OPERATION_MODE FAST_PWM

//OC0_DISABLE- OC0_RESERVED - OC0_NON_INVERTING - OC0_INVERTING
#define OC0_DISABLE 0
#define OC0_RESERVED 1
#define OC0_NON_INVERTING 2
#define OC0_INVERTING 3
#define OC0_MODE OC0_NON_INVERTING

#define F_INPUT 1000000

// F_PWM = (F_INPUT)/(N*256)
// N = 1, 8, 64, 256, 1024
// 3906 - 488  - 61 - 15 - 4
#define F_PWM  488

void PWM_Init (void);
void PWM_Freq(void);
void PWM_Duty (U8);

#endif /* PWM_H_ */
