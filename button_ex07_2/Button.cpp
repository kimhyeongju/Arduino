#include "Button.h"

Button::Button(int pin) : pin(pin){
    pinMode(pin, INPUT_PULLUP);
    state_previous = true;  // 디폴트 상태가 HIGH
    callback = NULL;
}

int Button::read(){
    return !digitalRead(pin);   // 소프트웨어에서는 풀다운인 것처럼 운영하기 때문에 !붙임
}

void Button::setCallback(void(*callback)()){
    this->callback = callback;
}

int Button::check(){
    state_current = digitalRead(pin);
    if(!state_current){
        if(state_previous == true){
            state_previous == false;
            // 버튼을 누른 시점에서 해야 할 작업
            // timer.setInterval(100,work);
            if(callback != NULL){
            callback();
            }
        }
        delay(5);
    } else{state_previous = true;}
}
