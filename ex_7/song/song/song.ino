// Source of inspiration:
// https://www.hackster.io/brambi001/play-any-song-with-arduino-passive-buzzer-000d52

#include "pitches.h"
#include <time.h>
#include <RTClib.h>

RTC_DS1307 RTC;
const int buzzerPin = 9;

int h = 0;
int min = 0;
int sec = 0;

int melody [] = {NOTE_D4, NOTE_H4, NOTE_D5, NOTE_H4, NOTE_G4,
  NOTE_D4, NOTE_H4, NOTE_D5, NOTE_H4, NOTE_G4,
  NOTE_D4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_G4};

int durations[] = {8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 4, 8, 4, 8, 2};

void setup() {
  Serial.begin(9600);
  DateTime now = DateTime(__DATE__, __TIME__);
  h = now.hour();
  min = now.minute();
  sec = now.second();
  while (!((h == 8) && (min == 0) && (sec == 0))) {
    updateTime();
    delay(1000);
    Serial.print(h);
    Serial.print(":");
    Serial.print(min);
    Serial.print(".");
    Serial.println(sec);
  }

  for (int i = 0; i < 50; i++) {
    alarm();
    delay(10000);
  }
}

void loop() {
}

void updateTime() {
  sec = sec + 1;
  if (sec >= 60) {
    min = min + 1;
    sec = sec - 60;
  }
  if (min >= 60) {
    h = h + 1;
    min = min - 60;
  }
  if (h >= 24) {
    h = h - 24;
    min = 0;
    sec = 0;
  }
}

void alarm() {
  for (int note = 0; note < sizeof(melody) / 2; note++) {
    int duration = 1000 / durations[note];
    tone(buzzerPin, melody[note], duration);
    int pause = duration * 1.7;
    delay(pause);
  }
}
