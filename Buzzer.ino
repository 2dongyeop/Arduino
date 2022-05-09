#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
int scale[] = { NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4 };

//반짝반짝 작은별 -> 도도 솔솔 라라 솔 파파 미미 레레 도;
//int melody[] = { 7, 4, 4, 5, 5, 6, 7 };
//int durations[] = { 4, 8, 8, 4, 2, 4, 4 };
int melody[] = { 0, 0, 4, 4, 5, 5, 4, 3, 3, 2, 2, 1, 1, 0, 4, 4, 3, 3, 2, 2, 1, 4, 4, 3, 3, 2, 2, 1, 0, 0, 4, 4, 5, 5, 4, 3, 3, 2, 2, 1, 1, 0};
int durations[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2};

int noteLength = sizeof(melody) / sizeof(int);

#define BUZZER 4

void setup() {
  pinMode(BUZZER, OUTPUT);

}

void loop() {
  for (int i = 0; i < noteLength; i++) {
    int d = 1000 / durations[i];

    tone(BUZZER, scale[melody[i]], d);
    delay(d * 1.3);

    noTone(BUZZER);
  }
  delay(10000);
}