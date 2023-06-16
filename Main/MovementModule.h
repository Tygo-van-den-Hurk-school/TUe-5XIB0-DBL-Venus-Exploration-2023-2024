#pragma once

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  ~~~~ ~~ Libraries ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

#include <ESP32Servo.h>
//#include <vector>

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  ~~~~ ~~ Constants ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

/** This is the GPIO pin that will be used for the left-servo. */
#define LEFT_MOTOR_PIN      12
/** This is the GPIO pin that will be used for the right-servo. */
#define RIGHT_MOTOR_PIN     13

/** this stores how many degrees ninety-degrees are. */
#define NINETY_DEGREES      90
/** this stores how many degrees 180-degrees are. */
#define ONE_EIGHTY_DEGREES  180

/** The enum for moving fowards. */
#define FORWARD             1
/** The enum for not moving. */
#define NOT_MOVING          0
/** The enum for moving backwards. */
#define BACKWARDS          -1

/** Defines the delay between a degree turned, or a degree moved forward. */
#define DEFAULT_DELAY_TIME  20

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Data-Structures ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

/**
 * A data structure to hold the coordinates.
 */
struct Coordinate {
  /** The X-coordinate. */
  float x;
  /** The Y-coordinate. */
  float y;
};

/**
 * Template of how an action can be abstracted such that the bot can run back through its memory
 * If any action gets performed in this module it will get recorded via a struct looking like this,
 */
struct MovementAction{
  /** The coordinate that the robot was at the start of the instruction. */
  Coordinate startingCoordinate;
  /** The angle that the robot had at the start of the instruction. */
  int startingAngle;
  /** The coordinate that the robot had at the end of the instruction. */
  Coordinate endingCoordinate;
  /** The angle that the robot had at the end of the instruction. */
  int endingAngle;
  /** The speed at which the robot moved during the instruction. */
  int speed;
}; 

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  ~~~~ ~~~~ Class ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

/**
 * @class this class is used to control the robot's movement.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * // TODO Other people, add your names, and student numbers in the same way, do not remove this comment until we hand this in
 * @version 1.0
 */
class Movement {
  private:
    /** Stores the current coordinates of the robot. */
    const Coordinate CURRENT_COORDINATES;

    /** The servo to which it controles the left wheel. */
    const Servo LEFT_WHEEL;
    /** The servo to which it controles the right wheel. */
    const Servo RIGHT_WHEEL;

    /** Stores the angle with which the robot is moving. */
    float currentAngle = 0;

  public:
    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~ Constructors, and Destructors ~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

    /**
     * constructs a new `Movement` Object.
     * @since 1.0
     */
    Movement();

    /**
     * destroys the `Movement` Instance.
     * @since 1.0
     */
    ~Movement();

  // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~ Methods that move/rotate the  robot ~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

    /**
     * Moves the robot forward indefinitely with a certain speed.
     *
     * @pre `SPEED < 499 && SPEED > 0 && this->movementDirection != FORWARD`
     * @param (int) SPEED the speed that with which the robot should move.
     * @post `this -> movementDirection == FORWARD`
     * @since 1.0
     */
    void moveForward(int);

    /**
     * Moves the robot backwards indefinitely with a certain speed.
     *
     * @pre `SPEED < 499 && SPEED > 0 this->movementDirection != BACKWARDS`
     * @param (int) SPEED the speed that with which the robot should move.
     * @post `this -> movementDirection == BACKWARDS`
     * @since 1.0
     */
    void moveBackward(int);
  
    /**
     * Turns the robot a certain amount of degrees to the left.
     *
     * @pre `ANGLE < 360 && ANGLE > 0`
     * @param (float) ANGLE the angle you wish to turn
     * @post `this -> angle == (\old(angle) + ANGLE)`
     * @since 1.0
     */
    void turnLeft(float);

    /**
     * Turns the robot a certain amount of degrees to the right.
     *
     * @pre `ANGLE < 360 && ANGLE > 0`
     * @param (float) ANGLE the angle you wish to turn
     * @post `this -> angle == (\old(angle) + ANGLE)`
     * @since 1.0
     */
    void turnRight(float);
  
    /**
     * Stops the robot from moving.
     *
     * @pre `this -> movementDirection != NOT_MOVING`
     * @post `this -> movementDirection == NOT_MOVING`
     * @since 1.0
     */
    void stop();

    /* *
     * Records action history should be implemented as linked list.
     *
     * @since 1.0
     * /
    std::vector<MovementAction> movementHistory;
    */
};
