#ifndef UTILITY_H_
#define UTILITY_H_

#include <Arduino.h>


class Utility{
    public:
        Utility(); 
        int getKey(String str);
        int alphabitPos(String str);
        String buildDisplayString(int key);
        long generateHash(String str);
   
};

#endif