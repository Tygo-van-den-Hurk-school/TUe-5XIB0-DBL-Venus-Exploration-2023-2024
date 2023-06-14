#include "SensorModule.h"



Sensors::Sensors() { 
  // Initialize compass
  compass.init();
  compass.setSamplingRate(50); // Adjust the sampling rate as needed
  compass.setRange(QMC5883L_RANGE_8GA); // Adjust the range as needed
}

Sensors::~Sensors(){
  
}

bool Sensors::ambientLight(){
    int ambientLightValue = analogRead(GPIOPinAmbient);
    return ambientLightValue < 50;
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
