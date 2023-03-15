/* Use the serial port to read user input. User can give coordinates
to switch on LEDs on MAX7219 (8x8 display) */

#include <LedControl.h>

const int clockPin = 10;
const int latch = 9;
const int data = 8;
const int deviceID = 0;   // we only have one display device

LedControl led = LedControl(data, clockPin, latch, 1); // 1 = no. of MAX7219s

char buffer[3];
int column;
int row;

void setup() {
  Serial.begin(9600);
  led.shutdown(deviceID, false);
  led.setIntensity(deviceID, 1);
  led.clearDisplay(deviceID);

  Serial.println("Give coordinates to which to set led");
  Serial.println("Format: column, row");
  Serial.println("Column and row should be in range 0-7");
  Serial.println("To clear display type '9,9'");
}

void loop() {

  if (Serial.available() > 0) {
    Serial.readBytes(buffer, 3);
    Serial.println(buffer);

    // Serial.readBytes() takes the user data as char.
    // Convert it to numbers according to ASCII table
    // (0 is at place 48 in ASCII table)
    column = (int) buffer[0] - 48;
    row = (int) buffer[2] - 48;

    if ((column == 9) && (row == 9)) {
      led.clearDisplay(deviceID);
    } else if ((column < 0) || (column > 7) || (row < 0) || (row > 7)) {
      Serial.println("Incorrect input. Please give column in range 0-7 and row in range 0-7!");
      Serial.println("(Or row 9 and column 9 to clear display)");
    } else {
      led.setLed(deviceID, column, row, 1);
    }
  } 

}
