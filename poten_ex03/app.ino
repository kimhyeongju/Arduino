#include <LiquidCrystal_I2C.h>
#include "PWMLed.h"
#include "AnalogSensor.h"

PWMLed led(5);
AnalogSensor poten(A0, 0, 169);

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
    lcd.init();
    lcd.backlight();
    lcd.clear();
    Serial.begin(9600);
}

void loop(){
    char buf[17];

    int brightness = poten.read();
    led.set(brightness);
    
    sprintf(buf, "bright: %4d", brightness);
    lcd.setCursor(0,0);
    lcd.print(buf);
}