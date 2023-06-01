#include <Servo.h>

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

    /** Stores the angle with which the robot is moving */
    float angle = 0;

  public:

    /**
     * @brief constructs a new Movement Object.
     * @since 1.0
     */
    Movement();

    /**
     * @brief Moves the robot forward indefinitely with a certain speed.
     * @pre SPEED < 499 && SPEED > 0
     * @param (int) SPEED the speed that with which the robot should move.
     * @post this->movementDirection == FORWARD
     * @since 1.0
     */
    void moveForward(int);

    /**
     * @brief Moves the robot backwards indefinitely with a certain speed.
     * @pre SPEED < 499 && SPEED > 0
     * @param (int) SPEED the speed that with which the robot should move.
     * @post this->movementDirection == BACKWARDS
     * @since 1.0
     */
    void moveBackward(int);

    void turn(float);
    void stop();
};


