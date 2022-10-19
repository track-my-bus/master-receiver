void LoRa_init(int EN){
    pinMode(EN,OUTPUT);
    digitalWrite(EN,HIGH); 

    #ifndef DEBUG
        state = LoRa.begin();
        state = LoRa.setFrequency(UL);
        state = LoRa.setSpreadingFactor(SF);
        state = LoRa.setBandwidth(BW); 
    #endif

    #ifdef DEBUG
        Serial.println("Starting LoRa");
        state = LoRa.begin();
        debug();

        Serial.print("Setting Frequncy (hz) : ");
        Serial.println(UL);
        state = LoRa.setFrequency(UL);
        debug();

        Serial.print("Setting Spreading Factor : ");
        Serial.println(SF);
        state = LoRa.setSpreadingFactor(SF);
        debug();

        Serial.print("Setting Bandwidth (khz) : ");
        Serial.println(BW);
        state = LoRa.setBandwidth(BW);
        debug();
    #endif 
}

void LoRa_Rx(){

    state = LoRa.receive(str);
    if(state==0){
        Serial.println(str);
        Serial.print(" ");

        Serial.print(LoRa.getRSSI());
        Serial.print(" ");
        
        Serial.print(LoRa.getSNR());
        Serial.println("");
    }
    #ifdef DEBUG
        debug();
    #endif
}
