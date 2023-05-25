#include "MovementModule.h"

Movement::Movement(){
    this->coordinates.x = 0.0;
    this->coordinates.y = 0.0;
    this->leftWheel.attach(LEFT_MOTOR_PIN);
    this->rightWheel.attach(RIGHT_MOTOR_PIN); 
}

void Movement::moveForward(int speed){
    leftWheel.writeMicroseconds(1500 + speed);
    rightWheel.writeMicroseconds(1500 - speed);
}

void Movement::moveBackward(int speed){
    leftWheel.writeMicroseconds(1500 + speed);
    rightWheel.writeMicroseconds(1500 - speed);
}

void Movement::turn(float angle){
}

void Movement::stop(){
    leftWheel.writeMicroseconds(1500);
    rightWheel.writeMicroseconds(1500);
}