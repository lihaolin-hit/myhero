/*变量定义区*/
int PS2_mode=0,Vx=0,Vy=0,servo_down=60,servo_mid=45,servo_up=45,Vw=0;
int motor1 = 0, motor2 = 0, motor3 = 0, motor4 = 0;
/*#define servo_up_max 100
#define servo_up_min 90
#define servo_mid_max 100
#define servo_mid_min 90 */
const int servo_down_max=97,servo_down_min=45;

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
  watch();
  //Servo_Loop(servo_down,servo_mid,servo_up);
  delay(15);
}

