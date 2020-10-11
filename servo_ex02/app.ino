#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <AnalogSensor.h>
#include <SimpleTimer.h>

AnalogSensor poten(A0, 0, 169);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servoMotor;
SimpleTimer timer;

const int servoPin = 5;

void motorControl(){
    char buf[17];

    int angle = poten.read();
    servoMotor.write(angle);

    sprintf(buf, "angle: %3d", angle);
    lcd.setCursor(0,0);
    lcd.print(buf);
}

void setup(){
    lcd.init();
    lcd.backlight();
    lcd.clear();

    servoMotor.attach(servoPin);
    servoMotor.write(poten.read());

    timer.setInterval(50, motorControl);

    Serial.begin(9600);
}

void loop(){
    timer.run();

    // char buf[17];

    // int angle = poten.read();
    // servoMotor.write(angle);

    // springf(buf, "angle: %3d", angle);
    // lcd.setCursor(0,0);
    // lcd.print(buf);
}