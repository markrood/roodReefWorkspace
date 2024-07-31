#include "mach.h"

Mach::Mach(){
    ;
}

int Mach::getLowSensor(){
    ;
}

int Mach::getNormalSensor(){
    if(evap){
        evap = false;
        return 0;
    }else{
        return 1;
    }
}

void Mach::evapF(){
    
    if(evapFirstTime){
        current = millis();
        evapFirstTime = false;
    }
    long now = millis() - current;
    if(now > 60000){
        evap = true;
        evapFirstTime = true;
    }
}
void Mach::emptyF(){
    ;
}
void Mach::fillF(){
    ;
}