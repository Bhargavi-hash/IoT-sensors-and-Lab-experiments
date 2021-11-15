#include "WiFi.h"
#include <WebServer.h>
#include "HTTPClient.h"
#include "time.h"
#include <ArduinoJson.h>

#define pirPin 19

char* ssid = "Bhargavi";
char* password = "09262525";

String cse_ip = "192.168.1.7";
String cse_port = "8080";
String server = "http://" + cse_ip + ":" + cse_port + "/~/in-cse/in-name/";
String ae = "pir_sensor";
String cnt = "node1";

void createCI(String& val){
  // add the lines in step 3-6 inside this function
  HTTPClient http;
  http.begin(server + ae + "/" + cnt + "/");
  http.addHeader("X-M2M-Origin", "admin:admin");
  http.addHeader("Content-Type", "application/json;ty=4");

  int code = http.POST("{\"m2m:cin\": {\"cnf\":\"application/json\",\"con\": " + String(val) + "}}");

  Serial.println(code);
  if (code == -1) {
    Serial.println("UNABLE TO CONNECT TO THE SERVER");
  }
  http.end();

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  
  Serial.print("Try Connecting to ");
  Serial.println(ssid);
  
  delay(500);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  

}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(pirPin);
  String val =  (String)state;
  createCI(val);
  delay(1000);

}
