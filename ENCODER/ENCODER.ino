#include <ros.h>
#include <std_msgs/Int32.h>

// Motor 1 encoder pins
const byte motor1PinA = 2;  // Interrupt for Motor 1 Pin A
const byte motor1PinB = 3;  // Motor 1 Pin B

// Motor 2 encoder pins
const byte motor2PinA = 20; // Interrupt for Motor 2 Pin A
const byte motor2PinB = 21; // Motor 2 Pin B

// Variables for encoder counts
volatile long motor1Count = 0; // Motor 1 count
volatile long motor2Count = 0; // Motor 2 count

// ROS Node Handle
ros::NodeHandle nh;

// ROS Messages for motor ticks
std_msgs::Int32 motor1Ticks;
std_msgs::Int32 motor2Ticks;

// ROS Publishers
ros::Publisher motor1_pub("motor1_ticks", &motor1Ticks);
ros::Publisher motor2_pub("motor2_ticks", &motor2Ticks);

void setup() {
  // Initialize Serial for ROS communication
  nh.initNode();
  nh.advertise(motor1_pub);
  nh.advertise(motor2_pub);

  // Setup Motor 1 encoder pins
  pinMode(motor1PinA, INPUT_PULLUP);
  pinMode(motor1PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor1PinA), motor1ISR, CHANGE);

  // Setup Motor 2 encoder pins
  pinMode(motor2PinA, INPUT_PULLUP);
  pinMode(motor2PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(motor2PinA), motor2ISR, CHANGE);
}

void loop() {
  // Publish motor ticks to ROS topics
  motor1Ticks.data = motor1Count;
  motor2Ticks.data = motor2Count;

  motor1_pub.publish(&motor1Ticks);
  motor2_pub.publish(&motor2Ticks);

  // Spin the ROS node
  nh.spinOnce();
  delay(100); // Adjust publishing rate as needed
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
