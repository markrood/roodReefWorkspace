#ifndef MACH___h
#define MACH___h

#include <Arduino.h>


class Mach
{

    private:
        Mach();
        int getNormalSensor();
        int getLowSensor();
        void evapF();
        void emptyF();
        void fillF();

    public:
        int normalSensor = 0;
        int lowSensor = 0;
        bool emptied = false;
        bool evap = false;
        bool fill = false;
        long evapCounter = 0;
        long fillCounter = 0;
        long emptyCounter = 0;
        bool evapFirstTime = true;
        bool fillFirstTime = true;
        bool emptyFirstTime = true;
        long current = 0;

};
#endif