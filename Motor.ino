/*#include "Arduino.h"
//电机供电口和pwm引脚定义
#define wheel_lf_forward 54
#define wheel_lf_back 55
#define wheel_lf_pwm 13
//其余3个轮子待定义
#define wheel_lb_forward 
#define wheel_lb_back 
#define wheel_lb_pwm 

#define wheel_rf_forward 
#define wheel_rf_back 
#define wheel_rf_pwm 

#define wheel_rb_forward 
#define wheel_rb_back 
#define wheel_rb_pwm 

void Motor_Setup() {
  pinMode(wheel_lf_forward,OUTPUT);
  pinMode(wheel_lf_back,OUTPUT);
  digitalWrite(wheel_lf_forward,LOW);
  digitalWrite(wheel_lf_back,LOW);
  analogWrite(wheel_lf_pwm,130);

  pinMode(wheel_lb_forward,OUTPUT);
  pinMode(wheel_lb_back,OUTPUT);
  digitalWrite(wheel_lb_forward,LOW);
  digitalWrite(wheel_lb_back,LOW);
  analogWrite(wheel_lb_pwm,130);

  pinMode(wheel_rf_forward,OUTPUT);
  pinMode(wheel_rf_back,OUTPUT);
  digitalWrite(wheel_rf_forward,LOW);
  digitalWrite(wheel_rf_back,LOW);
  analogWrite(wheel_rf_pwm,130);

  pinMode(wheel_rb_forward,OUTPUT);
  pinMode(wheel_rb_back,OUTPUT);
  digitalWrite(wheel_rb_forward,LOW);
  digitalWrite(wheel_rb_back,LOW);
  analogWrite(wheel_rb_pwm,130);
}

void Motor_Loop(uint8_t *Control_mode, uint8_t *vx, uint8_t *vy){
  digitalWrite(wheel_forward, HIGH);
  digitalWrite(wheel_back, LOW);
  analogWrite(wheel_pwm, 255);
  
}*/