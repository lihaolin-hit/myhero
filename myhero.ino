/*变量定义区*/
int PS2_mode=0,Vx=0,Vy=0,servo_down=45,servo_mid=45,servo_up=45,Vw=0;
int motor1 = 0, motor2 = 0, motor3 = 0, motor4 = 0;

void watch()//串口调试
{
  
  Serial.print("Vw="); 
  Serial.print(Vw); 
  Serial.print("  Vy="); 
  Serial.print(Vy);
  Serial.print("  Vx="); 
  Serial.print(Vx); 
  Serial.print("   motor1="); 
  Serial.print(motor1); 
  Serial.print("   motor2="); 
  Serial.println(motor2); 
}

void setup(){
  PS2_Setup();
  Motor_Setup();
  //Servo_Setup();
}

void loop(){
  PS2_Loop(&PS2_mode,&Vx,&Vy,&servo_down,&servo_mid,&servo_up,&Vw);
  Motor_Loop(Vx,Vy,Vw,&motor1,&motor2,&motor3,&motor4);
  //Servo_Loop(servo_down,servo_mid,servo_up);
  delay(5);
}

