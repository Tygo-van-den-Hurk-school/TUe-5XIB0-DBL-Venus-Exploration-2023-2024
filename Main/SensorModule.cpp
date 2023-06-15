#include "SensorModule.h"

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~ Constructors, and Destructors ~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~
Sensors::Sensors() { 
  /* Initialize the compass */ {
    this -> COMPASS.init();
    this -> COMPASS.setSamplingRate(SAMPLING_RATE_COMPASS);
    this -> COMPASS.setRange(QMC5883L_RANGE_8GA); // Adjust the range as needed
  }
  
  /* Initialize the sonar */ {
    this -> SONAR = NewPing(trigPin, echoPin);
  }
}

// Sensors::~Sensors(){
// If it does nothing, do not write it. It is just extra lines. 
// Plus I do not expect an arduino to destruct objects when shut
// down due to power loss. So is this even needed?
// }

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Sensor value returning methods ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 
bool Sensors::ambientLight() { 
    const int VALUE = (50); // TODO change the name of this variable to better reflect its purpose
    const int AMBIENT_LIGHT = analogRead(AMBIENT_LIGHT_SENSOR_GPIO_PIN);
    // TODO Awnser this question: why are we not using "LIGHT_THRESHOLD"?
    const bool LIGHT_WAS_NOT_BRIGHT_ENOUGH = (AMBIENT_LIGHT < VALUE); // TODO change the name of this variable to better reflect its purpose
    return (LIGHT_WAS_NOT_BRIGHT_ENOUGH);
}

bool Sensors::rockDetected() {
  const int MESSURED_INFRARED_VALUE = analogRead(INFRA_RED_SENSOR_GPIO_PIN);
  const bool ROCK_DETECTED = (MESSURED_INFRARED_VALUE > infraredThreshold);
  return ROCK_DETECTED;
}

bool Sensors::boundaryDetected() {
  const int LEFT_LIGHT_VALUE = (analogRead(LEFT_LIGHT_SENSOR_GPIO_PIN));
  const int RIGHT_LIGHT_VALUE = (analogRead(RIGHT_LIGHT_SENSOR_GPIO_PIN));
  
  const bool LEFT_SUSPECTS_BOUNDRY = (LEFT_LIGHT_VALUE > LIGHT_THRESHOLD);
  const bool RIGHT_SUSPECTS_BOUNDRY = (RIGHT_LIGHT_VALUE > LIGHT_THRESHOLD);
  
  const bool BOUNDRY_DETECTED = (LEFT_SUSPECTS_BOUNDRY && RIGHT_SUSPECTS_BOUNDRY); 
  return BOUNDRY_DETECTED;
}

bool Sensors::cliffDetected() {
  const long ZERO_CENTIMETERS = (0);
  const long TEN_CENTIMETERS = (10);
  const long DISTANCE = (SONAR.ping_cm());
    
  const bool DISTANCE_IS_SHORTER_THEN_TEN_CENTIMETERS = (DISTANCE <= TEN_CENTIMETERS); 
  const bool DISTANCE_IS_FURTHER_THEN_ZERO_CENTIMETERS = (DISTANCE > ZERO_CENTIMETERS);
  
  const bool DISTANCE_IS_BETWEEN_ZERO_AND_TEN_CENTIMETERS = (
    DISTANCE_IS_SHORTER_THEN_TEN_CENTIMETERS && DISTANCE_IS_FURTHER_THEN_ZERO_CENTIMETERS
  );
  
  return (DISTANCE_IS_IN_RANGE); 
}

bool Sensors::hillDetected() {
  const long TEN_CENTIMETERS = (10);
  const long TWENTY_CENTIMETERS = (20);
  const long DISTANCE = (SONAR.ping_cm());
  
  const bool DISTANCE_IS_SHORTER_THEN_TWENTY_CENTIMETERS = (DISTANCE <= MAXIMUM);
  const bool DISTANCE_IS_FURTHER_THEN_TEN_CENTIMETERS = (DISTANCE > TEN_CENTIMETERS);
  
  const bool DISTANCE_IS_BETWEEN_TEN_AND_TWENTY_CENTIMETERS = (
    DISTANCE_IS_SHORTER_THEN_TWENTY_CENTIMETERS && DISTANCE_IS_FURTHER_THEN_TEN_CENTIMETERS
  );
  
  return (DISTANCE_IS_IN_RANGE); 
}

float Sensors::getCompassHeading() {
  COMPASS.read();
  const float HEADING = COMPASS.getAzimuth();
  return HEADING;
}
