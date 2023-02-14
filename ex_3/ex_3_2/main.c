/*
 * GccApplication1.c
 *
 * Created: 14.2.2023 9.37.36
 * Author : ainol
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    while (1) 
    {
	    PORTB |= (1 << PB1);
	    _delay_ms(1000);
        PORTB &= ~(1 << PB1);
        _delay_ms(10);
	    //PORTB |= (1 << PB2);
	    //_delay_ms(10);
	    /*PORTB |= (1 << PB2);
	    _delay_ms(1000);
	    PORTB |= (1 << PB3);

	    _delay_ms(1000);

	    PORTB &= ~(1 << PB0);
	    _delay_ms(1000);
	    PORTB &= ~(1 << PB1);
	    _delay_ms(1000);
	    PORTB &= ~(1 << PB2);
	    _delay_ms(1000);
	    PORTB &= ~(1 << PB3);

	    _delay_ms(1000);*/
    }
}

