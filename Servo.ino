#include <Servo.h>

Servo Sservo_up;  // create servo object to control a servo
Servo Sservo_mid;
Servo Sservo_down;

void Servo_Setup() {
  Sservo_down.attach(2);  // attaches the servo on pin 9 to the servo object
  /*Sservo_mid.attach(9);
  Sservo_down.attach(9);*/
}
//调试程序
void Servo_testLoop(int servo_down,int servo_mid,int servo_up) {
  for (int pos = 45; pos <= 80; pos +=2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Sservo_down.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15 ms for the servo to reach the position
  }
  for (int pos = 80; pos >=45; pos -=2) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Sservo_down.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15 ms for the servo to reach the position
  }
}

void Servo_Loop(int servo_down,int servo_mid,int servo_up) {
  Sservo_down.write(servo_down);
  Sservo_mid.write(servo_mid);
  Sservo_up.write(servo_up);
  delay(50);
}
