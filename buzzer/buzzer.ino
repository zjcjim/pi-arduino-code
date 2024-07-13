int pinBuzzer = 30;  // Define pinBuzzer as pin D3 for connecting the buzzer module

// Define frequencies for the notes
int A4s = 466;
int B4 = 494;
int C5 = 523;
int C5s = 554;
int D5 = 587;
int D5s = 622;
int E5 = 659;
int F5 = 698;
int F5s = 740;
int G5 = 784;
int G5s = 831;
int A55 = 880;
int A55s = 932;
int B5 = 988;
int C6 = 1047;
int C6s = 1109;
int D6 = 1175;
int D6s = 1245;
int E6 = 1319;
int F6 = 1397;
int F6s = 1480;
int stop = 0;

void playNoteSequence();
void playNote(int note);
void playNote05(int note);
void playNote15(int note);
void playNote2(int note);

void setup() {
  pinMode(pinBuzzer, OUTPUT);  // Set pinBuzzer as an output pin
}

void loop() {
  playNoteSequence();
  noTone(pinBuzzer);
  delay(2000);  // Delay before repeating the song
}

void playNoteSequence() {
  playNote(B5);
  playNote(A55s);
  playNote(F5s);
  playNote(F5s);
  playNote05(G5s);
  playNote15(G5s);
  playNote(F5s);
  playNote(F5s);
  playNote05(G5s);
  playNote15(G5s);
  playNote(F5s);
  playNote(F5s);
  playNote05(F5s);
  playNote15(G5s);
  playNote(G5s);
  playNote(G5s);
  playNote(A55s);
  playNote(B5);
  playNote(C6s);
  playNote2(A55s);
  playNote2(F5s);
  playNote2(E6);
  playNote2(C6s);
  playNote15(C6s);
  playNote15(C6s);
  playNote(D6s);
  noTone(pinBuzzer);
  delay(200);

  playNote(B5);
  playNote(A55s);
  playNote(F5s);
  playNote(F5s);
  playNote05(G5s);
  playNote15(G5s);
  playNote(F5s);
  playNote(F5s);
  playNote05(G5s);
  playNote15(G5s);
  playNote(F5s);
  playNote(F5s);
  playNote05(G5s);
  playNote15(G5s);
  playNote(G5s);
  playNote(G5s);
  playNote(A55s);
  playNote(B5);
  playNote(C6s);
  playNote15(A55s);
  playNote15(G5s);
  playNote(D5s);
  noTone(pinBuzzer);
  delay(200);
}

void playNote(int note) {
 tone(pinBuzzer, note);
 delay(200); // Adjust this delay to control the length of each note
 noTone(pinBuzzer);
 delay(20); // Short pause between notes
}
void playNote05(int note) {
 tone(pinBuzzer, note);
 delay(100); // Adjust this delay to control the length of each note
 noTone(pinBuzzer);
 delay(20); // Short pause between notes
}
void playNote2(int note) {
 tone(pinBuzzer, note);
 delay(400); // Adjust this delay to control the length of each note
 noTone(pinBuzzer);
 delay(20); // Short pause between notes
}
void playNote15(int note) {
 tone(pinBuzzer, note);
 delay(300); // Adjust this delay to control the length of each note
 noTone(pinBuzzer);
 delay(20); // Short pause between notes
}
