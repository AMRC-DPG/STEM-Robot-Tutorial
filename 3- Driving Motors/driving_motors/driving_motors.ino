/*  driving_motors
 *   Declan Clifford- Johnson, 2024
 *   Part Four of AMRC STEM Robot Tutorial
    Adapted from Martin Hebel, 2023- https://www.selmaware.com/

(RPower (Right power))
(LPower (Left power))
(RDIR (Right Direction))
(LDIR (Left Direction))
  
    Code to test the motors on the Elegoo Robot Car 4  

    Download, disconnect cable, place on floor with room to drive  
    (about 4 feet clearance in all directions)
    Press the mode button, wait 2 seconds for it to begin
*/

// define IO pin
#define RPower  5     // Controls power to right motor (RPower (Right power))PWMA
#define LPower  6     // Controls power to left motor (LPower (Left power))PWMB
#define RDIR   7     // Controls direction of right motor, HIGH = FORWARD, LOW = REVERSE (RDIR (Right Direction))AIN 
#define LDIR   8     // Controls direction of left motor, HIGH = FORWARD, LOW = REVERSE (LDIR (Left Direction))BIN
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

  delay(2000);

  // RIGHT WHEELS
  // Drive Right Wheels forward for 2 second  
  digitalWrite(RDIR, HIGH);    // Forward direction
  digitalWrite(RPower, HIGH);   // Full power
  delay(2000);                //delay 2000mS

  // Stop for 2 seconds
  stopTime(2000);

  // Drive Right Wheels Backwards for 2 second  
  digitalWrite(RDIR, LOW);    // Backwards direction
  digitalWrite(RPower, HIGH);  // Full power
  delay(2000);               //delay 2000mS

  // Stop for 2 seconds
  stopTime(2000);

  // Turn off Right Motor's Power
  digitalWrite(RPower, LOW);

  // DRIVE LEFT WHEELS
  // Drive LEFT Wheels forward for 2 second  
  digitalWrite(LDIR, HIGH);    // Forward direction
  digitalWrite(LPower, HIGH);   // Full power
  delay(2000);              //delay 2000mS

  // Stop for 2 seconds
  stopTime(2000);

  // Drive Left Wheels Backwards for 2 second  
  digitalWrite(LDIR, LOW);    // Forward direction
  digitalWrite(LPower, HIGH);  // Full power
  delay(2000);               //delay 2000mS

  // Stop for 2 seconds
  stopTime(2000);

  // Drive car Forward for 1 second
  digitalWrite(RDIR, HIGH);    // Forward direction on Right
  digitalWrite(LDIR, HIGH);    // Forward direction on Left
  digitalWrite(RPower, HIGH);   // Full power on Right
  digitalWrite(LPower, HIGH);   // Full power on Left
  delay(1000);              //delay 2000mS

  // stop for 2 seconds
  stopTime(2000);

  // Drive car Backwards for 1 second1
  digitalWrite(RDIR, LOW);    // Reverse direction on Right
  digitalWrite(LDIR, LOW);    // Reverse direction on Left
  delay(1000);

  // stop for 2 seconds
  stopTime(2000);
  
  // All motor power off
  digitalWrite(RPower, LOW);   // No power on Right
  digitalWrite(LPower, LOW);   // No power on Left
}

// Function - accepts the time in milli-Seconds to go into standby for
void stopTime(int mS){
  digitalWrite(STBY, LOW);   // Go into standby
  delay(mS);                //  Wait defined time
  digitalWrite(STBY, HIGH);  //  Come out of standby
}
