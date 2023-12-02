#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Bluetooth device name
  delay(1000);  // Give some time for the Bluetooth module to initialize
}

void loop() {
  // Get the ESP32 Bluetooth address
  uint8_t esp32Address[6];
  esp_efuse_mac_get_default(esp32Address);

  // Print the address in a readable format
  Serial.printf("ESP32 Bluetooth Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                esp32Address[0], esp32Address[1], esp32Address[2],
                esp32Address[3], esp32Address[4], esp32Address[5]);

  // Your main code here
}