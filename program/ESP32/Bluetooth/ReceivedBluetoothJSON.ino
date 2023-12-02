#include <BluetoothSerial.h>
#include <ArduinoJson.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT_JSON");
}

void loop() {
  if (SerialBT.available()) {
    // Read the incoming data
    String json_data = SerialBT.readStringUntil('\n');

    // Deserialize the JSON
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, json_data);

    if (error) {
      Serial.println("Failed to parse JSON");
    } else {
      // Extract values from JSON
      const char* arah = doc["arah"];
      const char* kecepatan = doc["kecepatan"];

      // Perform actions based on the received data
      Serial.print("Received Arah: ");
      Serial.println(arah);
      Serial.print("Received Kecepatan: ");
      Serial.println(kecepatan);
    }
  }
}