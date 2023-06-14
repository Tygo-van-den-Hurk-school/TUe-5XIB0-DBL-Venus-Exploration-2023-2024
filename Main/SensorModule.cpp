#include "SensorModule.h"

Sensors::Sensors() { 
  /* Initialize compass */ {
    compass.init();
    compass.setSamplingRate(50); // Adjust the sampling rate as needed
    compass.setRange(QMC5883L_RANGE_8GA); // Adjust the range as needed
  }
  
  /* Initialize sonar */ {
    sonar = NewPing(trigPin, echoPin);
  }
}

bool Sensors::ambientLight() { 
    const int VALUE = (50); // TODO change the name of this variable to better reflect its purpose
    const int AMBIENT_LIGHT = analogRead(GPIOPinAmbient);
    
    const bool LIGHT_WAS_NOT_BRIGHT_ENOUGH = (AMBIENT_LIGHT < VALUE); // TODO change the name of this variable to better reflect its purpose
    return (LIGHT_WAS_NOT_BRIGHT_ENOUGH); // TODO change the name of this variable to better reflect its purpose
}


bool Sensors::rockDetected() {
  const int MESSURED_INFRARED_VALUE = analogRead(infraredPin);
  const bool ROCK_DETECTED = (MESSURED_INFRARED_VALUE > infraredThreshold);
  return ROCK_DETECTED;
}

bool Sensors::boundaryDetected() {
  const int LEFT_LIGHT_VALUE = analogRead(leftLightPin);
  const int RIGHT_LIGHT_VALUE = analogRead(rightLightPin);
  
  const bool LEFT_SUSPECTS_BOUNDRY = (LEFT_LIGHT_VALUE > lightThreshold);
  const bool RIGHT_SUSPECTS_BOUNDRY = (RIGHT_LIGHT_VALUE > lightThreshold);
  
  const bool BOUNDRY_DETECTED = (LEFT_SUSPECTS_BOUNDRY && RIGHT_SUSPECTS_BOUNDRY); 
  return BOUNDRY_DETECTED;
}

bool Sensors::cliffDetected() {
  const long MINIMUM = (0); // TODO change the name of this variable to better reflect its purpose
  const long MAXIMUM = (10); // TODO change the name of this variable to better reflect its purpose
  const long DISTANCE = sonar.ping_cm();
  
  return ((DISTANCE > MINIMUM) && (DISTANCE <= MAXIMUM)); // TODO break this down into separate boolean statements, that explain what this range means
}

bool Sensors::hillDetected() {
  const long MINIMUM = (10); // TODO change the name of this variable to better reflect its purpose
  const long MAXIMUM = (20); // TODO change the name of this variable to better reflect its purpose
  const long DISTANCE = sonar.ping_cm();
  
  const bool DISTANCE_IS_BELOW_MAXIMUM = (DISTANCE <= MAXIMUM); // TODO change the name of this variable to better reflect its purpose
  const bool DISTANCE_IS_ABOVE_MINIMUM = (DISTANCE > MINIMUM); // TODO change the name of this variable to better reflect its purpose
  
  const bool DISTANCE_IS_IN_RANGE = (DISTANCE_IS_BELOW_MAXIMUM && DISTANCE_IS_ABOVE_MINIMUM);
  return (DISTANCE_IS_IN_RANGE); 
}

float Sensors::getCompassHeading() {
  compass.read();
  const float HEADING = compass.getAzimuth();
  return HEADING;
}

// Sensors::~Sensors(){
// If it does nothing, do not write it. It is just extra lines.
// for now I have dumped it here
// }
