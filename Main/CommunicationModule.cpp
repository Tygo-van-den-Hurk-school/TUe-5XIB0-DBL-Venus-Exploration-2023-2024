#include "CommunicationModule.h"


Communication::Communication(){
    Serial.begin(115200); // Always the first line in setup,e is used to setup communication
    WiFi.mode(WIFI_STA);
    senderSetup();
    receiverSetup();
}

Communication::~Communication(){
}

void onDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  // this function will print if the packet was send succesfull or failed
  // this is a callback  function
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void Communication::senderSetup(){
    // for comunication always use a baud rate of 115200

  // initating EPS-Now protocol. If it does not work an error message will pop up
  if (esp_now_init() != ESP_OK) { 
    //ESP_OK is a macro in the esp now libary to check if anything in the libary works
    Serial.printf("Error %d ,please see the error list\n", errorCode);
    
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
    Serial.printf("Error %d Failed to add peer\n", errorCode);
    return;
  }
  errorCode++;
    Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(buttonPin, INPUT_PULLDOWN);
}

void Communication::receiverSetup(){
    if (esp_now_init() != ESP_OK) { 
        //ESP_OK is a macro in the esp now libary to check if anything in the libary works
        printf("Error %d ,please see the rror list\n", errorCode);
        
        return;
    } else{
        Serial.println("[CommunicationModule] ESPNow Init Success");
        errorCode++;
    }
    // Once ESPNow is successfully Init, we will register for recv CB to
    // get recv packer info
    esp_now_register_recv_cb(OnDataRecv);
}


void Communication::send(sendMessage myData){
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
}
