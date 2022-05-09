void setup() {
  Serial.begin(9600);
  Serial.println("프로그램 시작");
}
int number = 1;

void loop() {
  Serial.print("number = ");
  Serial.println(number);

  number = number + 1;

  delay(5000);
}