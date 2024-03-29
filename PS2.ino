#include "PS2X_lib.h" //PS2手柄库
PS2X ps2x;            // 创建控制对象
/*************************************************************
 *               PS2手柄接线方式：
 *         arduino          手柄接收器
 *            51               MOSI
 *            50               MISO
 *            53               CS
 *            52              SCLK
 *************************************************************/
#define PS2_DAT 51 // MOSI
#define PS2_CMD 50 // MISO
#define PS2_SEL 53 // CS
#define PS2_CLK 52 // SCLK
/*************************************************************/
unsigned char servo, PS2_LY, PS2_LX, PS2_RY, PS2_RX, PS2_KEY; // 定义L侧Y轴、X轴;以及R侧Y轴、X轴的变量

void (*resetFunc)(void) = 0; // 重置函数

void PS2_Setup()
{
  char error;
  Serial.begin(9600);                                                          // 开启串口，波特率9600
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true); // PS2控制
}

void checkadd(int *froma, int maxi, int mini, int adder)
{
  int becomea = (*froma) + adder;
  if ((becomea <= maxi) && (becomea >= mini))
    *froma = becomea;
}

void PS2_Loop(int *Control_mode, int *vx, int *vy, int *servo_down, int *servo_mid, int *servo_up, int *vw)
{
  ps2x.read_gamepad(false, 0); // read controller and set large motor to spin at 'vibrate' speed
  if (ps2x.Button(PSB_CIRCLE)) // 传统模式
    *Control_mode = 1;
  else if (ps2x.Button(PSB_SQUARE)) // 新运动模式
    *Control_mode = 2;
  if (*Control_mode == 1)
  {
    *vx = ps2x.Analog(PSS_LX) / 10;       // 读取L侧X轴的模拟值
    *vy = ps2x.Analog(PSS_LY) / 10;       // 读取L侧Y轴的模拟值
    *vx += ps2x.Analog(PSS_RX) / 10 - 24; // 读取R侧X轴的模拟值
    *vy += ps2x.Analog(PSS_RY) / 10 - 24; // 读取R侧Y轴的模拟值
    (*vy) = -(*vy);
    if (*vx == 26)
      (*vx)--;
    else if (*vy == -26)
      (*vy)++;

    if (ps2x.Button(PSB_CROSS))
      checkadd(servo_up,servo_up_max,servo_up_min,2);
    else if (ps2x.Button(PSB_TRIANGLE))
      checkadd(servo_up,servo_up_max,servo_up_min,-2);
    if (ps2x.Button(PSB_R1))
      checkadd(servo_mid,servo_mid_max,servo_mid_min,1);
    else if (ps2x.Button(PSB_R2))
      checkadd(servo_mid,servo_mid_max,servo_mid_min,-1);
    if (ps2x.Button(PSB_L1)) // 上部摇杆向下
      checkadd(servo_down,servo_down_max,servo_down_min,-1);
    else if (ps2x.Button(PSB_L2))
      checkadd(servo_down,servo_down_max,servo_down_min,1);

    // 角速度以逆时针方向为正
    if (ps2x.Button(PSB_PAD_RIGHT))
      (*vw) = -10;
    else if (ps2x.Button(PSB_PAD_LEFT))
      (*vw) = 10;
    else
      *vw = 0;
  }

  else if (*Control_mode == 2)
  {
    if (ps2x.Button(PSB_PAD_UP))
      *vy = 15;
    else if (ps2x.Button(PSB_PAD_DOWN))
      *vy = -15;
    else
      *vy = 0;

    if (ps2x.Button(PSB_PAD_RIGHT))
      (*vw) = -10;
    else if (ps2x.Button(PSB_PAD_LEFT))
      (*vw) = 10;
    else
      *vw = 0;

    if (ps2x.Button(PSB_CROSS))
      checkadd(servo_up,servo_up_max,servo_up_min,2);
    else if (ps2x.Button(PSB_TRIANGLE))
      checkadd(servo_up,servo_up_max,servo_up_min,-2);
    if (ps2x.Button(PSB_R1))
      checkadd(servo_mid,servo_mid_max,servo_mid_min,1);
    else if (ps2x.Button(PSB_R2))
      checkadd(servo_mid,servo_mid_max,servo_mid_min,-1);
    if (ps2x.Button(PSB_L1)) // 上部摇杆向下
      checkadd(servo_down,servo_down_max,servo_down_min,-1);
    else if (ps2x.Button(PSB_L2))
      checkadd(servo_down,servo_down_max,servo_down_min,1);
  }

}
