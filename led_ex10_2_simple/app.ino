#include <SimpleTimer.h>
int pin_LED1 = 3;
int pin_LED2 = 6;
int pin_LED3 = 9;
int pin_LED4 = 12;

SimpleTimer timer;

void blink_1000(){
    int state = digitalRead(pin_LED1);  // HIGH이면 1을, LOW이면 0을 리턴
    digitalWrite(pin_LED1, !state);
}

void blink_500(){
    int state = digitalRead(pin_LED2);
    digitalWrite(pin_LED2, !state);
}

void blink_250(){
    int state = digitalRead(pin_LED3);
    digitalWrite(pin_LED3, !state);
}
void blink_125(){
    int state = digitalRead(pin_LED4);
    digitalWrite(pin_LED4, !state);
}

void setup(){
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    pinMode(pin_LED3, OUTPUT);
    pinMode(pin_LED4, OUTPUT);
    timer.setInterval(1000,blink_1000);
    timer.setInterval(500,blink_500);
    timer.setInterval(250,blink_250);
    timer.setInterval(125,blink_125);
}

void loop(){
    timer.run();
}




// SimpleTimer timer;


// void printTest1(){
//     Serial.print("simple called by 1 sec");
// }

// void printTest2(){
//     Serial.print("simple called by 0.5 sec");
// }

// void setup(){
//     Serial.begin(9600);
//     timer.setInterval(1000,printTest1);
//     timer.setInterval(500,printTest2);
// }

// void loop(){
//     timer.run();
// }