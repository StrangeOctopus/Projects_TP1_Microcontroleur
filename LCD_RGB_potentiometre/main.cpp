#include "Grove_LCD_RGB.h"

AnalogIn pot(A0);



int main()
{   

    init();


    while(1) {
        
            
        commandLCD(0x80, 1);    // Place le curseur au début
        char buff[10];
        float tmp = pot.read();
        sprintf(buff, "%.2f", tmp);
        print(buff, 4);
        
        set_color(255*tmp, 0, 255 - (255*tmp));
       
    }
}

