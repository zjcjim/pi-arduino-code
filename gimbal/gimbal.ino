#include <AFMotor.h>
#include <Servo.h>

unsigned long startTime;
unsigned long endTime;
unsigned long elapsedTime;

int position_x, position_y;
char dataArray[50];
int checksum = 0;
int previous_status[6];

int pos1 = 90;
int pos2 = 90;

int speed1 = 0;
int speed2 = 0;
int speed3 = 0;
int speed4 = 0;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);  // The motor number, i.e. 1, 2, 3 or 4
Servo servo1;
Servo servo2;

void stop();
void update_servo_position(int x, int y);
void motor_control(int speed1, int speed2, int speed3, int speed4);

void setup() {
    Serial.begin(9600);
    motor1.setSpeed(100);
    motor2.setSpeed(100);
    motor3.setSpeed(100);
    motor4.setSpeed(100);  // Default maximum speed
    servo1.attach(10);
    servo2.attach(9);

    servo1.write(90);
    servo2.write(90);
}

void loop() {
    // 4 * motor speed(int) + 2 * servo angle(float)

    if (Serial.available()) {
        // 读取一行数据，直到换行符'\n'
        startTime = millis();

        String data = Serial.readStringUntil('\n');

        
        endTime = millis();
        elapsedTime = endTime - startTime;

        data.toCharArray(dataArray, 50);

        // 使用sscanf解析数据
        sscanf(dataArray, "%d %d %d %d %d %d %d", &speed1, &speed2, &speed3, &speed4, &position_x, &position_y, &checksum);

        
        // 打印解析后的数据
        if (checksum == speed1 + speed2 + speed3 + speed4 + position_x + position_y) {
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
            
            Serial.print(" Time: ");
            Serial.print(elapsedTime);
            Serial.print("\n");

            update_servo_position(position_x, position_y);
            motor_control(speed1, speed2, speed3, speed4);

            previous_status[0] = speed1;
            previous_status[1] = speed2;
            previous_status[2] = speed3;
            previous_status[3] = speed4;
            previous_status[4] = position_x;
            previous_status[5] = position_y;
        } else {
            Serial.print("Checksum error: ");
            Serial.print(checksum);
            Serial.print(" speed1: ");
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

            update_servo_position(previous_status[4], previous_status[5]);
            motor_control(previous_status[0], previous_status[1], previous_status[2], previous_status[3]);
        }

        while (Serial.read() >= 0) {
            // Clear the buffer
        }
    }
}

void motor_control(int speed1, int speed2, int speed3, int speed4) {
    if (speed1 > 0) {
        motor1.setSpeed(speed1);
        motor1.run(FORWARD);
    } else if (speed1 < 0) {
        motor1.setSpeed(-speed1);
        motor1.run(BACKWARD);
    } else {
        motor1.run(RELEASE);
    }

    if (speed2 > 0) {
        motor2.setSpeed(speed2);
        motor2.run(FORWARD);
    } else if (speed2 < 0) {
        motor2.setSpeed(-speed2);
        motor2.run(BACKWARD);
    } else {
        motor2.run(RELEASE);
    }

    if (speed3 > 0) {
        motor3.setSpeed(speed3);
        motor3.run(FORWARD);
    } else if (speed3 < 0) {
        motor3.setSpeed(-speed3);
        motor3.run(BACKWARD);
    } else {
        motor3.run(RELEASE);
    }

    if (speed4 > 0) {
        motor4.setSpeed(speed4);
        motor4.run(FORWARD);
    } else if (speed4 < 0) {
        motor4.setSpeed(-speed4);
        motor4.run(BACKWARD);
    } else {
        motor4.run(RELEASE);
    }
}

void stop() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void update_servo_position(int x, int y) {
    // Map the x coordinate to the servo2 position (left/right)
    pos2 = x;
    pos1 = y;

    servo2.write(pos2);

    // Map the y coordinate to the servo1 position (up/down)

    servo1.write(pos1);

    // maybe problem here
    // Serial.print(pos1);
    // Serial.println(pos2);
}
