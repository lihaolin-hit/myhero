#include <Servo.h>
#define servo_up_max 100
#define servo_up_min 90
#define servo_mid_max 100
#define servo_mid_min 90 
#define servo_down_max 100
#define servo_down_min 90

Servo Sservo_up;  // create servo object to control a servo
Servo Sservo_mid;
Servo Sservo_down;

void Servo_Setup() {
  Sservo_up.attach(9);  // attaches the servo on pin 9 to the servo object
  /*Sservo_mid.attach(9);
  Sservo_down.attach(9);*/
}

void Servo_Loop() {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Sservo_up.write(pos);              // tell servo to go to position in variable 'pos'
    delay(150);                       // waits 15 ms for the servo to reach the position
  }
}
