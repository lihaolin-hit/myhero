/*变量定义区*/
int PS2_mode=1,Vx=0,Vy=0,dj1=45,dj2=45,dj3=45,Vw=0;
uint8_t motor1 = 0, motor2 = 0, motor3 = 0, motor4 = 0;
void setup(){
  PS2_Setup();
  //Motor_Setup();
}

void loop(){
  PS2_Loop(&PS2_mode,&Vx,&Vy,&dj1,&dj2,&dj3,&Vw);
  //Motor_Loop(Vx,Vy,Vw,&motor1,&motor2,&motor3,&motor4);
  Serial.print("Vw="); 
  Serial.print(Vw); 
  Serial.print("  Vy="); 
  Serial.print(Vy);
  Serial.print("  Vx="); 
  Serial.println(Vx); 
  Serial.print("motor1="); 
  //Serial.print(motor1); 
  Serial.print("   motor2="); 
  //Serial.println(motor2); 
  delay(50);
}

