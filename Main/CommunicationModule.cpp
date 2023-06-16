#include "CommunicationModule.h"

// ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~ Constructors, and Destructors ~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~ ~~~~

Communication::Communication(){
    
    WiFi.mode(WIFI_STA);
    
    // if(BOARD) {
    //   board = {0, 0, 0, 0, 0, 0, 0, 0};
    // } else {
    //   board = {0, 0, 0, 0, 0, 0, 0, 0};
    // }
    board = {0, 0, 0, 0, 0, 0, 0, 0}; // TODO remove unused if statement...

    /* Doing the setup */ {
    senderSetup();
    receiverSetup();
    }
}

Communication::~Communication(){
  // If it does nothing, do not write it. It is just extra lines. 
  // Plus I do not expect an arduino to destruct objects when shut
  // down due to power loss. So is this even needed?
}

void Communication::onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  printf("\r\nLast Packet Send Status:\t");
  
  const bool AN_ERROR_OCCURED = (status == ESP_NOW_SEND_SUCCESS);
  if (AN_ERROR_OCCURED) {
    printf("Delivery Fail\n");
    return;
  }
  
  else {
    printf("Delivery Success\n");
  }
}

void Communication::senderSetup(){
  /* initating EPS-Now protocol. */ {
    const bool AN_ERROR_OCCURED = (esp_now_init() != ESP_OK);
    if (AN_ERROR_OCCURED) { 
      printf("Error %d ,please see the error list\n", errorCode);
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
      printf("Error %d Failed to add peer\n", errorCode);
      return;
    }
  }
  
  errorCode++; // TODO Awnser question, if no error occured, why are we increasing the error code?
}

void Communication::receiverSetup(){
    const bool AN_ERROR_OCCURED = (esp_now_init() != ESP_OK);
    if (AN_ERROR_OCCURED) {
        printf("Error %d ,please see the rror list\n", errorCode);
        return;
    }
  
    printf("[CommunicationModule] ESPNow Init Success");
    errorCode++; // TODO Awnser question, if no error occured, why are we increasing the error code?
  
    /* register for recv CB to get recv packer info */ {
      esp_now_register_recv_cb(onReceive);
    }
}


int Communication::send(sendMessage myData){
  const int MESSAGE_SENT_SUCCESFULLY = (0);
  const int ERROR = (1);

  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  
  /* checking if it worked */ {
    const bool AN_ERROR_OCCURED = (result != ESP_OK);
    if (AN_ERROR_OCCURED) {
      printf("[CommunicationModule]: unable to send message, with error code Error %d. \n", errorCode);
      return ERROR;
    } 

    else {
      printf("[CommunicationModule]: Succes, message was send.\n");
      return MESSAGE_SENT_SUCCESFULLY;
    }
  }
}

void Communication::onReceive(const uint8_t * mac, const uint8_t * INCOMMING_DATA, int LENGTH) { // TODO awnser this question, why is the param "mac" here if it is not used?
    memcpy(&myData, INCOMMING_DATA, sizeof(myData));
    printf(myData.status);
}
