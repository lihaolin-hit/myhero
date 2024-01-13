# Arduino特性

## 串口打印 调试
Serial.print("motor2="); //直接打印
Serial.println(motor2); //ln换行打印
Serial.begin(9600); //开启串口  设置波特率9600 

##  Arduino I/O函数
pinMode(pin_number,OUTPUT); //引脚模式 Arduino引脚默认配置为输入  不需要使用 pinMode()显式声明为输入
digitalWrite(pin_number,LOW); //数字信号
analogWrite(pin_number,*motor4); //模拟信号

## 时间函数
delay(ms); 
delayMicroseconds(us);
millis(ms); //返回Arduino板开始运行当前程序时的毫秒数  在大约50天后溢出
micros(us); 

