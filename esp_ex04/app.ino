#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <SimpleTimer.h>
#include <WifiUtil.h>
#include <MiniCom.h>
#include <DHT.h>

SoftwareSerial softSerial(2,3); // RX, TX
const char ssid[] = "COCO3F";
const char password[] = "coco5088715";
const char mqtt_server[] = "192.168.43.234";   // 라즈베리 주소

unsigned long lowpulseoccupancy = 0;
float ratio = 0;

const int DUST_PIN = 8;
unsigned long sampletime_ms = 2000;

// MQTT용 WiFi 클라이언트 객체 초기화
WifiUtil wifi(2,3);
WiFiEspClient espClient;
PubSubClient client(espClient);
MiniCom com;
DHT dht(4, DHT11);

void mqtt_init(){
    client.setServer(mqtt_server, 1883);
}

// MQTT 서버에 접속될 때까지 재접속 시도
void reconnect(){
    while (!client.connected()){
        Serial.print("Attempting MQTT connection...");

        if(client.connect("ESP8266Client")){
            Serial.println("connected");
            // subscriber 등록
            client.subscribe("home/livingroom/led");    // 구독신청!
        } else{
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void publish(){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    char message[10];

    dtostrf(h, 5, 2, message);
    client.publish("iot/home1/humi", message);
    dtostrf(t, 5, 2, message);
    client.publish("iot/home1/temp", message);

    com.print(0, "humi", h);
    com.print(1, "humi", t);
    Serial.print(h);
    Serial.print(",");
    Serial.println(t);
}

void setup(){
    com.init();
    wifi.init(ssid, password);
    mqtt_init();
    dht.begin();
    pinMode(DUST_PIN, INPUT);
    com.setInterval(2000, publish);
}

void loop(){
    if (!client.connected()){
        reconnect();
    }
    client.loop();
    com.run();
}