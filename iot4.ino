
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

/* Set these to your desired credentials. */
const char *ssid = "Galaxy J2";  //ENTER YOUR WIFI SETTINGS
const char *password = "xxxxx000";

//Web/Server address to read/write from 
//const char *host = "http://group9-pro.000webhostapp.com"; 

//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  pinMode(5, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(14, OUTPUT);
  
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(4, LOW);
  digitalWrite(0, LOW);
  digitalWrite(14, LOW);
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient

  String postData;
  
  postData ="status";
  
  http.begin("http://group9-pro.000webhostapp.com/api.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.println(payload);    //Print request response payload
  int Index11 = payload.indexOf("LOAD1");
  int Index12 = payload.indexOf("2");
  String st1 = payload.substring(Index11+6, Index12-4);
  
  int Index21 = payload.indexOf("LOAD2");
  int Index22 = payload.indexOf("3");
  String st2 = payload.substring(Index21+6, Index22-4);

  int Index31 = payload.indexOf("LOAD3");
  int Index32 = payload.indexOf("4");
  String st3 = payload.substring(Index31+6, Index32-4);

  int Index41 = payload.indexOf("LOAD4");
  int Index42 = payload.indexOf("5");
  String st4 = payload.substring(Index41+6, Index42-4);

  int Index51 = payload.indexOf("LOAD5");
  int Index52 = payload.indexOf("\0");
  String st5 = payload.substring(Index51+6, Index52-1);
  Serial.println(st1); 
  Serial.println(st2); 
  Serial.println(st3); 
  Serial.println(st4); 
  Serial.println(st5);
  if (st1=="ON") {
   digitalWrite(5, HIGH);
   //Serial.println("congrats");
   
  }
  if (st1=="OFF"){
    digitalWrite(5, LOW);
    //Serial.println("good");
  }
  if (st2=="ON"){
    digitalWrite(16,HIGH);
    //Serial.println("good");
  }
  if (st2=="OFF"){
    digitalWrite(16, LOW);
    //Serial.println("good");
  }
  if (st3=="ON"){
    digitalWrite(4, HIGH);
    //Serial.println("good");
  }
  if (st3=="OFF"){
    digitalWrite(4, LOW);
    //Serial.println("good");
  }
  if (st4=="ON"){
    digitalWrite(0, HIGH);
    //Serial.println("good");
  }
  if (st4=="OFF"){
    digitalWrite(0, LOW);
    //Serial.println("good");
  }
  if (st5=="ON<br>"){
    digitalWrite(14, HIGH);
    //Serial.println("good");
  }
  if (st5=="OFF<br>"){
    digitalWrite(14, LOW);
    //Serial.println("good");
  }
  http.end();  //Close connection
  
  delay(1000);  //Post Data at every 5 seconds
}
