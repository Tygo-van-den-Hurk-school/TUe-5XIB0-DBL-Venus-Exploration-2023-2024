/**
 * @file This headerfile is for the Encoder object.
 *
 * @author Tygo van den Hurk, Student at TU/e: 1705709
 */
// Encoder.h
#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include <HardwareSerial.h>

/**
 * @class An object to contol Encoders.
 * @version 1.0
 */
class Encoder {
  private:
  public:
    /** Stores the pin for that the Encoder is connected to. */
  	/*const*/ byte pin;

    /**
     * @brief Constructs a new Encoder object .
     * 
     * @param pin_ is used to get a signal from that pin.
     * @since 1.0
     */
    Encoder(const byte pin_) {
      pin = pin_;
      pinMode(pin, INPUT);
      Serial.println("[BUILD] => Opened the Encoder for output.");
    };
};

#endif 
