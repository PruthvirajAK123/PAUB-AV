// Motor 1 encoder pins
const byte motor1PinA = 2;  // Interrupt for Motor 1 Pin A
const byte motor1PinB = 3;  // Motor 1 Pin B

// Motor 2 encoder pins
const byte motor2PinA = 20; // Interrupt for Motor 2 Pin A
const byte motor2PinB = 21; // Motor 2 Pin B

// Variables for encoder counts
volatile long motor1Count = 0; // Motor 1 count
volatile long motor2Count = 0; // Motor 2 count

void setup() {
  Serial.begin(9600);

  // Setup Motor 1 encoder pins
  pinMode(motor1PinA, INPUT_PULLUP);
  pinMode(motor1PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor1PinB), motor1ISR, CHANGE);

  // Setup Motor 2 encoder pins
  pinMode(motor2PinA, INPUT_PULLUP);
  pinMode(motor2PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor2PinB), motor2ISR, CHANGE);
}

void loop() {
  // Display encoder counts
  Serial.print("Motor 1 Count: ");
  Serial.println(motor1Count);
  Serial.print("Motor 2 Count: ");
  Serial.println(motor2Count);
  delay(500); // Update every 500ms
}

// Interrupt Service Routine for Motor 1
void motor1ISR() {
  bool pinA = digitalRead(motor1PinA);
  bool pinB = digitalRead(motor1PinB);

  if (pinA == pinB) {
    motor1Count++; // Increment for clockwise
  } else {
    motor1Count--; // Decrement for counterclockwise
  }
}

// Interrupt Service Routine for Motor 2
void motor2ISR() {
  bool pinA = digitalRead(motor2PinA);
  bool pinB = digitalRead(motor2PinB);

  if (pinA == pinB) {
    motor2Count++; // Increment for clockwise
  } else {
    motor2Count--; // Decrement for counterclockwise
  }
}
