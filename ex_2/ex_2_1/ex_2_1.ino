#include <stdio.h>

const int Clock = 10;
const int latch = 9;
const int data = 8;
//byte value = B11111100;

void setup() {
  // put your setup code here, to run once:
  pinMode(Clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte bin_list[] = {B11111100, B01100000, B11011010, B11110010};
    //for (int i=0; i <= sizeof(bin_list); i++) {
    digitalWrite(latch, LOW);
    shiftOut(data, Clock, LSBFIRST, bin_list[1]);
    digitalWrite(latch, HIGH);
    delay(500);
    digitalWrite(latch, LOW);
    shiftOut(data, Clock, LSBFIRST, bin_list[2]);
    digitalWrite(latch, HIGH);
    delay(500);
  //}

}
