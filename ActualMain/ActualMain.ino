#include <Servo.h>
#include "MovementModule.h"

Movement movement = Movement();

/* Class definitions for the  */
void setup() {
  Serial.begin(9600);
  Serial.println("test");
  movement.stop();

}

void loop() {
  movement.moveForward(499);
  delay(2000);
  movement.stop();
  delay(2000);
  movement.moveBackward(499);
  delay(2000);
    movement.stop();
  delay(2000);
}