#define F_CPU 16000000UL
#define FOSC 16000000	// Clock speed
#define BAUD 9600
#define UBRR FOSC/16/BAUD-1

void USART_init(unsigned int ubrr);
void USART_transmit(unsigned char data);
unsigned char USART_receive(void);



