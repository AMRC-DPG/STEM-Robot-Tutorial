/*   Driving_with_Functions
 *    
 *   Declan Clifford- Johnson, 2024
 *   Part Four of AMRC STEM Robot Tutorial
    Adapted from Martin Hebel, 2023- https://www.selmaware.com/
    
    Demonstrates driving by calling functions to perform various car functions.
    Place on floor and press Mode switch to start
*/

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
  setSpeeds(200, 200);        // sets speeds fairly high
  forward();   delay(2000);   // drive forward 2 seconds
  reverse();   delay(2000);   // drive reverse 2 seconds
  setSpeeds(100,100);         // set speeds moderate
  forward();   delay(1000);   // drive forward 1 second
  left();      delay(1000);   // turn left 1 second
  right();     delay(1000);   // turn right 1 second
  stop();      delay(1000);   // stop for 1 second
  spinRight(); delay(2000);   // spin to right 3 second
  spinLeft();  delay(2000);   // spin to left 2 seconds
  stop();                     // stop both motors and repeat
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
