int ledR = 16;
int ledG = 5;

void setup() {
  Serial.begin(9600);
  Serial.println("프로그램 시작");

  //신호등 핀 설정
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  
  //꺼짐으로 시작
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, HIGH);
}

boolean ledRState = false;
boolean ledGState = true;

void loop() {

  digitalWrite(ledR, ledRState);
  digitalWrite(ledG, ledGState);


  ledRState = !ledRState;
  ledGState = !ledGState;
  
  delay(2000);
}