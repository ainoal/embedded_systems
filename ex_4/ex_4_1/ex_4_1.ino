void setup() {
   pinMode(A2, OUTPUT); 
   Serial.begin(9600);
}

void loop() {
  int temperatureValue = analogRead(A1);
  Serial.println(temperatureValue);
  if (temperatureValue < 488) {
    // Turn motor off
    analogWrite(6, 0);
  } 
  else {
    // Turn motor on
    analogWrite(6, 250);
  }
}
