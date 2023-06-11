#include "MovementModule.h"
#include "SensorModule.h"
#include "CommunicationModule.h"

Movement movement;
Sensors sensors;
Communication communication;

void setup() {
  Serial.begin(9600);

  movement = Movement();
  sensors = Sensors();
  communication = Communication();

}

void loop() {
    
}