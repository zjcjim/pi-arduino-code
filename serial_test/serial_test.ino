int motor1, motor2, motor3, motor4;
float position_x, position_y;

void setup() {
    // put your setup code here, to run once:
    // Serial.begin(9600);
    String data = "10MA20MB30MC40MD0.1SA0.2SB";
    char dataArray[30];
    data.toCharArray(dataArray, 30);

    // 使用sscanf解析数据
    sscanf(dataArray, "%dMA%dMB%dMC%dMD%fSA%fSB", &motor1, &motor2, &motor3, &motor4, &position_x, &position_y);
    // 打印解析后的数据
    Serial.print("motor1: ");
    Serial.print(motor1);
    Serial.print(" motor2: ");
    Serial.print(motor2);
    Serial.print(" motor3: ");
    Serial.print(motor3);
    Serial.print(" motor4: ");
    Serial.print(motor4);
    Serial.print(" position_x: ");
    Serial.print(position_x);
    Serial.print(" position_y: ");
    Serial.println(position_y);
}

void loop() {
    // put your main code here, to run repeatedly:
    // if (Serial.available()) {
    //     // 读取一行数据，直到换行符'\n'
    //     String data = Serial.readStringUntil('\n');
    //     // 打印读取到的数据
    //     Serial.print("Received: " + data);
    //     // 解析数据

    // }
}