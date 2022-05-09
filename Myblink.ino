void setup() {
  Serial.begin(9600);
  Serial.println("프로그램 시작");

  Serial.print("HIGH : ");
  Serial.println(HIGH);
  Serial.print("LOW : ");
  Serial.println(LOW);

  Serial.print("true : ");
  Serial.println(true);
  Serial.print("false : ");
  Serial.println(false);

  pinMode(LED_BUILTIN, OUTPUT);
}

//LED 상태를 저장하는 ledState 변수의 선언 및 초기화
boolean ledState = true;

void loop() {
  Serial.print("ledState = ");
  Serial.println(ledState);

  digitalWrite(LED_BUILTIN, ledState);

  if (ledState == true) {
    ledState = false;
  } else {
    ledState = true;
  }
  //ledState = !ledState;

  delay(1000);
}