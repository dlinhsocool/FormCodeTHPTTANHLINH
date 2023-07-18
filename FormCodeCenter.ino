#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "tenplateid"
#define BLYNK_DEVICE_NAME "devicename"

#define BLYNK_TEMPLATE_ID "templateid"
#define BLYNK_TEMPLATE_NAME "templatename"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "authtoken";

char ssid[] = "ssid";
char pass[] = "password";

// Declaring a global variabl for sensor data
//chencode vao day
int Relay = 15;

// This function creates the timer object. It's part of Blynk library 
BlynkTimer timer; 
String chuoi;
void myTimer() 
{
  // This function describes what will happen with each timer tick
  // e.g. writing sensor value to datastream V5
  // chen code vao day
}

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 5
#define rst 14
#define dio0 2

void setup() {
  
  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);
  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, myTimer); 
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet ");

    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData);
      chuoi = String(LoRaData);
    }
    //chen code vao day
    Serial.println("");
  }
  Blynk.run();
  timer.run();
  //chen code vao day
}
