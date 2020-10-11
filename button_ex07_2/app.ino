#include <SimpleTimer.h>
#include "Led.h"
#include "Button.h"

SimpleTimer timer;

Led led1(3);
Led led2(4);
Led led3(5);

Button btn1(9);
Button btn2(10);
Button btn3(11);

bool blinkPlay = false; // 블링크 중인지 여부. 디폴트는 중지
int blinkTimer = -1;    // 블링크용 타이머 ID

void led2OnOff(){
    led2.toggle();
}

void led3Blink(){
    led3.toggle();
}

void led3BlinkControl(){
    blinkPlay =! blinkPlay; // 상태반전
    if(!blinkPlay){
        led3.off();
    }
    timer.toggle(blinkTimer);
}

void setup(){
    Serial.begin(9600);
    btn2.setCallback(led2OnOff);
    btn3.setCallback(led3BlinkControl);
    blinkTimer = timer.setInterval(500, led3Blink);
    timer.disable(blinkTimer);
}

void loop(){
    timer.run();
    led1.set(btn1.read());
    btn2.check();
    btn3.check();
}