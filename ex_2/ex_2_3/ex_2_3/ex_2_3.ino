/* 
* Display the letters A I N O on a MAX7219 display first using binary
* form and then hexadecimal form to control the display.
*/

#include <LedControl.h>

const int clockPin = 10;
const int latch = 9;
const int data = 8;
const int deviceID = 0;   // we only have one display device

LedControl led = LedControl(data, clockPin, latch, 1); // 1 = no. of MAX7219s

byte bitTableA[] = { // Lights up leds in A shape
  B00000000,
  B01111100,
  B01000100,
  B01000100,
  B01111100,
  B01000100,
  B01000100,
  B00000000,
};

byte bitTableI[] = { // Lights up leds in I shape
  B00000000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00000000,
};

byte bitTableN[] = { // Lights up leds in N shape
  B00000000,
  B01000010,
  B01100010,
  B01010010,
  B01001010,
  B01000110,
  B01000010,
  B00000000,
};

byte bitTableO[] = { // Lights up leds in O shape
  B00000000,
  B01111100,
  B01000100,
  B01000100,
  B01000100,
  B01000100,
  B01111100,
  B00000000,
};

byte hexTableA[] = { // Lights up leds in O shape
  0x00,
  0x7C,
  0x44,
  0x44,
  0x7C,
  0x44,
  0x44,
  0x00,
};

byte hexTableI[] = { // Lights up leds in O shape
  0x00,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x10,
  0x00,
};

byte hexTableN[] = { // Lights up leds in O shape
  0x00,
  0x42,
  0x62,
  0x52,
  0x4A,
  0x46,
  0x42,
  0x00,
};

byte hexTableO[] = { // Lights up leds in O shape
  0x00,
  0x7C,
  0x44,
  0x44,
  0x44,
  0x44,
  0x7C,
  0x00,
};

void setup() {
  led.shutdown(deviceID, false);
  led.setIntensity(deviceID, 1);
  led.clearDisplay(deviceID);
}

void draw(byte bitTable[]) {
  int bitTableLength = 8;
    
  for (int row = 0; row < bitTableLength; row++) {
        led.setRow(0, row, bitTable[row]); 
  }  
    delay(500);
}

void loop() {
  draw(bitTableA);
  delay(500);
  draw(bitTableI);
  delay(500);
  draw(bitTableN);
  delay(500);
  draw(bitTableO);
  delay(500);

  draw(hexTableA);
  delay(500);
  draw(hexTableI);
  delay(500);
  draw(hexTableN);
  delay(500);
  draw(hexTableO);
  delay(500);
}
