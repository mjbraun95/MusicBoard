#include <Arduino.h>
int dPins[] = {8,9,10};
const int dPinCount = sizeof(dPins)/sizeof(dPins[0]);
int dpinStates[dPinCount];

int aPins[] = {8,9,10};
const int aPinCount = sizeof(aPins)/sizeof(aPins[0]);
int apinStates[aPinCount];

void init_aPins(){
    for (int i = 0; i < aPinCount; i++) {
        int pin = aPins[i];
        pinMode(pin, INPUT);
        analogWrite(pin, 0);
    }
}

void update_aPins(){
    for (int i = 0; i < aPinCount; i++) {
        int pin = aPins[i];
        int newVal = analogRead(pin);

        if (newVal != apinStates[i]) {
            Serial.print(pin);
            Serial.print(":");
            Serial.println(newVal);
            apinStates[i] = newVal;
        }
    }
}

void init_dPins(){
    for (int i = 0; i < dPinCount; i++) {
        int pin = dPins[i];
        pinMode(pin, INPUT);
        digitalWrite(pin, HIGH);
    }
}

void update_dPins(){
    for (int i = 0; i < dPinCount; i++) {
        int pin = dPins[i];
        int newVal = digitalRead(pin);

        if (newVal != dpinStates[i]) {
            Serial.print(pin);
            Serial.print(":");
            Serial.println(newVal);
            dpinStates[i] = newVal;
        }
    }
}

void setup() {
    init();
    Serial.begin(19200);
    init_dPins(); init_aPins();
}

int main() {
    setup();
    while (true) {
        // update all digital pins
        update_dPins(); update_aPins();
    }
    return 0;
}
