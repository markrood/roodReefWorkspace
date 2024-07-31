#ifndef WAPPSIGN_H_
#define WAPPSIGN_H_

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 5

 static Adafruit_NeoMatrix matrixx = Adafruit_NeoMatrix(54, 10, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);




const uint16_t colors[] = {
     matrixx.Color(249, 88, 8), matrixx.Color(249, 169, 8), matrixx.Color(249, 8, 8) }; 


class WappSign{
    public:
        WappSign();
        void display(String str, int length);

    private:
      int xxxx = 0;
        int piss = 0;
};

#endif