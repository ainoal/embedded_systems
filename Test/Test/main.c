/*
 * KeypadTest.c
 *
 * Created: 1.4.2023 18.34.49
 * Author : ainoal
 *
 * https://circuitdigest.com/microcontroller-projects/keypad-interfacing-with-avr-atmega32
 */ 

//#define F_CPU 1000000

//#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>

void led_test();
int compare(char *password, char *given_password);

int main(void)
{
    /********************testing****************************/
    DDRB |= (1 << PB0);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB2);
    DDRB |= (1 << PB3);
    
    /*char input;
    FILE uart_output = FDEV_SETUP_STREAM(USART_transmit, NULL, _FDEV_SETUP_WRITE);
    FILE uart_input = FDEV_SETUP_STREAM(NULL, USART_receive, _FDEV_SETUP_READ);
        
    USART_init(UBRR);
        
    stdout = &uart_output;
    stdin = &uart_input;*/
    /******************************************************/
    
    char* password = "0123";
    char* given_password = "xxxx";
    int idx = 0;
    
    // Set digital pins 0-3 (rows) as output and 4-7 (columns) as input
    DDRD |= 0b00001111;
    _delay_ms(1);
    
    PORTD = 0b11110000;    // Power the row pins
    
    int key_pressed = 0;
    
    while (1) 
    {

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
                //printf("1");
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
            
            /*if (PIND != 0b11110000) {
                
                while (PIND != 0b00001111){
                    ;
                    //led_test();
                    _delay_ms(5);
                    //wait
                }
            }*/
            
            DDRD ^= 0b11111111;
            _delay_ms(1);
            PORTD ^= 0b11111111;
            key_pressed = 0;
            idx +=1;
            //printf("%i \n", idx);
            _delay_ms(10);
        }
    }
}

int compare(char *password, char *given_password){
    //printf("%s", given_password);
    if (strcmp(password, given_password) != 0) {
        // Wrong password
        led_test();
        led_test();
        led_test();
        led_test();
        led_test();
        led_test();
        led_test();
    } 
    else {
        // Correct password
        led_test();
    }
    return 0;
}

void led_test(){
    PORTB &= ~(1 << PB0);
    _delay_ms(1000);
    PORTB |= (1 << PB0);
    _delay_ms(1000);
    PORTB &= ~(1 << PB0);
    _delay_ms(1000);
}
