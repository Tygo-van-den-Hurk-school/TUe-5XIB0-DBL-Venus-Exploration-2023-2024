#include "MovementModule.h"

Movement::Movement(){
  this->coordinates.x = 0.0;
  this->coordinates.y = 0.0;
  this->leftWheel.attach(LEFT_MOTOR_PIN);
  this->rightWheel.attach(RIGHT_MOTOR_PIN); 
}

void Movement::moveForward(const int SPEED){

  const bool SPEED_IS_TOO_HIGH = (SPEED > 499);
  const bool SPEED_IS_TOO_LOW = (SPEED < 0);
  const bool INVALID_SPEED = (SPEED_IS_TOO_HIGH || SPEED_IS_TOO_LOW);
  if (INVALID_SPEED) {
    return;
  }

  this->leftWheel.writeMicroseconds(NEUTRAL + (FORWARD * SPEED));
  this->rightWheel.writeMicroseconds(NEUTRAL - (FORWARD * SPEED));
}

void Movement::moveBackward(const int SPEED){

  const bool SPEED_IS_TOO_HIGH = (SPEED > 499);
  const bool SPEED_IS_TOO_LOW = (SPEED < 0);
  const bool INVALID_SPEED = (SPEED_IS_TOO_HIGH || SPEED_IS_TOO_LOW);
  if (INVALID_SPEED) {
    return;
  }

  this->leftWheel.writeMicroseconds(NEUTRAL + SPEED);
  this->rightWheel.writeMicroseconds(NEUTRAL - SPEED);
}

void Movement::turn(const float ANGLE){

  const bool ANGLE_IS_TOO_HIGH = (ANGLE > 360);
  const bool ANGLE_IS_TOO_LOW = (ANGLE < 0);
  const bool INVALID_ANGLE = (ANGLE_IS_TOO_HIGH || ANGLE_IS_TOO_LOW);
  if (INVALID_ANGLE) {
    return;
  }

}

void Movement::stop(){
  this->leftWheel.writeMicroseconds(NEUTRAL);
  this->rightWheel.writeMicroseconds(NEUTRAL);
}