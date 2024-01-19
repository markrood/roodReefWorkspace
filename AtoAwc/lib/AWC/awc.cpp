#include "awc.h"

Awc::Awc(){
    pinMode(LOW_SENSOR ,INPUT);
    pinMode(SUMP_PUMP, OUTPUT);
    pinMode(NEW_PUMP, OUTPUT);
    text = new Text();
}



bool Awc::doAwc(){
    //if low in water
    if(digitalRead(LOW_SENSOR) == 1 && !emptied){
        if(emptyFirstTime){ 
            timeStamp = millis();
            text->sendHttp("WaterChange");
            emptyFirstTime = false;
        }
        Serial.print("e_ ");
        WebSerial.print("e ");
        digitalWrite(SUMP_PUMP, 1);
        long current = millis() - timeStamp;
        if(current > MAX_AWC_EMPTY){
            //send http message
            int rst = text->sendHttp("WCEmptyTTL");
            digitalWrite(SUMP_PUMP, 0);
            emptyFirstTime = true;
            return false;
        }
        ret = true;
    }else{
        digitalWrite(SUMP_PUMP, 0);
         emptyFirstTime = true;
         awcEmptyTime = millis() - timeStamp;
        emptied = true;
    }
/////////////////////////////////////////////////////////////////////////////////////////
    if(emptied && digitalRead(NORMAL_SENSOR) == 1){
        if(fillFirstTime){ 
            timeStamp = millis();
            fillFirstTime = false;
        }
        digitalWrite(NEW_PUMP, 1);
        long current = millis() - timeStamp;
        if(current > MAX_AWC_FILL){
            //send http message
            int rst = text->sendHttp("WCFillTTL");
            digitalWrite(NEW_PUMP, 0);
            fillFirstTime = true;
            return false;
        }
        ret = true;
    }{
        digitalWrite(NEW_PUMP, 0);
         fillFirstTime = true;
         awcFillTime = millis() - timeStamp;
         ret = false;
    }
    return ret;
}

int Awc::getEmptyTime(){
    return awcEmptyTime;
}

int Awc::getFillTime(){
    return awcFillTime;
}