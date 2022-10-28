#ifndef HTTP_H
#define HTTP_H 
    const char *ssid = "GL7";  //ENTER YOUR WIFI SETTINGS
    const char *password = "";
    const char *host = "trackmybus-api.herokuapp.com";
    const int httpsPort = 443;  //HTTPS= 443 and HTTP = 80

    const char fingerprint[] PROGMEM = "D6 27 27 66 FB 8A 91 E6 31 3A B8 AF B1 79 4B 8F C7 A6 5A DC";
    #include "http.c"
#endif
