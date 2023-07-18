#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSyncWord(0xF3);
}

void loop() {
  float sensorValue;
  int send_data;
  sensorValue = analogRead(A0);
  Serial.print("sensorValue = ");
  Serial.println(sensorValue);
  if(sensorValue<900){
    send_data = int(sensorValue);
    Serial.print("send_data = ");
    Serial.println(send_data);
    
    Serial.print("Sending packet...");
  
    // send packet
    LoRa.beginPacket();
    LoRa.print("000000");
    LoRa.print(send_data);
    LoRa.endPacket();
    Serial.println("OK");
    delay(1000);
  }
  else{
    delay(100);
  }
}
