#include <WiFiEsp.h>
#include <SoftwareSerial.h>

SoftwareSerial softSerial(2,3);

char ssid[] = "COCO3F";
char pass[] = "coco5088715";
int status = WL_IDLE_STATUS;

void printWifiStatus(){
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    long rssi = WiFi.RSSI();
    Serial.print("Signal strength (RSSI): ");
    Serial.print(rssi);
    Serial.println(" dBm");
}

void setup(){
    Serial.begin(115200);
    softSerial.begin(9600);
    WiFi.init (&softSerial);

    if(WiFi.status() == WL_NO_SHIELD){
        Serial.println("WiFi shield not present");
        while (true);
    }

    while (status != WL_CONNECTED){
        Serial.print("Attempting to connect to WPA SSID: ");
        status = WiFi.begin(ssid, pass);
    }
    Serial.println("You're connected to the network");

    printWifiStatus();
}
void loop(){
}

