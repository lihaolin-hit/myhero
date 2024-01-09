#define ab 198

void myclac (int vx,int vy,int w,int *motor1,int *motor2,int *motor3,int *motor4)
{
  *motor1=vy-vx+w*ab;
  *motor2=vy+vx-w*ab;
  *motor3=vy-vx-w*ab;
  *motor4=vy+vx+w*ab;
}