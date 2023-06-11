#pragma once
#include "WiFi.h"
#include "espnow.h"


//Structure for sending messages --> MUST BE THE SAME FOR THE RECEIVER
typedef struct sendMessage{
  char status[32];
} sendMessage;

class Communication
{

    public:
        Communication();
        ~Communication();
        void send();
        void onReceive();

    private:
        void receiverSetup();
        void senderSetup();
        void onDatasent(const uint8_t *, esp_now_send_status_t);
        esp_now_peer_info_t peerInfo;
        uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
        sendMessage myData;

};