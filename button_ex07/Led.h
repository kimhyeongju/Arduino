#pragma once

#include <Arduino.h>

class Led{
protected:
    int pin;

public:
    Led(int pin);
    void on();
    void off();
    void toggle();  // 현재상태 반전
    void set(int value);
};
