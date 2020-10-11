#include <LiquidCrystal_I2C.h>
#include <AnalogSensor.h>
#include <Led.h>
#include <PWMLed.h>

AnalogSensor illu(A0, 0, 1023);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Led led(3);
PWMLed led(3);

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.off();
}

void printIllu(int value){
    char buf[17];
    sprintf(buf,"illu: %3d", value);
    lcd.setCursor(0,0);
    lcd.print(buf);
}

void loop(){
    int readVal = illu.read();
    readVal = constrain(readVal, 0, 200);
    int brightness = map(readVal, 0, 200, 255, 0);
    printIllu(readVal);
    led.set(brightness);
    // if(readVal <15){
    //     led.on();
    // } else{
    //     led.off();
    // }
    delay(200);
}