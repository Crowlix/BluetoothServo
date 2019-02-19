#include <ServoTimer2.h>

// define the pin for the servo
#define rollPin  17
boolean punchit = false;
boolean retract = false;
ServoTimer2 servoRoll;   

//Attach the servo and define an interrupt on pin 2 (Bluetooth RTX)
void setup() {
  servoRoll.attach(rollPin);     
   attachInterrupt(digitalPinToInterrupt(2), punchIt, CHANGE);

}

void loop()
{ 
  if(retract) {
    servoRoll.write(1500);
    delay(1000);
    retract = false;
  }
  if(punchit) {
   servoRoll.write(2100);
   punchit = false;
   retract = true;
   delay(1000);   
  }
}

void punchIt(){
  punchit = true;
  delay(20);
}