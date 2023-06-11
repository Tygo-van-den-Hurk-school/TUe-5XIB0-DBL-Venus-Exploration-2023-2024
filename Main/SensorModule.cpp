#include "SensorModule.h"

Sensors::Sensors(){
}

Sensors::~Sensors(){
}

int ambientLight(){
    int ambientLightValue = analogRead(GPIOPinAmbient);
    if(ambientLightValue < 50){
      return 1;
    }
    return 0;
}