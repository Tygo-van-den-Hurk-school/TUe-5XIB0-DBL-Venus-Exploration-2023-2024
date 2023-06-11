#include "MovementModule.h"
#include <Arduino.h>
#include <Servo.h>

Movement::Movement(){
  
  this->coordinates.x = 0.0;
  this->coordinates.y = 0.0;
}

Movement::~Movement(){
}

void Movement::moveForward(const int degrees){
  printf("[LOG]: Moving forward.");
  rightWheel.attach(LEFT_MOTOR_PIN);
  leftWheel.attach(RIGHT_MOTOR_PIN);

  for(int posDegrees = 0; posDegrees <= degrees; posDegrees++) {
    leftWheel.write(posDegrees);
    rightWheel.write(-posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped moving forward.");
  rightWheel.detach();
  leftWheel.detach();
}

void Movement::moveBackward(const int degrees){
  printf("[LOG]: Moving backward.");
  rightWheel.attach(RIGHT_MOTOR_PIN);
  leftWheel.attach(LEFT_MOTOR_PIN);

  for(int posDegrees = 0; posDegrees <= degrees; posDegrees++) {
    leftWheel.write(-posDegrees);
    rightWheel.write(posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped moving backward.");
  rightWheel.detach();
  leftWheel.detach();
}

void Movement::leftTurn(const float angle){
  printf("[LOG]: Turning left angle degrees : %f.", angle);
  leftWheel.attach(LEFT_MOTOR_PIN);
  for(int posDegrees = 0; posDegrees <= angle; posDegrees++) {
    leftWheel.write(posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped turning left.");
  leftWheel.detach();
}

void Movement::rightTurn(const float angle){
  printf("[LOG]: Turning right angle degrees : %f.", angle);
  rightWheel.attach(RIGHT_MOTOR_PIN);
  for(int posDegrees = 0; posDegrees <= angle; posDegrees++) {
    rightWheel.write(posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped turning right.");
  rightWheel.detach();
}

void Movement::stop(){
  rightWheel.attach(RIGHT_MOTOR_PIN);
  leftWheel.attach(LEFT_MOTOR_PIN);

  rightWheel.write(0);
  leftWheel.write(0);

  rightWheel.detach();
  leftWheel.detach();
}