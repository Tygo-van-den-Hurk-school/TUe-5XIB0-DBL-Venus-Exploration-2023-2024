#include "MovementModule.h"
#include <Arduino.h>
#include <ESP32Servo.h>

Movement::Movement() {
  this -> coordinates.x = 0.0;
  this -> coordinates.y = 0.0;
}

Movement::~Movement(){
// If it does nothing, do not write it. It is just extra lines. 
// Plus I do not expect an arduino to destruct objects when shut
// down due to power loss. So is this even needed?
}

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Methods that move/rotate the robot ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 
void Movement::moveForward(const int DEGREES) {
  /* Attaching the wheels. */ {
    printf("[%f] : MovementModule.moveBackward() ==> Moving forwards. \n", System.milis()); // TODO replace with static function Comunications.println();
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
    printf("[%f] : MovementModule.moveBackward() ==> Stopped moving forward. \n", System.milis()); // TODO replace with static function Comunications.println();
    rightWheel.detach();
    leftWheel.detach();
  }
}

void Movement::moveBackward(const int DEGREES) {
  /* Attaching the wheels. */ {
    printf("[%f] : MovementModule.moveBackward() ==> Moving backwards. \n", System.milis()); // TODO replace with static function Comunications.println();
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
    printf("[%f] : MovementModule.moveBackward() ==> Stopped moving backward. \n", System.milis()); // TODO replace with static function Comunications.println();
    rightWheel.detach();
    leftWheel.detach();
  }
}

void Movement::turnLeft(const float ANGLE){
  /* Attaching the wheels. */ {
    printf("[%f] : MovementModule.turnLeft() ==> Turning left %f degrees. \n", System.milis(), ANGLE); // TODO replace with static function Comunications.println();
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
    printf("[%f] : MovementModule.turnLeft() ==> Stopped turning left. \n", System.milis()); // TODO replace with static function Comunications.println();
    leftWheel.detach();
  }
}

void Movement::turnRight(const float ANGLE){
  /* Attaching the wheels. */ {
    printf("[%f] : MovementModule.turnRight() ==> Turning right %f degrees. \n", System.milis(), ANGLE); // TODO replace with static function Comunications.println();
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
    printf("[%f] : MovementModule.turnRight() ==> Stopped turning right. \n", System.milis()); // TODO replace with static function Comunications.println();
    rightWheel.detach();
  }
}

void Movement::stop(){
  /* Attaching the wheels. */ {
    printf("[%f] : MovementModule.stop() ==> Stopping the robot. \n", System.milis()); // TODO replace with static function Comunications.println();
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
    printf("[%f] : MovementModule.stop() ==> Stopped. \n", System.milis()); // TODO replace with static function Comunications.println();
  }
}
