#include "MovementModule.h"
#include <Arduino.h>
//#include <Serial.h>

Movement::Movement(){
  
  this->coordinates.x = 0.0;
  this->coordinates.y = 0.0;

  this->leftWheel.attach(LEFT_MOTOR_PIN);
  this->rightWheel.attach(RIGHT_MOTOR_PIN); 
}

Movement::~Movement(){
  this->leftWheel.detach();
  this->rightWheel.detach();
}

void Movement::moveForward(const int SPEED){

  /* validating the Pre-Conditions */ {
    const bool SPEED_IS_TOO_HIGH = (SPEED > 499);
    const bool SPEED_IS_TOO_LOW = (SPEED < 0);
    const bool INVALID_SPEED = (SPEED_IS_TOO_HIGH || SPEED_IS_TOO_LOW);
    if (INVALID_SPEED) {
      Serial.println("FIS");
      return;
    }

    const bool WAS_ALREADY_MOVING = (this->movementDirection == FORWARDS);
    if (WAS_ALREADY_MOVING) {
      Serial.println("FIM");
      return;
    }
  }

  /* Made the motors go forwards with the speed */ {
    Serial.println("Fm");
    for(int posDegrees = 0; posDegrees <= 300; posDegrees++) {
      leftWheel.write(posDegrees);
      delay(20);
    }
    this->movementDirection = FORWARDS;
  }
}

void Movement::moveBackward(const int SPEED){

  /* validating the Pre-Conditions */ {
    const bool SPEED_IS_TOO_HIGH = (SPEED > 499);
    const bool SPEED_IS_TOO_LOW = (SPEED < 0);
    const bool INVALID_SPEED = (SPEED_IS_TOO_HIGH || SPEED_IS_TOO_LOW);
    if (INVALID_SPEED) {
      Serial.println("BIS");
      return;
    }

    const bool WAS_ALREADY_MOVING = (this->movementDirection == BACKWARDS);
    if (WAS_ALREADY_MOVING) {
      Serial.println("BIM");
      return;
    }
  }

  /* Made the motors go backwards with the speed */ {
    Serial.println("Bm");
    this->leftWheel.writeMicroseconds(NEUTRAL - (BACKWARDS * SPEED));
    this->rightWheel.writeMicroseconds(NEUTRAL - (BACKWARDS * SPEED));
    this->movementDirection = BACKWARDS;
  }
}

void Movement::turn(const float ANGLE){

  /* validating the Pre-Conditions */ {
    const bool ANGLE_IS_TOO_HIGH = (ANGLE > 360);
    const bool ANGLE_IS_TOO_LOW = (ANGLE < 0);
    const bool INVALID_ANGLE = (ANGLE_IS_TOO_HIGH || ANGLE_IS_TOO_LOW);
    if (INVALID_ANGLE) {
      Serial.println("TIA");
      return;
    }
  }

  Serial.println("Tm");

}

void Movement::stop(){

  /* validating the Pre-Conditions */ {
    const bool WAS_NOT_EVEN_MOVING = (this->movementDirection == NOT_MOVING);
    if (WAS_NOT_EVEN_MOVING) {
      Serial.println("SIM");
      return;
    }
  }

  /* Stopping the wheels */ {
    Serial.println("Sm");
    this->leftWheel.writeMicroseconds(NEUTRAL);
    this->rightWheel.writeMicroseconds(NEUTRAL);
    this->movementDirection = NOT_MOVING;
  }
}