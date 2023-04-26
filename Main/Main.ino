// Printing statements
#define ARROW " ==> "
#define BUILD ("[BUILD]" + ARROW)
#define ERROR ("[ERROR]" + ARROW)
#define MESSAGE ("[ MSG ]" + ARROW)

// ---- ---- ---- ---- ---- ---- ---- ----  communications  ---- ---- ---- ---- ---- ---- ---- ----
/** This pin is used for communications */
#define ZIGBEE_ROUTER_PIN_RX 0  
/** This pin is used for communications */
#define ZIGBEE_ROUTER_PIN_TX 1  

// ---- ---- ---- ---- ---- ---- ---- ---- -- Encoder's --- ---- ---- ---- ---- ---- ---- ---- ----
/** I do not know what the encoder does */
#define LEFT_ENCODER 7
/** I do not know what the encoder does */
#define RIGHT_ENCODER 8

// ---- ---- ---- ---- ---- ---- ---- ---- --- Sensor's --- ---- ---- ---- ---- ---- ---- ---- ----
/** This pin is the ultraSoundSensor*/
#define ULTRA_SOUND_SENSOR_PIN 9

// ---- ---- ---- ---- ---- ---- ---- ---- --- Servo's ---- ---- ---- ---- ---- ---- ---- ---- ---- 
/** This pin is used for the GrabberServo, that is attached to the grabber */
#define GRABBER_SERVO_PIN 10 
/** This pin is used for the UltraSoundServo, that is attached to the "face" */
#define ULTRA_SOUND_SENSOR_PIN 11
/** This pin is used for the LeftServo, that is attached to the left wheel */
#define LEFT_SERVO_PIN 12
/** This pin is used for the LeftServo, that is attached to the right wheel */
#define RIGHT_SERVO_PIN 13

/** stores where the robot is on the map in respect to the lab. */
int xCoordinateRobot = 0; 
/** stores where the robot is on the map in respect to the lab. */
int yCoordinateRobot = 0;

// ---- ---- ---- ---- ---- ---- ---- ---- --- Method's --- ---- ---- ---- ---- ---- ---- ---- ----
/**
 * @brief This is where the Code starts and where we initialise the Pins.
 */
void setup() {
  Serial.begin(9600);
  Serial.println(BUILD + "try setting up.");
} 

/**
 * @brief This is where we loop until our objective is 
 */
void loop() {
  Serial.print(MESSAGE + "hello world!");
  sleep(100);
}
