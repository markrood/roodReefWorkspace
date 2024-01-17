#ifndef TEXT___h
#define TEXT___h

#include <Arduino.h>
#include <WebSerial.h>
#include <ArduinoJson.h>

class Text
{
  
  public: 
    Text();
    int sendHttp(String event);

  private:  
    WiFiClient client;
    String url = "";  //used in sendHttp
    const char* host = "maker.ifttt.com";  //used in sendHttp
    const int httpsPort = 80;  //used in sendHttp
    String iPAddress;
};
#endif