/*变量定义区*/
int PS2_mode = 0, Vx = 0, Vy = 0, servo_down = 5, servo_mid = 0, servo_up = 150, Vw = 0;
int motor1 = 0, motor2 = 0, motor3 = 0, motor4 = 0;
const int servo_down_max = 60, servo_down_min = 5, servo_mid_min = 0, servo_mid_max = 53, servo_up_min = 95, servo_up_max = 150;

void watch() // 串口调试
{

  /*Serial.print("Vw=");
  Serial.print(Vw);
  Serial.print("  Vy=");
  Serial.print(Vy);
  Serial.print("  Vx=");
  Serial.print(Vx);
  Serial.print("   motor1=");
  Serial.print(motor1);
  Serial.print("   motor2=");
  Serial.print(motor2); */
  Serial.print("   servo up =");
  Serial.print(servo_up);
  Serial.print("   servo mid =");
  Serial.print(servo_mid);
  Serial.print("   servo down =");
  Serial.println(servo_down);
}

void setup()
{
  PS2_Setup();
  Motor_Setup();
  Servo_Setup();
}

void loop()
{
  PS2_Loop(&PS2_mode, &Vx, &Vy, &servo_down, &servo_mid, &servo_up, &Vw);
  Motor_Loop(Vx, Vy, Vw, &motor1, &motor2, &motor3, &motor4);
  watch();
  Servo_Loop(servo_down, servo_mid, servo_up);
}
