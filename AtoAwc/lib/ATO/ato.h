#ifndef ATO___h
#define ATO___h
#include <Arduino.h>
#include <WebSerial.h>
#include "text.h"


class Ato
{
  
  public: 
    Ato();
    bool doAto();
    void setI(int x);
    long getAtoRunTime();

  private:  
    Text *text;
    int i = 0;
    bool ret = false;
    bool firstTime = true;
    long timer = 0;
    long atoRunTime = 0;
  
};
#endif