#ifndef AWC___h
#define AWC___h

#include <Arduino.h>
#include <WebSerial.h>

class Awc
{
  
  public:
    Awc();
    bool doAwc();
    void setI(int x);
    
  private:
    int i = 0;
    bool ret = false;
  
  
};
#endif