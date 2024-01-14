#include "Arduino.h"

//电机供电口和pwm引脚定义
//电机供电口和pwm引脚定义
//正反转未知，待上机调试后若相反，宏定义两个引脚数字对换

#define wheel_lf_forward 57
#define wheel_lf_back 56
#define wheel_lf_pwm 12

#define wheel_lb_forward 54
#define wheel_lb_back 55
#define wheel_lb_pwm 13

#define wheel_rf_forward 60
#define wheel_rf_back 61
#define wheel_rf_pwm 9 //114事变

#define wheel_rb_forward 59
#define wheel_rb_back 58
#define wheel_rb_pwm 11

void Motor_Setup() {
  //两个引脚全部先拉低电平，PWM降到0
  pinMode(wheel_lf_forward,OUTPUT);
  pinMode(wheel_lf_back,OUTPUT);
  digitalWrite(wheel_lf_forward,LOW);
  digitalWrite(wheel_lf_back,LOW);
  analogWrite(wheel_lf_pwm,0);

  pinMode(wheel_lb_forward,OUTPUT);
  pinMode(wheel_lb_back,OUTPUT);
  digitalWrite(wheel_lb_forward,LOW);
  digitalWrite(wheel_lb_back,LOW);
  analogWrite(wheel_lb_pwm,0);

  pinMode(wheel_rf_forward,OUTPUT);
  pinMode(wheel_rf_back,OUTPUT);
  digitalWrite(wheel_rf_forward,LOW);
  digitalWrite(wheel_rf_back,LOW);
  analogWrite(wheel_rf_pwm,0);

  pinMode(wheel_rb_forward,OUTPUT);
  pinMode(wheel_rb_back,OUTPUT);
  digitalWrite(wheel_rb_forward,LOW);
  digitalWrite(wheel_rb_back,LOW);
  analogWrite(wheel_rb_pwm,0);
}

void Motor_Loop(int vx,int vy,int w,int *motor1,int *motor2,int *motor3,int *motor4){
  //计算每个电机分速度
  int v1, v2, v3, v4;
  v1 = 5*(vy - vx + w);
  v2 = 5*(vy + vx - w);
  v3 = 5*(vy - vx - w);
  v4 = 5*(vy + vx + w);

  //控制
  if (v1 >= 0){
    *motor1 = v1;
    digitalWrite(wheel_rf_forward, HIGH);
    digitalWrite(wheel_rf_back, LOW);
    analogWrite(wheel_rf_pwm, *motor1);
  }
  else if (v1 < 0){
    *motor1 = -v1;
    digitalWrite(wheel_rf_forward, LOW);
    digitalWrite(wheel_rf_back, HIGH);
    analogWrite(wheel_rf_pwm, *motor1);
  }

  if (v2 >= 0){
    *motor2 = v2;
    digitalWrite(wheel_lf_forward, HIGH);
    digitalWrite(wheel_lf_back, LOW);
    analogWrite(wheel_lf_pwm, *motor2);
  }
  else if (v2 < 0){
    *motor2 = -v2;
    digitalWrite(wheel_lf_forward, LOW);
    digitalWrite(wheel_lf_back, HIGH);
    analogWrite(wheel_lf_pwm, *motor2);
  }
  
  if (v3 >= 0){
    *motor3 = v3;
    digitalWrite(wheel_lb_forward, HIGH);
    digitalWrite(wheel_lb_back, LOW);
    analogWrite(wheel_lb_pwm, *motor3);
  }
  else if (v3 < 0){
    *motor3 = -v3;
    digitalWrite(wheel_lb_forward, LOW);
    digitalWrite(wheel_lb_back, HIGH);
    analogWrite(wheel_lb_pwm, *motor3);
  }
  
  if (v4 >= 0){
    *motor4 = v4;
    digitalWrite(wheel_rb_forward, HIGH);
    digitalWrite(wheel_rb_back, LOW);
    analogWrite(wheel_rb_pwm, *motor4);
  }
  else if (v4 < 0){
    *motor4 = -v4;
    digitalWrite(wheel_rb_forward, LOW);
    digitalWrite(wheel_rb_back, HIGH);
    analogWrite(wheel_rb_pwm, *motor4);
  }
}