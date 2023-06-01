#include <Servo.h>
#include "MovementModule.h"

Movement movement = Movement();

/* Class definitions for the  */
void setup() {
  movement.stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  movement.moveBackward(512);
}