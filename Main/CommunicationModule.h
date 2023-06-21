#pragma once

/**
 * @file this file defines the methods for the comunication class.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * @author Jerry Liang, student at TU/e (1522019)
 * @author Saviël van Wijngaarden, student at TU/e (1460811)
 */
// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Libraries ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

#include "esp_now.h"
#include "WiFi.h"
#include <cstring>

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Constants ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

/** TODO discribe what the use is for this. */
#define BOARD true

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Data-Structures ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

/**
 * Structure for sending messages 
 * TODO MUST BE THE SAME FOR THE RECEIVER
 */
typedef struct sendMessage {
  char status[32];
} sendMessage;

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Class ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

/**
 * @class A class that handles the communication between the robots.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * @author Jerry Liang, student at TU/e (1522019)
 * @author Saviël van Wijngaarden, student at TU/e (???????)
 * @version 1.0
 */
class Communication {
  // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~ Constructors, and Destructors ~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

  public:
    /**
     * Creates a new `Communication` Object.
     */
    Communication();

    /**
     * Deconstructs the `Communication` Object.
     */
    ~Communication();

    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~ Methods for sending and receiving data ~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

    /**
     * TODO Discribe what the function does.
     *
     * @param (sendMessage) VARIABLE_NAME Discribe it's use case.
     * @return Discribe what it returns, since it returns an int.
     */
    int send(sendMessage);
  
    /**
     * TODO Discribe what the function does.
     *
     * @param (uint8_t) MAC Discribe it's use case.
     * @param (uint8_t) INCOMMING_DATA Discribe it's use case.
     * @param (int) LENGTH Discribe it's use case.
     */
    void onReceive(const uint8_t * MAC, const uint8_t * INCOMMING_DATA, const int LENGTH);
    sendMessage myData;

    // TODO create this function
    /* *
     * Prints a message over serial to the host.
     *
     * @pre ``
     * @param (char[]) MESSAGE the message you want to sent over Serial
     * /
    void printSerial(const char[] MESSAGE, const unsigned int MESSAGE_LENGTH) {

      /* Printing the timeStamp * / {
        Serial.print("["+System.millis()+"] : ");
      }

      /* Printing the message * / {
        for (int index = 0; index < MESSAGE_LENGTH; index++) {
          Serial.print(MESSAGE[index]);
        }
      }
    }; */

  private:
    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~ Methods for setting up comunications ~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ 

    /**
     * TODO Discribe what the function does.
     */
    void receiverSetup();

    /**
     * TODO Discribe what the function does.
     */
    void senderSetup();

    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~  Methods with unknown use cases  ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ // TODO fill in what this section is about

    /**
     * this function will print if the packet was send succesfull or failed
     *
     * @param (uint8_t) VARIABLE_NAME Discribe it's use case.
     */
    void onDataSent(const uint8_t *, esp_now_send_status_t);

    // ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ Methods with unknown use cases ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ // TODO fill in what this section is about

    /** TODO Discribe it's use case. */
    esp_now_peer_info_t peerInfo;

    /** TODO Discribe it's use case. */
    uint8_t board[8];

    /** TODO Discribe it's use case. */
    int errorCode = 0; // TODO awnser quesion, why do we need this?
};
