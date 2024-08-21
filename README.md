# STEM-Robot-Tutorial

![Picture of Elegoo car](<z Tutorial Image/Elegoo robot.png>)

- [STEM-Robot-Tutorial](#stem-robot-tutorial)
  - [Introduction](#introduction)
  - [What software will be used?](#what-software-will-be-used)
  - [How to set up the robot with the software?](#how-to-set-up-the-robot-with-the-software)
  - [What are libraries?](#what-are-libraries)
  - [Data Types](#data-types)
  - [1 Controlling the LED](#1-controlling-the-led)
    - [Core concept](#core-concept)
    - [Breaking down the code](#breaking-down-the-code)
    - [What is a variable?](#what-is-a-variable)
    - [What is an include directive?](#what-is-an-include-directive)
    - [What is a define directive?](#what-is-a-define-directive)
    - [What is an array?](#what-is-an-array)
    - [What is a void?](#what-is-a-void)
    - [What is a loop?](#what-is-a-loop)
    - [What does Void setup mean?](#what-does-void-setup-mean)
    - [Task](#task)
  - [2 Reading mode switch](#2-reading-mode-switch)
    - [What is a bool(ean)?](#what-is-a-boolean)
    - [What is an if statement?](#what-is-an-if-statement)
    - [What is a print?](#what-is-a-print)
    - [What is a serial monitor?](#what-is-a-serial-monitor)
    - [Task](#task-1)
    - [Task 2- Advanced](#task-2--advanced)
  - [3 Driving Motors](#3-driving-motors)
    - [What is a delay?](#what-is-a-delay)
    - [What is digital write?](#what-is-digital-write)
    - [Task- Drive in square](#task--drive-in-square)
  - [4 Motor Speed Control](#4-motor-speed-control)
    - [What is analog write?](#what-is-analog-write)
    - [What is a while loop?](#what-is-a-while-loop)
    - [What is a for loop?](#what-is-a-for-loop)
    - [Task](#task-2)
  - [5 Driving with Functions](#5-driving-with-functions)
    - [What is a function?](#what-is-a-function)
  - [6 IR Receiver](#6-ir-receiver)
    - [What is a switch…case?](#what-is-a-switchcase)

<details open><summary>Introduction</summary>

## Introduction

Welcome to the Arduino Robot Car Tutorial. This code has been adapted from Martin Hebels 2023 https://www.selmaware.com/. This document is an explanation into the code which is used to operate the Arduino Robot. This document contains explanations of what parts of the code mean and why we use them, with the help of images.

In this tutorial, you will learn the adapted coding language from C, called C++. you will also learn multiple common features that are shared between other coding languages.

</details>



<details open><summary>Software to be used</summary>

## What software will be used?
Within this tutorial, you are going to be using a software called ‘Arduino’. This software is going to act as a compiler for your code and allow you to verify/ upload and run code into the robot. The software for the Arduino should already be installed, but just in case, the links are included below.

![alt text](<z Tutorial Image/Arduino Logo.png>)

Below will include the necessary links in order to download this software.

- Windows: [Arduino software](https://downloads.arduino.cc/arduino-1.8.18-windows.exe?_gl=1*cbkesg*_gcl_au*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*FPAU*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*_ga*MTA0NzU2ODUyNC4xNzIzNTQyOTA5*_ga_NEXN8H46L5*MTcyMzU1MTE0MC4yLjEuMTcyMzU1MTE0NS4wLjAuMTcxNjQ1MTUwMw..*_fplc*bWd6c2VxN3l0THgyRXZDTEo1c0lKODQyMG5ndlpSbEFnQklxZUNZRUJIcDZhSDdtYkw0d3JRdzEwUXhLc2wxSDZZeG1FSU9vR0p3V3MwZjI5dHRYS0hTcmdmalluVmhhMnhPZjlRNkxEV3Z5RUZLUGlKMDRXRXcxWVN2TTVnJTNEJTNE)


- macOS: [Arduino software](https://downloads.arduino.cc/arduino-1.8.18-macosx.zip?_gl=1*cbkesg*_gcl_au*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*FPAU*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*_ga*MTA0NzU2ODUyNC4xNzIzNTQyOTA5*_ga_NEXN8H46L5*MTcyMzU1MTE0MC4yLjEuMTcyMzU1MTE0NS4wLjAuMTcxNjQ1MTUwMw..*_fplc*bWd6c2VxN3l0THgyRXZDTEo1c0lKODQyMG5ndlpSbEFnQklxZUNZRUJIcDZhSDdtYkw0d3JRdzEwUXhLc2wxSDZZeG1FSU9vR0p3V3MwZjI5dHRYS0hTcmdmalluVmhhMnhPZjlRNkxEV3Z5RUZLUGlKMDRXRXcxWVN2TTVnJTNEJTNE)


- Linux 32 bit: [Arduino software](https://downloads.arduino.cc/arduino-1.8.18-linux32.tar.xz?_gl=1*1hbngn5*_gcl_au*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*FPAU*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*_ga*MTA0NzU2ODUyNC4xNzIzNTQyOTA5*_ga_NEXN8H46L5*MTcyMzU1MTE0MC4yLjEuMTcyMzU1MTE0NS4wLjAuMTcxNjQ1MTUwMw..*_fplc*bWd6c2VxN3l0THgyRXZDTEo1c0lKODQyMG5ndlpSbEFnQklxZUNZRUJIcDZhSDdtYkw0d3JRdzEwUXhLc2wxSDZZeG1FSU9vR0p3V3MwZjI5dHRYS0hTcmdmalluVmhhMnhPZjlRNkxEV3Z5RUZLUGlKMDRXRXcxWVN2TTVnJTNEJTNE)


- Linux 64 bit:[Arduino software](https://downloads.arduino.cc/arduino-1.8.18-linux64.tar.xz?_gl=1*1hbngn5*_gcl_au*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*FPAU*MTc0MzQ1MzAwOS4xNzIzNTQzMTQ5*_ga*MTA0NzU2ODUyNC4xNzIzNTQyOTA5*_ga_NEXN8H46L5*MTcyMzU1MTE0MC4yLjEuMTcyMzU1MTE0NS4wLjAuMTcxNjQ1MTUwMw..*_fplc*bWd6c2VxN3l0THgyRXZDTEo1c0lKODQyMG5ndlpSbEFnQklxZUNZRUJIcDZhSDdtYkw0d3JRdzEwUXhLc2wxSDZZeG1FSU9vR0p3V3MwZjI5dHRYS0hTcmdmalluVmhhMnhPZjlRNkxEV3Z5RUZLUGlKMDRXRXcxWVN2TTVnJTNEJTNE)


If you have any issues with downloading this software, please ask a supervisor/ adult in the room to help.

Upon opening the Arduino software, This is how the software should look.

![alt text](<z Tutorial Image/Clean Sketch.png>)

</details>



<details open><summary>Setting up software</summary>

## How to set up the robot with the software?
Before you upload any code to the board, make sure that the board is in upload mode. This ensures that the board is not attempting to communicate with the camera. See the image below.

![alt text](<z Tutorial Image/Switch.png>)

After this, you are going to need to plug in the usb into the robot, this should result in a solid red light showing on the board as well as a flashing green light.

you will need to open the application and ensure that you have all the settings correct in order to have the software connected well to your robot. In doing this, you will firstly need to select the board that you are using, to do this, you will need to navigate to (tools > Board: > “Arduino Uno”) when you hover over “Board:” a dropdown box will pop up, allowing you to select “Arduino Uno” from the list.

![alt text](<z Tutorial Image/Board selection.png>)

As well as this, you will also need to select the correct port that the robot will be running on. Once again, if you select (tools > port > COMX) this will allow you to select the correct port which will further help in having the robot set up. 

![alt text](<z Tutorial Image/Port.png>)

</details>



<details open><summary>0- Installing the library</summary>

## What are libraries?

This section uses the files located in [0- Installing the library](<0- Installing the library>)

Just like most programming platforms, the Arduino environment can be extended through the use of libraries. Libraries provide extra functionality for use in sketches, e.g. working with hardware or manipulating data. To use a library in a sketch, select it from Sketch > Include Library. 

![alt text](<z Tutorial Image/Include Library.png>)

In this tutorial, all the library files needed for the program are included in the tutorial folder, you just need to add them to the IDE by following steps.

In order to upload the library files to the robot, you will need to select (sketch > include library > Add .ZIP library) then select the library file/s that you are wanting to add. In this case you will need to navigate to the file as shown below.

![alt text](<z Tutorial Image/0- Installing Library.png>)

After uploading and verifying the library into the compiler, you can enter the code below to see the light on the board of the robot turn yellow.

</details> 



<details open><summary>Data types</summary>

## Data Types 

Throughout the course of this tutorial you will use a variety of different data types within the code, here is a reference page to the different [Data Types](DataTypes.md) and what they can be used for.

</details>



<details open><summary>1- Controlling the LED</summary>

## 1 Controlling the LED


***
*Before beginning this section, please ensure that you have the Fast LED library installed. You can find this within the [Installing libraries section](<0- Installing the library>) > [Fast LED Library](<0- Installing the library/FastLED-master.zip>)*
***


<details><summary>Changing the led light</summary>

```cpp
#include <FastLED.h>

#define NUM_LEDS 1    // Number of LEDs in strip (just 1)
#define DATA_PIN 4    // Pin for data communications
 
// Define the array of leds
CRGB leds[NUM_LEDS];

// Runs once to configure devices
void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Configure the LED    
} 

// loops forever
void loop() { 
  FastLED.setBrightness(30);       // Set the brightness, 0 to 255 - Warning: 255 can be VERY bright
  
  leds[0] = CRGB::Yellow;            // Set Color with name - Erase Azure and press CTRL-Space for choices
  // leds[0] = CRGB(128,0,0);       // OR, Set color with amount of Red, Green and Blue, 0 to 255 each
  FastLED.show();                   // Set the LED to show
  delay(500);                       // Wait 1/2 second
```

</details>


### Core concept
You can further your practise of this section by changing the colours on the robot to a colour of your choice. Try changing the colour below.

```cpp
leds[0] = CRGB::Yellow;
```

### Breaking down the code
The section following on from this is going to break down the code from this file and explain to you why it is used.

### What is a variable?
A variable is an allocated space in memory for a value.

### What is an include directive?
The first line of code includes an include file. This file is quite literally used to include a whole page of code into the beginning of another.

`
#include <FastLED.h>
`

### What is a define directive?
A define can be used to set a bind to a pin that you know is not going to change. In this case, the define has been used to set the individual pin to the number of LEDs (1 in this scenario) 


<details><summary>Use of define directive</summary>

```cpp
#define NUM_LEDS 1    // Number of LEDs in strip (just 1)
#define DATA_PIN 4    // Pin for data communications
```

</details>


### What is an array?
Arrays are a collection of variables of the same data type. Below the array is using a single LED neopixel strip.


<details><summary>Use of array</summary>

```cpp
// Define the array of leds
CRGB leds[NUM_LEDS];
```

</details>


### What is a void?
The void keyword is used only in function declarations. It indicates that the function is expected to return no information to the function from which it was called.

<details><summary>Void set up</summary>

```cpp
// Runs once to configure devices
void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Configure the LED    
} 
```

</details>

### What is a loop?
A loop is used to run over a set section of code multiple times. In this scenario, the loop runs continuously as there is no condition used.

After creating a setup() function, which initialises and sets the initial values, the loop() function does precisely what its name suggests, and loops consecutively, allowing your program to change and respond. Use it to actively control the Arduino board.


<details><summary>Loops</summary>

```cpp
// loops forever
void loop() { 
  FastLED.setBrightness(30);       // Set the brightness, 0 to 255 - Warning: 255 can be VERY bright
  
  leds[0] = CRGB::Yellow;            // Set Color with name - Erase Azure and press CTRL-Space for choices
  FastLED.show();                   // Set the LED to show
  delay(500);                       // Wait 1/2 second
  
  
} // repeat
```

</details>

### What does Void setup mean?
Void setup is the startup of when a sketch (Arduinos IDE software) is first created. It initialises the configuration of variables, pin modes and libraries. 

### Task

Try changing the colour and attempt at making the LED flash through multiple colours. You can also try and change the brightness of the LED to make the colours stand out more.

If you are struggling with this task, below is a link to the solution to help you with this.

[RGB LED Task](/Solutions.md#rgb-led-task)

</details>















<details open><summary>2- Reading Mode Switch</summary>

## 2 Reading mode switch

<details><summary>Code for mode switch</summary>

```cpp
#define modeSwitch 2     // Define pin of Mode Switch
bool modeSwitchState;   // Holds state of mode switch

// Setup runs once on reset or power-up
void setup() {
  pinMode(modeSwitch,INPUT);      // Ensure modeSwitch is an input (by deafult it should be)
  Serial.begin(9600);             // Begin serial communications at 9600 baud
}

// Loop runs forever
void loop() {
  // Serial.print() does not go to a new line, Serial.println() will go to next line after printing

  modeSwitchState = digitalRead(modeSwitch);  // read mode switch and store in modeSwitch State
  Serial.print("Mode Switch Value = ");       // Display Text for Mode Switch
  Serial.print(modeSwitchState);              // Display value of modeSwitchState in Serial Monitor

  if (modeSwitchState)  // Test if state is true (1) - braces are NOT needed if just 1 line of code for the conditional
  {                       
    Serial.println(" -- Switch not pressed");  // show this if true
  }
  else 
  {                                        
    Serial.println(" -- Switch pressed");       // show this if false
  }
}
```

</details>

### What is a bool(ean)?
A boolean is used when you want to gain the answer of yes or no. in the scenario below, a boolean is used to acknowledge whether the switch is in the on or off state, yes being on and no being off.

<details><summary>Boolean</summary>

```cpp
#define modeSwitch 2     // Define pin of Mode Switch
bool modeSwitchState;   // Holds state of mode switch
```

</details>

### What is an if statement?
An if statement is used when you are wanting to check whether there is a condition and run the following statement or set of statements if the condition is ‘true’.

In the scenario below, an if statement is used to find whether the result of the bool used earlier on was true or false. If the result comes back as true, then the program will show that the switch has not been pressed. If the value returns as false, then the switch will return as being pressed.

<details><summary>If statement</summary>

```cpp
if (modeSwitchState)  // Test if state is true (1) - braces are NOT needed if just 1 line of code for the conditional
  {                       
    Serial.println(" -- Switch not pressed");  // show this if true
  }
  else 
  {                                        
    Serial.println(" -- Switch pressed");       // show this if false
  }
```

</details>

### What is a print? 
Following on from the example above, you can see that a print class has been used. This provides the interface with the ability to print data to different output devices.

<details><summary>Print</summary>

```cpp
Serial.print("Mode Switch Value = ");       // Display Text for Mode Switch
  Serial.print(modeSwitchState);              // Display value of modeSwitchState in Serial Monitor
```
</details>


### What is a serial monitor?
The serial monitor is a tool within the Arduino IDE which opens up the communication between the pc and the robot. In doing this, it means that we, as humans, are able to gain an understanding as to what is going on within the robot.

![alt text](<z Tutorial Image/Serial Monitor.png>)

![alt text](<z Tutorial Image/Serial Monitor 2.png>)

As you can see above, there are two different messages within the serial monitor. When the switch on the robot has not been pressed, we get a message telling us “switch not pressed” but when the switch has been pressed, a message returns saying “switch pressed”.

### Task

Have a go at changing the message that is outputted to the serial monitor.


### Task 2- Advanced


if you have successfully changed the colour of the LED, have a go at connecting this change in LED to the switch on the robot. You can use whatever colour you would like to make it more personal to you.

Below a link will included for the solution of this task if you get stuck.

[Switch Advanced Task](/Solutions.md#switch-advanced-task)

</details>


<details open><summary>3- Driving Motors</summary>

## 3 Driving Motors

### What is a delay? 
A delay is used to pause the program for the amount of time (in milliseconds) specified as parameter. (There are 1000 milliseconds in a second.) in the scenario below, we are driving the right wheels forward for exactly 2 seconds.

<details><summary>Use of delay</summary>

```cpp
  // RIGHT WHEELS
  // Drive Right Wheels forward for 2 second  
  digitalWrite(RDIR, HIGH);    // Forward direction
  digitalWrite(RPower, HIGH);   // Full power
  delay(2000);  
```

</details>

### What is digital write?

<details><summary>Use of digital write</summary>

```cpp
  // Drive Right Wheels Backwards for 2 second  
  digitalWrite(RDIR, LOW);    // Backwards direction
  digitalWrite(RPower, HIGH);  // Full power
  delay(2000);               //delay 2000mS
```

</details><p>


A digital write is used to Write a HIGH or a LOW value to a digital pin. In the scenario above, we are moving the right hand side wheels backwards for 2 seconds at full power.

If the pin has been configured as an OUTPUT with pinMode(), its voltage will be set to the corresponding value: 5V (or 3.3V on 3.3V boards) for HIGH, 0V (ground) for LOW.
If the pin is configured as an INPUT, digitalWrite() will enable (HIGH) or disable (LOW) the internal pullup on the input pin. It is recommended to set the pinMode() to INPUT_PULLUP to enable the internal pull-up resistor. 

If you do not set the pinMode() to OUTPUT, and connect an LED to a pin, when calling digitalWrite(HIGH), the LED may appear dim. Without explicitly setting pinMode(), digitalWrite() will have enabled the internal pull-up resistor, which acts like a large current-limiting resistor.


### Task- Drive in square

Try and get the robot to drive forwards and turn after driving forwards, whilst also creating the shape of a square. 

If you are struggling with this section, please go to the solutions page and navigate to the solution for this task.

[Driving in a square](/Solutions.md#driving-in-a-square)

</details>


<details open><summary>4- Motor Speed Control</summary>

## 4 Motor Speed Control

### What is analog write?
In the scenario below, an analog write is used to set the robot at a specific speed as opposed to just setting the speed at high (full speed) or low (stops driving).

<details><summary>Controlling motor speed</summary>

```cpp
  // RIGHT WHEELS 1/2 speed forward, LEFT wheels 1/4 speed forward
  // for 2 seconds
  digitalWrite(RDIR, HIGH);    // Right Forward direction
  digitalWrite(LDIR, HIGH);    // Left Forward direction
  analogWrite(RPower, 128);    // 1/2 power on right
  analogWrite(LPower, 64);     // 1/4 power on left 
  delay(2000);  
```

</details>

### What is a while loop?
A while loop is a type of loop which runs until the condition is true or false (like an if statement.) In the scenario below a while loop has been used to indicate whilst the mode switch is being pressed, the speed will alternatively be at zero since the circuit will be closed and a signal will be sent to stop the power. However, whilst this signal is not being sent, due to the switch being open, the speed will theoretically be at maximum power due to the system assuming that the power being on will mean it will be at its maximum potential. This is why the speed is set at a specific speed.

<details><summary>Use of while loop</summary>

```cpp
//main loop
void loop() 
  while (digitalRead(modeSwitch) == 1)  
    ;  // Do nothing
```

</details>

### What is a for loop?
The for statement is used to repeat a block of statements enclosed in curly braces. An increment counter is usually used to increment and terminate the loop. The for statement is useful for any repetitive operation, and is often used in combination with arrays to operate on collections of data/pins. In the scenario below a for loop is used to indicate that for every loop, whilst the speed of the robot is greater than zero, the speed is going to reduce until it reaches zero.

<details><summary>Use of for loop</summary>

```cpp
for (int speed = 255; speed > 0; speed--){
    analogWrite(RPower, speed);
    analogWrite(LPower, speed);
    delay(4);
  }
```

</details>

### Task

For this task, try and drive the robot in the shape of a circle.*Hint* you will need to drive the wheels at different speeds in order to carry this task out successfully.

Below will be a link to the solution for this task.

[Driving in a circle](/Solutions.md#driving-in-a-circle)

</details>


<details open><summary>5- Driving with functions</summary>

## 5 Driving with Functions

### What is a function?
As the code that is being dealt with is starting to become much more complex, we begin to make use of something called functions. This means that we can have our code be more organised and easier to understand. Below you can see an image of where functions have been used to separate code which carries out different tasks. 

<details><summary>Use of functions</summary>

```cpp
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
```

</details>

</details>


<details open><summary>10- IR Receiver</summary>

## 6 IR Receiver
### What is a switch…case?
Like if statements, switch case controls the flow of programs by allowing programmers to specify different code that should be executed in various conditions. In particular, a switch statement compares the value of a variable to the values specified in case statements. When a case statement is found whose value matches that of the variable, the code in that case statement is run.
The break keyword exits the switch statement, and is typically used at the end of each case. Without a break statement, the switch statement will continue executing the following expressions ("falling-through") until a break, or the end of the switch statement is reached. In the scenario below,  a switch case is used so that code can be written to the individual buttons on the remote controller for the robot.

<details><summary>Use of switch...case</summary>

```cpp
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
```

</details>