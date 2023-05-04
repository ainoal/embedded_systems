/*
 * ProjectMega.c
 *
 * Created: 3.5.2023 15.39.20
 * Author : ainol
 */ 

#define F_CPU 16000000UL    // Clock frequency
#define FOSC 16000000	    // Frequency of oscillator
#define BAUD 9600
#define UBRR FOSC/16/BAUD-1

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h" // lcd header file made by Peter Fleury

// States for state machine
#define IDLE 0
#define DISARMED 1
#define ALARM 2
#define TRIGGERED_WRONGPASSWORD 3
#define TRIGGERED_TOOSLOW 4
volatile int8_t state = 0;

void USART_init(unsigned int ubrr);

int main(void)
{   
    // Set up passive buzzer ports and pins
    DDRE |= (1 << PE3); // OC3A is located in digital pin 5
    
    // Initialize USART
    USART_init(UBRR);
    
    // Enable interrupts
    sei();
    
    // initialize display, cursor off
    lcd_init(LCD_DISP_ON);
    
    while (1) 
    {
        // State machine
        switch(state) {
            case IDLE:
                // Clear display and print string
                lcd_clrscr();
                lcd_puts("Alarm system on");
            
                // Wait for data to be received
                while (!(UCSR0A & (1<<RXC0)));
                
                // Read the received data into state variable
                state = UDR0;
                break;
                
            case DISARMED:
                lcd_clrscr();
                lcd_puts("Disarmed");
                _delay_ms(10);
                
                // Wait for data to be received and read the received data
                // TODO: should it only be possible to change the state to idle from here? 
                while (!(UCSR0A & (1<<RXC0)));
                state = UDR0;
                break;
                
            case ALARM:
                lcd_clrscr();
                lcd_puts("Give password");
                                
                // Wait for data to be received and read the received data
                while (!(UCSR0A & (1<<RXC0)));
                state = UDR0;
                break;
                
            case TRIGGERED_WRONGPASSWORD:
                lcd_clrscr();
                lcd_puts("Wrong password");
                break;
                
            case TRIGGERED_TOOSLOW:
                lcd_clrscr();
                lcd_puts("You did not give password on time");
                break;
                
            default:
                state = IDLE;
                break;
        }
    }
}

void USART_init(unsigned int ubrr) {
    // Set baud rate
    UBRR0H = (unsigned char) (ubrr>>8);
    UBRR0L = (unsigned char) ubrr;
    
    // Enable receiver and transmitter
    UCSR0B = (1<<RXEN0) | (1<<TXEN0);
    
    // Set frame format: 8data, 2stop bit
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);
}