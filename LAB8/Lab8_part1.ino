#include "PubSubClient.h"
#include"WiFi.h"
#include"ThingSpeak.h"

#define POWER_PIN  23 // ESP32 pin GIOP23 connected to sensor's VCC pin
#define SIGNAL_PIN A0 // ESP32 pin GIOP36 (ADC0) connected to sensor's signal pin

const char* ssid = "Bhargavi";
const char* password =  "09262525";

char* topic = "channels/1578876/publish/T34JC4VAVB0WMM1Y"; //channels/<channelID>/publish/API
char* server = "mqtt.thingspeak.com";

WiFiClient wifiClient;
PubSubClient client(server, 1883, wifiClient);

void callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived
}


void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);
  
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  String clientName="ESP-Thingspeak";
  Serial.print("Connecting to ");
  Serial.print(server);
  Serial.print(" as ");
  Serial.println(clientName);
  
  if (client.connect((char*) clientName.c_str())) {
    Serial.println("Connected to MQTT broker");
    Serial.print("Topic is: ");
    Serial.println(topic);
    
    if (client.publish(topic, "hello from ESP8266")) {
      Serial.println("Publish ok");
    }
    else {
      Serial.println("Publish failed");
    }
  }
  else {
    Serial.println("MQTT connect failed");
    Serial.println("Will reset and try again...");
    abort();
  }
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);
  delay(10);
  int value = analogRead(SIGNAL_PIN);
  digitalWrite(POWER_PIN, LOW);
    
  static int counter = 0;
  String payload="field1=";
  payload+=value;
  payload+="&status=MQTTPUBLISH";
  
  if (client.connected()){
    Serial.print("Sending payload: ");
    Serial.println(payload);
    
    if (client.publish(topic, (char*) payload.c_str())) {
      Serial.println("Publish ok");
    }
    else {
      Serial.println("Publish failed");
    }
  }
  ++counter;
  delay(10000);
}
