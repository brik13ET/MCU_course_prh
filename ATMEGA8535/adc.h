#ifndef ADC_H
#define ADC_H

#include <inttypes.h>

extern uint16_t adc_values_16[128];
extern uint16_t adc_values_current[8];
extern uint16_t adc_avg[16];

void ADC_Init(void);
uint16_t ADC_ReadChannel(uint8_t ch);
uint16_t ADC_avg16(uint8_t ch);


#endif
