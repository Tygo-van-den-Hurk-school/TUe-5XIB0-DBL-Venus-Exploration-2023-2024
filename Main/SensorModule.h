#pragma once

/**
 * @file this file defines the methods for the sensormodule class.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * @author Jerry Liang, student at TU/e (1522019)
 * @author Saviël van Wijngaarden, student at TU/e (1460811)
 */
// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Libraries ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

#include <NewPing.h>
#include <Wire.h>
#include <QMC5883LCompass.h>

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Constants ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

/** this is the threshold that the infrared sensor needs to pass for it to offically "detect" something. */
#define INFRA_RED_THRESHOLD             500
/** this is the threshold that the light sensor needs to pass for it to offically "detect" something. */
#define LIGHT_THRESHOLD                 800

/** This is the sampling rate of the compass. */
#define SAMPLING_RATE_COMPASS           50

/** The pin we will be using for the ambient light sensor. */
#define AMBIENT_LIGHT_SENSOR_GPIO_PIN   4
/** The pin we will be using for the infra-red sensor. */
#define INFRA_RED_SENSOR_GPIO_PIN       A0
/** The pin we will be using for the left light sensor. That is used to detect bouderies. */
#define LEFT_LIGHT_SENSOR_GPIO_PIN      A1
/** The pin we will be using for the right light sensor. That is used to detect bouderies. */
#define RIGHT_LIGHT_SENSOR_GPIO_PIN     A2
/** 
 * The pin we will be using for the sonar. setting this to high will trigger a sonar pulse that 
 * will then be eventually temperarily set the "ECHO_SONAR_GPIO_PIN" to high.
 */
#define TRIGGER_SONAR_GPIO_PIN          2
/** 
 * The pin we will be using for the sonar. will then be eventually temperarily set to high,
 * when the "TRIGGER_SONAR_GPIO_PIN" was set to high.
 */
#define ECHO_SONAR_GPIO_PIN             3

/** TODO Discribe what this does. */
#define QMC5883L_RANGE_8GA              20

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Class ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

// TODO anwser this question: Why is this class not static/singleton? its not modular anyways...
/**
 * @class A class that stores all the sensors, and is capable of returning their values.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * @author Jerry Liang, student at TU/e (1522019)
 * @author Saviël van Wijngaarden, student at TU/e (???????)
 * @version 1.0
 */
class Sensors { 
  public:
    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~ Constructors and Destructors ~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

    /**
     * Creates a new Sensors Object.
     * @since 1.0
     */
    Sensors();

    /**
     * Destructs the Sensors Object.
     * @since 1.0
     */
    ~Sensors();

    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  Sensor value returning methods  ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

    /**
     * A method to detect rocks.
     *
     * @return wether or not the robot detected a rock.
     * @since 1.0
     */
    bool rockDetected();

    /**
     * A method to detect boundries.
     *
     * @return wether or not the robot detected a boundry.
     * @since 1.0
     */
    bool boundaryDetected();

    /** 
     * A method to detect cliffs.
     *
     * @return wether or not the robot detected a cliff.
     * @since 1.0
     */
    bool cliffDetected();

    /** 
     * A method to detect hills.
     *
     * @return wether or not the robot detected a hill.
     * @since 1.0
     */
    bool hillDetected();

    /** 
     * A method to get the heading of the robot.
     *
     * @return the current azimuth rotation of the robot.
     * @since 1.0
     */
    float getCompassHeading();

    // TODO change the name of this function to better reflect its purpose, and TODO Write the Documentation of what this does.
    /**
     * What this function does goes here.
     *
     * @return what this function returns goes here.
     * @since 1.0
     */
    bool ambientLight();

  private:
    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Sensor instances ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

    /** This is the sonar sensor that is used to measure the distance of the robot to something. */
    const NewPing SONAR;
    /** This is the compass that is used to keep track of the direction the robot is facing. */
    const QMC5883LCompass COMPASS;
};
