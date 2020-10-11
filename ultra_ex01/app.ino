#include <MiniCom.h>
#include <Ultra.h>
#include <Led.h>
#include <Servo.h>
#include <Pulse.h>

MiniCom com;
Servo servo;
Ultra ultra(4,5);
Led led(9);
Pulse pulse(100, 500);

int delayTimes[] = {
    50, 100, 200, 300, 500, 1000
};

void pulseCallback(int value){
    // LED 제어
    led.set(value);     // true면 켜지고 false면 꺼짐
}

void checkDistance(){
    int distance = ultra.read();
    com.print(0, "distance: ", distance);
    if(distance < 10){
        // led.on();

        // Pulse의 offDelay를 distance를 고려하여 조정
        int offDelay = map(distance, 0, 9, 0, 4);
        pulse.setDelay(10, delayTimes[offDelay]);

        servo.write(90);
        if(!pulse.getState()){  // 처음 지정거리 이하로 됐을 때
            pulse.play();
        }
    }else{
        if(pulse.getState()){
            pulse.stop();
        }
        // led.off();
        servo.write(0);
    }
}

void setup(){
    com.init();
    servo.attach(8);
    servo.write(0);
    pulse.setCallback(pulseCallback);
    com.setInterval(300, checkDistance);
    
}

void loop(){
    com.run();
    pulse.run();
}