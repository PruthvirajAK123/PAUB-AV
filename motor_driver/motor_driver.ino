#include "CytronMotorDriver.h"

// Configure the motor driver pins for ESP8266
// Adjust the GPIO numbers as per your wiring.
CytronMD motor1(PWM_PWM, D6, D7);   // PWM 1A = D1 (GPIO5), PWM 1B = D2 (GPIO4).
CytronMD motor2(PWM_PWM, D1, D0);   // PWM 2A = D3 (GPIO0), PWM 2B = D4 (GPIO2).

void setup() {
  // Optional: Add debugging messages for setup
  Serial.begin(115200);
  Serial.println("Motor control with ESP8266");
}

void loop() {
  motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
  motor2.setSpeed(-128);  // Motor 2 runs backward at 50% speed.
  delay(1000);

  motor1.setSpeed(255);   // Motor 1 runs forward at full speed.
  motor2.setSpeed(-255);  // Motor 2 runs backward at full speed.
  delay(1000);

  motor1.setSpeed(0);     // Motor 1 stops.
  motor2.setSpeed(0);     // Motor 2 stops.
  delay(1000);

  motor1.setSpeed(-128);  // Motor 1 runs backward at 50% speed.
  motor2.setSpeed(128);   // Motor 2 runs forward at 50% speed.
  delay(1000);

  motor1.setSpeed(-255);  // Motor 1 runs backward at full speed.
  motor2.setSpeed(255);   // Motor 2 runs forward at full speed.
  delay(1000);

  motor1.setSpeed(0);     // Motor 1 stops.
  motor2.setSpeed(0);     // Motor 2 stops.
  delay(1000);
}
