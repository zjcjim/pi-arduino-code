#include <AFMotor.h>
#include <Servo.h>

float x, y;
int pos1 = 90;
int pos2 = 90;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);  // The motor number, i.e. 1, 2, 3 or 4
Servo servo1;
Servo servo2;

void forward();
void backward();
void turn_left();
void turn_right();
void stop();
void update_servo_position(int x, int y);

void setup() {
  Serial.begin(9600);
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);  // Default maximum speed
  servo1.attach(10);
  servo2.attach(9);
}

void loop() {

    // 4 * motor speed(int) + 2 * servo angle(float)

    if (Serial.available() >= (4 * sizeof(int) + 2 * sizeof(float))) { 
    // Read the coordinates
    speed1 = Serial.parseInt();
    speed2 = Serial.parseInt();
    speed3 = Serial.parseInt();
    speed4 = Serial.parseInt();

    x = Serial.parseFloat();
    y = Serial.parseFloat();

    // Control the car's movement based on the x coordinate
    // if (x > 0.5) {
    //   turn_right();
    //   Serial.println("Turning right");
    // } else if (x < -0.5) {
    //   turn_left();
    //   Serial.println("Turning left");
    // } else {
    //   stop();
    //   Serial.println("Stopped");
    // }

    // Control the servos' position based on the x and y coordinates
    update_servo_position(x, y);
  }
}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void turn_left() {
  motor1.run(BACKWARD);
  motor4.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
}

void turn_right() {
  motor1.run(FORWARD);
  motor4.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
}

void stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void update_servo_position(int x, int y) {
  // Map the x coordinate to the servo2 position (left/right)
  pos2 = 90 - x * 90;
  servo2.write(pos2);
  delay(100);

  // Map the y coordinate to the servo1 position (up/down)
  pos1 =  90 - y * 90;
  servo1.write(pos1);
  delay(100);

  Serial.print("Servo1 position: ");
  Serial.print(pos1);
  Serial.print(", Servo2 position: ");
  Serial.println(pos2);
}
