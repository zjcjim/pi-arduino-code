void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    if (Serial.available()) {
        // 读取一行数据，直到换行符'\n'
        String data = Serial.readStringUntil('\n');
        // 打印读取到的数据
        Serial.println("Received: " + data);
    }
}
