int PIN_SENSOR = 40;

void setup() {
  pinMode(PIN_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int x = digitalRead(PIN_SENSOR);
  Serial.println(x);
  delay(50);
}
