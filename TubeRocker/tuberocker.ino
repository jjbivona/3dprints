#include <Servo.h>
#include <math.h>  // For using sine function

Servo myServo;  // Create a Servo object
int startPos = 40;   // Starting position
int endPos = 150;    // Ending position
int waitTime = 1000; // Wait time in milliseconds
int delayTime = 10;  // Time between position updates
int totalSteps = 100; // Number of steps for easing

void setup() {
  myServo.attach(4);  // Attach the servo to pin 4
  myServo.write(startPos); // Initialize the servo position
}

void smoothMove(int start, int end, int steps) {
  for (int i = 0; i <= steps; i++) {
    // Apply sine easing function
    float easedPos = start + (end - start) * (1 - cos(i * PI / steps)) / 2;
    myServo.write(easedPos);
    delay(delayTime);  // Small delay for each step
  }
}

void loop() {
  // Move from startPos to endPos using the easing function
  smoothMove(startPos, endPos, totalSteps);
  
  delay(waitTime);  // Wait at the end position

  // Move from endPos back to startPos using the easing function
  smoothMove(endPos, startPos, totalSteps);
  
  delay(waitTime);  // Wait at the start position
}
