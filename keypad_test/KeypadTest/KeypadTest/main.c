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


#define BITMASK_D 0b11000000
#define BITMASK_B 0b00111111

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
    
    // Set digital pins 6-9 (rows) as input and 10-13 (columns) as output
    DDRD &= 0b00111111;
    DDRB &= 0b11111100;
    DDRB |= 0b00111100;
    _delay_ms(1);
    
    // Power the row pins
    PORTD |= 0b11000000;
    PORTB |= 0b00000011;
    _delay_ms(1);
    
    uint8_t key_pressed = 0;
    uint8_t keypad_vals;
    uint8_t portb_vals;
    uint8_t portd_vals;
    
    while (1) 
    { 
        //_delay_ms(10);
        portd_vals = ((PIND & BITMASK_D) >> 6);
        portb_vals = ((PINB & BITMASK_B) << 2);
        keypad_vals = portd_vals | portb_vals;
        
        //printf("Keypad_vals %d", keypad_vals);
        keypad_vals &= 0b00001111;
        printf("kp_vals: %d  portd_vals: %d  portb_vals: %d  PINB: %d\n\r", keypad_vals, portd_vals, portb_vals, PINB);
        
        if (keypad_vals != 0b00001111) {     // If any of column pins goes high
            printf("if\n\r");
            key_pressed = keypad_vals;
            //_delay_ms(1);
   
            
            // Make rows as output and columns as input
            DDRD |= 0b11000000;
            DDRB = 0b00000011;
            _delay_ms(1);
            
            // Power the column pins
            PORTB = 0b00111100;
            PORTD &= 0b00111111;
            _delay_ms(1);
            
            printf("PINB %d   ", PINB);
            portd_vals = ((PIND & BITMASK_D) >> 6);
            portb_vals = ((PINB & BITMASK_B) << 2);
            printf("portb_vals %d   portd_vals %d ", portb_vals, portd_vals);
            
            //_delay_ms(10);
            keypad_vals = portd_vals | portb_vals;
            keypad_vals &= 0b11110000;
            
            //printf("PINB %d   ", PINB);
            printf("Key pressed %d   ", key_pressed);
            //_delay_ms(10);
            key_pressed |= keypad_vals;    // The variable has now both row and column values
            printf("%d\n\r", key_pressed);
            
            if (key_pressed == 0b01110111) {
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
            }
            
            /* Initialization for new loop */
            // Set digital pins 6-9 (rows) as input and 10-13 (columns) as output
            DDRD &= 0b00111111;
            DDRB &= 0b11111100;
            DDRB |= 0b00111100;
            _delay_ms(1);
    
            // Power the row pins
            PORTD |= 0b11000000;
            PORTB |= 0b00000011;
            PORTB &= 0b11000011;
            _delay_ms(1);

            
            key_pressed = 0;
            idx +=1;
            //printf("%i \n", idx);
            _delay_ms(100);
        }
    }
}