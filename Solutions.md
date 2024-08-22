# Solutions


## 1- RGB LED Task

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

## 2- Switch Advanced Task 

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


## 3- Driving Motors- Drive in a square

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



## 4- Motor speed control- Drive in circle


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


## 5- Driving With Functions- turning anti/ clockwise in a square using functions

<details><summary>Driving in a square (anti-/clockwise)</summary>

```cpp
// define IO pin
#define RPower  5    // Controls power to right motor
#define LPower  6    // Controls power to left motor
#define RDIR   7    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define LDIR   8    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY  3    // Place H-Bridge in standby if LOW, Run if HIGH

// define variables
int speedLeft = 0;  // holds the speed of left wheels
int speedRight = 0; // holds the speed of right wheels

#define modeSwitch 2 // Mode Switch input
//init the car
void setup() {
  pinMode(RPower, OUTPUT);     //set IO pin mode OUTPUT
  pinMode(LPower, OUTPUT);
  pinMode(LDIR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(STBY, OUTPUT);
  
  analogWrite(RPower, 0);      // Fully off for Right
  analogWrite(LPower, 0);      // Fully off for Left
  digitalWrite(STBY, HIGH);  //Enable Motors to run
}


//main loop to drive by calling functions for car functions
void loop() {
  waitForStart();             // Wait for mode button to be pressed
  setSpeeds(200,200);        // sets speeds fairly high
  forward();   delay(500);  // drive forward 0.5 seconds
  stop();      delay(200);  // stops for 0.2 seconds

  right();     delay(1025);   // turn right 1.025 seconds
  stop();      delay(200);

  forward();   delay(500);
  stop();      delay(200);

  right();     delay(1025);  
  stop();      delay(200);

  forward();   delay(500);
  stop();      delay(200);

  right();     delay(1025);   
  stop();      delay(200);

  forward();   delay(500);
  stop();      delay(200);

  delay(2000);

  left();     delay(1025);   // turn left 1.025 second
  stop();      delay(200);

  forward();   delay(500);
  stop();      delay(200);

  left();     delay(1025);   
  stop();      delay(200);

  forward();   delay(500);
  stop();      delay(200);

  left();     delay(1025);  
  stop();      delay(200);

  forward();   delay(500);
  stop();      delay(200);

  left();     delay(1025); 
  stop();      delay(200);

  forward();   delay(500);
  stop();      delay(200);

  stop(); 
}

void waitForStart(){
    while (digitalRead(modeSwitch) == 1)  // wait for mode switch to be pressed (go to 0)
    ;  // Do nothing
  delay(2000);    // delay 2 seconds before starting
}

void setSpeeds(int leftSpeed, int rightSpeed){    // stores speeds in variables to be used when driving
  speedLeft = leftSpeed;
  speedRight = rightSpeed;  
}

void forward(){             // drives both motors in forward direction at set speed
  digitalWrite(RDIR, HIGH);
  digitalWrite(LDIR, HIGH);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

void right(){               // turns right with 1/2 speed on right going forward
  digitalWrite(RDIR, HIGH);
  digitalWrite(RDIR, HIGH);
  analogWrite(RPower, speedRight / 2);
  analogWrite(LPower, speedLeft);    
}

void left(){                // turns left with 1/2 speed on left going forward
  digitalWrite(RDIR, HIGH);
  digitalWrite(LDIR, HIGH);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft / 2);
}
void reverse(){             // drives both motors in reverse direction at set speed
  digitalWrite(RDIR, LOW);
  digitalWrite(LDIR, LOW);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

void spinLeft(){            // spins left with right motor forward and left in reverse
  digitalWrite(RDIR, HIGH);
  digitalWrite(LDIR, LOW);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

void spinRight(){           // spins right with left motor going forward and right in reverse
  digitalWrite(RDIR, LOW);
  digitalWrite(LDIR, HIGH);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

void stop(){                // stops drive on both motors
  analogWrite(RPower, 0);
  analogWrite(LPower, 0); 
}

// Function stopTime - accepts the time in milliSeconds to go into standby for, returns nothing
void stopTime(int mS){
  digitalWrite(STBY, LOW);    // Go into standby
  delay(mS);                  //  Wait defined time
  digitalWrite(STBY, HIGH);   //  Come out of standby
}
```

</details>

## 10- IR Remote- Change LED Colour with buttons 1-9

<details><summary>Driving in a square (anti-/clockwise)</summary>

