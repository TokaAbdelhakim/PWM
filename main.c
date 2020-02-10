/*
 * main.c
 *
 *  Created on: 12 Oct 2019
 *      Author: Kimo Store
 */


#include "Std_types.h"
#include "BitOperations.h"
#include "Registers.h"
#include "DIO.h"
#include "PWM.h"
#include <util/delay.h>
int main (void)
{
	PWM_Init ();
	PWM_Freq ();
	U8 i;
	while (1)
	{
		for (i=0; i<= 100 ; i+=1)
		{
			PWM_Duty(i);
			_delay_ms(30);

		}

	}
	return 0;
}
