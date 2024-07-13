#define NOTE_D0 -1 
#define NOTE_D1 294 
#define NOTE_D2 330 
#define NOTE_D3 350 
#define NOTE_D4 393 
#define NOTE_D5 441 
#define NOTE_D6 495 
#define NOTE_D7 556 
 
#define NOTE_DL1 147 
#define NOTE_DL2 165 
#define NOTE_DL3 175 
#define NOTE_DL4 196 
#define NOTE_DL5 221 
#define NOTE_DL6 248 
#define NOTE_DL7 278 
 
#define NOTE_DH1 589 
#define NOTE_DH2 661 
#define NOTE_DH3 700 
#define NOTE_DH4 786 
#define NOTE_DH5 882 
#define NOTE_DH6 990 
#define NOTE_DH7 112  
//���ϲ����Ƕ����ǰ�ÿ��������Ƶ��ֵ��Ӧ��������ʵ���ô���ô�࣬���Ƕ������ˣ�������������д
 
#define WHOLE 1 
#define HALF 0.5 
#define QUARTER 0.25 
#define EIGHTH 0.25 
#define SIXTEENTH 0.625  
//�ⲿ������Ӣ�Ķ�Ӧ�����ӣ���������Ҳ�ȽϺÿ�
 
 
int tune[] =  
{  
 NOTE_D0,NOTE_D0,NOTE_D0,NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_D7,NOTE_DH1,NOTE_DH3,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D3,NOTE_D3,
 NOTE_D6,NOTE_D5,NOTE_D6,NOTE_DH1,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D3,NOTE_D4,NOTE_D3,NOTE_D4,NOTE_DH1,
 NOTE_D3,NOTE_D3,NOTE_D0,NOTE_DH1,NOTE_DH1,NOTE_DH1,NOTE_D7,NOTE_D4,NOTE_D4,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D0,NOTE_D6,NOTE_D7,
 NOTE_DH1,NOTE_D7,NOTE_DH1,NOTE_DH3,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D3,NOTE_D3,NOTE_D6,NOTE_D5,NOTE_D6,NOTE_DH1,
 NOTE_D5,NOTE_D5,NOTE_D5,NOTE_D2,NOTE_D3,NOTE_D4,NOTE_DH1,NOTE_D7,NOTE_D7,NOTE_DH1,NOTE_DH1,NOTE_DH2,NOTE_DH2,NOTE_DH3,NOTE_DH1,NOTE_DH1,NOTE_DH1,
 NOTE_DH1,NOTE_D7,NOTE_D6,NOTE_D6,NOTE_D7,NOTE_D5,NOTE_D6,NOTE_D6,NOTE_D6,NOTE_DH1,NOTE_DH2,NOTE_DH3,NOTE_DH2,NOTE_DH3,NOTE_DH5,
 NOTE_DH2,NOTE_DH2,NOTE_DH2,NOTE_D5,NOTE_D5,NOTE_DH1,NOTE_D7,NOTE_DH1,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,
 NOTE_D6,NOTE_D7,NOTE_DH1,NOTE_D7,NOTE_DH2,NOTE_DH2,NOTE_DH1,NOTE_D5,NOTE_D5,NOTE_D5,NOTE_DH4,NOTE_DH3,NOTE_DH2,NOTE_DH1,
 NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH6,NOTE_DH6,NOTE_DH5,NOTE_DH5,NOTE_DH3,NOTE_DH2,NOTE_DH1,NOTE_DH1,NOTE_D0,NOTE_DH1,
 NOTE_DH2,NOTE_DH1,NOTE_DH2,NOTE_DH2,NOTE_DH5,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH3,NOTE_DH6,NOTE_DH6,NOTE_DH5,NOTE_DH5,
 NOTE_DH3,NOTE_DH2,NOTE_DH1,NOTE_DH1,NOTE_D0,NOTE_DH1,NOTE_DH2,NOTE_DH1,NOTE_DH2,NOTE_DH2,NOTE_D7,NOTE_D6,NOTE_D6,NOTE_D6,NOTE_D6,NOTE_D7
};//�ⲿ�־����������ӵ��������֣�����һ�����ж���Ϊtune������
 
float duration[]= 
 
{  
  1,1,1,0.5,0.5,     1+0.5,0.5,1,1,     1,1,1,0.5,0.5,
  1+0.5,0.5,1,1,     1,1,1,1,          1+0.5,0.5,1,1, 
  1,1,0.5,0.5,0.5,0.5,    1+0.5,0.5,1,1,     1,1,1,0.5,0.5,
  1+0.5,0.5,1,1,    1,1,1,0.5,0.5,     1+0.5,0.5,1,1,
  1,1,1,0.5,0.5,    1,0.5,0.25,0.25,0.25,0.5,    0.5,0.5,0.5,0.25,0.5,1,
  0.5,0.5,0.5,0.5,1,1,    1,1,1,0.5,0.5,    1+0.5,0.5,1,1,
  1,1,1,0.5,0.5,    1.5,0.5,1,1,    1,1,1,1,
  0.5,0.5,1,1,0.5,0.5,    1.5,0.25,0.5,1,    1,1,1,1,
  1,1,1,1,    1,1,1,1,    0.5,0.5,1,1,0.5,0.5,
  1,0.5,0.5,1,1,    1,1,1,1,    1,1,1,1,
  0.5,0.5,1,1,0.5,0.5,    1,0.5,0.25,0.5,1,    1,1,1,0.5,0.5
};//�ⲿ�����������ӵĽ��Ĳ��֣�Ҳ���������duration�����㣨����ĸ�����ǰ�������ĸ�����һ���ģ�һһ��Ӧô��
 
int length;//���ﶨ��һ������������������ʾ���ж��ٸ�����
 
int tonePin=30;//��������pin 
 
 
void setup() 
 
{  
  pinMode(tonePin,OUTPUT);//���÷�������pinΪ���ģʽ
 
  length = sizeof(tune)/sizeof(tune[0]);//��������һ��sizeof������ ���Բ��tone�������ж��ٸ�����
 
} 
 
void loop() 
 
{  
 
  for(int x=0;x<length;x++)//ѭ�������Ĵ���
  {  
    tone(tonePin,tune[x]);//�˺������β���tune����������飬��ÿ�� ����
 
 delay(400*duration[x]);//ÿ������������ʱ�䣬������duration���ǵ���ʱ���Խ�������ٶ�Խ����ԽС�����ٶ�Խ�죬�Լ����հ�
 
noTone(tonePin);//ֹͣ��ǰ������������һ����
 
  } 
  delay(5000);//�ȴ�5���ѭ�����¿�ʼ
}
