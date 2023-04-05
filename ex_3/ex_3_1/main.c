/*
 * GccApplication3.c
 *
 * Created: 7.2.2023 10:39:28
 * Author : ainol
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);

    while (1) 
    {
        PORTB &= ~(1 << PB0);
        _delay_ms(1000);
        PORTB &= ~(1 << PB1);
        _delay_ms(1000);
        PORTB &= ~(1 << PB2);
        _delay_ms(1000);
        PORTB &= ~(1 << PB3);

        _delay_ms(1000);
        
        PORTB |= (1 << PB0);
        _delay_ms(1000);
        PORTB |= (1 << PB1);
        _delay_ms(1000);
        PORTB |= (1 << PB2);
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

        _delay_ms(1000);
    }
}

