/**
 * @file this file defines the methods for the movement header file.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * @author Jerry Liang, student at TU/e (1522019)
 * @author Saviël van Wijngaarden, student at TU/e (???????)
 */
// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  ~~~~ ~~ Libraries ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

#include "MovementModule.h"
#include <Arduino.h>
#include <ESP32Servo.h>

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Constructors, and Destructors ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

Movement::Movement() {
  this -> coordinates.x = 0.0;
  this -> coordinates.y = 0.0;
}

Movement::~Movement() {
  // If it does nothing, do not write it. It is just extra lines. 
  // Plus I do not expect an arduino to destruct objects when shut
  // down due to power loss. So is this even needed?
}

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  Methods that move/rotate the  robot ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

void Movement::moveForward(const int DEGREES) {
  /* Checking Pre-Conditions */ {
    if (this -> movementDirection == FORWARDS) {
      printf("[MovementModule.moveForward] ==> Error: Already moving forwards. \n");
      return;
    }
  }

  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Moving forwards. \n");
    rightWheel.attach(RIGHT_MOTOR_PIN);
    leftWheel.attach(LEFT_MOTOR_PIN);
  }
  
  /* Moving the robot forwards */ { // TODO make it so that it continues to move forward, until one of the sensors reads something different, for a certain distance // TODO make it return how many degrees it moved the wheel such that later, we can implement backwards to go back those degrees such that all the movement is reversable and we get back where we started.
    const int ZERO_DEGREES = (0);
    for (int posDegrees = ZERO_DEGREES; posDegrees <= DEGREES; posDegrees++) {
      LEFT_WHEEL.write(posDegrees);
      RIGHT_WHEEL.write(-posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
    this -> movementDirection = FORWARD;
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped moving forward. \n");
    rightWheel.detach();
    leftWheel.detach();
  }
}

void Movement::moveBackward(const int DEGREES) {

  /* Checking Pre-Conditions */ {
    if (this -> movementDirection == BACKWARDS) {
      printf("[MovementModule.moveBackward] ==> Error: Already moving backwards. \n");
      return;
    }
  }

  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Moving backwards. \n");
    rightWheel.attach(RIGHT_MOTOR_PIN);
    leftWheel.attach(LEFT_MOTOR_PIN);
  }
  
  /* Moving the robot backwards */ {
    const int ZERO_DEGREES = (0);
    for (int posDegrees = ZERO_DEGREES; posDegrees <= DEGREES; posDegrees++) {
      leftWheel.write(-posDegrees);
      rightWheel.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
    this -> movementDirection = BACKWARDS;
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped moving backward.\n");
    rightWheel.detach();
    leftWheel.detach();
  }
}

void Movement::turnLeft(const float ANGLE){
  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Turning left %f degrees. \n", ANGLE);
    leftWheel.attach(LEFT_MOTOR_PIN);
  }
  
  /* turing the robot */ { // TODO change to a while loop where we keep turning until the Compass.getHeading goes from x to x + ANGLE.
    const int CURRENT_HEADING = (0);
    const int NEW_HEADING = (CURRENT_HEADING + ANGLE);
    for (int posDegrees = CURRENT_HEADING; posDegrees <= NEW_HEADING; posDegrees++) {
      leftWheel.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped turning left. \n");
    leftWheel.detach();
  }
}

void Movement::turnRight(const float ANGLE){
  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Turning right %f degrees. \n", ANGLE);
    rightWheel.attach(RIGHT_MOTOR_PIN);
  }
  
  /* turing the robot */ { // TODO change to a while loop where we keep turning until the Compass.getHeading goes from x to x + ANGLE.
    const int CURRENT_HEADING = (0);
    const int NEW_HEADING = (CURRENT_HEADING + ANGLE);
    for (int posDegrees = CURRENT_HEADING; posDegrees <= NEW_HEADING; posDegrees++) {
      rightWheel.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped turning right. \n");
    rightWheel.detach();
  }
}

void Movement::stop(){
  /* Checking Pre-Conditions */ {
    if (this -> movementDirection == NOT_MOVING) {
      printf("[MovementModule.stop] ==> Error: Already not moving. \n");
      return;
    }
  }

  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopping the robot. \n");
    rightWheel.attach(RIGHT_MOTOR_PIN);
    leftWheel.attach(LEFT_MOTOR_PIN);
  }
  
  /* Stopping the wheels*/ {
    const int STOP = (0);
    rightWheel.write(STOP);
    leftWheel.write(STOP);
    this -> movementDirection = NOT_MOVING;
  }
  
  /* Detaching the wheels. */ {
    rightWheel.detach();
    leftWheel.detach();
    printf("[MovementModule.moveBackward] ==> Stopped. \n");
  }
}
