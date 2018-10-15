

/* Place cursor here when plugged in to avoid typing problems and put put RST to GND
 *  counterbalancing mode to improve focus
 */
// Set-up low-level interrupts for most acurate BPM math.
#define USE_ARDUINO_INTERRUPTS true 
//include libraries needed
#include "PulseSensorPlayground.h"       
#include <Keyboard.h>
//#include <HID.h>
int direction = 0; // to store count direction increase
// store previous IBI or BPM under lastbpm
int lastbpm = 0;
//  Variables
// PulseSensor PURPLE WIRE connected to ANALOG PIN 1
const int PulseWire = 0;
// The on-board Arduino LED, close to PIN 13.
//const int LED13 = 13;
 // Determine which Signal to "count as a beat" and which to ignore.
int Threshold = 550;
// Creates an instance of the PulseSensorPlayground object called "pulseSensor"                               
PulseSensorPlayground pulseSensor;
int comp = 0;
unsigned long int milli_time;    //variable to hold the time
//setup runs once
void setup() {
  Serial.begin(9600);
  //give enough time for startup   
  delay(10000);
  //start keyboard emulation
  Keyboard.begin();          // For Serial Monitor
  delay(300);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("vlc.exe");
  delay(500);
  Keyboard.write(KEY_RETURN);
  Keyboard.releaseAll();
  delay(500);
  //Keyboard.press(KEY_LEFT_CTRL); //Hide controls (breaks specific time skip!)
  //Keyboard.press('h'); //Hide controls (breaks specific time skip!)
  ////Keyboard.releaseAll(); //Hide controls (breaks specific time skip!)
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL); 
  Keyboard.press('o');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("demo.mp3");
  Keyboard.write(KEY_RETURN); //start file
   Keyboard.releaseAll();
   Serial.print(Time);
    Serial.print(",");
    Serial.print(Media);;
    Serial.print(",");
    Serial.println(Heart);
  //Serial.println(milli_time);
  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire); 
  //auto-magically blink Arduino's LED with heartbeat.  
  //pulseSensor.blinkOnPulse(LED13); 
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
  }
}//added

//loop repeats
void loop() {
  milli_time = millis();

// Calls function on our pulseSensor object that returns BPM as an "int".
int myBPM = pulseSensor.getBeatsPerMinute();
// "myBPM" hold this BPM value now. 

if (pulseSensor.sawStartOfBeat()) {// Constantly test to see if "a beat happened". 
      if (blipcheck == 0) {  //calibrate blip to bpm only once on startup
      blip = myBPM; // needs to go outside of this loop to below?
      blipcheck = 1;
     }
     Serial.print(milli_time / 1000);
    Serial.print(",");
    Serial.print(blip);;
    Serial.print(",");
    Serial.println(myBPM);
    ///???the rest goes here instead?
     //for some reason the rest returns "True" every single loop!]][
    comp = myBPM - lastbpm;
    //Serial.print("last vs new HR difference is");
    ////Serial.println(comp);
    //Serial.print("Heart BPM:   ");
    //Serial.println(myBPM);
    ////Serial.print("Count:  ");
    //Serial.println(direction);
    if (comp > 2 && myBPM > lastbpm) { //slow down to sync with HR
      blip = blip - 3;
     
     Serial.print(milli_time / 1000);
    Serial.print(",");
    Serial.print(blip);;
    Serial.print(",");
    Serial.println(myBPM); 
     Keyboard.write('[');
      lastbpm = myBPM;  
      
    }
     //moved down to separate loop:
     if (comp > 3 && myBPM > lastbpm) {
      //Serial.println("incrementing increase counter."); 
      direction = direction + 1;
     }
    
    else if (comp < -2 && myBPM < lastbpm) { //speed up to sync with HR
      blip = blip + 3;
     
     Serial.print(milli_time / 1000);
    Serial.print(",");
    Serial.print(blip);;
    Serial.print(",");
    Serial.println(myBPM); 
      Keyboard.write(']');
      lastbpm = myBPM; 
      //Serial.println("resetting increase counter"); 
      direction = 0;
    
    }
    else if (comp == 50)
    {
      //do nothing
      //Serial.println("==50");
    }
    
    if (direction > 5 && myBPM > 78) {  //calm boost due to high HR over many readings
      blip = blip - 5;
     
     Serial.print(milli_time / 1000);
    Serial.print(",");
    Serial.print(blip);;
    Serial.print(",");
    Serial.println(myBPM); 
      Keyboard.write('['); //slow down 3X
      Keyboard.write('[');
      Keyboard.write('[');
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_DOWN_ARROW);
      Keyboard.releaseAll(); //volume down.
      
      direction = 0;
    }

    if (comp > 8) {  //if HR spikes significantly skip ahead.
      blip = blip - 10;
     
     Serial.print(milli_time / 1000);
    Serial.print(",");
    Serial.print(blip);;
    Serial.print(",");
    Serial.println(myBPM); 
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll(); //volume down.
     
}
}

  delay(20);                    // considered best practice in a simple sketch?

}

