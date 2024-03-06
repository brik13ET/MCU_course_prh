#include <avr/interrupt.h>
#include <avr/io.h>
#include "adc.h"
#include "pins.h"

uint16_t avg = 0;

void ADC_Init(void)
{
	ADCSRA |= (1 << ADEN) |( 1 << ADPS0 ) | ( 1 << ADPS1 ) | ( 1 << ADPS2 );
	ADMUX = (1 << REFS0) | 0;
	ADC_DDR = 0;
	ADC_PORT = 0;
}

uint16_t ADC_avg16(uint8_t ch)
{
	uint8_t sampli = 0;
//	uint16_t avg = 0;
//	for (chi = 0; chi < 8; chi ++)
	avg = 0;
		for(sampli = 0; sampli < 16; sampli ++)
			avg += ADC_ReadChannel(ch);
	avg >>= 4;
	return avg;
}

uint16_t ADC_ReadChannel(uint8_t ch)
{
	ADMUX = (1 << REFS0) | 0;
	ADC_DDR = 0;
	ADC_PORT = 0;
	if (ch >= 8)
		return 0xFFFF;
	ADMUX |= ch;
	ADCSRA |= (1<<ADSC);
	while((ADCSRA & (1<<ADSC)));
	return ADC;
}