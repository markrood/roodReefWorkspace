#include "awc.h"

Awc::Awc(){
    //code here
}

void Awc::setI(int x){
    i = x;
}

bool Awc::doAwc(){
    if(i < 5){
        //Serial.print(i);
        Serial.println("in doAwc");
        WebSerial.print("c ");
        i++;
        ret = true;
    }else{
        ret = false;
        i = 0;
    }
    //Serial.print("********** ret in awc is ");
    //Serial.println(ret);
    return ret;
}