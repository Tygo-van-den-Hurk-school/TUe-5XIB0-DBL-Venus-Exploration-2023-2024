#include "ControlModule.h"

Control::Control()
{
    this->communication = Communication()
    this->movement = Movement()
    this->sensors = Sensors()    
}

void Control::run()
{
    movement.stop();
    delay(2000);
    movement.moveForward(499);
    delay(2000);
    movement.stop();
    delay(2000);
    movement.moveBackward(499);
    delay(2000);
    movement.stop();
    delay(2000);
}

