#include <WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>

const char* ssid = "iot_wireless"; // Your WiFi SSID
const char* password = "Unsecure!"; // Your WiFi password
const char* mqtt_server = "SamVafPi.local"; // MQTT broker address
const int mqtt_port = 1883;
const char* mqtt_topic = "sensor/moisture";

WiFiClient espClient;
PubSubClient client(espClient);

const long interval = 5000;
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    connect();
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int moistureValue = analogRead(A0); // Read moisture sensor value
    String message = "Moisture: " + String(moistureValue);

    client.loop();
    if (client.connected()) {
      client.publish(mqtt_topic, message.c_str());
      Serial.println("Moisture sent: " + message);
    }
  }
}

void connect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("Connected to MQTT broker");
      client.subscribe("control/watering");
    } else {
      Serial.print("Failed to connect to MQTT broker, rc=");
      Serial.print(client.state());
      Serial.println(" Try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  if (String(topic) == "control/watering") {
    if (message == "On") {
      // Simulated watering action
      Serial.println("Watering plants...");
      // Add your watering code here
    }
  }
}
