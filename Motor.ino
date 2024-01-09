#include "Arduino.h"
//电机供电口和pwm引脚定义
//电机供电口和pwm引脚定义
//正反转未知，待上机调试后若相反，宏定义两个引脚数字对换
#define wheel_lf_forward 55
#define wheel_lf_back 57
#define wheel_lf_pwm 12

#define wheel_lb_forward 54
#define wheel_lb_back 55
#define wheel_lb_pwm 13

#define wheel_rf_forward 60
#define wheel_rf_back 61
#define wheel_rf_pwm 10

#define wheel_rb_forward 58
#define wheel_rb_back 59
#define wheel_rb_pwm 11

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
  
}