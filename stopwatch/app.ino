#include <Led.h>
#include <Button.h>
#include <SimpleTimer.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
SimpleTimer timer;

Led led2(4);
Led led3(3);

Button btn1(9);     // start, stop
Button btn2(10);    // lap time
Button btn3(11);    // reset

int timerId = -1;   // stopwatch용 타이머
int blinkTimerId = -1;  // blink용 타이머

bool state = false;      // 0 준비상태, 1 가동상태
unsigned long startTime = 0;    // 시작 버튼을 누른 시점의 시간


void printTime(unsigned long t, int row){
    char buf[17];
    // millisecond -> 시:분:초 변환해서 출력
    int misec = t % 1000 / 100;     // 100ms 단위
    t = t / 1000;   // 밀리초 -> 초
    int h = t/3600;     // 초 -> 시간
    int m = (t - (h*3600)) / 60;    // 초 -> 분
    int s = t - (h*3600 + m*60);    // 초

    sprintf(buf, "%02d:%02d:%02d.%d", h, m, s, misec);
    lcd.setCursor(0,row);
    lcd.print(buf);
}

void printTime(){
    unsigned long t = millis();
    unsigned long diff = t - startTime;
    printTime(diff,0);
}

void startStop(){   // 버튼하나에 두가지 동작
    if(state == false){     // 리셋 이후 처음 버튼을 누른 경우
        startTime = millis();
        timer.enable(blinkTimerId);     // 기준 시간 설정
        led2.off();
        state = true;   // 기동중임을 설정
    }
        timer.toggle(timerId);
}

void laptime(){
    if(state){
    unsigned long t = millis();
    unsigned long diff = t - startTime;
    printTime(diff,1);
}
}

void reset(){
    state = false;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("00:00:00.0");
    led2.on();
    led3.off();
    timer.disable(timerId);
    timer.disable(blinkTimerId);
}

void blink(){
    led3.toggle();
}

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    // 타이머 ID, 0부터 배정
    timerId = timer.setInterval(100, printTime);
    blinkTimerId = timer.setInterval(250, blink);
    reset();

    btn1.setCallback(startStop);
    btn2.setCallback(laptime);
    btn3.setCallback(reset);
}

void loop(){
    timer.run();
    btn1.check();
    btn2.check();
    btn3.check();
}