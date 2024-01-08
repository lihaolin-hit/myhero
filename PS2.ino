#include "PS2X_lib.h"        //PS2手柄库
PS2X ps2x;                  // 创建控制对象
/*************************************************************
*               PS2手柄接线方式：
*         arduino          手柄接收器
*            51               MOSI
*            50               MISO
*            53               CS
*            52              SCLK
*************************************************************/
#define PS2_DAT        51    //MOSI
#define PS2_CMD        50    //MISO
#define PS2_SEL        53    //CS
#define PS2_CLK        52    //SCLK
/*************************************************************/
unsigned char servo,PS2_LY,PS2_LX,PS2_RY,PS2_RX,PS2_KEY;  //定义L侧Y轴、X轴;以及R侧Y轴、X轴的变量
void (* resetFunc) (void) = 0;                    // 重置函数

void PS2_Setup(){
  char error;
  Serial.begin(9600);        //开启串口，波特率9600    
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);//PS2控制
}
void PS2_Loop(int *Control_mode,int *vx,int *vy,int *dj1,int *dj2,int *dj3){
  ps2x.read_gamepad(false, 0); //read controller and set large motor to spin at 'vibrate' speed
  if(ps2x.Button(PSB_TRIANGLE))   //主要混动模式  
      *Control_mode=1;
    else if(ps2x.Button(PSB_CIRCLE))  //静止模式
      *Control_mode=3;
    else if(ps2x.Button(PSB_SQUARE))   //运动模式
      *Control_mode=2;
  *vx=ps2x.Analog(PSS_LX)/10;  //读取L侧X轴的模拟值
  *vy=ps2x.Analog(PSS_LY)/10;  //读取L侧Y轴的模拟值
  *vx+=ps2x.Analog(PSS_RX)/10-24;  //读取R侧X轴的模拟值
  *vy+=ps2x.Analog(PSS_RY)/10-24;  //读取R侧Y轴的模拟值   
  if(ps2x.Button(PSB_PAD_UP)&&(*Control_mode!=2))   
      (*dj3)++;
    else if(ps2x.Button(PSB_PAD_DOWN)&&(*Control_mode!=2))  
      (*dj3)--;
  if(ps2x.Button(PSB_R1)&&(*Control_mode!=2))        
      (*dj2)--;
    else if(ps2x.Button(PSB_R2)&&(*Control_mode!=2))         
      (*dj2)++;
  if(ps2x.Button(PSB_L1)&&(*Control_mode!=2))  //上部摇杆向下       
      (*dj1)--;
    else if(ps2x.Button(PSB_L2)&&(*Control_mode!=2))          
      (*dj1)++;
  if(*Control_mode==3){
    *vx=*vy=0;
  }

  /*冗余
      else if(ps2x.Button(PSB_CROSS)) ;
      else  Serial.println("  KEY_RELEASE");
       else if(ps2x.Button(PSB_SELECT))     
      Serial.println("  PSB_SELECT");
    else if(ps2x.Button(PSB_START))      
      Serial.println("  PSB_START"); 
      if(ps2x.Button(PSB_PAD_RIGHT))  
      Serial.println("  PSB_PAD_RIGHT");
    else if(ps2x.Button(PSB_PAD_LEFT))  
      Serial.println("  PSB_PAD_LEFT"); 
  */
}

