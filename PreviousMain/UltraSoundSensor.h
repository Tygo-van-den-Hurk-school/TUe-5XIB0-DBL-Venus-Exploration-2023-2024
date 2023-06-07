/**
 * @file this headerFile is for the UltraSoundSensor.
 *
 * @author Tygo van den Hurk, Student at TU/e: 1705709
 */
// UltraSoundSensor.h
#ifndef ULTRA_SOUND_SENSOR_H
#define ULTRA_SOUND_SENSOR_H

#include <Arduino.h>
#include <HardwareSerial.h>

/**
 * @class An object to get the distance from the robot to any object.
 * @version 1.0
 */
class UltraSoundSensor {
  private:
  public:
    /** the pin the UltraSoundSensor will read from. */
    /*const*/ byte pin;

    /**
     * @brief Construct a new UltraSoundSensor object.
     * 
     * @pre The pin_ that is given exists on the ardiuno, and is digital/analog (TODO).
     * @param pin_ the pin the UltraSoundSensor will read from.
     * @post {@code pin == pin_}
     * @since 1.0
     */
    UltraSoundSensor(const byte pin_) {
      pin = pin_;
      pinMode(pin, INPUT);
      Serial.println("[BUILD] => Opened the UltraSoundSensor for output.");
    };

    /**
     * @brief Gets the current distance from the UltraSoundSensor to the closed object it sees.
     * 
     * @pre The pin that is given exists on the ardiuno, and is digital/analog (TODO).
     * @return the current distance from the UltraSoundSensor to the closed object it sees.
     * @since 1.0
     */
    int next() {
      Serial.println("[ MSG ] => UltraSoundSensor returned a value.");
      return 0;
    }
};

#endif
