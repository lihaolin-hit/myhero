# Arduino特性

####  by lihaolin

## Reference
>
> <https://www.w3cschool.cn/arduino/>

## Arduino I/O函数

pinMode(pin_number,OUTPUT); //引脚模式 Arduino引脚默认配置为输入  不需要使用 pinMode()显式声明为输入
analogRead(pin); //可用于获取环境噪音  做随机数种子...
digitalRead(buttonPin)
digitalWrite(pin_number,LOW); //数字信号
analogWrite ( pin , value ) ;  //value : the duty cycle : between 0 (always off) and 255 (always on).

## 时间函数

delay(ms);
delayMicroseconds(us);
millis(ms); //返回Arduino板开始运行当前程序时的毫秒数  在大约50天后溢出
micros(us);

## Arduino中断

attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);

digitalPinToInterrupt(int) //能输入 Pin 口号并输出对应的中断号  提高可移植性

全局变量用于在 ISR 和主程序之间传递数据  为了确保在 ISR 和主程序之间共享的变量正确更新, 请将它们声明为 volatile
第二个参数是中断服务例程(ISR)的函数指针, 在 C/C++ 中直接写该函数的函数名即可。在触发时, 该函数将会被调用。 **该函数必须没有任何的参数也没有任何的返回值。**

第三个参数是中断触发条件, 由几个可选的值:
LOW 当中断所在 Pin 口处于低电平时触发
CHANGE 当中断所在 Pin口电平改变时触发
RISING 当中断所在Pin口从低电平变为高电平(上升沿)时触发
FALLING 当中断所在Pin口从高电平变为低电平(下降沿)时触发

由于中断会打断正常代码的运行, 因此 ISR 的应该尽可能快地执行完毕。
在 ISR 中修改的全局变量要用 volatile 修饰符修饰以防止编译器优化
在 ISR 中不能使用其他用中断实现的函数, 如 millis() delay() 等。延时可以使用  delayMicroseconds(), 它不是用中断实现的。

## Arduino 通信

### 并行和串行

并行接口同时传输多个位  它们通常需要数据总线 - 通过八条, 十六条或更多的线路进行传输
并行比串行更快, 更直接, 相对容易实施。然而, 它需要许多的输入/输出(I / O)端口和线路
多数Arduino板都是用几种不同的串行通信系统作为标准设备
较具代表性的串行通信系统要数Universal Serial Bus, 通用串行总线, 也就是USB
其它在嵌入式领域常见的串行接口还包括: I2C, SPI, RJ-45, UART, USART等

### 串行通讯

同步 - 同步的设备使用相同的时钟, 它们的时序彼此同步。异步 - 异步的设备具有各自的时钟, 并由前一状态的输出触发。
异步串行协议有一些内置的规则。这些规则只是有助于确保可靠且无误的数据传输的机制。这些避免外部时钟信号的机制是:
Synchronization bits 同步位  Data bits 数据位  Parity bits 奇偶校验位  Baud rate 波特率
同步位是与每个数据包传输的两个或三个特殊位。它们是起始位和停止位。
异步通信没有时钟线，只能在数据的头和尾加入标志位来区分不同的数据帧，接收数据之前也要预先知道波特率的大小，传输效率比同步通信要低。

### 串口(UART)

串口, 即串行接口, 与之相对应的另一种接口叫并口, 并行接口。
单片机的串口指的就是UART或USART
Serial.print("motor2="); //直接打印
Serial.println(motor2); //ln换行打印
Serial.begin(9600); //开启串口  设置波特率9600
Serial.print 和 Serial.println 将发回实际的ASCII代码, 而 Serial.write 将返回实际的文本

### 内部集成电路(I2C)

一主多从   同步通信   高速100 Kb/sec   短距离(几米之内)
I2C总线由两个信号组成 - SCL和SDA。SCL是时钟信号 SDA是数据信号。当前总线主机总是产生时钟信号。
我们有两种模式 - 主代码和从代码 - 使用I2C连接两个Arduino板
Master Transmitter / Slave Receiver 主发射器/从接收器  主机
Master Receiver / Slave Transmitter 主接收器/从发射器  从机

## Arduino项目 外设使用

看例程  调函数  现学现卖

## Arduino电机控制

有三种不同类型的电机: DC motor 直流电机 Servo motor 伺服电机 Stepper motor 步进电机
警告 - 不要直接从Arduino板引脚驱动电机。这可能会损坏电路板。使用驱动电路或IC

### 直流电机

旋转方向控制  为了控制直流电机的旋转方向而无需互换引线, 可以使用称为H桥的电路。H桥是可以双向驱动电机的电子电路。

### 伺服电机 舵机

伺服电机是一种有输出轴的小型设备。通过向伺服发送编码信号，可以将该轴定位到特定的角度位置。
只要编码信号存在于输入线上，伺服将保持轴的角位置。如果编码信号改变，则轴的角位置改变。
实际上，伺服用于无线电控制的飞机中来定位控制面，如升降舵和方向舵。
轻负载伺服不会消耗太多能量。
如果轴处于正确的角度，则电机关闭。如果电路发现角度不正确，则会转动电机直到处于所需的角度。
控制线用于传达角度。该角度由施加到控制线的脉冲持续时间确定。这称为脉冲编码调制。

### 步进电机

常规的直流电动机只在方向上旋转，而步进电动机可以以精确的增量旋转。
步进电机可以根据需要转动精确的度数（或步长）。这使你可以完全控制电机，允许你将其移动到精确的位置并保持在该位置
它通过为电机内部的线圈非常短时间的供电来实现。缺点是你必须给电机一直供电，以将它保持在你想要的位置。
可以用在打印机喷头控制上
