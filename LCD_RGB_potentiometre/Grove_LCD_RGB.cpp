#include "Grove_LCD_RGB.h"

I2C i2c(I2C_SDA, I2C_SCL);

void print(char *txt, int nb){
    char data[2];
    data[0] = 0x40;
    
    while(nb){
        data[1] = *txt;
        i2c.write(addr_LCD, data, 2);
        txt++;
        nb--;
    }
}

void commandLCD(char com, int last){
    char cmd[2];
    
    if(last)
        cmd[0] = 0x00;
        
    else
        cmd[0] = 0x80;
        
    cmd[1] = com;
    i2c.write(addr_LCD, cmd, 2);
}

void set_registerLED(char reg, char data){
    char set[2];
    set[0] = reg;
    set[1] = data;
    i2c.write(addr_LED, set, 2);
}

void set_color(int R, int G, int B){
    
    set_registerLED(0x02, B);
    set_registerLED(0x03, G);
    set_registerLED(0x04, R);
}

void init(){
    
    set_registerLED(0,0);
    set_registerLED(1,0);
    
    set_registerLED(0x08, 0xAA);

    wait(0.05);                     // Initialisation LCD
    commandLCD(0x3C, 1);                  // 2 lignes
    wait_us(45);
    commandLCD(0x0E, 1);
    wait_us(45);
    commandLCD(0x01, 1);
    wait_ms(2);
    commandLCD(0x06, 1);                  // Fin init LCD
}