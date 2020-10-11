#include "WifiUtil.h"

const char SSID[]="COCO3F";
const char PASSWORD[]="coco5088715";

WifiUtil wifi(2,3);

void setup(){
    Serial.begin(9600);
    wifi.init(SSID,PASSWORD);
}

void loop(){
    if(wifi.check()){       // WIFI 연결 확인(0:안끊김, 1:끊겼다가 다시 연결됨)
        ;
    }
}