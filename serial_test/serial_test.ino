float x, y;
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    while (Serial.available() > 2 * sizeof(float)) {
        Serial.readBytes((char*)&x, sizeof(float));
        Serial.readBytes((char*)&y, sizeof(float));
        Serial.print("x: ");
        Serial.print(x);
        Serial.print(" y: ");
        Serial.println(y);
    }
}
