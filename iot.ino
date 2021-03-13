
#include <ESP8266WiFi.h>

const char* ssid     = "Galaxy J2";  
const char* password = "xxxxxxx0";
const char* host = "api.thingspeak.com";
int value = 1;
String  gatheredStr2;
String  gatheredStr4;
String  gatheredStr6;
String  gatheredStr8;
String  gatheredStr10;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(14, OUTPUT);
  
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(14, HIGH);
  
  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");}
  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}//end setup
 
void loop() {
  delay(1000);
  Serial.print("Connecting to ");
  Serial.println(host);
  // Use WiFiClient class to create TCP connections
  WiFiClient Client;
  const int httpPort = 80;
  if (!Client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }
  // We now create a URI for the request
  String url = "/apps/thinghttp/send_request?api_key=2JE0A644E8PELUWW"; 
  Serial.print("Requesting URL: ");
  Serial.println(host + url);
  Serial.println(String("TRY: ") + value + ".");
  // This will send the request to the server
 Client.print(String("GET ") + url + "&headers=false" + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  delay(3000); 
  // Read all the lines of the reply from server and print them to Serial
  while(Client.available()){
  String line = Client.readStringUntil('\r');
  String firstDivider = "<tr>";
  String secondDivider = "</tr>";
  int firstDividerIndex = line.indexOf(firstDivider);
  int secondDividerIndex = line.indexOf(secondDivider);
  String gatheredStr = line.substring(firstDividerIndex+30, secondDividerIndex);
  
  String firstDivider2 = "<td>";
  String secondDivider2 = "</td>";
  int firstDividerIndex2 = gatheredStr.indexOf(firstDivider2);
  int secondDividerIndex2 = gatheredStr.indexOf(secondDivider2);
  gatheredStr2 = gatheredStr.substring(firstDividerIndex2+4, secondDividerIndex2);
  Serial.println(gatheredStr2);
  //----------------------------------------------------------------------------------------------------------------
  
  String line2 = line.substring(secondDividerIndex+1,secondDividerIndex+300);
  String firstDivider3 = "<tr>";
  String secondDivider3 = "</tr>";
  int firstDividerIndex3 = line2.indexOf(firstDivider3);
  int secondDividerIndex3 = line2.indexOf(secondDivider3);
  String gatheredStr3 = line2.substring(firstDividerIndex3+30, secondDividerIndex3);
  //Serial.println(gatheredStr3);
  String firstDivider4 = "<td>";
  String secondDivider4 = "</td>";
  int firstDividerIndex4 = gatheredStr3.indexOf(firstDivider4);
  int secondDividerIndex4 = gatheredStr3.indexOf(secondDivider4);
  gatheredStr4 = gatheredStr3.substring(firstDividerIndex4+4, secondDividerIndex4);
  Serial.println(gatheredStr4);
  //-----------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------
  
  String line3 = line2.substring(secondDividerIndex3+1,secondDividerIndex3+300);
  String firstDivider5 = "<tr>";
  String secondDivider5 = "</tr>";
  int firstDividerIndex5 = line3.indexOf(firstDivider5);
  int secondDividerIndex5 = line3.indexOf(secondDivider5);
  String gatheredStr5 = line3.substring(firstDividerIndex5+30, secondDividerIndex5);
  //Serial.println(gatheredStr3);
  String firstDivider6 = "<td>";
  String secondDivider6 = "</td>";
  int firstDividerIndex6 = gatheredStr5.indexOf(firstDivider6);
  int secondDividerIndex6 = gatheredStr5.indexOf(secondDivider6);
  gatheredStr6 = gatheredStr5.substring(firstDividerIndex6+4, secondDividerIndex6);
  Serial.println(gatheredStr6);
  //-----------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------
  
  String line4 = line3.substring(secondDividerIndex5+1,secondDividerIndex5+300);
  String firstDivider7 = "<tr>";
  String secondDivider7 = "</tr>";
  int firstDividerIndex7 = line4.indexOf(firstDivider7);
  int secondDividerIndex7 = line4.indexOf(secondDivider7);
  String gatheredStr7 = line4.substring(firstDividerIndex7+30, secondDividerIndex7);
  //Serial.println(gatheredStr3);
  String firstDivider8 = "<td>";
  String secondDivider8 = "</td>";
  int firstDividerIndex8 = gatheredStr7.indexOf(firstDivider8);
  int secondDividerIndex8 = gatheredStr7.indexOf(secondDivider8);
  gatheredStr8 = gatheredStr7.substring(firstDividerIndex8+4, secondDividerIndex8);
  Serial.println(gatheredStr8);
  //-----------------------------------------------------------------------------------------------------------------

  //----------------------------------------------------------------------------------------------------------------
  
  String line5 = line4.substring(secondDividerIndex7+1,secondDividerIndex7+300);
  String firstDivider9 = "<tr>";
  String secondDivider9 = "</tr>";
  int firstDividerIndex9 = line5.indexOf(firstDivider9);
  int secondDividerIndex9 = line5.indexOf(secondDivider9);
  String gatheredStr9 = line5.substring(firstDividerIndex9+30, secondDividerIndex9);
  //Serial.println(gatheredStr3);
  String firstDivider10 = "<td>";
  String secondDivider10 = "</td>";
  int firstDividerIndex10 = gatheredStr9.indexOf(firstDivider10);
  int secondDividerIndex10 = gatheredStr9.indexOf(secondDivider10);
  gatheredStr10 = gatheredStr9.substring(firstDividerIndex10+4, secondDividerIndex10);
  Serial.println(gatheredStr10);
  //-----------------------------------------------------------------------------------------------------------------
  
  if (gatheredStr2=="ON") {
   digitalWrite(5, LOW);
   //Serial.println("congrats");
   
  }
  if (gatheredStr2=="OFF"){
    digitalWrite(5, HIGH);
    //Serial.println("good");
  }
  if (gatheredStr4=="ON"){
    digitalWrite(16, LOW);
    //Serial.println("good");
  }
  if (gatheredStr4=="OFF"){
    digitalWrite(16, HIGH);
    //Serial.println("good");
  }
  if (gatheredStr6=="ON"){
    digitalWrite(4, LOW);
    //Serial.println("good");
  }
  if (gatheredStr6=="OFF"){
    digitalWrite(4, HIGH);
    //Serial.println("good");
  }
  if (gatheredStr8=="ON"){
    digitalWrite(0, LOW);
    //Serial.println("good");
  }
  if (gatheredStr8=="OFF"){
    digitalWrite(0, HIGH);
    //Serial.println("good");
  }
  if (gatheredStr10=="ON"){
    digitalWrite(14, LOW);
    //Serial.println("good");
  }
  if (gatheredStr10=="OFF"){
    digitalWrite(14, HIGH);
    //Serial.println("good");
  }
  
 } 
 
  Serial.println("");
  Serial.println(String("Try nr. ") + value + " is finished.");
  Serial.println("Waiting for next try...");
  Serial.println("");
  value = value + 1;
  delay(3000);
}
