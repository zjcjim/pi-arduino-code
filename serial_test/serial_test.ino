void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    unsigned int x = Serial.read();
    char* pt = (char*)&x;
    Serial.print(pt[0]);
    Serial.print(pt[1]);
    Serial.print(pt[2]);
    Serial.print(pt[3]);
  }
}
