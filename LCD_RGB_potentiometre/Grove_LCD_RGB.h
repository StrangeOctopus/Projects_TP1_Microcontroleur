#include "mbed.h"

const char addr_LCD = 0x7C;
const char addr_LED = 0xC4;

void print(char *txt, int nb);
void commandLCD(char com, int last);
void set_registerLED(char reg, char data);
void set_color(int R, int G, int B);
void init();