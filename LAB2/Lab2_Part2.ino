#include "Servo.h"
#include "DHT.h"

Servo servol;

#define servoPin 13
int posDegrees = 0;

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(19200);
  servol.attach(servoPin);
  dht.begin();
}

void moveservo() {
  for(int posDegrees = 0; posDegrees <= 180; posDegrees++)
  {
    servol.write(posDegrees);
    //Serial.println(posDegrees);
    delay(20);
  }
  for(int posDegrees = 180; posDegrees >= 0; posDegrees--)
  {
    servol.write(posDegrees);
    //Serial.println(posDegrees);
    delay(20);
  }
}

void loop(){
  delay(3000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print("\n");

  if(h > 50 && t > 30)
  {
    moveservo();
  }
}
