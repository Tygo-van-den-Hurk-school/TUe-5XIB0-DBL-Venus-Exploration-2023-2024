// Libraries
#include <NewPing.h>

// Constants
const int infraredPin = A0;
const int leftLightPin = A1;
const int rightLightPin = A2;
const int trigPin = 2;
const int echoPin = 3;

// Thresholds
const int infraredThreshold = 500; // Adjust this value based on your environment
const int lightThreshold = 800; // Adjust this value based on your environment

// Ultrasonic sensor instance
NewPing sonar(trigPin, echoPin);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int infraredValue = analogRead(infraredPin);
  int leftLightValue = analogRead(leftLightPin);
  int rightLightValue = analogRead(rightLightPin);

  // Detect rocks
  if (infraredValue > infraredThreshold) {
    Serial.println("Rock detected!");
    // Add code to handle rock detection here
  }

  // Detect black tape boundaries
  if (leftLightValue > lightThreshold && rightLightValue > lightThreshold) {
    Serial.println("Boundary detected!");
    // Add code to handle boundary detection here
  }

  // Detect cliffs
  long distance = sonar.ping_cm();
  if (distance > 0 && distance <= 10) {
    Serial.println("Cliff detected!");
    // Add code to handle cliff detection here
  }

  // Detect hills
  if (distance > 10 && distance <= 20) {
    Serial.println("Hill detected!");
    // Add code to handle hill detection here
  }

  delay(100); // Adjust the delay as per your requirements
}
