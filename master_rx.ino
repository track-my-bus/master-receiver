#define DEBUG
#include "include.h"

void setup(){
  Serial.begin(115200);
  LoRa_init(LORA_RXEN);
  http_init();
}

void loop(){
  http_post("hi");
  LoRa_Rx();  
}