#ifndef AWC___h
#define AWC___h

#include <Arduino.h>
#include <WebSerial.h>
#include "text.h"

class Awc
{
  
  public:
    Awc();
    bool doAwc();
    void setI(int x);
    int getEmptyTime();
    int getFillTime();
    
  private:
    Text *text;    
    bool ret = false;
    bool emptied = false;
    bool emptyFirstTime = true;
    bool fillFirstTime = true;
    long awcFillTime = 0;
    long awcEmptyTime = 0;
    long awcTime = 0;
    long timeStamp = 0;
    const long MAX_AWC_EMPTY = 300000;
    const long MAX_AWC_FILL = 300000;
    const int SUMP_PUMP = 5;
    const int NEW_PUMP = 6;
    const int NORMAL_SENSOR = 46;
    const int LOW_SENSOR = 21;
    const int LOW_NEW_WATER = 20;
};
#endif