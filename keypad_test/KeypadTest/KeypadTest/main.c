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
    
    char *password = "0123";
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
                if (password[idx] == '1') {
                    led_test();
                }
                else {                
                    ;
                }                    
            } 
            else if (key_pressed == 0b01111011) {
                // Key 2 pressed
                if (password[idx] == '2') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b01111101) {
                // Key 3 pressed
                if (password[idx] == '3') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b01111110) {
                // A
                if (password[idx] == 'A') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b10110111) {
                // 4
                if (password[idx] == '4') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b10111011) {
                // 5
                if (password[idx] == '5') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b10111101) {
                // 6
                if (password[idx] == '6') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b10111110) {
                // B
                if (password[idx] == 'B') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11010111) {
                // 7
                if (password[idx] == '7') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11011011) {
                // 8
                if (password[idx] == '8') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11011101) {
                // 9
                if (password[idx] == '9') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11011110) {
                // C
                if (password[idx] == 'C') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11100111) {
                // *
                if (password[idx] == '*') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11101011) {
                // 0
                if (password[idx] == '0') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11101101) {
                // #
                if (password[idx] == '#') {
                    led_test();
                }
                else {
                    ;
                }
            } 
            else if (key_pressed == 0b11101110) {
                // D
                if (password[idx] == 'D') {
                    led_test();
                }
                else {
                    ;
                }
            }
            
            if (PIND != 0b11110000) {
                
                while (PIND != 0b00001111){
                    ;
                    //led_test();
                    //wait
                }                
                //led_test();
            }
            //led_test();
            
            /*while (PIND != 0b11110000){
                ;
                //wait
                //led_test();
            }*/
            
            DDRD ^= 0b11111111;
            _delay_ms(1);
            PORTD ^= 0b11111111;
            key_pressed = 0;
            idx +=1;
            _delay_ms(10);
        }
    }    
}

void led_test(){
    PORTB &= ~(1 << PB0);
    _delay_ms(1000);
    PORTB |= (1 << PB0);
    _delay_ms(1000);
    PORTB &= ~(1 << PB0);
    _delay_ms(1000);
}


