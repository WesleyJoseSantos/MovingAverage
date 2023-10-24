/**
 * @file simple.ino
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <MovingAverage.h>
#include <Arduino.h>

#define BUFFER_SIZE 10
#define INTERPOLATION_STATE false
#define ANALOG_PIN A0
#define POOLING_DELAY 0

int buffer[BUFFER_SIZE];

MovingAverage movingAverage = MovingAverage(buffer, BUFFER_SIZE);

void setup()
{
    movingAverage.reset();
    movingAverage.setInterpolation(INTERPOLATION_STATE);

    pinMode(ANALOG_PIN, INPUT);
}

void loop()
{
    int analogValue = analogRead(ANALOG_PIN);
    int averageValue = movingAverage.getAverage(analogValue);

    Serial.println(averageValue);

    delay(POOLING_DELAY);
}
