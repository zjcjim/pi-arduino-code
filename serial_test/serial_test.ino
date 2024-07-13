int motor1, motor2, motor3, motor4;
float position_x, position_y;

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
        // Serial.println("Received: " + data);
        // 提取整数
        motor1 = data.substring(0, data.indexOf('M')).toInt();
        data = data.substring(data.indexOf('M') + 2);  // "20MB30MC40MD0.1SA0.2SB"

        motor2 = data.substring(0, data.indexOf('M')).toInt();
        data = data.substring(data.indexOf('M') + 2);  // "30MC40MD0.1SA0.2SB"

        motor3 = data.substring(0, data.indexOf('M')).toInt();
        data = data.substring(data.indexOf('M') + 2);  // "40MD0.1SA0.2SB"

        motor4 = data.substring(0, data.indexOf('M')).toInt();
        data = data.substring(data.indexOf('M') + 2);  // "0.1SA0.2SB"

        // 提取浮点数
        position_x = data.substring(0, data.indexOf('S')).toFloat();
        data = data.substring(data.indexOf('S') + 2);  // "0.2SB"

        position_y = data.substring(0, data.indexOf('S')).toFloat();

        // 打印结果
        Serial.print("motor1: ");
        Serial.print(motor1);
        Serial.print("motor2: ");
        Serial.print(motor2);
        Serial.print("motor3: ");
        Serial.print(motor3);
        Serial.print("motor4: ");
        Serial.print(motor4);

        Serial.print("servo1: ");
        Serial.print(position_x, 2);
        Serial.print("servo2: ");
        Serial.println(position_y, 2);
    }
}
