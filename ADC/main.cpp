#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

AnalogIn ras(A0);

int main() {
    while(1) {
        
        led1 = (ras >= 0.2f) ? 1 : 0;
        led2 = (ras >= 0.4f) ? 1 : 0;
        led3 = (ras >= 0.6f) ? 1 : 0;
        led4 = (ras >= 0.8f) ? 1 : 0;
    }
}
