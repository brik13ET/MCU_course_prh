#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.h"
#include "displ.h"
#include "adc.h"
#include "keypad.h"
#include "pins.h"

uint8_t read_order[8];

int main()
{
	//unsigned int baudrate = USART_CalcBaud(19200);
	DISP_Init();
	KEYPAD_Init();
	ADC_Init();
	LED_DDR |= (LED_MASK | LED_index_MASK | LED_value_MASK);
	uint8_t i, j; // c99 moment....
	for(i = 0; i < sizeof(read_order)/sizeof(read_order[0]); i++)
		read_order[i] = i;
	
	while (1)
	{
		for(i = 0; i < sizeof(read_order)/sizeof(read_order[0]); i++)
		{
			bcd_print(read_order[i]);
			key_t key = getkey();
			if (key == k_star)
			{
				LED_PORT &= ~(LED_index_MASK | LED_value_MASK);
				LED_PORT |= LED_index_MASK;
				uint8_t index = getnum();
				LED_PORT &= ~(LED_index_MASK | LED_value_MASK);
				LED_PORT |= LED_value_MASK;
				uint8_t ord_num = getnum();
				LED_PORT &= ~(LED_index_MASK | LED_value_MASK);
				if (index >= 8 || ord_num >= 8)
					continue;
				for(j = 0; j < sizeof(read_order)/sizeof(read_order[0]); j++)
					if (read_order[j] == ord_num && j != index)
					{
						uint8_t tmp = read_order[index];
						read_order[index] = read_order[j];
						read_order[j] = tmp;
					}
			}
			_delay_ms(100);
		}
	}
	return 0;
}