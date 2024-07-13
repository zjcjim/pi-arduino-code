int speed1, speed2, speed3, speed4;
int position_x, position_y;
char dataArray[30];

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    if (Serial.available()) {
        // 读取一行数据，直到换行符'\n'
        String data = Serial.readStringUntil('\n');

        data.toCharArray(dataArray, 30);

        // 使用sscanf解析数据
        sscanf(dataArray, "%d %d %d %d %d %d", &speed1, &speed2, &speed3, &speed4, &position_x, &position_y);
        // 打印解析后的数据
        Serial.print("speed1: ");
        Serial.print(speed1);
        Serial.print(" speed2: ");
        Serial.print(speed2);
        Serial.print(" speed3: ");
        Serial.print(speed3);
        Serial.print(" speed4: ");
        Serial.print(speed4);
        Serial.print(" position_x: ");
        Serial.print(position_x);
        Serial.print(" position_y: ");
        Serial.print(position_y);
        Serial.print("\n");
    }
}
