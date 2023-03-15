/*
 * Exercise7_1.c
 *
 * Created: 14.3.2023 10:23:13
 * Author : ainol
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

int main(void)
{
    DDRB |= (1 << PB1);
	sei();	        // enable interrupts
    
	TCCR1B = 0;
	TCCR1B |= 0b00010000;
	TCCR1A = 0;
	TCCR1A |= 0b01000001;
	TCNT1 = 0;
	TIMSK1 |= 0b00000010;
	//OCR1A |= 2462;

    OCR1A |= 3462;
    TCCR1B |= 0b00000001;
    _delay_ms(1000);
    //TCNT1 = 0;
    OCR1A |= 0;
    _delay_ms(1000);
    OCR1A |= 2462;
    _delay_ms(1000);
    OCR1A |= 3462;
    _delay_ms(1000);
    //TCNT1 = 0;
    OCR1A |= 103462;
    _delay_ms(1000);
    TCNT1 = 0;
    //OCR1A |= 103462;
    //_delay_ms(1000);
    //TCNT1 = 0;
    //OCR1A |= 2462;
    //_delay_ms(1000);
    //OCR1A |= 10002462;
    //_delay_ms(1000);
    //TCNT1 = 0;

    while (1) 
    {

    }
}

ISR (TIMER1_COMPA_vect) {
    // Reset the timer/counter register
    TCNT1 = 0;
}