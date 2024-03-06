#ifndef KEYPAD_H
#define KEYPAD_H

#include <inttypes.h>
#include "pins.h"

typedef enum 
{
	k_1,
	k_2,
	k_3,
	k_4,
	k_5,
	k_6,
	k_7,
	k_8,
	k_9,
	k_star,
	k_0,
	k_hash,
	k_none
} key_t;

void KEYPAD_Init();
key_t getkey();
uint8_t getnum();
#endif