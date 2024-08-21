# Solutions


## RGB LED Task

<details><summary>Colour Changing Task</summary>

```cpp
#include <FastLED.h>

#define NUM_LEDS 1    // Number of LEDs in strip (just 1)
#define DATA_PIN 4    // Pin for data communications
 
// Define the array of leds
CRGB leds[NUM_LEDS];

// Runs once to configure devices
void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Configure the LED
  //pinMode(NUM_LEDS, OUTPUT);   
} 

// loops forever
void loop() { 
  FastLED.setBrightness(100);       // Set the brightness, 0 to 255 - Warning: 255 can be VERY bright
  
  leds[0] = CRGB::Yellow;            // Set Color with name - Erase Azure and press CTRL-Space for choices
  // leds[0] = CRGB(128,0,0);       // OR, Set color with amount of Red, Green and Blue, 0 to 255 each
  FastLED.show();                   // Set the LED to show
  delay(500);
  leds[0] = CRGB::Orange;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Green;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);                       // Wait 1/2 second
  leds[0] = CRGB::Pink;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Purple;
  FastLED.show();
  delay(500);
  
  
} // repeat
```

</details>

## Switch Advanced Task 

<details><summary>Colour change with switch</summary>

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
</details>


## Driving Motors- Drive in a square

<details><summary>Driving in a square</summary>

```CPP
// define IO pin
#define RPower  5     // Controls power to right motor 
#define LPower  6     // Controls power to left motor 
#define RDIR   7     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define LDIR   8     // Controls direction of left motor, HIGH = FORWARD, LOW = REVERSE
#define STBY  3     // Place H-Bridge in standby if LOW, Run if HIGH 
#define modeSwitch 2 // Mode Switch input

//initialize the car
void setup() {
  pinMode(RPower, OUTPUT);     //set IO pin mode OUTPUT
  pinMode(LPower, OUTPUT);
  pinMode(LDIR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(RPower, LOW);   // Fully Off
  digitalWrite(STBY, HIGH);  //Enable Motors to run
}

//main loop
void loop() {
  while (digitalRead(modeSwitch) == 1)  // wait for mode switch to be pressed (go to 0)
    ;  // Do nothing

  // Drive car Forward for 1 second and stop for half a second
  digitalWrite(RDIR, HIGH);     // Forward direction on Right
  digitalWrite(LDIR, HIGH);     // Forward direction on Left
  digitalWrite(RPower, HIGH);   // Full power on Right
  digitalWrite(LPower, HIGH);   // Full power on Left
  delay(500);                   //delay 500mS
  stopTime(500);                // Stop for 1/2 second

  // Turn Right for 160ms and stop for 1/2 a second
  digitalWrite(RDIR, LOW);    // Forward direction
  digitalWrite(RPower, HIGH);   // Full power
  digitalWrite(LDIR, HIGH);
  digitalWrite(LPower, HIGH);
  delay(160);            
  stopTime(500);

  // Driving forwards
  digitalWrite(RDIR, HIGH);    // Forward direction on Right
  digitalWrite(LDIR, HIGH);    // Forward direction on Left
  digitalWrite(RPower, HIGH);   // Full power on Right
  digitalWrite(LPower, HIGH);   // Full power on Left
  delay(500);              
  stopTime(500);

  // Turn Right
  digitalWrite(RDIR, LOW);    // Forward direction
  digitalWrite(RPower, HIGH);   // Full power
  digitalWrite(LDIR, HIGH);
  digitalWrite(LPower, HIGH);
  delay(160);              
  stopTime(500);

  // Drive car Forward
  digitalWrite(RDIR, HIGH);    // Forward direction on Right
  digitalWrite(LDIR, HIGH);    // Forward direction on Left
  digitalWrite(RPower, HIGH);   // Full power on Right
  digitalWrite(LPower, HIGH);   // Full power on Left
  delay(500); 
  stopTime(500);
   
  // Turn Right
  digitalWrite(RDIR, LOW);    // Forward direction
  digitalWrite(RPower, HIGH);   // Full power
  digitalWrite(LDIR, HIGH);
  digitalWrite(LPower, HIGH);
  delay(160);           
  stopTime(500);

  // Drive car Forward
  digitalWrite(RDIR, HIGH);    // Forward direction on Right
  digitalWrite(LDIR, HIGH);    // Forward direction on Left
  digitalWrite(RPower, HIGH);   // Full power on Right
  digitalWrite(LPower, HIGH);   // Full power on Left
  delay(500); 
  stopTime(500);

  // Turn Right
  digitalWrite(RDIR, LOW);    // Forward direction
  digitalWrite(RPower, HIGH);   // Full power
  digitalWrite(LDIR, HIGH);
  digitalWrite(LPower, HIGH);
  delay(160);              
  stopTime(500);

  // Drive car Forward 
  digitalWrite(RDIR, HIGH);    // Forward direction on Right
  digitalWrite(LDIR, HIGH);    // Forward direction on Left
  digitalWrite(RPower, HIGH);   // Full power on Right
  digitalWrite(LPower, HIGH);   // Full power on Left
  delay(500); 
  stopTime(500);
  digitalWrite(STBY, LOW);
}


// Function - accepts the time in milli-Seconds to go into standby for
void stopTime(int mS){
  digitalWrite(STBY, LOW);   // Go into standby
  delay(mS);                //  Wait defined time
  digitalWrite(STBY, HIGH);  //  Come out of standby
}
```
</details>



## Motor speed control- Drive in circle


<details><summary>Driving in a circle</summary>

```CPP
// define IO pin
#define RPower  5    // Controls power to right motor
#define LPower  6    // Controls power to left motor
#define RDIR   7    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define LDIR   8    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY  3    // Place H-Bridge in standby if LOW, Run if HIGH

#define modeSwitch 2 // Mode Switch input
//init the car
void setup() {
  pinMode(RPower, OUTPUT);     //set IO pin mode OUTPUT
  pinMode(LPower, OUTPUT);
  pinMode(LDIR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(STBY, OUTPUT);

  
  analogWrite(RPower, 0);  // Fully off for Right
  analogWrite(LPower, 0);  // Fully off for Left
  digitalWrite(STBY, HIGH);  //Enable Motors to run
}

//main loop
void loop() {
  while (digitalRead(modeSwitch) == 1)  // wait for mode switch to be pressed (go to 0)(switch is not pressed, speed on| switch pressed, speed off/ circuit closed)
    ;  // Do nothing
  delay(2000);    // delay 2 seconds before starting

  digitalWrite(STBY, HIGH);    // Go into standby

  // RIGHT WHEELS 1/2 speed forward, LEFT wheels 1/4 speed forward
  // for 2 seconds
  digitalWrite(RDIR, HIGH);    // Right Forward direction
  digitalWrite(LDIR, HIGH);    // Left Forward direction
  analogWrite(RPower, 140);    
  delay(3800);  
  stopTime(500);  // stop for 1/2 second
  digitalWrite(STBY, LOW);    // Go into standby
}

// Function stopTime - accepts the time in milliSeconds to go into standby for, returns nothing
void stopTime(int mS){
  digitalWrite(STBY, LOW);    // Go into standby
  delay(mS);                  //  Wait defined time
  digitalWrite(STBY, HIGH);   //  Come out of standby
}
```
</details>


## Driving With Functions- turning anti/ clockwise in a square using functions



## IR Remote- Change LED Colour with buttons 1-9


