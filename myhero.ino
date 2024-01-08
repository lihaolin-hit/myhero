/*变量定义区*/
int PS2_mode=1,Vx=0,Vy=0,dj1=45,dj2=45,dj3=45;

void setup(){
  PS2_Setup();
}

void loop(){
  PS2_Loop(&PS2_mode,&Vx,&Vy,&dj1,&dj2,&dj3);
  delay(100);
}

