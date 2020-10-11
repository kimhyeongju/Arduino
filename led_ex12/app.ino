int pin_LED1 = 3;
int pin_LED2 = 6;
int pin_LED3 = 9;

int brightness = 0;
int increment = 1;

void setup(){
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    pinMode(pin_LED3, OUTPUT);
}

void loop(){

    // analogWrite(pin_LED1, 255 - brightness);
    analogWrite(pin_LED2,brightness);
    analogWrite(pin_LED3,255 - brightness);

    brightness = brightness + increment;

    if((brightness > 255) || (brightness <= 0)) increment = -increment;
}