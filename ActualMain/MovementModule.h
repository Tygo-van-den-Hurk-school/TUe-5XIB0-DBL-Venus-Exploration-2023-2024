#include <Servo.h>

#define LEFT_MOTOR_PIN 12                           
#define RIGHT_MOTOR_PIN 13  

struct Coordinates
{
  float x,y;
};

class Movement
{
  private:
    Servo leftWheel;
    Servo rightWheel;
    Coordinates coordinates;
    bool isMoving;
    float angle;

  public:
    Movement();
    void moveForward(int);
    void moveBackward(int);
    void turn(float);
    void stop();
};


