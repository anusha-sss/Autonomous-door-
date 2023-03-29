//using the Servo library to control the servo motor connected to pin 12 of the ESP32.

#include <Servo.h>


const int servoPin = 12;

//instance of the Servo library
Servo doorLock;

void setup() {
  
  doorLock.attach(servoPin);
  
  // Set the initial position of the servo to 0 degrees
  doorLock.write(0);
}

void loop() {
  // Nothing to do repeatedly 
}

// Function to unlock the door
void unlockDoor() {
  // Set the position of the servo to 90 degrees
  doorLock.write(90);
  delay(1000); // Wait for the servo to move for 1 scond before turing back to 0 degrees
}


