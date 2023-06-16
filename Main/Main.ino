// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  ~~~~ ~~ Libraries ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 
#include "MovementModule.h"
#include "SensorModule.h"
#include "CommunicationModule.h"
#include <Arduino.h>                // TODO awnser this question: Why is this in here? Arduino includes this by default.
#include <ESP32Servo.h>

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Constants ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~
/** The GPIO pin used for controling the head servo. */
#define HEAD_SERVO_GPIO_PIN   25
/** The GPIO pin used for controling the claw servo. */
#define CLAWS_SERVO_GPIO_PIN  26

/** this stores how many degrees zero-degrees are. */
#define ZERO_DEGREES          0
/** this stores how many degrees ninety-degrees are. */
#define NINETY_DEGREES        90
/** this stores how many degrees 180-degrees are. */
#define ONE_EIGHTY_DEGREES    180

/** the default delay time. */
#define DEFAULT_DELAY_TIME    20
/** the enum for when a situation is not understood/reconised. */
#define NOT_UNDERSTOOD        0
/** the enum for when a situation is that there are rocks detected. */
#define ROCK_IS_DETECTED      1
/** the enum for when a situation is that there are hills detected. */
#define HILL_IS_DETECTED      2
/** the enum for when a situation is that there are cliffs detected. */
#define CLIFF_IS_DETECTED     3
/** the enum for when a situation is that there are boundaries detected. */
#define BOUNDARY_IS_DETECTED  4

/** the speed at which the Serial monitor parses the incoming bits. */
#define DEFAULT_SERIAL_SPEED  115200

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~ Objects ~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~
/** The object that is responsible for all the movement of the robot. */
const Movement movement;            // TODO remove this when the functions become static.
/** The object that is responsible processing all the sensor data of the robot. */
const Sensors sensors;              // TODO remove this when the functions become static.
/** The object that is responsible for all the communications of the robot. */
const Communication communication;  // TODO remove this when the functions become static.

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~ Arduino main-functions ~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~
/**
 * this method is the main method where the code starts running. This method is only run once. After this, the method `loop()`
 * is run indefinitely. Meaning that that one will run until reset, or powerloss.
 */
void setup() {
  /* Setting up Serial */ {
    Serial.begin(DEFAULT_SERIAL_SPEED); 
  }
  
  /* creating the objects */ {                          // TODO remove this when the functions become static.
    movement = Movement();                              // TODO remove this when the functions become static.
    sensors = Sensors();                                // TODO remove this when the functions become static.
    communication = Communication();                    // TODO remove this when the functions become static.
  }
  
  /* Testing Communications? */ {                       // TODO awnser this question: Why is this in here?
    strcpy(communication.myData.status, "something");   // TODO awnser this question: Why is this in here?
    communication.send(communication.myData);           // TODO awnser this question: Why is this in here?
  }
}

/**
 * Loops until reset, or powerloss. This function fetched the current situation that the robot is in, and for each case
 * does the logic that belongs to that case.
 */
void loop() {
  const int CURRENT_SITUATION = (getSituation());
  
  /* doing the logic for each situation. */ {
    switch (CURRENT_SITUATION) {
      case ROCK_IS_DETECTED:
        // TODO put logic here
        break;
      case HILL_IS_DETECTED:
        // TODO put logic here
        break;
      case CLIFF_IS_DETECTED:
        // TODO put logic here
        break;
      case BOUNDARY_IS_DETECTED:
        // TODO put logic here
        break;
      default:
      Serial.print("[ ERR ] ==> Situation not reconised: ");
      Serial.print(CURRENT_SITUATION);
      Serial.print(".\n");
    }
  }

  delay(DEFAULT_DELAY_TIME);
}

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Helper-functions ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~
/**
 * Finds in what situation the robot is in, and returns that. Possible situations are: "ROCK_IS_DETECTED",
 * "HILL_IS_DETECTED", "CLIFF_IS_DETECTED", "BOUNDARY_IS_DETECTED", and "NOT_UNDERSTOOD". For each situation there is
 * different logic to handle it.
 *
 * @return and int that represents the situation that the robot is in.
 */
int getSituation() { // TODO move this function into its own file
  
  /* checking if a rock is detected */ {
    const bool ROCK_DETECTED = (sensors.rockDetected());
    if (ROCK_DETECTED) {
      return ROCK_IS_DETECTED;
    }
  }
 
  /* checking if a hill is detected */ {
    const bool HILL_DETECTED = (sensors.hillDetected);
    if (HILL_DETECTED) {
      return HILL_IS_DETECTED;
    }
  }
  
  /* checking if a cliff is detected */ {
    const bool CLIFF_DETECTED = (sensors.cliffDetected);
    if (CLIFF_DETECTED) {
      return CLIFF_IS_DETECTED;
    }
  }
  
  /* checking if a boundary is detected */ {
    const bool BOUNDARY_DETECTED = (sensor.boundaryDetected());
    if (BOUNDARY_DETECTED) {
      return BOUNDARY_IS_DETECTED;
    }
  }
  
  return NOT_UNDERSTOOD;
}

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  should-not-be-here-functions  ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~
/** The servo that controls the head of the robot. */
const Servo servoHead;              // TODO awnser this question: Why is this in here in this file?
/** The servo that controls the claws of the robot. */
const Servo servoClaws;             // TODO awnser this question: Why is this in here in this file?

/**
 * Opens and closes the claws.
 */
void clawsTurn() { // TODO awnser this question: Why is this in here in this file?
  servoClaws.attach(CLAWS_SERVO_GPIO_PIN);
  
  /* Opening Claws */ {
    for(int posDegrees = ZERO_DEGREES; posDegrees <= NINETY_DEGREES; posDegrees++) {
      servoClaws.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
    printf("[LOG]: opened claw\n");
  }
  
  /* Closing Claws */ {
    for(int posDegrees = NINETY_DEGREES; posDegrees > ZERO_DEGREES; posDegrees--) {
      servoClaws.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
    printf("[LOG]: closed claw\n");
  }

  servoClaws.detach();
}

/**
 * Turns the head of the robot left and right. Does nothing else, just turns.
 * 
 * TODO awnser this question: what is the purpose of this method?
 */
void headTurn() { // TODO awnser this question: Why is this in here in this file?
  servoHead.attach(HEAD_SERVO_GPIO_PIN);
  
  // if something detected at x angle store that angle // TODO awnser this question: is this a TODO?
  
  /* Turning head left */ {
    for(int posDegrees = ZERO_DEGREES; posDegrees <= NINETY_DEGREES; posDegrees++) {
      servoHead.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
    printf("[LOG]: Head turned left\n");
  }
  
  /* Turning head Right */ {
    for(int posDegrees = ONE_EIGHTY_DEGREES; posDegrees >= ZERO_DEGREES; posDegrees--) {
      servoHead.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
    printf("[LOG]: Head turned right\n");
  }

  /* putting head back in original position */ {
    for(int posDegrees = ZERO_DEGREES; posDegrees <= NINETY_DEGREES; posDegrees++) {
      servoHead.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
  }
  
  servoHead.detach();
}
