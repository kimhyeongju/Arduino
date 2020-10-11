#include "Led.h"
#include "Button.h"

Led led(4);
Button btn(11);

// int pin_button = 11;
// int led = 4;
boolean state_previous = true;
boolean state_current;


void setup() {
    Serial.begin(9600);
    // pinMode(pin_button, INPUT_PULLUP);
    // pinMode(led,OUTPUT);     // 생성자에서 이미 했음
    btn.setCallback(work);
}

void work(){
    led.toggle();

    // int ledState = digitalRead(led);
    // digitalWrite(led, !ledState);   // 한번 누르면 상태 유지
}

// void loop() {
// state_current = digitalRead(pin_button);
// if(!state_current){ // 누른 경우
//     if(state_previous == true){
//         state_previous = false;
//         // 버튼을 누른 시점에서 해야할 작업
//         work();
//     }
//     delay(5);
// } else {
//     state_previous = true;
//     }
// }

// 누른동안 켜지게 하기

void loop(){
    // state_current = digitalRead(pin_button);
    // led.set(!state_current);
    // led.set(btn.read);
    btn.check();    // Falling 엣지가 발생했는지 체크
}