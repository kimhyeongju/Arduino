#include <trafficLight.h>

TrafficLight lights(3,6,9,12);


// int greenLed = 6;
// int yellowLed = 9;
// int redLed = 12;

void setup()    // cpp에서 생성자에서 했음
{
	// pinMode(greenLed, OUTPUT);
    // pinMode(yellowLed, OUTPUT);
    // pinMode(redLed, OUTPUT);
}


void loop()
{
    lights.run();
}
