#pragma once

#include <Arduino.h>
class LED {
private:
    int pin;
public:
    LED(int pin) : pin(pin) {
        pinMode(pin, OUTPUT);
        off();
    }
    void on() {
        digitalWrite(pin, HIGH);
    }
    void off() {
        digitalWrite(pin, LOW);
    }
    void toggle() {
        digitalWrite(pin, !digitalRead(pin));
    }
};