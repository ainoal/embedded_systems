#define F_CPU 16000000UL
// Include the necessary libraries
#include <avr/io.h>
#include <util/delay.h>

// Define the motion sensor pin
#define MOTION_SENSOR_PIN 3

// Define the LED pin
#define LED_PIN 13

// Initialize the ports and pins
void init()
{
    // Set the LED pin as an output
    DDRB |= (1 << DDB4);

    // Set the motion sensor pin as an input
    DDRD &= ~(1 << DDD3);
}

// Function to check if motion is detected
int isMotionDetected()
{
    if (PIND & (1 << PD3))
    {
        return 1; // Motion detected
    }
    else
    {
        return 0; // No motion detected
    }
}

int main(void)
{
    // Initialize the ports and pins
    init();

    // Infinite loop
    while (1)
    {
        // Check if motion is detected
        if (isMotionDetected())
        {
            // Turn on the LED
            PORTB |= (1 << PB4);
            _delay_ms(500); // Delay for 500 milliseconds
        }
        else
        {
            // Turn off the LED
            PORTB &= ~(1 << PB4);
        }
    }

    return 0;
}
