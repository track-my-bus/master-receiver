#ifndef GLOBALS_H
#define GLOBALS_H
  
  int state;
  String str,accli,gps;
  // HTTPClient http;
  SX1262 LoRa = new Module(LORA_CS, LORA_DIO1, LORA_RST, LORA_BUSY);

#endif