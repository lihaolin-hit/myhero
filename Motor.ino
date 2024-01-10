#include "Arduino.h"
#define ab 1


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

void Motor_Loop(int vx,int vy,int w,uint8_t *motor1,uint8_t *motor2,uint8_t *motor3,uint8_t *motor4){
  //计算每个电机分速度
  int v1, v2, v3, v4;
  v1 = (vy - vx + w * ab);
  v2 = (vy + vx - w * ab);
  v3 = (vy - vx - w * ab);
  v4 = (vy + vx + w * ab);
  // *motor1 = (uint8_t)(vy - vx + w * ab);
  // *motor2 = (uint8_t)(vy + vx - w * ab);
  // *motor3 = (uint8_t)(vy - vx - w * ab);
  // *motor4 = (uint8_t)(vy + vx + w * ab);
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

  digitalWrite(wheel_lf_forward, HIGH);
  digitalWrite(wheel_lf_back, LOW);
  analogWrite(wheel_lf_pwm, *motor2);

  digitalWrite(wheel_lb_forward, HIGH);
  digitalWrite(wheel_lb_back, LOW);
  analogWrite(wheel_lb_pwm, *motor3);

  digitalWrite(wheel_rb_forward, HIGH);
  digitalWrite(wheel_rb_back, LOW);
  analogWrite(wheel_rb_pwm, *motor4);

}