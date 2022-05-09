#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 4 // NeoPixel ring size
#define PIN 13

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

///부저를 통해 소리 낼 음계
#define NOTE_C0 0
#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_D4 293
#define NOTE_E4 330
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_C7 2093
#define NOTE_G6 1568
#define NOTE_G7 3136
int scale[] = { NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3,
NOTE_B3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E7, NOTE_F7, NOTE_C7, NOTE_G6, NOTE_G7, NOTE_C0};

//melody->음 높낮이, durations -> 음 길이
int melody[] = {10, 10, 15, 10, 15, 12, 10, 15, 14, 15, 15, 15, 13, 15, 15, 15};
int durations[] = { 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12 };

int noteLength = sizeof(melody) / sizeof(int);
int cm = 0;      //초음파 센서를 통한 거리 측정을 위한 기본 설정

#define BUZZER 4

//초음파 센서를 통한 거리 측정 함수
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup() {

  Serial.begin(9600);
  Serial.println("오토라이트 on");
  pixels.begin();
  pixels.clear();

  //부저 초기 설정
  pinMode(BUZZER, OUTPUT);

  pixels.show();
}

boolean ledRState = true;
int count = 0;

void loop() {
  
  cm = 0.01723 * readUltrasonicDistance(12, 14);
  
  Serial.print("접근 물체 거리: ");
  Serial.print(cm);
  Serial.println("cm");
  
  delay(100); // Wait for 100 millisecond(s)

  if (cm < 6) { //6센치 이하로 누군가가 접근하면
    pixels.setBrightness(255);
    pixels.setPixelColor(0, pixels.Color(250, 0, 0));
    pixels.setPixelColor(1, pixels.Color(250, 0, 0));
    pixels.setPixelColor(2, pixels.Color(250, 0, 0));
    pixels.setPixelColor(3, pixels.Color(250, 0, 0));
    pixels.show();

    if (count < 1) { //count 변수를 통해 첫 접근에만 소리가 나도록 함
      for (int i = 0; i < noteLength; i++) {
        int d = 1000 / durations[i];

        tone(BUZZER, scale[melody[i]], d);
        delay(d * 1.3);

        noTone(BUZZER);
      }
      count++;
    }

    Serial.println("!!!!!!초근접 접근 감지!!!!!!");
  } else {
    pixels.setBrightness(255);
    pixels.setPixelColor(0, pixels.Color(74, 205, 34));
    pixels.setPixelColor(1, pixels.Color(74, 205, 34));
    pixels.setPixelColor(2, pixels.Color(74, 205, 34));
    pixels.setPixelColor(3, pixels.Color(74, 205, 34));
    pixels.show();
  }
}