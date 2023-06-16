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

Movement::~Movement(){
  // If it does nothing, do not write it. It is just extra lines. 
  // Plus I do not expect an arduino to destruct objects when shut
  // down due to power loss. So is this even needed?
}

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  Methods that move/rotate the  robot ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

void Movement::moveForward(const int DEGREES) {
  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Moving forwards. \n"); // TODO replace with static function Comunications.println();
    rightWheel.attach(RIGHT_MOTOR_PIN);
    leftWheel.attach(LEFT_MOTOR_PIN);
  }
  
  /* Moving the robot forwards */ { // TODO make it so that it continues to move forward, until one of the sensors reads something different, for a certain distance
    const int ZERO_DEGREES = (0);
    for (int posDegrees = ZERO_DEGREES; posDegrees <= DEGREES; posDegrees++) {
      LEFT_WHEEL.write(posDegrees);
      RIGHT_WHEEL.write(-posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped moving forward. \n", System.milis()); // TODO replace with static function Comunications.println();
    rightWheel.detach();
    leftWheel.detach();
  }
}

void Movement::moveBackward(const int DEGREES) {
  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Moving backwards. \n"); // TODO replace with static function Comunications.println();
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
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped moving backward.\n"); // TODO replace with static function Comunications.println();
    rightWheel.detach();
    leftWheel.detach();
  }
}

void Movement::turnLeft(const float ANGLE){
  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Turning left %f degrees. \n", ANGLE); // TODO replace with static function Comunications.println();
    leftWheel.attach(LEFT_MOTOR_PIN);
  }
  
  /* turing the robot */ {
    const int ZERO_DEGREES = (0);
    for (int posDegrees = ZERO_DEGREES; posDegrees <= ANGLE; posDegrees++) {
      leftWheel.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped turning left. \n"); // TODO replace with static function Comunications.println();
    leftWheel.detach();
  }
}

void Movement::turnRight(const float ANGLE){
  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Turning right %f degrees. \n", ANGLE); // TODO replace with static function Comunications.println();
    rightWheel.attach(RIGHT_MOTOR_PIN);
  }
  
  /* turing the robot */ {
    const int ZERO_DEGREES = (0);
    for(int posDegrees = ZERO_DEGREES; posDegrees <= ANGLE; posDegrees++) {
      rightWheel.write(posDegrees);
      delay(DEFAULT_DELAY_TIME);
    }
  }
  
  /* Detaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopped turning right. \n"); // TODO replace with static function Comunications.println();
    rightWheel.detach();
  }
}

void Movement::stop(){
  /* Attaching the wheels. */ {
    printf("[MovementModule.moveBackward] ==> Stopping the robot. \n"); // TODO replace with static function Comunications.println();
    rightWheel.attach(RIGHT_MOTOR_PIN);
    leftWheel.attach(LEFT_MOTOR_PIN);
  }
  
  /* Stopping the wheels*/ {
    const int STOP = (0);
    rightWheel.write(STOP);
    leftWheel.write(STOP);
  }
  
  /* Detaching the wheels. */ {
    rightWheel.detach();
    leftWheel.detach();
    printf("[MovementModule.moveBackward] ==> Stopped. \n"); // TODO replace with static function Comunications.println();
  }
}
