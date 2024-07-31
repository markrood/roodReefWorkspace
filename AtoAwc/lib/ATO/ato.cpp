#include "ato.h"
#include "mach.h"



Ato::Ato(){
    pinMode(NORMAL_SENSOR ,INPUT);
    pinMode(RO_PUMP, OUTPUT);
    text = new Text();
    mach = new Mach();
}
/*
*   RO_PUMP
*   S(ENSOR_NORMAL_INPUT
*/

void Ato::setI(int x){
    i = x;
}

bool Ato::doAto(){
    mach->evapF();//
    //if(digitalRead(NORMAL_SENSOR) == 0 ){
        if(mach->getNormalSensor() == 0 ){//
        if(firstTime){
            timer = millis();
            text->sendHttp("Auto_Top_Off");
            firstTime = false;
        }
        Serial.print("ro_ ");
        WebSerial.print("ro ");
        digitalWrite(RO_PUMP, 1);
        long current = millis() - timer;
        if(current > MAX_ATO){
            //send http message
            int rst = text->sendHttp("ATO_TTL");
            digitalWrite(RO_PUMP, 0);
            firstTime = true;
            return false;
        }
        ret = true;
    }else{
        digitalWrite(RO_PUMP, 0);
        firstTime = true;
        atoRunTime = millis() - timer;
        ret = false;

    }
    //Serial.print(ret);
    //if
    return ret;
}

long Ato::getAtoRunTime(){
    return atoRunTime;
}