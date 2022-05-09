int ledR = 16;
int ledG = 5;


void setup() {
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);

  digitalWrite(ledR, LOW);
  digitalWrite(ledG, HIGH);

}

// 센서 값을 저장할 변수 inputValue의 선언 및 초기화
int inputValue = 0;
boolean ledRState = false;
boolean ledGState = true;


void loop() {
  inputValue = analogRead(A0);
  Serial.println(inputValue);

  if (inputValue > 500) { //매우 어두울 때
    ledRState = true;
    ledGState = true;
  } else if (inputValue > 250) { //어두울 때
    ledRState = false;
    ledGState = true;
  } else { //밝을 때
    ledRState = false;
    ledGState = false;
  }

  digitalWrite(ledR, ledRState);
  digitalWrite(ledG, ledGState);

  delay(1000);
}