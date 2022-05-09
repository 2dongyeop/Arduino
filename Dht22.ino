#include "DHT.h"

#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT22 sensor test!"));
  
  dht.begin();
}

void loop() {
  delay(2000);
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT22 sensor error!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("% Temperature: ");
  Serial.print(temperature);
  Serial.println();
}