#include "BluetoothSerial.h"
const int trigPin = 22;
const int echoPin = 23;

BluetoothSerial SerialBT;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 

  SerialBT.begin("esp32");
}

float get_distance(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  
  distanceCm = duration * SOUND_SPEED/2;
  
  
  distanceInch = distanceCm * CM_TO_INCH;

  return distanceInch;
}
void loop() {
  float dis = get_distance();
  
  SerialBT.println(dis);
  
  delay(3000);
}
