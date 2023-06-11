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
  servoRight.attach(servoPinRight);
  servoLeft.attach(servoPinLeft);

  for(int posDegrees = 0; posDegrees <= degrees; posDegrees++) {
    servoLeft.write(posDegrees);
    servoRight.write(-posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped moving forward.");
  servoRight.detach();
  servoLeft.detach();
}

void Movement::moveBackward(const int degrees){
  printf("[LOG]: Moving backward.");
  servoRight.attach(servoPinRight);
  servoLeft.attach(servoPinLeft);

  for(int posDegrees = 0; posDegrees <= degrees; posDegrees++) {
    servoLeft.write(-posDegrees);
    servoRight.write(posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped moving backward.");
  servoRight.detach();
  servoLeft.detach();
}

void Movement::leftTurn(const float angle){
  printf("[LOG]: Turning left angle degrees : " + angle + ".");
  servoLeft.attach(servoPinLeft);
  for(int posDegrees = 0; posDegrees <= angle; posDegrees++) {
    servoLeft.write(posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped turning left.");
  servoLeft.detach();
}

void Movement::rightTurn(const float angle){
  printf("[LOG]: Turning right angle degrees : " + angle + ".");
  servoRight.attach(servoPinRight);
  for(int posDegrees = 0; posDegrees <= angle; posDegrees++) {
    servoRight.write(posDegrees);
    delay(20);
  }

  printf("[LOG]: Stopped turning right.");
  servoRight.detach();
}

void Movement::stop(){
  servoRight.attach(servoPinRight);
  servoLeft.attach(servoPinLeft);

  servoRight.write(0);
  servoLeft.write(0);

  servoRight.detach();
  servoLeft.detach();
}