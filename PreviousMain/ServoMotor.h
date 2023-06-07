/**
 * @file This headerfile is for the ServoMotor object.
 *
 * @author Tygo van den Hurk, Student at TU/e: 1705709
 */
// ServoMotor.h
#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <HardwareSerial.h>

/**
 * @class An object to contol ServoMotors.
 * @version 1.0
 */
class ServoMotor {
  private:
  public:
    /** Stores the pin for that the ServoMotor is connected to. */
  	/*const*/ byte pin;

    /**
     * @brief Constructs a new ServoMotor object .
     * 
     * @param pin_ is used to output a signal to that pin.
     * @since 1.0
     */
    ServoMotor(const byte pin_) {
      pin = pin_;
      pinMode(pin, OUTPUT);
      Serial.println("[BUILD] => Opened the ServoMotor for input.");
    };

    /**
     * @brief does something to the ServoMotor object.
     * 
     * @param param is used to do something.
     * @since 1.0
     */
    void doSomething(short param) { /* ... */ };
};

#endif 
