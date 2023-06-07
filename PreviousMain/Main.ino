/**
 * @file This is the main file where the code starts execution. This is where the robot will  
 * process the data from it's sensors, and steer itself away from craters and mountains to
 * find the rocks on the surface.
 *
 * @author Tygo van den Hurk, studen at TU/e: 1705709
 *
 * @version 1.0
 */
// ---- ---- ---- ---- ---- ---- ---- ----  communications  ---- ---- ---- ---- ---- ---- ---- ----
#include <XBee.h>

/** This pin is used for communications, receiving in this case. */
#define ZIGBEE_ROUTER_PIN_RX 0
/** This pin is used for communications, sending in this case. */
#define ZIGBEE_ROUTER_PIN_TX 1

// ---- ---- ---- ---- ---- ---- ---- ---- -- Encoder's --- ---- ---- ---- ---- ---- ---- ---- ----
#include "Encoder.h"
/** These keep track of how many rotations the left wheel makes. */
#define LEFT_ENCODER 7
/** These keep track of how many rotations the right wheel makes. */
#define RIGHT_ENCODER 8

// ---- ---- ---- ---- ---- ---- ---- ---- --- Sensor's --- ---- ---- ---- ---- ---- ---- ---- ----
#include "UltraSoundSensor.h"

/** This pin is the ultraSoundSensor*/
#define ULTRA_SOUND_SENSOR_PIN 9
/** Object to get the distance from the robot to something in frond of it. */
UltraSoundSensor soundSensor(ULTRA_SOUND_SENSOR_PIN);

// ---- ---- ---- ---- ---- ---- ---- ---- --- Servo's ---- ---- ---- ---- ---- ---- ---- ---- ----
#include "ServoMotor.h"

/** This pin is used for the GrabberServo, that is attached to the grabber */
#define GRABBER_SERVO_PIN 10
/** Object to control the grabber of the robot */
ServoMotor grabber(GRABBER_SERVO_PIN);

/** This pin is used for the UltraSoundServo, that is attached to the "face" */
#define ULTRA_SOUND_SERVO_PIN 11
/** Object to control rotation of the UltraSoundSensor */
ServoMotor sensorServo(ULTRA_SOUND_SERVO_PIN);

/** This pin is used for the LeftServo, that is attached to the left wheel */
#define LEFT_SERVO_PIN 12
/** Object to control left wheel of the robot */
ServoMotor leftWheel(LEFT_SERVO_PIN);

/** This pin is used for the LeftServo, that is attached to the right wheel */
#define RIGHT_SERVO_PIN 13
/** Object to control left wheel of the robot */
ServoMotor rightWheel(RIGHT_SERVO_PIN);

// ---- ---- ---- ---- ---- ---- ---- ---- Global Variables ---- ---- ---- ---- ---- ---- ---- ----

// These must be at least a short since a byte only goes until 128, while a short goes until 32768.
/** stores where the robot is on the map in respect to the lab. */
short xCoordinateRobot = 0;
/** stores where the robot is on the map in respect to the lab. */
short yCoordinateRobot = 0;

// ---- ---- ---- ---- ---- ---- ---- ---- --- Method's --- ---- ---- ---- ---- ---- ---- ---- ----
/**
 * @brief This is where the Code starts and where we initialise the Pins.
 */
void setup() {
  Serial.begin(9600);
  Serial.println("try setting up.");
}

/**
 * @brief This is where we loop until our objective is completed.
 */
void loop() {
  Serial.print("hello world!");
  delay(1000);
}
