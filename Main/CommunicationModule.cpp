#include "CommunicationModule.h"

Communication::Communication(){
    WiFi.mode(WIFI_STA);
    if(BOARD) {
      board = {0,0,0,0,0,0,0,0};
    } else {
      board = {0,0,0,0,0,0,0,0};
    }
    senderSetup();
    receiverSetup();
}

Communication::~Communication(){
}

void Communication::onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  // this function will print if the packet was send succesfull or failed
  // this is a callback  function
  printf("\r\nLast Packet Send Status:\t");
  printf(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success\n" : "Delivery Fail\n");
}

void Communication::senderSetup(){
  // initating EPS-Now protocol. If it does not work an error message will pop up
  if (esp_now_init() != ESP_OK) { 
    //ESP_OK is a macro in the esp now libary to check if anything in the libary works
    printf("Error %d ,please see the error list\n", errorCode);
    
    return;
  }
  // Calling back to the data sending function
  esp_now_register_send_cb(onDataSent);

  // Registering with a peer
  // ESP now is peer to peer, this system will be using one to many design
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  //Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK){ 
    printf("Error %d Failed to add peer\n", errorCode);
    return;
  }
  errorCode++;
}

void Communication::receiverSetup(){
    if (esp_now_init() != ESP_OK) { 
        //ESP_OK is a macro in the esp now libary to check if anything in the libary works
        printf("Error %d ,please see the rror list\n", errorCode);
        
        return;
    } else{
        printf("[CommunicationModule] ESPNow Init Success");
        errorCode++;
    }
    // Once ESPNow is successfully Init, we will register for recv CB to
    // get recv packer info
    esp_now_register_recv_cb(onReceive);
}


int Communication::send(sendMessage myData){
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
    // checking if it worked
        if (result == ESP_OK) {
          printf("[CommunicationModule]: Succes, message was send.\n");
          return 0;
          
        }
        else if (result != ESP_OK){
          printf("[CommunicationModule]: Error %d, unable to send message\n", errorCode);
          return 1;
        } 
}

void Communication::onReceive(const uint8_t * mac, const uint8_t * incomingData, int len) {
    memcpy(&myData, incomingData, sizeof(myData));
    printf(myData.status);
}
    
