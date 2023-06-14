// Libraries
#include <NewPing.h>
#include <Wire.h>
#include <QMC5883L.h>

// Constants
const int infraredPin = A0;
const int leftLightPin = A1;
const int rightLightPin = A2;
const int trigPin = 2;
const int echoPin = 3;

// Thresholds
const int infraredThreshold = 500; // Adjust this value based on your environment
const int lightThreshold = 800; // Adjust this value based on your environment

// Sensor instances
NewPing sonar(trigPin, echoPin);
QMC5883L compass;

// Function prototypes
void detectRocks();
void detectBoundaries();
void detectCliffs();
void detectHills();
void readCompass();

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  
  // Initialize compass
  compass.init();
  compass.setSamplingRate(50); // Adjust the sampling rate as needed
  compass.setRange(QMC5883L_RANGE_8GA); // Adjust the range as needed
}

void loop() {
  detectRocks();
  detectBoundaries();
  detectCliffs();
  detectHills();
  readCompass();

  delay(100); // Adjust the delay as per your requirements
}

// Function to detect rocks
void detectRocks() {
  int infraredValue = analogRead(infraredPin);
  if (infraredValue > infraredThreshold) {
    Serial.println("Rock detected!");
    // Add code to handle rock detection here
  }
}

// Function to detect black tape boundaries
void detectBoundaries() {
  int leftLightValue = analogRead(leftLightPin);
  int rightLightValue = analogRead(rightLightPin);
  if (leftLightValue > lightThreshold && rightLightValue > lightThreshold) {
    Serial.println("Boundary detected!");
    // Add code to handle boundary detection here
  }
}

// Function to detect cliffs
void detectCliffs() {
  long distance = sonar.ping_cm();
  if (distance > 0 && distance <= 10) {
    Serial.println("Cliff detected!");
    // Add code to handle cliff detection here
  }
}

// Function to detect hills
void detectHills() {
  long distance = sonar.ping_cm();
  if (distance > 10 && distance <= 20) {
    Serial.println("Hill detected!");
    // Add code to handle hill detection here
  }
}

// Function to read compass data
void readCompass() {
  compass.read();
  float heading = compass.getAzimuth();
  Serial.print("Compass Heading: ");
  Serial.println(heading);
}
