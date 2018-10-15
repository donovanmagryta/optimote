/* Place cursor here when plugged in to avoid typing problems and put RST to GND
CURRENTLY ONLY SENDS GENERIC SYNC DATA. CAN LATER ADD IN SIMULTAENEOUS MULTIMODE DATA SENDING (ONE )
*/
#define USE_ARDUINO_INTERRUPTS true
#include "PulseSensorPlayground.h"
#include <Keyboard.h>
int direction = 0; // to store count direction increase
int lastbpm = 0;
const int PulseWire = 0; //analog pin 0
int Threshold = 550;
PulseSensorPlayground pulseSensor;
int comp = 0;
unsigned long int milli_time;    //variable to hold the time
int blip = 0; // to hold projected HR.
int blipcheck = 0; //to hold boolean state to calibrate projected HR once on startup.
int mode = 0;
//int modeswitch = digitalRead(2);
int modestate = 0;
int printit = 0;
void setup() {
  pinMode(2, INPUT_PULLUP);  //D2 to pole on spdt switch.
  delay(1000);
  delay(300);

  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
  }
} //added
void loop() {
  //if (modeswitch == LOW) {
    if (printit == 0) {
      //Serial.println("focus mode started");
      printit = 1;
    }
    digitalWrite(3, HIGH);
    milli_time = millis();
    int myBPM = pulseSensor.getBeatsPerMinute();
  if (pulseSensor.sawStartOfBeat()) {// Constantly test to see if "a beat happened".
      if (blipcheck == 0) {  //calibrate blip to bpm only once on startup
      blip = myBPM; // needs to go outside of this loop to below?
      blipcheck = 1;
     }
     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String time = "time";
     int timedigit = milli_time / 1000;
     String timestring = String(timedigit);
     time += timedigit;
     Keyboard.print(time);                        // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String pred = "pred";
     pred += blip;
     Keyboard.print(pred);                       // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String bpm = "bpm";
     bpm += myBPM;
     Keyboard.println(bpm);                       // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();
     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("appencsv");                        // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

    comp = myBPM - lastbpm;

    if (comp > 2 && myBPM > lastbpm) { //slow down to sync with HR
      blip = blip - 3;


     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String time = "time";
     int timedigit = milli_time / 1000;
     String timestring = String(timedigit);
     time += timedigit;
     Keyboard.print(time);                       // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String pred = "pred";
     pred += blip;
     Keyboard.print(pred);                       // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String bpm = "bpm";
     bpm += myBPM;
     Keyboard.println(bpm);                       // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();
     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("appencsv");                        // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.print("slower");                       // Print the value inside of myBPM.
      Keyboard.releaseAll();
      delay(50);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.print("z");
      Keyboard.releaseAll();
      lastbpm = myBPM;

    }
     //moved down to separate loop:
     if (comp > 3 && myBPM > lastbpm) {
      //Serial.println("incrementing increase counter.");
      direction = direction + 1;
     }

    else if (comp < -2 && myBPM < lastbpm) { //speed up to sync with HR
      blip = blip + 3;

      Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
    String time = "time";
     int timedigit = milli_time / 1000;
     String timestring = String(timedigit);
     time += timedigit;
     Keyboard.print(time);                        // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String pred = "pred";
     pred += blip;
     Keyboard.print(pred);                       // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();

     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     String bpm = "bpm";
     bpm += myBPM;
     Keyboard.println(bpm);                       // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();
     Keyboard.press(KEY_LEFT_CTRL);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("appencsv");                        // Print the value inside of myBPM.
     Keyboard.releaseAll();
     delay(50);
     Keyboard.press(KEY_LEFT_ALT);
     Keyboard.print("z");
     Keyboard.releaseAll();
      delay(50);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.print("z");
      Keyboard.releaseAll();
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.print("faster");                       // Print the value inside of myBPM.
      Keyboard.releaseAll();
      delay(50);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.print("z");
      Keyboard.releaseAll();
      lastbpm = myBPM;
      //Serial.println("resetting increase counter");
      direction = 0;

    }
    else if (direction > 3 && myBPM > 60) {  //changed to double ands ******switched less than (thrill mode) to greater than (calm)
      blip = blip + 8;
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.print("peak");                       // Print the value inside of myBPM.
      Keyboard.releaseAll();
      delay(50);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.print("z");
      Keyboard.releaseAll();
      direction = 0; //reset direction count
    }
    delay(20);                    // considered best practice in a simple sketch?
  }
}
