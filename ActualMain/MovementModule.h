#pragma once
#include <Servo.h>
#include <vector>

// 11 is the head
#define LEFT_MOTOR_PIN    12
#define RIGHT_MOTOR_PIN   13

#define NEUTRAL           1500

#define FORWARDS          -1
#define NOT_MOVING         0
#define BACKWARDS          1

struct Coordinates {
  float x, y;
};

/**
 * @brief Template of how an action can be abstracted such that the bot can run back through its memory
 * If any action gets performed in this module it will get recorded via a struct looking like this,
 * @since 1.0
 */
struct MovementAction{
  Coordinates startingCoordinates;
  int startingAngle;
  Coordinates endingCoordinates;
  int endingAngle;
  int speed;
}; 

/**
 * @class this class is used to control the robot's movement.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * @version 1.0
 */
class Movement {

  private:
    /** Stores the current coordinates of the robot. */
    Coordinates coordinates;

    /** The servo to which it controles the left wheel. */
    Servo leftWheel;
    /** The servo to which it controles the right wheel. */
    Servo rightWheel;

    /** 
     * Keeps track of if the robot is in motion. is equal to FOWARD if going 
     * forward, is equal to BACKWARD if going backwards, and is equal to 
     * NOT_MOVING if not in motion.
     */
    short movementDirection = NOT_MOVING;

    /** Stores the angle with which the robot is moving. */
    float angle = 0;

  public:

    /**
     * @brief constructs a new Movement Object.
     * @since 1.0
     */
    Movement();

    /**
     * @brief Moves the robot forward indefinitely with a certain speed.
     * @pre SPEED < 499 && SPEED > 0 && this->movementDirection != FORWARD
     * @param (int) SPEED the speed that with which the robot should move.
     * @post this->movementDirection == FORWARD
     * @since 1.0
     */
    void moveForward(int);

    /**
     * @brief Moves the robot backwards indefinitely with a certain speed.
     * @pre SPEED < 499 && SPEED > 0 this->movementDirection != BACKWARDS
     * @param (int) SPEED the speed that with which the robot should move.
     * @post this->movementDirection == BACKWARDS
     * @since 1.0
     */
    void moveBackward(int);
  
    /**
     * @brief Turns the robot a certain amount of degrees to the left, or the right.
     * @pre ANGLE < 360 && ANGLE > 0
     * @post TODO fill this in
     * @since 1.0
     */
    void turn(float);
  
    /**
     * @brief Stops the robot from moving.
     * @pre this->movementDirection != NOT_MOVING
     * @post this->movementDirection == NOT_MOVING
     * @since 1.0
     */
    void stop();

    /**
     * @brief Records action history
     * @since 1.0
     */
    std::vector<MovementAction> movementHistory;
};


