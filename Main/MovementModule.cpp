#include "MovementModule.h"
#include <Arduino.h>
#include <ESP32Servo.h>

Movement::Movement(){
  
  this->coordinates.x = 0.0;
  this->coordinates.y = 0.0;
}

Movement::~Movement(){
}

void Movement::moveForward(const int degrees){
  printf("[MovementModule]: Moving forward. \n");
  rightWheel.attach(LEFT_MOTOR_PIN);
  leftWheel.attach(RIGHT_MOTOR_PIN);

  for(int posDegrees = 0; posDegrees <= degrees; posDegrees++) {
    leftWheel.write(posDegrees);
    rightWheel.write(-posDegrees);
    delay(20);
  }

  printf("[MovementModule]: Stopped moving forward. \n");
  rightWheel.detach();
  leftWheel.detach();
}

void Movement::moveBackward(const int degrees){
  printf("[MovementModule]: Moving backward. \n");
  rightWheel.attach(RIGHT_MOTOR_PIN);
  leftWheel.attach(LEFT_MOTOR_PIN);

  for(int posDegrees = 0; posDegrees <= degrees; posDegrees++) {
    leftWheel.write(-posDegrees);
    rightWheel.write(posDegrees);
    delay(20);
  }

  printf("[MovementModule]: Stopped moving backward. \n");
  rightWheel.detach();
  leftWheel.detach();
}

void Movement::leftTurn(const float angle){
  printf("[MovementModule]: Turning left angle degrees : %f. \n", angle);
  leftWheel.attach(LEFT_MOTOR_PIN);
  for(int posDegrees = 0; posDegrees <= angle; posDegrees++) {
    leftWheel.write(posDegrees);
    delay(20);
  }

  printf("[MovementModule]: Stopped turning left. \n");
  leftWheel.detach();
}

void Movement::rightTurn(const float angle){
  printf("[MovementModule]: Turning right angle degrees : %f. \n", angle);
  rightWheel.attach(RIGHT_MOTOR_PIN);
  for(int posDegrees = 0; posDegrees <= angle; posDegrees++) {
    rightWheel.write(posDegrees);
    delay(20);
  }

  printf("[MovementModule]: Stopped turning right. \n");
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
