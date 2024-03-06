#include <avr/io.h>
#include "interrupts.h"
#include "pins.h"

volatile bool rs_send = false;

void INT_Init(void)
{
	// Init button
	MCUCR |= (1 << ISC00) | (1 << ISC01);
	GICR  |= 1 << 6;
}


ISR(INT0_vect)
{
	rs_send = true;
	return;
}

bool isPressed()
{
	bool ret = rs_send;
	rs_send = false;
	return ret;
}