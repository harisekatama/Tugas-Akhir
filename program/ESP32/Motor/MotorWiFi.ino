#include <WiFi.h>
#include <Arduino.h>

//Motor Kiri
#define pwmpin1 5
#define dir1  18
#define dir2  19

//Motor kanan
#define pwmpin2 25
#define dir3 32
#define dir4 33

//STATE Motor
int stdir[4];

#define pwmChannel1  0
#define pwmChannel2  1
#define freq  15000
#define res  8

int PWM1_DutyCycle = 0;
int maxspeed = 50;
int turnspeed = 30;

const char* ssid = "STARLINK-548";
const char* password = "crni6711";

WiFiServer server(80);

void setup() {
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  //pinMode(pwmpin,OUTPUT);

  ledcSetup(pwmChannel1, freq, res);
  ledcSetup(pwmChannel2, freq, res);

  ledcAttachPin(pwmpin1, pwmChannel1);
  ledcAttachPin(pwmpin2, pwmChannel2);

  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("ESP32 IP Address : ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (client) {
    //Serial.println("New client connected");
    
    // Read the data from the client
    while (client.connected()) {
      if (client.available()) {
        char data = client.read();
        char dataTemp;
        Serial.println(data);

        if(data == 'A'){
          while(PWM1_DutyCycle <= turnspeed){
            stdir[0] = LOW;
            stdir[1] = LOW;
            stdir[2] = HIGH;
            stdir[3] = LOW;

            digitalWrite(dir1, stdir[0]);
            digitalWrite(dir2, stdir[1]);
            digitalWrite(dir3, stdir[2]);
            digitalWrite(dir4, stdir[3]);
            ledcWrite(pwmChannel1, PWM1_DutyCycle++);
            ledcWrite(pwmChannel2, PWM1_DutyCycle++);
            delay(10);
            }

          }

        else if (data == 'B'){
          while(PWM1_DutyCycle <= maxspeed){
            stdir[0] = HIGH;
            stdir[1] = LOW;
            stdir[2] = HIGH;
            stdir[3] = LOW;

            digitalWrite(dir1, stdir[0]);
            digitalWrite(dir2, stdir[1]);
            digitalWrite(dir3, stdir[2]);
            digitalWrite(dir4, stdir[3]);
            ledcWrite(pwmChannel1, PWM1_DutyCycle++);
            ledcWrite(pwmChannel2, PWM1_DutyCycle++);
            delay(10);
            }

          }
        else if(data == 'C'){ 
          while(PWM1_DutyCycle >= 0){

            digitalWrite(dir1, stdir[0]);
            digitalWrite(dir2, stdir[1]);
            digitalWrite(dir3, stdir[2]);
            digitalWrite(dir4, stdir[3]);
            ledcWrite(pwmChannel1, PWM1_DutyCycle--);
            ledcWrite(pwmChannel2, PWM1_DutyCycle--);
            delay(10);
            }
          }
        else if (data == 'D'){
            while(PWM1_DutyCycle <= turnspeed){
              stdir[0] = LOW;
              stdir[1] = HIGH;
              stdir[2] = LOW;
              stdir[3] = HIGH;

              digitalWrite(dir1, stdir[0]);
              digitalWrite(dir2, stdir[1]);
              digitalWrite(dir3, stdir[2]);
              digitalWrite(dir4, stdir[3]);
              ledcWrite(pwmChannel1, PWM1_DutyCycle++);
              ledcWrite(pwmChannel2, PWM1_DutyCycle++);
              delay(10);
              }

            }
        else if(data == 'E'){
            while(PWM1_DutyCycle <= turnspeed){
              stdir[0] = HIGH;
              stdir[1] = LOW;
              stdir[2] = LOW;
              stdir[3] = LOW;

              digitalWrite(dir1, stdir[0]);
              digitalWrite(dir2, stdir[1]);
              digitalWrite(dir3, stdir[2]);
              digitalWrite(dir4, stdir[3]);
              ledcWrite(pwmChannel1, PWM1_DutyCycle++);
              ledcWrite(pwmChannel2, PWM1_DutyCycle++);
              delay(10);
              }

            }
                }
                }

    // Close the connection
    client.stop();
    //Serial.println("Client disconnected");
  }
}