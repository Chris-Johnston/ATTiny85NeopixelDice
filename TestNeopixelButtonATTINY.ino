#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN_BUTTON 4
#define PIN_LIGHTS 3
#define LENGTH 7

#define BRIGHTNESS 10

#define POLLING_MS 10
#define PAUSE_MS 2500

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LENGTH, PIN_LIGHTS, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:

  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS);
//printer
  pinMode(PIN_BUTTON, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  do {
    delay(POLLING_MS);
  }while(!digitalRead(PIN_BUTTON));

  // roll between 0 and 5
  int roll = random(1, 7);

  switch(roll)
  {
    case 1:
    case 5:
      for(int i=0; i< LENGTH; i++)
      { 
        strip.setPixelColor(i, 255, 0, 0);
      }
      break;
    case 2:
    case 3:
    case 4:
    default:
    for(int i=0; i< LENGTH; i++)
      { 
        strip.setPixelColor(i, 0, 255, 0);
      }
    break;
  }

  strip.show();

  delay(PAUSE_MS);

  strip.clear();
  strip.show();
  
/*
  if(!digitalRead(PIN_BUTTON))
  {
    for(int i=0; i< LENGTH; i++)
    { 
      strip.setPixelColor(i, 255, 0, 0);
    }
  }
  else
  {
    for(int i=0; i< LENGTH; i++)
    { 
      strip.setPixelColor(i, 0, 255, 0);
    }
  }

  strip.show();*/

}
