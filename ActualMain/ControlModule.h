#pragma once
#include "MovementModule.h"
#include "SensorModule.h"
#include "CommunicationModule.h"

#define INITIAL_NUMBER_OF_ROCKS 3

class Control {
    private:
        void grab()
        void drop()
        int numberOfRocksLeft;
        Movement movement;
        Sensors sensors;
        Communication communication;

    public:
        Control();
        void run();

};

