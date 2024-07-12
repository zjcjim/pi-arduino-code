                    //���弤�����ģ���ź�����Ϊ2
int SensorReading = HIGH;                 //���弤�����ģ���ź�����Ϊ�ߵ�ƽ
int Laser = 46;                           //���弤�ⷢ��ģ���ź�����Ϊ12
 
void setup() {

  pinMode(Laser, OUTPUT);                 //����LaserΪ���ģʽ
            //����LaserSensorΪ����ģʽ
}
 
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Laser, HIGH);             //��Laser�ߵ�ƽ�����ⷢ��ģʽ���伤��
  delay(200);                            //��ʱ200����
   digitalWrite(Laser, LOW);             //��Laser�ߵ�ƽ�����ⷢ��ģʽ���伤��
  delay(200);   
}
