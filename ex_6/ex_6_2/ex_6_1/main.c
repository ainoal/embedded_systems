/*
 * Mega_LCD.c
 *
 * Created: 3.5.2023 18:23:39
 * Author : ainoal
 */ 


#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h" // lcd header file made by Peter Fleury

int
main(void)
{
    /* initialize display, cursor off */
    lcd_init(LCD_DISP_ON);
    
    // let's create a test number (int) and convert it to char array
    int16_t test_number = 1923;
    char test_char_array[16]; // 16-bit array, assumes that the int given is 16-bits
    itoa(test_number, test_char_array, 10);

    /* clear display */
    lcd_clrscr();
    /* print string */
    lcd_puts("Hello World!");
    
    /* move cursor to position second line and print test number */
    lcd_gotoxy(0,1);
    lcd_puts(test_char_array);


    while(1)
    {

    }
    
    return 0;
}