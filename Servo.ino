#include <Servo.h>

Servo Sservo_up; // create servo object to control a servo
Servo Sservo_mid;
Servo Sservo_down;

void Servo_Setup()
{
  Sservo_down.attach(2);
  Sservo_mid.attach(3);
  Sservo_up.attach(4);
}
// 调试程序
/*
void Servo_testLoop()
{
  for (int pos = 90; pos <= 155; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Sservo_up.write(pos); // tell servo to go to position in variable 'pos'
    delay(50);            // waits 15 ms for the servo to reach the position
  }
  for (int pos = 155; pos > 90; pos -= 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Sservo_up.write(pos); // tell servo to go to position in variable 'pos'
    delay(50);            // waits 15 ms for the servo to reach the position
  }
}
*/
void Servo_Loop(int servo_down, int servo_mid, int servo_up)
{
  Sservo_down.write(servo_down);
  Sservo_mid.write(servo_mid);
  Sservo_up.write(servo_up);
}
