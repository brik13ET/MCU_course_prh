#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.h"
#include "displ.h"
#include "adc.h"
#include "keypad.h"
#include "interrupts.h"
#include "pins.h"

uint8_t read_order[8];
uint16_t adc_values_current[8];



int main()
{
	D_PORT &= ~(D_OFF_MASK);
	//unsigned int baudrate = USART_CalcBaud(19200);
	DISP_Init();
	KEYPAD_Init();
	ADC_Init();
	INT_Init();
	USART_Init(USART_CalcBaud(1200), 0);
	
	LED_DDR |= (LED_MASK | LED_index_MASK | LED_value_MASK);
	for(uint8_t i = 0; i < sizeof(read_order)/sizeof(read_order[0]); i++)
		read_order[i] = i;
	
	D_PORT |= D_OFF_MASK;
	
	
	while (!isPressed())
	{
		for(uint8_t i = 0; i < sizeof(read_order)/sizeof(read_order[0]); i++)
		{
			adc_values_current[read_order[i]] = (uint32_t)ADC_avg16(read_order[i]) * 5000 / 1023;
			bcd_print(adc_values_current[read_order[i]]);
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
				for(uint8_t j = 0; j < sizeof(read_order)/sizeof(read_order[0]); j++)
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
	LED_PORT |= LED_MASK;
	USART_TransmitBlock(&adc_values_current[read_order[0]],2);
	USART_TransmitBlock(&adc_values_current[read_order[1]],2);
	USART_TransmitBlock(&adc_values_current[read_order[2]],2);
	USART_TransmitBlock(&adc_values_current[read_order[3]],2);
	USART_TransmitBlock(&adc_values_current[read_order[4]],2);
	USART_TransmitBlock(&adc_values_current[read_order[5]],2);
	USART_TransmitBlock(&adc_values_current[read_order[6]],2);
	USART_TransmitBlock(&adc_values_current[read_order[7]],2);
	
	while (1) ;
	return 0;
}