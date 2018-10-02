#include <ESP8266WiFi.h>

char ssid[] = "qccesspoint name";
char pass[] = "password goes here";
IPAddress ip(192, 168, 1, 50); //set static ip
IPAddress gateway(192, 168, 1, 1); //set getteway
IPAddress subnet(255, 255, 255, 0);//set subnet
WiFiServer server(80);
//int led1 = 13; // GPIO13
//int led2 = 15; // GPIO15
String header;
String output1State = "off";
String output2State = "off";
String output3State = "off";
String output4State = "off";
String output5State = "off";
String output6State = "off";
String output7State = "off";
String output8State = "off";

void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(D1, OUTPUT);
  digitalWrite(D1, HIGH);
  pinMode(D2, OUTPUT);
  digitalWrite(D2, HIGH);
  pinMode(D3, OUTPUT);
  digitalWrite(D3, HIGH);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);
  pinMode(D5, OUTPUT);
  digitalWrite(D5, HIGH);
  pinMode(D6, OUTPUT);
  digitalWrite(D6, HIGH);
  pinMode(D7, OUTPUT);
  digitalWrite(D7, HIGH);
  pinMode(D8, OUTPUT);
  digitalWrite(D8, HIGH);
  
  Serial.print("connecting to..");
  Serial.println(ssid);
  delay(500);

  WiFi.disconnect();
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid,pass);


  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
Serial.println("SSID....");
Serial.println(WiFi.SSID());
Serial.println("successfully connected....");

Serial.print("IP assigned to NodeMCU....");
Serial.println(WiFi.localIP());

Serial.print("MAC address of nodemcu is....");
Serial.println(WiFi.macAddress());
WiFi.printDiag(Serial);
server.begin();
  Serial.println("Server started");


}

void loop() {
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it to the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /1/on") >= 0) {           //D1
              Serial.println("GPIO 1 on");
              output1State = "on";
              digitalWrite(D1, LOW);
            } else if (header.indexOf("GET /1/off") >= 0) {      
              Serial.println("GPIO 1 off");
              output1State = "off";
              digitalWrite(D1, HIGH);
            } else if (header.indexOf("GET /2/on") >= 0) {      //D2
              Serial.println("GPIO 2 on");
              output2State = "on";
              digitalWrite(D2, LOW);
            } else if (header.indexOf("GET /2/off") >= 0) {
              Serial.println("GPIO 2 off");
              output2State = "off";
              digitalWrite(D2, HIGH);
            } else if (header.indexOf("GET /3/on") >= 0) {          //D3
              Serial.println("GPIO 3 on");
              output3State = "on";
              digitalWrite(D3, LOW);
            } else if (header.indexOf("GET /3/off") >= 0) {
              Serial.println("GPIO 3 off");
              output3State = "off";
              digitalWrite(D3, HIGH);
            } else if (header.indexOf("GET /4/on") >= 0) {          //D4
              Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(D4, LOW);
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(D4, HIGH);
            } else if (header.indexOf("GET /5/on") >= 0) {          //D5
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(D5, LOW);
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(D5, HIGH);
            } else if (header.indexOf("GET /6/on") >= 0) {          //D6
              Serial.println("GPIO 6 on");
              output6State = "on";
              digitalWrite(D6, LOW);
            } else if (header.indexOf("GET /6/off") >= 0) {
              Serial.println("GPIO 6 off");
              output6State = "off";
              digitalWrite(D6, HIGH);
            } else if (header.indexOf("GET /7/on") >= 0) {          //D7
              Serial.println("GPIO 7 on");
              output7State = "on";
              digitalWrite(D7, LOW);
            } else if (header.indexOf("GET /7/off") >= 0) {
              Serial.println("GPIO 7 off");
              output7State = "off";
              digitalWrite(D7, HIGH);
            } else if (header.indexOf("GET /8/on") >= 0) {          //D8
              Serial.println("GPIO 8 on");
              output8State = "on";
              digitalWrite(D8, LOW);
            } else if (header.indexOf("GET /8/off") >= 0) {
              Serial.println("GPIO 8 off");
              output8State = "off";
              digitalWrite(D8, HIGH);
            } 


            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP8266 Home Automation</h1>");
            
            // Display current state, and ON/OFF buttons for D1  
            client.println("<p>D1 - State " + output1State + "</p>");
            // If the output1State is off, it displays the ON button       
            if (output1State=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for D2 
            client.println("<p>D2 - State " + output2State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output2State=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for D3 
            client.println("<p>D3 - State " + output3State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output3State=="off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button button3\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for D4 
            client.println("<p>D4 - State " + output4State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output4State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button4\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for D5 
            client.println("<p>D5 - State " + output5State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button5\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for D6 
            client.println("<p>D6 - State " + output6State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output6State=="off") {
              client.println("<p><a href=\"/6/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/6/off\"><button class=\"button button6\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for D7 
            client.println("<p>D7 - State " + output7State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output7State=="off") {
              client.println("<p><a href=\"/7/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/7/off\"><button class=\"button button7\">OFF</button></a></p>");
            }
            // Display current state, and ON/OFF buttons for D8 
            client.println("<p>D8 - State " + output8State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output8State=="off") {
              client.println("<p><a href=\"/8/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/8/off\"><button class=\"button button8\">OFF</button></a></p>");
            }
            
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
