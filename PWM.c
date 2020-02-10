/*
 * PWM.c
 *
 *  Created on: 12 Oct 2019
 *      Author: Kimo Store
 */

#include "Std_types.h"
#include "BitOperations.h"
#include "Registers.h"
#include "DIO.h"
#include "PWM.h"

void PWM_Init (void)
{
	CLRBIT(TCCR0,FOC0); // DISABLE FORCE OUTPUT MODE
	// ENABLE FAST PWM
	SETBIT(TCCR0,WGM01);
	SETBIT(TCCR0,WGM00);
	// OC0 MODE
	DIO_SetPinDirection (PORT1,PIN3, OUTPUT);
#if (OC0_MODE == OC0_DISABLE)
	{
		CLRBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
	}
#elif (OC0_MODE == OC0_RESERVED)
	{
		SETBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
	}
#elif (OC0_MODE == OC0_NON_INVERTING)

	{
			CLRBIT(TCCR0,COM00);
			SETBIT(TCCR0,COM01);
	}

#elif (OC0_MODE == OC0_INVERTING)
	{
		SETBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
	}
#endif
}

void PWM_Freq(void)
{
#if (F_PWM == 3906)
	{
		SETBIT (TCCR0,CS00);
		CLRBIT (TCCR0,CS01);
		CLRBIT (TCCR0,CS02);
	}

#elif (F_PWM == 488)
	{
		CLRBIT (TCCR0,CS00);
		SETBIT (TCCR0,CS01);
		CLRBIT (TCCR0,CS02);
	}

#elif (F_PWM == 61)
	{
		SETBIT (TCCR0,CS00);
		SETBIT (TCCR0,CS01);
		CLRBIT (TCCR0,CS02);
	}

#elif (F_PWM == 15)
	{
		CLRBIT (TCCR0,CS00);
		CLRBIT (TCCR0,CS01);
		SETBIT (TCCR0,CS02);
	}
#elif (F_PWM == 4)
	{
		SETBIT (TCCR0,CS00);
		CLRBIT (TCCR0,CS01);
		SETBIT (TCCR0,CS02);
	}
#endif
}

void PWM_Duty(U8 DC)
{
	OCR0=(U8)((DC/100.0)*255);
}
