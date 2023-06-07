#include "ControlModule.h"
#include "stdio.h"
#include "time.h"

Control::Control()
{
    //this->communication = Communication()
    this->movement = Movement();
    //this->sensors = Sensors()    

    this->numberOfRocksLeft = INITIAL_NUMBER_OF_ROCKS;
}

void Control::run()
{
    
}

