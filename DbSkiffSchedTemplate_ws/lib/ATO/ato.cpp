#include "ato.h"

Ato::Ato(){
    
}
/*
*   RO_PUMP
*   S(ENSOR_NORMAL_INPUT
*/

void Ato::setI(int x){
    i = x;
}

bool Ato::doAto(){
    if(i < 5){
        Serial.println("in doAto");
        WebSerial.println("t ");
        i++;
        //Serial.print(i);
        ret = true;
    }else{
        ret = false;
        i = 0;
    }
    //Serial.print(ret);
    return ret;
}