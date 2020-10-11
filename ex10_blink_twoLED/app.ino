#include <SimpleTimer.h>
int pin_LED1 = 3;
int pin_LED2 = 6;
int pin_LED3 = 9;

SimpleTimer timer;

boolean LED_state1 = false;
unsigned long time_previous1, time_current1;

boolean LED_state2 = false;
unsigned long time_previous2, time_current2;

unsigned long time_previous, time_current;
boolean LED_state = false;

void setup() {
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    digitalWrite(pin_LED1, LOW);
    digitalWrite(pin_LED2, LOW);
}


void blink_1000() {
    time_current1 = millis();
    if(time_current1 - time_previous1 >= 1000) {
        time_previous1 = time_current1;
        LED_state1 =! LED_state1;
        digitalWrite(pin_LED1, LED_state1);
    }
}


void blink_500() {
    time_current2 = millis();
    // 0.5초 이상 시간이 경과한 경우
    if(time_current2 - time_previous2 >= 500) {
        time_previous2 = time_current2;
        LED_state2 =! LED_state2;
        digitalWrite(pin_LED2, LED_state2);
    }
}


void loop(){
    blink_1000();
    blink_500();

}




