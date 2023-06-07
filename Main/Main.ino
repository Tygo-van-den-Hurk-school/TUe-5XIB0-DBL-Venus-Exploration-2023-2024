#include "ControlModule.h"
#include "MovementModule.h"

Movement movement;
/* Class definitions for the  */
void setup() {
  Serial.begin(9600);
  Serial.println("test");
  movement = Movement();
}

void loop() {
    movement.stop();
    delay(2000);
    movement.moveForward(499);
    delay(2000);
    movement.stop();
    
    
}