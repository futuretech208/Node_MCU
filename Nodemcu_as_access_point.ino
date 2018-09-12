 /*
 * Open browser, visit 192.168.4.1
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "NodeMCU";
const char *password = "nodemcurelay";
int stateRelay1 = HIGH;
int stateRelay2 = HIGH;
int stateRelay3 = HIGH;
int stateRelay4 = HIGH;
int stateRelay5 = HIGH;
int stateRelay6 = HIGH;
int stateRelay7 = HIGH;
int stateRelay8 = HIGH;

ESP8266WebServer server(80);

void handleRoot() 
{
    response();
}

void relay1On() {
  stateRelay1 = LOW;
  digitalWrite(D1, stateRelay1);
  response();
}

void relay1Off() {
  stateRelay1 = HIGH;
  digitalWrite(D1, stateRelay1);
  response();
}
void relay2On() {
  stateRelay2 = LOW;
  digitalWrite(D2, stateRelay2);
  response();
}

void relay2Off() {
  stateRelay2 = HIGH;
  digitalWrite(D2, stateRelay2);
  response();
}
void relay3On() {
  stateRelay3 = LOW;
  digitalWrite(D3, stateRelay3);
  response();
}

void relay3Off() {
  stateRelay3 = HIGH;
  digitalWrite(D3, stateRelay3);
  response();
}
void relay4On() {
  stateRelay4 = LOW;
  digitalWrite(D4, stateRelay4);
  response();
}

void relay4Off() {
  stateRelay4 = HIGH;
  digitalWrite(D4, stateRelay4);
  response();
}
void relay5On() {
  stateRelay5 = LOW;
  digitalWrite(D5, stateRelay5);
  response();
}

void relay5Off() {
  stateRelay5 = HIGH;
  digitalWrite(D5, stateRelay5);
  response();
}
void relay6On() {
  stateRelay6 = LOW;
  digitalWrite(D6, stateRelay6);
  response();
}

void relay6Off() {
  stateRelay6 = HIGH;
  digitalWrite(D6, stateRelay6);
  response();
}
void relay7On() {
  stateRelay7 = LOW;
  digitalWrite(D7, stateRelay7);
  response();
}

void relay7Off() {
  stateRelay7 = HIGH;
  digitalWrite(D7, stateRelay7);
  response();
}
void relay8On() {
  stateRelay8 = LOW;
  digitalWrite(D8, stateRelay8);
  response();
}

void relay8Off() {
  stateRelay8 = HIGH;
  digitalWrite(D8, stateRelay8);
  response();
}


const String HtmlHtml = "<html><head>"
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /></head>";
const String HtmlHtmlClose = "</html>";
const String HtmlTitle = "<h1>NodeMCU 8 relay control board</h1><br/>\n";
//const String HtmlRelay1statelow = "<big>Relay 1 is <b>ON</b></big><br/>\n";
//const String HtmlRelay1statehigh = "<big>Relay 1 is <b>OFF</b></big><br/>\n";
const String HtmlButtons = 
    "<a href=\"R1On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 1 ON</button></a>"
    "<a href=\"R1Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 1 OFF</button></a><br/><br/>"
    "<a href=\"R2On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 2 ON</button></a>"
    "<a href=\"R2Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 2 OFF</button></a><br/><br/>"
    "<a href=\"R3On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 3 ON</button></a>"
    "<a href=\"R3Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 3 OFF</button></a><br/><br/>"
    "<a href=\"R4On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 4 ON</button></a>"
    "<a href=\"R4Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 4 OFF</button></a><br/><br/>"
    "<a href=\"R5On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 5 ON</button></a>"
    "<a href=\"R5Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 5 OFF</button></a><br/><br/>"
    "<a href=\"R6On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 6 ON</button></a>"
    "<a href=\"R6Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 6 OFF</button></a><br/><br/>"
    "<a href=\"R7On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 7 ON</button></a>"
    "<a href=\"R7Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 7 OFF</button></a><br/><br/>"
    "<a href=\"R8On\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 8 ON</button></a>"
    "<a href=\"R8Off\"><button style=\"display: inline-block; width: 50%; margin: 5px auto; text-align: center;\">Relay 8 OFF</button></a><br/><br/>";
    
void response()
{
  String htmlRes = HtmlHtml + HtmlTitle;
//  if(stateRelay1 == LOW)
//  {
//    htmlRes += HtmlRelay1statelow;
//  }
//  else
//  {
//    htmlRes += HtmlRelay1statehigh;
//  }

  htmlRes += HtmlButtons;
  htmlRes += HtmlHtmlClose;

  server.send(200, "text/html", htmlRes);
}

void setup() {
    delay(1000);
    Serial.begin(115200);
    Serial.println();

    WiFi.softAP(ssid, password);

    IPAddress apip = WiFi.softAPIP();
    Serial.print("visit: \n");
    Serial.println(apip);
    server.on("/", handleRoot);
    server.on("/R1On", relay1On);
    server.on("/R1Off", relay1Off);
    server.on("/R2On", relay2On);
    server.on("/R2Off", relay2Off);
    server.on("/R3On", relay3On);
    server.on("/R3Off", relay3Off);
    server.on("/R4On", relay4On);
    server.on("/R4Off", relay4Off);
    server.on("/R5On", relay5On);
    server.on("/R5Off", relay5Off);
    server.on("/R6On", relay6On);
    server.on("/R6Off", relay6Off);
    server.on("/R7On", relay7On);
    server.on("/R7Off", relay7Off);
    server.on("/R8On", relay8On);
    server.on("/R8Off", relay8Off);
    server.begin();
    Serial.println("HTTP server started");
    
  pinMode(D1, OUTPUT);
  digitalWrite(D1, stateRelay1);
  pinMode(D2, OUTPUT);
  digitalWrite(D2, stateRelay2);
  pinMode(D3, OUTPUT);
  digitalWrite(D3, stateRelay3);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, stateRelay4);
  pinMode(D5, OUTPUT);
  digitalWrite(D5, stateRelay5);
  pinMode(D6, OUTPUT);
  digitalWrite(D6, stateRelay6);
  pinMode(D7, OUTPUT);
  digitalWrite(D7, stateRelay7);
  pinMode(D8, OUTPUT);
  digitalWrite(D8, stateRelay8);
}

void loop() 
{
    server.handleClient();
}
