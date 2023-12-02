#include <WiFi.h>
#include <Arduino.h>

int maxspeed;

const char* ssid = "B300-Access-Point";
const char* password = "123456789";

WiFiServer server(80);

void setup(){
  Serial.begin(115200);


  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);
 
  IPAddress IP = WiFi.softAPIP();
  Serial.print("ESP32 AP IP Address : ");
  Serial.println(IP);

  // Start the server
  server.begin();
}

void loop(){
    // Check if a client has connected
  WiFiClient client = server.available();

  if (client) {
    //Serial.println("New client connected");
    
    // Read the data from the client
    while (client.connected()) {
      if (client.available()) {
    
        String receivedData = client.readStringUntil('\n');

        String data1 = receivedData.substring(0, receivedData.indexOf(','));
        String data2 = receivedData.substring(receivedData.indexOf(',') + 1);

        maxspeed = data2.toInt();

        Serial.print("Data 1 : ");
        Serial.println(data1);
        Serial.print("Data 2 : ");
        Serial.println(data2);

        if(maxspeed < 20){
          Serial.println("TRUE");
        }
        else{
          Serial.println("FALSE");
        }

      }
    }

    client.stop();

  }
}