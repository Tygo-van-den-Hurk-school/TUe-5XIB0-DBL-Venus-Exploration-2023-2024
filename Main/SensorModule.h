#pragma once

// Libraries
#include <NewPing.h>
#include <Wire.h>
#include <QMC5883L.h>


class Sensors
{
    // Put in methods where the robot can read from here (e.g. ambient light)
    public:
        Sensors();
        ~Sensors();
        // Function prototypes
        bool detectRocks();
        bool detectBoundaries();
        bool detectCliffs();
        bool detectHills();
        float readCompass();
        bool ambientLight(); 
    private:
        // Constants
        const int infraredPin = A0;
        const int leftLightPin = A1;
        const int rightLightPin = A2;
        const int trigPin = 2;
        const int echoPin = 3;
        // Thresholds
        const int infraredThreshold = 500; // Adjust this value based on your environment
        const int lightThreshold = 800; // Adjust this value based on your environment
        static const int GPIOPinAmbient =4;
        // Sensor instances
        NewPing sonar(trigPin, echoPin);
        QMC5883L compass;
};
