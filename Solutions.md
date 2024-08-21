# Solutions





## RGB Advanced Task 

```cpp
#include <FastLED.h>
#define NUM_LEDS 1    // Number of LEDs in strip (just 1)
#define DATA_PIN 4    // Pin for data communications

// Define the array of leds
CRGB leds[NUM_LEDS];
#define modeSwitch 2     // Define pin of Mode Switch
bool modeSwitchState;   // Holds state of mode switch

// Setup runs once on reset or power-up
void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Configure the LED
  pinMode(NUM_LEDS, OUTPUT);
  pinMode(modeSwitch,INPUT);      // Ensure modeSwitch is an input (by deafult it should be)
  Serial.begin(9600);             // Begin serial communications at 9600 baud
}

// Loop runs forever
void loop() {
  modeSwitchState = digitalRead(modeSwitch);  // read mode switch and store in modeSwitch State
  Serial.print("Mode Switch Value = ");       // Display Text for Mode Switch
  Serial.print(modeSwitchState);              // Display value of modeSwitchState in Serial Monitor

  if (modeSwitchState)  // Test if state is true (1) - braces are NOT needed if just 1 line of code for the conditional
  {                       
    Serial.println(" -- Switch not pressed"); // show this if true
    leds[0] = CRGB::Purple;
    FastLED.show();                   // Set the LED to show
  }
  else 
  {                                        
    Serial.println(" -- Switch pressed"); // show this if false
    leds[0] = CRGB(0,255,255);       // OR, Set color with amount of Red, Green and Blue, 0 to 255 each
    FastLED.show();                   // Set the LED to show
    delay(500); 
  }
}
```


