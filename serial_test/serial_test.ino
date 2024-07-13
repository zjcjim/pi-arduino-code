int speed1, speed2, speed3, speed4;
int position_x, position_y;
char dataArray[30];

unsigned long startTime;
unsigned long endTime;
unsigned long elapsedTime;

String data;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    if (Serial.available()) {
        // 读取一行数据，直到换行符'\n'
        startTime = millis();

        while (Serial.available()) {
            char c = Serial.read();
            if (c == '\n') {
                break;
            }
            data += c;
        }

        Serial.print(data);

        endTime = millis();
        elapsedTime = endTime - startTime;

        Serial.print(" Time: ");
        Serial.print(elapsedTime);
        Serial.print("\n");

        // data.toCharArray(dataArray, 30);

        // // 使用sscanf解析数据
        // sscanf(dataArray, "%d %d %d %d %d %d", &speed1, &speed2, &speed3, &speed4, &position_x, &position_y);
        // // 打印解析后的数据
        // Serial.print("speed1: ");
        // Serial.print(speed1);
        // Serial.print(" speed2: ");
        // Serial.print(speed2);
        // Serial.print(" speed3: ");
        // Serial.print(speed3);
        // Serial.print(" speed4: ");
        // Serial.print(speed4);
        // Serial.print(" position_x: ");
        // Serial.print(position_x);
        // Serial.print(" position_y: ");
        // Serial.print(position_y);
        // Serial.print(" Time: ");
        // Serial.print(elapsedTime);
        // Serial.print("\n");
    }
}
