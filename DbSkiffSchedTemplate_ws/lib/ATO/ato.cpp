#include "ato.h"
#include "global.h"

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
        WebSerial.print("t ");
        i++;
        //Serial.print(i);
        ret = true;
    }else{
        i = 0;
        ret = false;
    }
    //Serial.print(ret);
    //if
    return ret;
}
