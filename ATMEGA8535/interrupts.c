#include <avr/io.h>
#include "interrupts.h"
#include "pins.h"

void INT_Init(void)
{
	// Init button
	MCUCR |= (1 << ISC00) | (1 << ISC01);
	GICR  |= 1 << 6;
}


ISR(INT0_vect)
{
	return;
}