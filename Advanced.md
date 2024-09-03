# Further Learning

## Data Types

[Data Types](DataTypes.md)


## Ultrasonic Measurement- LED to indicate distance

<details><summary>LED to indicate distance</summary><p>

Within this task you will be required to use the LED to indicate the distance measured by the ultrasonic sensor. For this task you will ned to  make sure that you have installed the library. [UltraSonic Sensor](<0- Installing the library/HC-SR04.zip>)

```cpp
// Configure ultrasonic sensor
#include "SR04.h"
#define TRIG_PIN 13
#define ECHO_PIN 12
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
#include <FastLED.h>
#define NUM_LEDS 1    // Number of LEDs in strip (just 1)
#define DATA_PIN 4    // Pin for data communications

// Define variables
long distance;

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Configure the LED
   Serial.begin(9600);//Initialization of Serial Port
   delay(500);
}

void loop() {
   distance=sr04.Distance();  // Get and store the distance from the device driver
   Serial.print(distance);
   Serial.println("cm");//The difference between "Serial.print" and "Serial.println" 
                        //is that "Serial.println" can change lines.
  if(distance <= 20){
    leds[0] = CRGB::Red;
    }
    else if(distance <= 40){
    leds[0] = CRGB::Yellow;
    }
    else{
    leds[0] = CRGB::Green;
    }
  FastLED.show();
  
                        
   delay(250);
}
```

</details>

## Drive until object- turn when close to object

<details><summary>Turn when close to an object</summary>

```cpp
// Configure ultrasonic sensor
#include "SR04.h"
#define TRIG_PIN 13
#define ECHO_PIN 12 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);    // create an instance of the ultrasonic class

// define Motor IO pin
#define RPower  5    // Controls power to right motor
#define LPower  6    // Controls power to left motor
#define RDIR   7    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define LDIR   8    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY  3    // Place H-Bridge in standby if LOW, Run if HIGH

#define modeSwitch 2 // Mode Switch input

// Define variables
int speedLeft = 0;  // holds the speed of left wheels
int speedRight = 0; // holds the speed of right wheels
long distance;      // Holds distance from sensor

//init the car
void setup() {
  pinMode(RPower, OUTPUT);     //set IO pin mode OUTPUT
  pinMode(LPower, OUTPUT);
  pinMode(LDIR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(STBY, OUTPUT);
 
  analogWrite(RPower, 0);       // Fully off for Right
  analogWrite(LPower, 0);       // Fully off for Left
  digitalWrite(STBY, HIGH);   //Enable Motors to run

  waitForStart();             // wait until mode is pressed
  setSpeeds(100, 100);        // sets moderate speed
}

//main loop to drive forward until an object is detected
void loop() {
  setSpeeds(100,100);
  forward();                  // drive forward 
  distance=sr04.Distance();   // Get and store the distance from the device driver
  if (distance < 40) {        // if too close, stop, reverse and turn
    stop();     delay(500);
    setSpeeds(200,200);  
 //   left();  delay (1025);
    spinLeft(); delay(250);
  }
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
  digitalWrite(RDIR, LOW);
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

## Position servo- Use servo to make decision on which way to turn *task for obstacle avoidance*

<details><summary>Turn when close to an object</summary>

```cpp
// Ultrasonic configuration
#include "SR04.h"
#define TRIG_PIN 13
#define ECHO_PIN 12 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);    // create an instance of the ultrasonic class

// Servo configuration
#include <Servo.h>
#define servoPin 10
Servo servo1;                           // create an instance of the servo class

// define Motor IO pin
#define RPower  5    // Controls power to right motor
#define LPower  6    // Controls power to left motor
#define RDIR   7    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define LDIR   8    // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE
#define STBY  3    // Place H-Bridge in standby if LOW, Run if HIGH

// variables
int speedLeft = 0;  // holds the speed of left wheels
int speedRight = 0; // holds the speed of right wheels
int rightDistance = 0, leftDistance = 0, middleDistance = 0;  // holds distances when it 'looks around'

#define modeSwitch 2 // Mode Switch input

//initilize the car
void setup() {
  pinMode(RPower, OUTPUT);     //set IO pin mode OUTPUT
  pinMode(LPower, OUTPUT);
  pinMode(LDIR, OUTPUT);
  pinMode(RDIR, OUTPUT);
  pinMode(STBY, OUTPUT);
 
  analogWrite(RPower, 0);       // Fully off for Right
  analogWrite(LPower, 0);       // Fully off for Left
  digitalWrite(STBY, HIGH);  //Enable Motors to run

  servo1.attach(servoPin);    //connect pin 10 with the control line of the servo 
  servo1.write(90);           // move servos to center position -> 90°

  waitForStart();             // wait until mode is pressed
  setSpeeds(100, 100);        // sets speeds fairly high
}

//main loop to drive forward until an object is detected
void loop() {
    servo1.write(90);                   //Look forward
    middleDistance = sr04.Distance();   // Get and store the distance from the device driver

    if(middleDistance <= 30) {          // if nearby obstacle in front...
      stop();
      delay(250);
      servo1.write(10);                  // look right
      delay(1000);
      rightDistance = sr04.Distance();   // Get and store the distance from the device driver

      servo1.write(180);                // look left
      delay(1000);
      leftDistance = sr04.Distance();   // Get and store the distance from the device driver

      servo1.write(90);                 // look forward
      if((rightDistance <= 30) || (leftDistance <= 30)) {  // if both side too close
        reverse();
        delay(500);
        spinLeft();
        delay(180);
      }
      else if(rightDistance > leftDistance) {   // if right more open
        spinRight();
        delay(180);
      }
      else if(rightDistance < leftDistance) {  // if left more open
        spinLeft();
        delay(180);
      }
      else {
        forward();
      }
    }
    else {
        forward();
    }
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
  digitalWrite(RDIR, LOW);
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
