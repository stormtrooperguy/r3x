#include <FastLED.h>

#define LED_PIN     13
#define NUM_LEDS    9
#define LED_TYPE    WS2812
CRGB leds[NUM_LEDS];

void setup() {
  delay( 1000 ); // power-up safety delay
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  randomSeed(1138);

  // pin 13 is the neopixels. I should move it but the wiring is tight so HACK!
  for (int dio = 2; dio < 20; dio++) {
    if ( dio != 13) {
      pinMode(dio, OUTPUT);
    }
  }

  // turn the eyes on
  digitalWrite(19, HIGH);

}

/*
 * Color map for the neopixels
 * 
 * 
    leds[0] = CRGB::Blue;  // panel 1, bottom  
    leds[1] = CRGB::White;  // panel 1, bottom  
    leds[2] = CRGB::Blue;  // panel 1, bottom  
    leds[3] = CRGB::White;  // panel 1, bottom  
    leds[4] = CRGB::Blue;  // panel 1, bottom  
    leds[5] = CRGB::White;  // panel 1, bottom  
    leds[6] = CRGB::White;  // panel 1, bottom  
    leds[7] = CRGB::Blue;  // panel 1, bottom  
    leds[8] = CRGB::Blue;  // panel 1, bottom  
*/

void loop()
{

  // I'm not trying to match park blinks. I'm just going to randomly
  // turn stuff off and on
  int randnum = random(1, 100);

  // Set all the neopixels off
  for (int lednum = 0; lednum < 9; lednum++) {
     leds[lednum] = CRGB::Black;
  }

  // Activate all the LED pins (other than 13 of course!)
  for (int dio = 2; dio < 19; dio++) {
    if ( dio != 13) {
      digitalWrite(dio, LOW);
    }
  }

  FastLED.show();

  if (randnum > 25) {
    leds[0] = CRGB::Blue;  // panel 1, bottom  
  }

  if ( randnum > 31) {
     digitalWrite(2, HIGH);
     digitalWrite(3, HIGH);
     digitalWrite(4, HIGH);

  }

  if (randnum < 66) {
    leds[1] = CRGB::White; // panel 1, top left

     digitalWrite(5, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(7, HIGH);
     digitalWrite(8, HIGH);
  
  }

  if (randnum > 75) {
    leds[2] = CRGB::Blue;  // panel 1, top right
     digitalWrite(9, HIGH);
     digitalWrite(10, HIGH);
     digitalWrite(11, HIGH);
     digitalWrite(12, HIGH);
   
  }

  if (randnum < 75) {
    leds[3] = CRGB::White; // panel 2, bottom left
     digitalWrite(14, HIGH);
  
  }

  if (randnum > 60) { 
    leds[4] = CRGB::Blue;  // panel 1,  bottom right
     digitalWrite(15, HIGH);
     digitalWrite(16, HIGH);
    
  }

  if (randnum < 50) {
    leds[5] = CRGB::White; // panel 1, top right

     digitalWrite(17, HIGH);
     digitalWrite(7, HIGH);
   
  }

  if (randnum > 21) {
    leds[6] = CRGB::White; // panel 1, bottom left
     digitalWrite(18, HIGH);
     digitalWrite(8, HIGH);

  }

  if (randnum > 70) {
    leds[7] = CRGB::Blue;  // panel 1, top left
  }

  if (randnum > 28) {
    leds[8] = CRGB::Blue;  // panel 1, top right    
    digitalWrite(11, HIGH);

  }

  if (randnum == 99) {
    leds[0] = CRGB::Blue;  // panel 1, bottom  
    leds[1] = CRGB::White;  // panel 1, bottom  
    leds[2] = CRGB::Blue;  // panel 1, bottom  
    leds[3] = CRGB::White;  // panel 1, bottom  
    leds[4] = CRGB::Blue;  // panel 1, bottom  
    leds[5] = CRGB::White;  // panel 1, bottom  
    leds[6] = CRGB::White;  // panel 1, bottom  
    leds[7] = CRGB::Blue;  // panel 1, bottom  
    leds[8] = CRGB::Blue;  // panel 1, bottom  
  }

  if (randnum == 7) {
    leds[0] = CRGB::Blue;  // panel 1, bottom  
    leds[1] = CRGB::White;  // panel 1, bottom  
    leds[2] = CRGB::Blue;  // panel 1, bottom  
  }

  if (randnum == 74) {

    leds[3] = CRGB::White;  // panel 1, bottom  
    leds[4] = CRGB::Blue;  // panel 1, bottom  
    leds[5] = CRGB::White;  // panel 1, bottom  

  }

  if (randnum == 99) {

    leds[6] = CRGB::White;  // panel 1, bottom  
    leds[7] = CRGB::Blue;  // panel 1, bottom  
    leds[8] = CRGB::Blue;  // panel 1, bottom  
  }

  FastLED.show();
  delay(1000);
}
