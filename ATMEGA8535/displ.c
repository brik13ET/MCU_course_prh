#include <inttypes.h>
#include <util/delay.h>

#include "displ.h"
#include "pins.h"

void bcd_print(uint16_t n)
{
	uint8_t _7seg[] = {
		0b0111111, // 0
		0b0000110, // 1
		0b1011011, // 2
		0b1001111, // 3
		0b1100110, // 4
		0b1101101, // 5
		0b1111101, // 6
		0b0000111, // 7
		0b1111111, // 8
		0b1101111  // 9
	};
	uint8_t i = 0;
	uint8_t bcd[] = {
		 n         / 1000,
		(n % 1000) / 100,
		(n % 100)  / 10,
		 n % 10,
	};
	for (i = 0; i < 4; i ++)
	{
		D_PORT = _7seg[bcd[i]];
		DC_PORT &= ~(DC_1_MASK | DC_2_MASK);
		DC_PORT |=  (i & 1 ? DC_1_MASK : 0) | ( i & 2 ? DC_2_MASK : 0);
		_delay_ms(70);
	}
}

void DISP_Init(void)
{
	D_DDR |= D1_MASK | D2_MASK | D3_MASK | D4_MASK | D5_MASK | D6_MASK | D7_MASK | D_OFF_MASK;
	D_PORT |= ~D_OFF_MASK;
	DC_DDR |= DC_1_MASK | DC_2_MASK;
}