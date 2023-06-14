#pragma once
#include "esp_now.h"
#include "WiFi.h"
#include <cstring>
#define BOARD true


//Structure for sending messages --> MUST BE THE SAME FOR THE RECEIVER
typedef struct sendMessage{
  char status[32];
} sendMessage;

class Communication
{

    public:
        Communication();
        ~Communication();
        int send(sendMessage);
        void onReceive(const uint8_t * mac, const uint8_t * incomingData, int len);
        sendMessage myData;

    private:
        void receiverSetup();
        void senderSetup();
        void onDataSent(const uint8_t *, esp_now_send_status_t);
        esp_now_peer_info_t peerInfo;
        uint8_t board[8];
        int errorCode = 0;

};
