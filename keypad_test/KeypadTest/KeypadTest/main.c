/*
 * KeypadTest.c
 *
 * Created: 1.4.2023 18.34.49
 * Author : ainoal
 *
 * https://circuitdigest.com/microcontroller-projects/keypad-interfacing-with-avr-atmega32
 */ 

//#define F_CPU 1000000

#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


int main(void)
{
    /********************testing****************************/
    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);
    /******************************************************/
    
    // Set digital pins 0-3 (rows) as output and 4-7 (columns) as input
    DDRD |= 0b00001111;
    _delay_ms(1);
    
    PORTD = 0b11110000;    // Power the row pins
    
    int key_pressed = 0;
    
    while (1) 
    {
        /*PORTB &= ~(1 << PB0);
        _delay_ms(1000);
        PORTB |= (1 << PB0);
        _delay_ms(1000);
        PORTB &= ~(1 << PB0);
        _delay_ms(1000);*/
        
        if (PIND != 0b11110000) {     // If any of row pins goes low (!??)
            key_pressed = PIND;
            _delay_ms(10);
            DDRD ^= 0b11111111;      // Make rows as inputs and columns as outputs
            _delay_ms(1);
             PORTD ^= 0b11111111;        // Power the columns
            _delay_ms(100);
            
            key_pressed |= PIND;    // The variable has now both row and column values as 0, others as 1
            
            if (key_pressed == 0b01110111) {
                // Key 1 pressed
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b01111011) {
                // Key 2 pressed
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b01111101) {
                // Key 3 pressed
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b01111110) {
                // A
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b10110111) {
                // 4
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b10111011) {
                // 5
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b10111101) {
                // 6
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b10111110) {
                // B
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11010111) {
                // 7
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11011011) {
                // 8
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11011101) {
                // 9
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11011110) {
                // C
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11100111) {
                // *
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11101011) {
                // 0
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11101101) {
                // #
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } 
            else if (key_pressed == 0b11101110) {
                // D
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            }
            
            DDRD ^= 0b11111111;
            _delay_ms(1);
            PORTD ^= 0b11111111;
            key_pressed = 0;
            _delay_ms(10);
        }
    }    
}

