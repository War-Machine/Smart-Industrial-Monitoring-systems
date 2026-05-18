#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define GAS_SENSOR A0
#define BUZZER 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);

  dht.begin();

  Serial.println("Smart Industrial Monitoring System Started");
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int gasValue = analogRead(GAS_SENSOR);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > 400) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("Warning! Gas Leakage Detected!");
  } else {
    digitalWrite(BUZZER, LOW);
  }

  Serial.println("-------------------------");

  delay(2000);
}
