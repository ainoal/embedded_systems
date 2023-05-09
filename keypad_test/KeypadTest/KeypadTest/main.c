/*
 * KeypadTest.c
 *
 * Created: 1.4.2023 18.34.49
 * Author : ainoal
 *
 * https://circuitdigest.com/microcontroller-projects/keypad-interfacing-with-avr-atmega32
 */ 

#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>


#define BITMASK_D 0b00001111
#define BITMASK_B 0b00001111

void led_test(void){
    PORTD &= ~(1 << PD3);
    _delay_ms(1000);
    PORTD |= (1 << PD3);
    _delay_ms(1000);
    PORTD &= ~(1 << PD3);
    _delay_ms(1000);
}

int compare(char *password, char *given_password){
    if (strcmp(password, given_password) != 0) {
        led_test();
        led_test();
        led_test();
        led_test();
        led_test();
        led_test();
        led_test();
        return 0;
    }
    else {
        return 1;
    }
}

int main(void)
{
    /********************testing****************************/
    //DDRD |= (1 << PD3);
    
    char input;
    FILE uart_output = FDEV_SETUP_STREAM(USART_transmit, NULL, _FDEV_SETUP_WRITE);
    FILE uart_input = FDEV_SETUP_STREAM(NULL, USART_receive, _FDEV_SETUP_READ);
        
    USART_init(UBRR);
        
    stdout = &uart_output;
    stdin = &uart_input;
    /******************************************************/
    
    char* password = "0123";
    char* given_password = "xxxx";
    int idx = 0;
    
    // CONFIG FOR READING COLUMNS (portB permanently high + portD will be able to read):
    DDRB |= 0b00000100; // PB2 as output
    DDRB |= 0b00001000; // PB3 as output
    DDRB |= 0b00010000; // PB4 as output
    DDRB |= 0b00100000; // PB5 as output
    _delay_ms(1);
    PORTB |= 0b00000100; // PB2 high output
    PORTB |= 0b00001000; // PB3 high output
    PORTB |= 0b00010000; // PB4 high output
    PORTB |= 0b00100000; // PB5 high output
    _delay_ms(1);
    DDRD &= 0b11101111; // PD4 as input
    DDRD &= 0b11011111; // PD5 as input
    DDRD &= 0b10111111; // PD6 as input
    DDRD &= 0b01111111; // PD7 as input
    _delay_ms(1);
  
    // Set digital pins 4-7 (rows) as output and 10-13 (columns) as input
    // DDRD = 0b00000000;
    // DDRB = 0b00001111;
    // _delay_ms(100);
    
    // Power the row pins
    // PORTD = 0b00001111;
    // PORTB = 0b00000000;
    // _delay_ms(100);
    
    uint8_t key_pressed = 0;
    uint8_t keypad_vals;
    uint8_t portb_vals;
    uint8_t portd_vals;
    
    while (1) 
    { 
        // READ THE COLUMNS:
        portd_vals = ((PIND & 0b11110000)); // hardcoded mask
        keypad_vals = portd_vals; // [columns_bit4 zeros_bit4]
            
        printf("PIND %d\n\r", PIND);
        
        // _delay_ms(100);
        /* portd_vals = ((PORTD & BITMASK_D) << 4);
        printf("portd_vals %d ", portd_vals);
        _delay_ms(100);
        
        portb_vals = ((PORTB & BITMASK_B) << 2);
        printf("portb_vals %d ", portb_vals);
        _delay_ms(10);
        keypad_vals = portd_vals | portb_vals;
        
        printf("Keypad_vals %d ", keypad_vals);
        keypad_vals &= 0b00001111;
        printf("Keypad_vals %d\n\r", keypad_vals);
        //printf("%d %d %d PIND: %d\n\r", keypad_vals, portd_vals, portb_vals, PIND);*/
        
        if (keypad_vals == 0b00000000) {     // If any of row pins goes low (!??)
            
            printf("loop\n\r");
            
            // CONFIG FOR READING ROWS (portD permanently high + portB will be able to read):
            DDRD |= 0b00010000; // PD4 as output
            DDRD |= 0b00100000;// PD5 as output
            DDRD |= 0b01000000; // PD6 as output
            DDRD |= 0b10000000; // PD7 as output
            _delay_ms(1);
            PORTD |= 0b00010000; // PD4 high output
            PORTD |= 0b00100000; // PD5 high output
            PORTD |= 0b01000000; // PD6 high output
            PORTD |= 0b10000000; // PD7 high output
            _delay_ms(1);    
            DDRB &= 0b11111011; // PB2 as input
            DDRB &= 0b11110111; // PB3 as input
            DDRB &= 0b11110111; // PB4 as input
            DDRB &= 0b11101111; // PB5 as input
            _delay_ms(1);
            
            // READ THE ROWS:
            portb_vals = ((PINB & 0b00111100)>>2); // hardcoded mask [zero_bit4 rows_bit4]
            
            // CONCATENATE COLUMNS AND ROWS
            key_pressed = keypad_vals | portb_vals; // [columns_bit4 row_bit4]
            
            printf("%d\n\r", PINB);
            
            // 
            
            //_delay_ms(10);
            
            // Make rows as inputs and columns as outputs
            // DDRD ^= 0b00000011;
            // DDRB ^= 0b00111111;
            
            // _delay_ms(1);
            // PORTB ^= 0b00001111;        // Power the columns
            // _delay_ms(100);
            
            // portd_vals = ((PIND & BITMASK_D) << 6);
            // portb_vals = PINB & BITMASK_B;
            // keypad_vals = portd_vals | portb_vals;
            // keypad_vals &= 0b11110000;
            
            // key_pressed |= keypad_vals;    // The variable has now both row and column values as 0, others as 1
            
            
            /*if (key_pressed == 0b01110111) {
                // Key 1 pressed
                given_password[idx] = '1';
                if (password[idx] == '1') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b01111011) {
                // Key 2 pressed
                given_password[idx] = '2';
                if (password[idx] == '2') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b01111101) {
                // Key 3 pressed
                given_password[idx] = '3';
                if (password[idx] == '3') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b01111110) {
                // A
                given_password[idx] = 'A';
                if (password[idx] == 'A') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b10110111) {
                // 4
                given_password[idx] = '4';
                if (password[idx] == '4') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b10111011) {
                // 5
                given_password[idx] = '5';
                if (password[idx] == '5') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b10111101) {
                // 6
                given_password[idx] = '6';
                if (password[idx] == '6') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b10111110) {
                // B
                given_password[idx] = 'B';
                if (password[idx] == 'B') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b11010111) {
                // 7
                given_password[idx] = '7';
                if (password[idx] == '7') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b11011011) {
                // 8
                given_password[idx] = '8';
                if (password[idx] == '8') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b11011101) {
                // 9
                given_password[idx] = '9';
                if (password[idx] == '9') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b11011110) {
                // C
                given_password[idx] = 'C';
                if (password[idx] == 'C') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b11100111) {
                // *
                // TODO: make this the backspace button
                given_password[idx] = '*';
                if (password[idx] == '*') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b11101011) {
                // 0
                given_password[idx] = '0';
                if (password[idx] == '0') {
                    led_test();
                }
                else {
                    ;
                }
            }
            else if (key_pressed == 0b11101101) {
                // #
                compare(password, given_password);
                //printf("#");
                //given_password[idx] = '#';
                //led_test();
            }
            else if (key_pressed == 0b11101110) {
                // D
                given_password[idx] = 'D';
                if (password[idx] == 'D') {
                    led_test();
                }
                else {
                    ;
                }
            }*/
            
            /*if (PIND != 0b11110000) {
                
                while (PIND != 0b00001111){
                    ;
                    //led_test();
                    _delay_ms(5);
                    //wait
                }
            }*/
            
            // Set digital pins 6-9 (rows) as output and 10-13 (columns) as input
            // DDRD |= 0b00000000;
            // DDRB |= 0b001111;
            // _delay_ms(1);
            
            // Power the row pins
            // PORTD = 0b00000011;
            // PORTB = 0b00110000;
            
            // key_pressed = 0;
            // idx +=1;
            //printf("%i \n", idx);
            //_delay_ms(10);
            
            // CONFIG FOR READING COLUMNS (portB permanently high + portD will be able to read):
            DDRB |= 0b00000100; // PB2 as output
            DDRB |= 0b00001000; // PB3 as output
            DDRB |= 0b00010000; // PB4 as output
            DDRB |= 0b00100000; // PB5 as output
            _delay_ms(1);
            PORTB |= 0b00000100; // PB2 high output
            PORTB |= 0b00001000; // PB3 high output
            PORTB |= 0b00010000; // PB4 high output
            PORTB |= 0b00100000; // PB5 high output
            _delay_ms(1);
            DDRD &= 0b11101111; // PD4 as input
            DDRD &= 0b11011111; // PD5 as input
            DDRD &= 0b10111111; // PD6 as input
            DDRD &= 0b01111111; // PD7 as input
            _delay_ms(1);   
       }
    }
}