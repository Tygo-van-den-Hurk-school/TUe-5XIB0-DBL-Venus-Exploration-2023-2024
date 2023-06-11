#pragma once
class Sensors
{
    // Put in methods where the robot can read from here (e.g. ambient light)
    public:
        Sensors();
        ~Sensors();
        int ambientLight(); 
    private:
        static const int GPIOPinAmbient =4;
};