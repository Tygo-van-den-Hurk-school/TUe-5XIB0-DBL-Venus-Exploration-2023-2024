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
bool detectRocks();
bool detectBoundaries();
bool detectCliffs();
bool detectHills();
bool readCompass();

Sensors::Sensors() { 
  // Initialize compass
  compass.init();
  compass.setSamplingRate(50); // Adjust the sampling rate as needed
  compass.setRange(QMC5883L_RANGE_8GA); // Adjust the range as needed
}

Sensors::~Sensors(){
  
}

// Function to detect rocks
bool Sensors::detectRocks() {
  int infraredValue = analogRead(infraredPin);
  return infraredValue > infraredThreshold;
}

// Function to detect black tape boundaries
bool Sensors::detectBoundaries() {
  int leftLightValue = analogRead(leftLightPin);
  int rightLightValue = analogRead(rightLightPin);
  returnleftLightValue > lightThreshold && rightLightValue > lightThreshold;
}

// Function to detect cliffs
bool Sensors::detectCliffs() {
  long distance = sonar.ping_cm();
  return distance > 0 && distance <= 10;
}

// Function to detect hills
bool Sensors::detectHills() {
  long distance = sonar.ping_cm();
  return distance > 10 && distance <= 20;
}

// Function to read compass data
float Sensors::readCompass() {
  compass.read();
  float heading = compass.getAzimuth();
  return heading;
}
