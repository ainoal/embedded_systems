/*
* Dimmer switch program
* The program turns a LED on or off based on the surrounding brightness.
* The circuit has a photoresistor that decreases resistance with respect
* to recieving light on its sensitive surface. The analog value is then
* read, and at a certain (arbitrary) voltage treshold, the light switches
* on/off when it gets darker or lighter.
*/

void setup() {
  // The pin used for the LED
  pinMode(2, OUTPUT);
  // Begin serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Read the analog value and print it in serial monitor
  int sensorValue = analogRead(A0);
  Serial.print("Analog value: ");
  Serial.println(sensorValue);

  // Control the LED based on the analog value
  if (sensorValue < 600) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}
