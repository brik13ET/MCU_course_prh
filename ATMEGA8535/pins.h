#ifndef PINS_H
#define PINS_H
#include <avr/io.h>

#define ADC_PORT	PORTA
#define ADC_PIN	PINA
#define ADC_DDR	DDRA
#define ADC0_MASK	(1 << 0)
#define ADC1_MASK	(1 << 1)
#define ADC2_MASK	(1 << 2)
#define ADC3_MASK	(1 << 3)
#define ADC4_MASK	(1 << 4)
#define ADC5_MASK	(1 << 5)
#define ADC6_MASK	(1 << 6)
#define ADC7_MASK	(1 << 7)

#define D_PORT	PORTB
#define D_PIN	PINB
#define D_DDR	DDRB
#define D1_MASK	(1 << 0)
#define D2_MASK	(1 << 1)
#define D3_MASK	(1 << 2)
#define D4_MASK	(1 << 3)
#define D5_MASK	(1 << 4)
#define D6_MASK	(1 << 5)
#define D7_MASK	(1 << 6)
#define D_OFF_MASK (1 << 7)
#define DC_PORT	PORTD
#define DC_DDR	DDRD
#define DC_1_MASK (1 << 3)
#define DC_2_MASK (1 << 4)

#define I_OE_PORT	PORTB
#define I_OE_PIN	PINB
#define I_OE_DDR	DDRB
#define I_OE_MASK	(1 << 7)

#define KP_PORT	PORTC
#define KP_PIN	PINC
#define KP_DDR	DDRC
#define KP1_MASK	(1 << 0)
#define KP2_MASK	(1 << 1)
#define KP3_MASK	(1 << 2)
#define KPA_MASK	(1 << 4)
#define KPB_MASK	(1 << 5)
#define KPC_MASK	(1 << 6)
#define KPD_MASK	(1 << 7)

#define LED_PORT	PORTD
#define LED_PIN	PIND
#define LED_DDR	DDRD
#define LED_MASK	(1 << 0)
#define LED_index_MASK	(1 << 5)
#define LED_value_MASK	(1 << 6)

#define RX_OUT_PORT	PORTD
#define RX_OUT_PIN	PIND
#define RX_OUT_DDR	DDRD
#define RX_OUT_MASK	(1 << 1)

#define BTN_PORT	PORTD
#define BTN_PIN	PIND
#define BTN_DDR	DDRD
#define BTN_MASK	(1 << 2)

#endif
