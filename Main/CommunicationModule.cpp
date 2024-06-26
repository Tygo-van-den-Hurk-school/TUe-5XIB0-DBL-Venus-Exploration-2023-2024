/**
 * @file this file defines the methods for the communication header file.
 * @author Tygo van den Hurk, student at TU/e (1705709)
 * @author David Constantin, student at TU/e (1569139)
 * @author Jerry Liang, student at TU/e (1522019)
 * @author Saviël van Wijngaarden, student at TU/e (1460811)
 */
// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Libraries ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

#include "CommunicationModule.h"

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Constructors, and Destructors ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

Communication::Communication() {
  
  WiFi.mode(WIFI_STA);
  
  // if(BOARD) { // TODO remove unused if statement.
  //   board = {0, 0, 0, 0, 0, 0, 0, 0};
  // } else {
  //   board = {0, 0, 0, 0, 0, 0, 0, 0};
  // }
  board = {0, 0, 0, 0, 0, 0, 0, 0};

  /* Doing the setup */ {
    senderSetup();
    receiverSetup();
  }
}

Communication::~Communication() {
  // If it does nothing, do not write it. It is just extra lines. 
  // Plus I do not expect an arduino to destruct objects when shut
  // down due to power loss. So is this even needed?
}

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~ Methods for sending and receiving data ~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

void Communication::onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  printf("\r\n[Communication.onDataSent] ==> Last Packet Send Status:\t");
  
  const bool AN_ERROR_OCCURED = (status == ESP_NOW_SEND_SUCCESS);
  if (AN_ERROR_OCCURED) {
    printf("Delivery Fail\n");
    return;
  }
  
  else {
    printf("Delivery Success\n");
  }
}

void Communication::senderSetup() {
  /* initating EPS-Now protocol. */ {
    const bool AN_ERROR_OCCURED = (esp_now_init() != ESP_OK);
    if (AN_ERROR_OCCURED) { 
      printf("[Communication.onDataSent] ==> Error %d ,please see the error list\n", errorCode);
      return;
    }
  }

  /* Calling back to the data sending function */ {
    esp_now_register_send_cb(onDataSent);
  }

  /* Registering with a peer */ {
    const bool DO_NO_ENCRYPT = (false);
    const int CHANNLE = (0);
    const int VALUE = (6); // TODO Rename to better discribe it's purpose.
    
    memcpy(peerInfo.peer_addr, broadcastAddress, VALUE);    
    peerInfo.channel = CHANNLE;
    peerInfo.encrypt = DO_NO_ENCRYPT;
  }

  /* checking if adding peer was succesfull. */ {
    const bool AN_ERROR_OCCURED = (esp_now_add_peer(&peerInfo) != ESP_OK);
    if (AN_ERROR_OCCURED) { 
      printf("[Communication.onDataSent] ==> Error %d Failed to add peer\n", errorCode);
      return;
    }
  }
  
  errorCode++; // TODO Awnser question, if no error occured, why are we increasing the error code?
}

void Communication::receiverSetup() {
    const bool AN_ERROR_OCCURED = (esp_now_init() != ESP_OK);
    if (AN_ERROR_OCCURED) {
        printf("[Communication.onDataSent] ==> Error %d ,please see the rror list\n", errorCode);
        return;
    }
  
    printf("[Communication.onDataSent] ==> ESPNow Init Success");
    errorCode++; // TODO Awnser question, if no error occured, why are we increasing the error code?
  
    /* register for recv CB to get recv packer info */ {
      esp_now_register_recv_cb(onReceive);
    }
}


int Communication::send(sendMessage myData) {
  const int MESSAGE_SENT_SUCCESFULLY = (0);
  const int ERROR = (1);

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  
  /* checking if it worked */ {
    const bool AN_ERROR_OCCURED = (result != ESP_OK);
    if (AN_ERROR_OCCURED) {
      printf("[Communication.onDataSent] ==> unable to send message, with error code Error %d. \n", errorCode);
      return ERROR;
    } 

    else {
      printf("[Communication.onDataSent] ==> Succes, message was send.\n");
      return MESSAGE_SENT_SUCCESFULLY;
    }
  }
}

void Communication::onReceive(const uint8_t * mac, const uint8_t * INCOMMING_DATA, int LENGTH) { // TODO awnser this question, why is the param "mac" here if it is not used?
  memcpy(&myData, INCOMMING_DATA, sizeof(myData));
  printf("[Communication.onDataSent] ==> ");
  printf(myData.status);
  printf(".\n");
}
