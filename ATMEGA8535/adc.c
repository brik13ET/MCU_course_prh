#include <avr/interrupt.h>
#include <avr/io.h>
#include "adc.h"


uint16_t adc_values_16[128];

void ADC_Init(void)
{
	ADCSRA |= (1 << ADEN) | ( 1 << ADIE ) | ( 1 << ADIE );
}

uint16_t ADC_avg16(uint8_t ch)
{
	uint8_t chi = 0, sampli = 0;
	uint16_t avg = 0;
	for (chi = 0; chi < 8; chi ++)
		for(sampli = 0; sampli < 16; sampli ++)
			avg += ADC_ReadChannel(ch);
	avg >>= 4;
	return avg;
}

uint16_t ADC_ReadChannel(uint8_t ch)
{
	ADMUX &= ~(0x1F << MUX0);
	if (ch >= 8)
		ADMUX |= ch;
	uint16_t ret = ADCL;
	ret |= ADCH << 8;
	return ret;
}