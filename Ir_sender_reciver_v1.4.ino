#include <ESP8266WiFi.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "samsung_ir_code.h"
#include "epson_ir_code.h"
#include "etc_ir_code.h"
 


 
//how many clients should be able to telnet to this ESP8266
#define MAX_SRV_CLIENTS 3
const char* ssid = "SSID";
const char* password = "PASSWORD";

// SELECT IR PIN
const int IRpin = D2;

//true SENDS GROUND, false SENDS VCC SIGNAL
const bool sendGround = false; 

IRsend irsend(D2, sendGround);

WiFiServer server(5055);
WiFiClient serverClients[MAX_SRV_CLIENTS+1];
 
void setup() {
  //start UART
  Serial.begin(115200);

  irsend.begin();
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to "); Serial.println(ssid);
  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED && i++ < 20) delay(100);
  if(i == 21){
    Serial.print("Could not connect to"); Serial.println(ssid);
  }
  //start server
  server.begin();
  server.setNoDelay(true);
 
  Serial.print("Ready! Use 'telnet ");
  Serial.print(WiFi.localIP());
  Serial.println(":23' to connect");

 
}
 
void loop() {
 // while (1) {sansung_tv1_power; delay(100);}
  uint8_t i;
  //check if there are any new clients
  if (server.hasClient()){
    for(i = 0; i < MAX_SRV_CLIENTS; i++){
      //find free/disconnected spot
      if (!serverClients[i] || !serverClients[i].connected()){
        if (serverClients[i]) serverClients[i].stop();
        serverClients[i] = server.available();
        Serial.print("New client: "); Serial.print(i);
        break;
      }
    }
    //no free/disconnected spot so reject
    serverClients[MAX_SRV_CLIENTS] = server.available();
    serverClients[MAX_SRV_CLIENTS].stop();
  }
  //check clients for data
  for(i = 0; i < MAX_SRV_CLIENTS; i++){
    if (serverClients[i] && serverClients[i].connected()){
      if(serverClients[i].available()){
        size_t len = serverClients[i].available();
        uint8_t sbuf[len+1];
        serverClients[i].readBytes(sbuf, len);
        Serial.write(sbuf, len);
        sbuf[len]=0x00;
        String str = (char*)sbuf;
        Serial.println(str);
        if (str == "Pr_On") {
          epson_pr1_power_on; delay(100);
          Serial.println("Projector power on");
          }
        if (str == "Pr_Off") {
          epson_pr1_power_off; delay(100);
          Serial.println("Projector power off");
          }
        if (str == "Pr_0") {
          epson_pr1_hdmi2;
          Serial.println("Projector power on. Sel HDMI 2");
          }
        if (str == "Pr_1") {
          hdmi_matrix_1_a1; delay(100); epson_pr1_hdmi1;
          Serial.println("Projector power on. Sel HDMI 1. Matrix HDMI A1");
          }
        if (str == "Pr_2") {
          hdmi_matrix_1_a2; delay(100); epson_pr1_hdmi1; 
          Serial.println("Projector power on. Sel HDMI 1. Matrix HDMI A2");
          }
        if (str == "Pr_3") {
          hdmi_matrix_1_a3; delay(100); epson_pr1_hdmi1;
          Serial.println("Projector power on. Sel HDMI 1. Matrix HDMI A3");
          }
        if (str == "Pr_4") {
          hdmi_matrix_1_a4; delay(100); epson_pr1_hdmi1; 
          Serial.println("Projector power on. Sel HDMI 1. Matrix HDMI A4");
          }
        if (str == "Pr_5") {
          hdmi_matrix_1_a5; delay(100); epson_pr1_hdmi1; 
          Serial.println("Projector power on. Sel HDMI 1. Matrix HDMI A5");
          }
        if (str == "Pr_6") {
          hdmi_matrix_1_a6; delay(100); epson_pr1_hdmi1; 
          Serial.println("Projector power on. Sel HDMI 1. Matrix HDMI A6");
          }
        if (str == "Tv_on") {
          sansung_tv1_power_on; delay(100);
          Serial.println("TV power on");
          }
        if (str == "Tv_off") {
          sansung_tv1_power_off; delay(100);
          Serial.println("TV power off");
          }  
        if (str == "Tv_0") {
          sansung_tv1_hdmi2; 
          Serial.println("TV power on. Sel HDMI 2.");
          }
        if (str == "Tv_1") {
          hdmi_matrix_1_b1; delay(100); sansung_tv1_hdmi1; 
          Serial.println("TV power on. Sel HDMI 1. Matrix HDMI B1");
          }
        if (str == "Tv_2") {
          hdmi_matrix_1_b2; delay(100); sansung_tv1_hdmi1;
          Serial.println("TV power on. Sel HDMI 1. Matrix HDMI B2");
          }
        if (str == "Tv_3") {
          hdmi_matrix_1_b3; delay(100); sansung_tv1_hdmi1; 
          Serial.println("TV power on. Sel HDMI 1. Matrix HDMI B3");
          }
        if (str == "Tv_4") {
          hdmi_matrix_1_b4; delay(100); sansung_tv1_hdmi1; 
          Serial.println("TV power on. Sel HDMI 1. Matrix HDMI B4");
          }
        if (str == "Tv_5") {
          hdmi_matrix_1_b5; delay(100); sansung_tv1_hdmi1;
          Serial.println("TV power on. Sel HDMI 1. Matrix HDMI B5");
          }
        if (str == "Tv_6") {
          hdmi_matrix_1_b6; delay(100); sansung_tv1_hdmi1; 
          Serial.println("TV power on. Sel HDMI 1. Matrix HDMI B6");
          }
      }
    }
  }
  //check UART for data
  if ( Serial.available() ){
    size_t len = Serial.available();
    uint8_t sbuf[len];
    Serial.readBytes(sbuf, len);
    //push UART data to all connected telnet clients
    //for(i = 0; i < MAX_SRV_CLIENTS; i++){
    //  if (serverClients[i] && serverClients[i].connected()){
    //    serverClients[i].write(sbuf, len);
    //    delay(100);
    //  }
    //}
  }

}
