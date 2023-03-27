int state = 1;
int prevFloor = 1;
int nextFloor = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int temp = 0;

  switch(state) {
    case 1:   // Idle state
      Serial.println("Choose floor");
      while (Serial.available() == 0) {}
      nextFloor = Serial.parseInt();
      temp = Serial.parseInt();
      if (nextFloor > 6) {
        state = 5;
      } else if (nextFloor < 1) {
        state = 5;
      } else if (nextFloor > prevFloor) {
        state = 2;
      } else if (nextFloor < prevFloor) {
        state = 3;
      }
      break;
    case 2:   // Going up
      Serial.println("Going up");
      while(nextFloor > prevFloor){
        prevFloor += 1;
        Serial.println(prevFloor);
      }
      state = 4;
      break;
    case 3:   // Going down
      Serial.println("Going down");
      while(nextFloor < prevFloor){
        prevFloor -= 1;
        Serial.println(prevFloor);
      }
      state = 4;
      break;
    case 4:   // Door open
      Serial.println("Door open.");
      state = 1;
      break;
    default:  // Fault
      Serial.println("Invalid input, please try again.");
      state = 1;
      break;
  }
  

}
