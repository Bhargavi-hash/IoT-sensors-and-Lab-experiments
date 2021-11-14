#include "BluetoothSerial.h"
const int trigPin = 22;
const int echoPin = 23;
const int buzzer = 18;

BluetoothSerial SerialBT;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

int th = 0;
void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);

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
  Serial.println(dis);
  if(SerialBT.available())
  {
    int temp = SerialBT.parseInt();
    if (temp > 0){
      th = temp;
      Serial.println("threshold updated");
      Serial.print(th);
    }
  }
    
  if (dis < th){
    digitalWrite(buzzer, HIGH);
    SerialBT.println("Close");
    Serial.println("Close");
  }
  else
  {
    digitalWrite(buzzer, LOW);
    SerialBT.println("far");
    Serial.println("far");
  }
  delay(3000);
}
