#pragma once

// Libraries
#include <NewPing.h>
#include <Wire.h>
#include <QMC5883LCompass.h>

// TODO anwser this question: Why is this class not static/singleton? its not modular anyways...

/**
 * @class A class that stores all the sensors, and is capable of returning their values.
 */
class Sensors {
    public:
        // Constructors, and Destructors        
        /**
         * @brief Creates a new Sensors Object.
         */
        Sensors();
        ~Sensors();
    
        // Sensor value returning methods
        /**
         * // TODO Write the Documentation of what this does
         * @brief What this function does goes here.
         * @return what this function returns goes here.
         */
        bool ambientLight(); // TODO change the name of this function to better reflect its purpose
    
        /**
         * @brief A method to detect rocks.
         * @return wether or not the robot detected a rock.
         */
        bool rockDetected();

        /**
         * @brief A method to detect boundries.
         * @return wether or not the robot detected a boundry.
         */
        bool boundaryDetected();
    
        /** 
         * @brief A method to detect cliffs.
         * @return wether or not the robot detected a cliff.
         */
        bool cliffDetected();
    
        /** 
         * @brief A method to detect hills.
         * @return wether or not the robot detected a hill.
         */
        bool hillDetected();
    
        /** 
         * @brief A method to get the heading of the robot.
         * @return the current azimuth rotation of the robot.
         */
        float getCompassHeading();
    
    private:
        // Constants
        /** Write the Documentation of what this is used for */
        const int infraredPin = A0;
        /** Write the Documentation of what this is used for */
        const int leftLightPin = A1;
        /** Write the Documentation of what this is used for */
        const int rightLightPin = A2;
        /** Write the Documentation of what this is used for */
        const int trigPin = 2;
        /** Write the Documentation of what this is used for */
        const int echoPin = 3;
    
        // Thresholds
        /** Write the Documentation of what this is used for */
        const int infraredThreshold = 500; // Adjust this value based on your environment TODO, make a function that does this, because this is bandate
        /** Write the Documentation of what this is used for */
        const int lightThreshold = 800; // Adjust this value based on your environment TODO, make a function that does this, because this is bandate
        /** Write the Documentation of what this is used for */
        static const int GPIOPinAmbient = 4;
    
        // Sensor instances
        NewPing sonar;
        QMC5883LCompass compass;
};
