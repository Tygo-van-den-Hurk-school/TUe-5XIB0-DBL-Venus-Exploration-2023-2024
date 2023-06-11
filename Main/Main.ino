#include "MovementModule.h"
#include "SensorModule.h"
#include "CommunicationModule.h"

#define HEAD_PIN 25
#define PIN_CLAWS 26

Movement movement;
Sensors sensors;
Communication communication;


// General behaviour (head & claws)
Servo servoHead;
Servo servoClaws;


void clawsTurn(){
  servoClaws.attach(servoPinClaws);
  for(int posDegrees = 0; posDegrees <= 90; posDegrees++) {
    servoClaws.write(posDegrees);
    delay(20);
  } for(int posDegrees = 90; posDegrees >= 20; posDegrees--) {
    servoClaws.write(posDegrees);
    delay(1);
  }
  servoClaws.detach();
}

void headTurn(){
  servoHead.attach(servoPinHead);
  // if something detected at x angle store that angle
  for(int posDegrees = 0; posDegrees <= 90; posDegrees++) {
    servoHead.write(posDegrees);
    delay(20);
  }
  printf("[LOG]: Head turned left\n");

  for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
    servoHead.write(posDegrees);
    delay(20);
  }
  printf("[LOG]: Head turned right\n");

  for(int posDegrees = 0; posDegrees <= 90; posDegrees++) {
    servoHead.write(posDegrees);
    delay(1);
  }
  servoHead.detach();
}


void setup() {
  Serial.begin(9600);

  movement = Movement();
  sensors = Sensors();
  communication = Communication();

}

void loop() {
    
}