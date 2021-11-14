#include "DHT.h"

#define DHTPIN 4    
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(19200);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  //float t = dht.readTemperature();
  Serial.print(F("Humidity: "));
  Serial.print(h);
  
  delay(1000);
  
  float t = dht.readTemperature();
  
  Serial.print(F("% ;  Temperature: "));
  Serial.print(t);
  Serial.print("\n");
  delay(1000);
}
