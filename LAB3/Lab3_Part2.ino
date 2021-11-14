#include <Adafruit_BMP085.h>
#include <Wire.h>


#define I2C_SCL 4
#define I2C_SDA 19
Adafruit_BMP085 bmp;
TwoWire I2CBMP = TwoWire(0);
void setup() {
  //TwoWire I2CBMP = TwoWire(0);
  Serial.begin(9600);
  I2CBMP.begin(I2C_SDA, I2C_SCL, 100000);
  bmp.begin(0x76,&I2CBMP);
  
}
  
void loop() {
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(2000);
}
