/* The circuit contains red, green and blue LEDs parallel connected.
 * The user of this program can control the LEDs and turn one LED 
 * on or off separately. It is also possible to turn all LEDs on or
 * off at the same time.
 */

void setup() {
  pinMode(12, OUTPUT);  // Red LED
  pinMode(8, OUTPUT);   // Green LED
  pinMode(2, OUTPUT);   // Blue LED
  Serial.begin(9600);

  Serial.println("1. Switch R on/off");
  Serial.println("2. Switch G on/off");
  Serial.println("3. Switch B on/off");
  Serial.println("4. Switch all LEDs on");
  Serial.println("5. Switch all LEDs off\n");
}

void printState() {
  Serial.println("The current state:");
  if(digitalRead(12)==LOW) {
        Serial.println("R: OFF");
      } else {
        Serial.println("R: ON");
      }
    if(digitalRead(8)==LOW) {
        Serial.println("G: OFF");
      } else {
        Serial.println("G: ON");
      }
  if(digitalRead(2)==LOW) {
        Serial.println("B: OFF\n");
      } else {
        Serial.println("B: ON\n");
      }
}

void loop() {
  while (Serial.available() == 0) {}

  int menuChoice = Serial.parseInt();

  switch(menuChoice) {
    case 1:
      if(digitalRead(12)==LOW) {
        digitalWrite(12, HIGH);
      } else {
        digitalWrite(12, LOW);
      }
      printState();
      break;
    case 2:
      if(digitalRead(8)==LOW) {
        digitalWrite(8, HIGH);
      } else {
        digitalWrite(8, LOW);
      }
      printState();
      break;
    case 3:
      if(digitalRead(2)==LOW) {
        digitalWrite(2, HIGH);
      } else {
        digitalWrite(2, LOW);
      }
      printState();
      break;
    case 4:
      digitalWrite(12, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(2, HIGH);
      printState();
      break;
    case 5:
      digitalWrite(12, LOW);
      digitalWrite(8, LOW);
      digitalWrite(2, LOW);
      printState();
      break;
    default:
      Serial.println("Please try again");
      break;
  }
}
