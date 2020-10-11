#include <WifiUtil.h>

const char SSID[]="COCO3F";
const char PASSWORD[]="coco5088715";

WifiUtil wifi(2,3);
WiFiEspClient client;

char server[] = "arduino.cc";

void request(){
    if(client.connect(server, 80)){
        Serial.println("connected to server");
        // Make a HTTP request
        client.println("GET /asciilogo.txt HTTP/1.1");
        client.println("Host: arduino.cc");
        client.println("Connection: Close");
        client.println();
    }
}

void response(){
    while (client.available()){
        char c = client.read();
        Serial.write(c);
    }
}


void setup(){
    Serial.begin(9600);
    wifi.init(SSID,PASSWORD);
    request();
}

void loop(){
    response();
}


