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
    char input;
    FILE uart_output = FDEV_SETUP_STREAM(USART_transmit, NULL, _FDEV_SETUP_WRITE);
    FILE uart_input = FDEV_SETUP_STREAM(NULL, USART_receive, _FDEV_SETUP_READ);
    stdout = &uart_output;
    stdin = &uart_input;
    
    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);
    /******************************************************/
    
    // Set digital pins 0-3 (columns) as input and 4-7 (rows) as output
    DDRD |= 0b11110000;
    _delay_ms(1);
    
    PORTD |= 0b00001111;    // Power the row pins
    
    int key_pressed = 0;
    
    while (1) 
    {
        PORTB &= ~(1 << PB0);
        _delay_ms(1000);
        PORTB |= (1 << PB0);
        _delay_ms(1000);
        PORTB &= ~(1 << PB0);
        _delay_ms(1000);
        
        if (PIND!= 0b00001111) {     // If any of column pins goes high
            key_pressed = PIND;
            DDRD ^= 0b11111111;      // Make rows as inputs and columns as output
            _delay_ms(1);
             PORTD ^= 0b11111111;   // Power the columns
            _delay_ms(1);

            
            key_pressed |= PIND;    // The variable has now both row and column values
            
            if (key_pressed == 0b00010001) {
                // Key 1 pressed
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
            } else if (key_pressed == 0b00100001) {
                // Key 2 pressed
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                
                puts("2");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b01000001) {
                // Key 3 pressed
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("3");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b10000001) {
                // A
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("A");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b00010010) {
                // 4
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("4");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b00100010) {
                // 5
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("5");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b01000010) {
                // 6
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                //puts("6");
            } else if (key_pressed == 0b10000010) {
                // B
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("B");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b00010100) {
                // 7
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("7");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b00100100) {
                // 8
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("8");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b01000100) {
                // 9
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("9");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b10000100) {
                // C
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("C");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b00011000) {
                // *
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("*");
            } else if (key_pressed == 0b00101000) {
                // 0
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("0");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b01001000) {
                // #
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("#");
                input = getchar();
                printf("%c\n", input);
            } else if (key_pressed == 0b10001000) {
                // D
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                PORTB |= (1 << PB0);
                _delay_ms(1000);
                PORTB &= ~(1 << PB0);
                _delay_ms(1000);
                
                puts("D");
                input = getchar();
                printf("%c\n", input);
            }
            
            DDRD ^= 0b11111111;
            _delay_ms(1);
            PORTD ^= 0b11111111;
            key_pressed = 0;
            _delay_ms(10);
        }
    }    
}

