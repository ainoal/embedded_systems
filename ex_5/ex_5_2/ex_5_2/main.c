/*
 * ex_5_2.c
 *
 * Created: 16.3.2023 8.30.17
 * Author : ainol
 */ 

#define F_CPU 16000000UL    // Speed of the microprocessor 16MHz
#include <stdlib.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>

int floor_choice(int *current_floor) {
    //
    if (PINC & (1 << PC0)) {
        *current_floor = 1;
        } else if (PINC & (1 << PC1)) {
        *current_floor = 2;
        } else if (PINC & (1 << PC2)) {
        *current_floor = 3;
        } else if (PINC & (1 << PC3)) {
        *current_floor = 4;
        } else if ( (PINC & (1 << PC4)) ) {
        *current_floor = 5;
        } else {
        return 0;
    }
}

int main(void)
{
    // 1 = output, 0 = input -> LED pins output, button pins input
    DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5); // Floor LEDs
    DDRH |= (1 << PH3) | (1 << PH4); // Door LED | movement LED
    DDRC &= ~(1 << PC0) & ~(1 << PC1) & ~(1 << PC2) & ~(1 << PC3) & ~(1 << PC4); // Floor buttons
    int state = 1;
    int current_floor = 1;
    int next_floor = 1;
    
    PORTH &= ~(1 << PH3);
    
    while (1) 
    {
        switch(state) {
            case 1:         // Idle state
                
                if (current_floor == next_floor) {
                    floor_choice(&next_floor);
                    _delay_ms(10);
                } else if ((next_floor < 1) || (next_floor > 5)) {
                    state = 5;
                } else if (next_floor > current_floor) {
                    state = 2;
                } else if (next_floor < current_floor) {
                    state = 3;
                }
                break;
            case 2:         // Going up
                while (next_floor > current_floor) {
                    current_floor ++;
                    PORTH |= (1 << PH4);    // Turn movement LED on
                    _delay_ms(2000);
                }
                break;
            case 3:         // Going down
                break;
            case 4:         // Door open
                break;
            case 5:         // Fault
                break;
            default:
                break;
        }
    }
    return 0;
}


