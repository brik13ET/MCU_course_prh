#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// ATMEGA8535 DATASHEET - DOC2502 - p.172
// 19_200 baudrate -> UBRR = 25 && X2 == 0
// 38_400 baudrate -> UBRR = 25 && X2 == 1


// Select value from table where X2 Flag is clear
unsigned int USART_CalcBaud(unsigned int baud)
{
	return F_CPU / 16 / baud - 1;
}

// ATMEGA8535 DATASHEET - DOC2502 - p.151
void USART_Init( unsigned int speed, uint8_t x2)//Инициализация модуля USART
{
	cli();
	UBRRH  = (uint8_t)(speed >> 8);
	UBRRL  = (uint8_t) speed;
	
	if (x2)
		UCSRA |=  ( 1 << U2X  );
	else
		UCSRA &= ~( 1 << U2X  );
	UCSRB  = ( 1 << TXEN); //Включаем передачу по USART
	UCSRC  = ( 1 << URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	sei();
	// Обращаемся именно к регистру UCSRC (URSEL=1),
	// ассинхронный режим (UMSEL=0), без контроля четности (UPM1=0 и UPM0=0),
	//1 стоп-бит (USBS=0), 8-бит посылка (UCSZ1=1 и UCSZ0=1)
}

void USART_X2_Set(uint8_t x2)
{
	if (x2)
		UCSRA |=  ( 1 << U2X  );
	else
		UCSRA &= ~( 1 << U2X  );
}

// ATMEGA8535 DATASHEET - DOC2502 - p.152
void USART_Transmit( uint8_t data ) //Функция отправки данных
{
	loop_until_bit_is_set(UCSRA, UDRE);
	UDR = data; //Начало передачи данных
}
