/*变量定义区*/
int PS2_mode=1,Vx=0,Vy=0,dj1=45,dj2=45,dj3=45,Vw=0;

void setup(){
  PS2_Setup();
}

void loop(){
  PS2_Loop(&PS2_mode,&Vx,&Vy,&dj1,&dj2,&dj3,&Vw);
  Serial.print("Vw="); 
  Serial.println(Vw); 
  Serial.print("Vy="); 
  Serial.println(Vy); 
  delay(100);
}

