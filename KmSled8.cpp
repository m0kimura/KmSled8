//*******1*********2*********3*********4*********4*********5*********6*********7*********8
#include "Arduino.h"
#include "KmSled8.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif
KmSled8::KmSled8(int pin, int num){
  Pin=pin; Num=num;
  Pixels=Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);
}

void KmSled8::begin(){

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  Pixels.begin();

  int r, g, b; r=200; g=0; b=0;
  for(int i=0; i<Num; i++){
    KmSled8::bright(i, r, g, b); delay(300); KmSled8::bright(i, 0, 0, 0);
    if(r){g=200; r=0;}else if(g){b=200; g=0;}else{r=200; b=0;}
  }
  Serial.begin(9600);

}

void KmSled8::rgb(String txt){
  int i, j=0, k=0; char x; int c[3];
  c[0]=0; c[1]=0; c[2]=0;
    txt.concat(",");
  for(i=0; i<txt.length(); i++){
      x=txt.charAt(i);
    if(x==44){
      if(k<Num){
        Pixels.setPixelColor(k, Pixels.Color(c[0], c[1], c[2]));
        c[0]=0; c[1]=0; c[2]=0;
        k++; j=0;
      }
    }else{
      if(j<3){
        if(x>47&&x<58){c[j]=x-48;}
        else if(x>96&&x<103){c[j]=x-87;}
        c[j]=c[j]*16;
        j++;
      }
    }
  }
  Pixels.show();
}

void KmSled8::bright(int i, int r, int g, int b){
  Pixels.setPixelColor(i, Pixels.Color(r,g,b));
  Pixels.show();
}
