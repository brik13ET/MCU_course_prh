#ifndef UART
#define UART
void USART_Init( unsigned int speed, uint8_t x2);
unsigned int USART_CalcBaud(unsigned int baud);
void USART_Transmit( uint8_t data );

#endif