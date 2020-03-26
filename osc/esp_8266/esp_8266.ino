#include <OSCBundle.h>
#include <OSCData.h>
#include <OSCMatch.h>
#include <OSCMessage.h>

#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

// Wi-Fi id and password
char ssid[] = "Andrade";
char pass[] = "mvtmjsunp";

/*==== PINS ====*/
#define PIN_CX D0 // snare
#define PIN_BU D1 // kick
#define PIN_CH D2 // hi-hat
#define PIN_CR D3 // crash
#define PIN_RI D4 // ride
#define PIN_T1 D5 // tom1
#define PIN_T2 D6 // tom2
#define PIN_SU D7 // floor

WiFiUDP Udp;                           // A UDP instance to let us send and receive packets over UDP
const IPAddress destIp(192,168,0,53);  // remote IP of the target device
const unsigned int destPort = 54322;    // remote port of the target device where the NodeMCU sends OSC to
const unsigned int localPort = 8000;   // local port to listen for UDP packets at the NodeMCU (another device must send OSC messages to this port)

OSCMessage msg_CX("/p1tgr/1");
OSCMessage msg_BU("/p2tgr/1");
OSCMessage msg_CH("/p3tgr/1");
OSCMessage msg_CR("/p4tgr/1");
OSCMessage msg_RI("/p5tgr/1");
OSCMessage msg_T1("/p6tgr/1");
OSCMessage msg_T2("/p7tgr/1");
OSCMessage msg_SU("/p8tgr/1");

void setup() {
  Serial.begin(115200);

  WiFi.config(IPAddress(192,168,43,123),IPAddress(192,168,43,1), IPAddress(255,255,255,0));

  Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("Starting UDP");
    Udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(Udp.localPort());

    pinMode(PIN_CX, INPUT); // snare
    pinMode(PIN_BU, INPUT); // kick
    pinMode(PIN_CH, INPUT); // hi-hat
    pinMode(PIN_CR, INPUT); // crash
    pinMode(PIN_RI, INPUT); // ride
    pinMode(PIN_T1, INPUT); // tom1
    pinMode(PIN_T2, INPUT); // tom2
    pinMode(PIN_SU, INPUT); // floor
}

void loop() {
    if(digitalRead(PIN_CX) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_CX.send(Udp);
      Udp.endPacket();
    }

    if(digitalRead(PIN_BU) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_BU.send(Udp);
      Udp.endPacket();
    }

    if(digitalRead(PIN_CH) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_CH.send(Udp);
      Udp.endPacket();
    }

    if(digitalRead(PIN_CR) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_CR.send(Udp);
      Udp.endPacket();
    }

    if(digitalRead(PIN_RI) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_RI.send(Udp);
      Udp.endPacket();
    }

    if(digitalRead(PIN_T1) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_T1.send(Udp);
      Udp.endPacket();
    }

    if(digitalRead(PIN_T2) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_T2.send(Udp);
      Udp.endPacket();
    }

    if(digitalRead(PIN_SU) == HIGH){
      Udp.beginPacket(destIp, destPort);
      msg_SU.send(Udp);
      Udp.endPacket();
    }
}
