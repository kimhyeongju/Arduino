// 내부 풀업
const int ledPin = 13;
const int inputPin = 11;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(inputPin, INPUT_PULLUP);
}

void loop()
{
    int swInput = digitalRead(inputPin);
    if (swInput == LOW)
        digitalWrite(ledPin, HIGH);
    else
        digitalWrite(ledPin, LOW);
}