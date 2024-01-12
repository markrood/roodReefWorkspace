#ifndef ATO___h
#define ATO___h
#include <Arduino.h>
#include <WebSerial.h>
class Ato
{
  
  public: 
    Ato();
    bool doAto();
    void setI(int x);

  private:  
    int i = 0;
    bool ret = false;
    int SENSOR_NORMAL_INPUT = 36;
    int RO_PUMP = 18;
  
};
#endif