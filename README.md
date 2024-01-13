# myhero 校内赛麦轮铲车

## 目标开发进度

1/11 重整旗鼓 完成底盘驱动 
1/12 装好其他机械结构 舵机驱动
1/13 调好舵机
1/14 整车调整 进行参数微调 练手
1/15 检查 练手 正式比赛

## 实际
1/13 刚刚解决底盘问题，机械装配基本完成


 

##开发中的问题


### Arduino烧了
- 现象:冒烟  异味  芯片严重发烫  vcc和gnd短路  
- 原因分析:锂电池下电早于单片机  导致单片机直接为四个电机供电  单片机供电功率过大  从而寄寄  
- 解决方案:购买新的2560  并且准备一片备用  
- 预防方案:谨记上下电顺序  时刻保护单片机  


### 电机驱动TB6612烧了
- 现象:冒烟  异味  芯片严重发烫  
- 原因分析:在测试电机的时候  使用锂电池直接上电  但是插错了方向  导致锂电池直接上电6612的输出口  从而寄寄  
- 解决方案:换新  准备2片DRV8833备用  


### 右侧轮有时不动/速度慢
- 现象:右侧轮有时不动/速度慢  貌似是接触不良  但是电机电压正常  重新插线后得到缓解  打上热熔胶固定不能解决  更换驱动芯片不能解决  
- 原因分析:接触不良  芯片重力导致的掉线  走线过于混乱  怀疑可能STBY掉线  
- 解决方案:将TB6612置于小车上方  重新走线固定  对所有固定好的线缠上胶布  


### 麦轮解算发现不能左右平移
- 现象:四个麦轮前后和小陀螺运动完全正常  但是左右运动寄寄  
- 原因分析:分析的不到位  过于依赖网上教程  与一开始的硬件配置问题有关  与CSDN的混乱建系方法也有关  
- 解决方案:装车完成后重调代码  注意参考资料的来源  


### 降压模块爆炸
- 现象:一开始接锂电池冒烟  此时对芯片进行了引脚焊接操作  接充电宝恢复正常  再次接锂电池芯片炸开  
- 原因分析:现象令人迷惑  无法排除焊接的嫌疑  但是最大的可能仍然是质量问题  
- 解决方案:购买换新  并且准备两片备用  


### 长时间对角线疯车
- 现象:对角线的两个轮子疯转  更换接线不改变对角线疯车现象  遥控器信号时好时环  总体表现信号不良  
- 原因分析:经多方提醒  最终发现和遥控器信号接受器接线接触不良有关  
- 解决方案:引出PS2遥控器接线并重新加固  


### 机械 3D打印件过于疲软
- 现象:摇摇欲坠  晃动明显  
- 原因分析:3D打印件太薄  与机械画图存在差别  铲斗过重  
- 解决方案:加厚  重新打印  


### 机械 联轴器滑丝
- 现象:螺丝一插到底  无法固定  
- 原因分析:钉子拧进去的过程中歪了  
- 解决方案:购买换新  并且准备三个备用  







