//*******1*********2*********3*********4*********4*********5*********6*********7*********8
#ifndef KMSLED8_H
#define KMSLED8_H
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class KmSled8{
  public:
    KmSled8(int pin, int num);
    void begin();
    void rgb(String txt);
    Adafruit_NeoPixel Pixels;
    int Pin;
    int Num;

  private:
    void bright(int i, int r, int g, int b);
};

#endif
