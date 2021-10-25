#define TouchPin 27
#define BuzzPin 18

const int threshold = 25;


void setup() {

  pinMode(BuzzPin, OUTPUT);
  Serial.begin(9600);
  delay(1000); // give me time to bring up serial monitor
}

void loop() {

  int touchValue = touchRead(TouchPin);
  Serial.println(touchValue);  // get value of Touch 0 pin = GPIO 32

  if(touchValue < threshold){
    
    digitalWrite(BuzzPin, HIGH);
    Serial.println(" - Buzzer on");
  }
  else{
    
    digitalWrite(BuzzPin, LOW);
    Serial.println(" - Buzzer off");
  }
  delay(1000);
}
