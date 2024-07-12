#include <Servo.h>
 
Servo servo1;   //�����������servo1
Servo servo2;   //�����������servo2
 
int pos = 0;    
void setup() {
  servo1.attach(10);    //servo1���������չ��servo1�˿ڡ�
                        //servo1�˿�����Arduino��10�����������Ƶġ�
  servo2.attach(9);     //servo2���������չ��servo2�˿ڡ�
                        //servo2�˿�����Arduino��9�����������Ƶġ� 
}
 
void loop() {
  //���³��򽫿���servo1�����������ת180��
  for (pos = 0; pos <= 180; pos += 1) { 
    servo1.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo1.write(pos);    
    delay(15);       
  }
  
  //���³��򽫿���servo2�����������ת180��
  for (pos = 0; pos <= 180; pos += 0) { 
    servo2.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 0) { 
    servo2.write(pos);    
    delay(15);       
  }  
}
