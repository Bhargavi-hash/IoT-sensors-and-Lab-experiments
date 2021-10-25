#define POWER_PIN  17 
#define SIGNAL_PIN A0 
#define SENSOR_MIN 0
#define SENSOR_MAX 521
#define BuzzPin 18
#define TouchPin 27

const int Touch_threshold = 25;
const int Water_threshold = 1000;

int value = 0; // variable to store the sensor value
int level = 0; // variable to store the water level

void setup() {
  Serial.begin(9600);
  pinMode(BuzzPin, OUTPUT);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
}

void loop() {
  //digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  //delay(10);                      // wait 10 milliseconds
  //value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  //digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  int touchValue = touchRead(TouchPin);

  if(touchValue < Touch_threshold){
    digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF
    level = map(value, SENSOR_MIN, SENSOR_MAX, 0, 4); // 4 levels
    Serial.print("Water level: ");
    Serial.println(level);

  }

  if(value > Water_threshold){
    Serial.print("Sensor value: ");
    Serial.println(value);
    digitalWrite(BuzzPin, HIGH);
  }
  else
  {
    digitalWrite(BuzzPin, LOW);
  }
  
  delay(1000);
}
