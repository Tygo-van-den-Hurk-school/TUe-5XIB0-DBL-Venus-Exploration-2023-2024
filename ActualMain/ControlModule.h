#pragma once
#include "MovementModule.h"
#include "SensorModule.h"
#include "CommunicationModule.h"

class Control {
    private:
        void grab()
        void drop()
        Movement movement;
        Sensors sensors;
        Communication communication;
           
    public:
        Control();
        void run();

};

