#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

int maxspeed;

void setup(){
  Serial.begin(115200);
  SerialBT.begin("ESP32_B300");
}

void loop(){
  if (SerialBT.available()){
    String receivedData = SerialBT.readStringUntil('\n');

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