int data = 4;
int latch = 5;
int clock = 6;
char common = 'c';

void setup() {
  pinMode(data, OUTPUT); // shift
  pinMode(latch, OUTPUT); // latch
  pinMode(clock, OUTPUT); // clock

  Serial.begin(9600);
}

void loop() {
  for (int i=0; i<=9; i++) { 
    byte bits = binary(i);
    display(bits);
    delay(500);
  }

}

void display(byte eightBits) {
  if (common == 'c') {
    eightBits = eightBits ^ B11111111;
  }
  digitalWrite(latch, LOW);
  shiftOut(data, clock, LSBFIRST, eightBits);
  digitalWrite(latch, HIGH);

}

byte binary(int letter) {
  Serial.println(letter);
  switch(letter) {
    case 0:
      Serial.print("0");    
      return B11110110;
      
      break;
    case 1:
      Serial.print("1");
      return B11110110;
      break;
    case 2:
      return B11110110;
      break;
    case 3:
      return B11110110;
      break;
    case 4:
      return B11110110;
      break;
    case 9:
      return B11110110;
      break;
    default:
      break;
  }
}
