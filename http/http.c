void http_init(){
    WiFi.begin(ssid,pass);   //WiFi connection
    while (WiFi.status() != WL_CONNECTED) {       //Wait for the WiFI connection completion
        delay(500);
        Serial.println("Waiting for connection");
    }
}

void http_post(String str){

    if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status

    HTTPClient http;    //Declare object of class HTTPClient

    http.begin(url);      //Specify request destination
    http.addHeader("Content-Type","text/plain");  //Specify content-type header
        
    int httpCode = http.POST("comp="+str);   //Send the request
    String payload = http.getString();                  //Get the response payload

    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload

    http.end();  //Close connection

    }else{
        Serial.println("Error in WiFi connection");   
    }

    delay(3000);
}