```cpp
#include "IRremote.h"
#include <FastLED.h>

// define IO pin
#define RPower  5    // Controls power to right motor
#define LPower  6    // Controls power to left motor
#define RDIR   7    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define LDIR   8    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY  3    // Place H-Bridge in standby if LOW, Run if HIGH
#define NUM_LEDS 1    // Number of LEDs in strip (just 1)
#define DATA_PIN 4    // Pin for data communications

IRrecv irrecv(9);             // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

// define variables
int speedLeft = 0;  // holds the speed of left wheels
int speedRight = 0; // holds the speed of right wheels
char lastKey = ' ';           // store last pressed for repeating key actions

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn();
  digitalWrite(STBY, HIGH);  //Enable Motors to run
  setSpeeds(200,200);        // set speeds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Configure the LED  
}

void loop()
{
  int tmpValue;
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    Serial.print(results.value, HEX); // Display key code
    Serial.print("   ");
    switch(results.value)
      {   // each code corresponds to a button on the remote.
      case 0xFF629D: 
        Serial.println("Forward"); 
        lastKey = 'f';    // store last button for repeat code when held
        forward();
        break;
      
      case 0xFF22DD: 
        Serial.println("LEFT");  
        lastKey = 'l';
        left();
        delay(500);
        forward();         
        break;

      case 0xFF02FD: 
        Serial.println("STOP");
        lastKey = 's';  
        stop();   
        break;

      case 0xFFC23D: 
        Serial.println("Right");
        lastKey = 'r';
        right(); 
        delay(500);
        forward();      
        break;

      case 0xFFA857: 
        Serial.println("BACK");
        reverse();
        lastKey = 'b';     
        break;
      
      case 0xFF6897: 
        Serial.println("1"); 
        leds[0] = CRGB::Blue; 
        FastLED.show();
        lastKey = '1';   
        break;

      case 0xFF9867: 
        Serial.println("2");
        leds[0] = CRGB::Green; 
        FastLED.show();
        lastKey = '2';    
        break;

      case 0xFFB04F: 
        Serial.println("3");
        leds[0] = CRGB::Yellow; 
        FastLED.show();
        lastKey = '3'; 
        break;

      case 0xFF30CF: 
        Serial.println("4");
        leds[0] = CRGB::Orange; 
        FastLED.show();
        lastKey = '4';    
        break;

      case 0xFF18E7: 
        Serial.println("5");
        leds[0] = CRGB::Pink; 
        FastLED.show();
        lastKey = '5';    
        break;

      case 0xFF7A85: 
        Serial.println("6");
        leds[0] = CRGB::Red; 
        FastLED.show();
        lastKey = '6';    
        break;

      case 0xFF10EF: 
        Serial.println("7");
        leds[0] = CRGB::Purple; 
        FastLED.show();
        lastKey = '7';    
        break;

      case 0xFF38C7: 
        Serial.println("8");
        leds[0] = CRGB::White; 
        FastLED.show();
        lastKey = '8';    
        break;

      case 0xFF5AA5: 
        Serial.println("9");
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
        lastKey = '9';    
        break;

      case 0xFF42BD: 
        Serial.println("*");
        lastKey = '*';    
        break;
      
      case 0xFF4AB5: 
        Serial.println("0");    
        lastKey = '0';
        break;
        
      case 0xFF52AD: 
        Serial.println("#");    
        lastKey = '#';
        break;

      case 0xFFFFFFFF: 
          Serial.print("Repeat: ");
          Serial.println(lastKey);
          if (lastKey == 'l'){    // repeat left turns if held
            left();
            delay(500);
            forward();
           }  
          break;

          if (lastKey == 'r'){    // repeat right turns if held
            right();
            delay(500);
            forward();
           }  
          break;

      default: 
        Serial.println("?");
        lastKey = ' ';
        break;
      }// End Case
  
  irrecv.resume(); // receive the next value
  }
}

void setSpeeds(int leftSpeed, int rightSpeed){    // stores speeds in variables to be used when driving
  speedLeft = leftSpeed;
  speedRight = rightSpeed;  
}

void forward(){             // drives both motors in forward direction at set speed
  digitalWrite(RDIR, HIGH);
  digitalWrite(LDIR, HIGH);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

void reverse(){             // drives both motors in reverse direction at set speed
  digitalWrite(RDIR, LOW);
  digitalWrite(LDIR, LOW);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

void stop(){                // stops drive on both motors
  analogWrite(RPower, 0);
  analogWrite(LPower, 0); 
}

void left(){                // turns left with 1/2 speed on left going forward
  digitalWrite(RDIR, HIGH);
  digitalWrite(LDIR, HIGH);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft / 2);
}

void right(){               // turns right with 1/2 speed on right going forward
  digitalWrite(RDIR, HIGH);
  digitalWrite(RDIR, HIGH);
  analogWrite(RPower, speedRight / 2);
  analogWrite(LPower, speedLeft);    
}

void spinLeft(){            // spins left with right motor forward and left in reverse
  digitalWrite(RDIR, HIGH);
  digitalWrite(LDIR, LOW);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

void spinRight(){           // spins right with left motor going forward and right in reverse
  digitalWrite(RDIR, LOW);
  digitalWrite(LDIR, HIGH);
  analogWrite(RPower, speedRight);
  analogWrite(LPower, speedLeft);
}

// Function stopTime - accepts the time in milliSeconds to go into standby for, returns nothing
void stopTime(int mS){
  digitalWrite(STBY, LOW);    // Go into standby
  delay(mS);                  //  Wait defined time
  digitalWrite(STBY, HIGH);   //  Come out of standby
}
```

</details>
