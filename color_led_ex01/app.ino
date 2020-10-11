const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// void setup(){
//     randomSeed(analogRead(A0));
// }

// void loop(){
//     analogWrite(redPin, random(256));
//     analogWrite(greenPin, random(256));
//     analogWrite(bluePin, random(256));
//     delay(1000);
// }

void setup(){
    randomSeed(analogRead(A0));
    analogWrite(redPin,255);
    delay(1000);
    analogWrite(redPin,0);
    analogWrite(greenPin,255);
    delay(1000);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
    delay(1000);
}

void loop(){
    analogWrite(redPin, random(256));
    analogWrite(greenPin, random(256));
    analogWrite(bluePin, random(256));
    delay(1000);
}