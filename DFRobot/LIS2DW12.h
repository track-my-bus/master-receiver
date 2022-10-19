
#if defined(ESP32) || defined(ESP8266)
    #define LIS2DW12_CS  D3
    #elif defined(__AVR__) || defined(ARDUINO_SAM_ZERO)
    #define LIS2DW12_CS 3
    #elif (defined NRF5)
    #define LIS2DW12_CS 2  //The pin on the development board with the corresponding silkscreen printed as P2
#endif

void init_accli(){
  while(!DFRobot.begin()){
     Serial.println("Communication failed, check the connection and I2C address setting when using I2C communication.");
  }
  Serial.print("chip id : ");
  Serial.println(DFRobot.getID(),HEX);
  DFRobot.softReset();
  DFRobot.continRefresh(true);
  DFRobot.setDataRate(DFRobot_LIS2DW12::eRate_50hz);
  DFRobot.setRange(DFRobot_LIS2DW12::e2_g);
  DFRobot.setFilterPath(DFRobot_LIS2DW12::eLPF);
  DFRobot.setFilterBandwidth(DFRobot_LIS2DW12::eRateDiv_4);
  DFRobot.setPowerMode(DFRobot_LIS2DW12::eContLowPwrLowNoise2_14bit);
}

void getAccliration(){
  accli = String(DFRobot.readAccX())+' '+String(DFRobot.readAccY())+' '+String(DFRobot.readAccZ());
}
