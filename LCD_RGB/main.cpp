#include "Grove_LCD_RGB.h"

AnalogIn pot(A0);

void setColor(int nb);



int main()
{   

    init();

    char data[] = "Hello World !";
    print(data, 13);
    wait_ms(1);
    
    int i = 0;
    char compteur[] = {48, 48, 48, 48, 48, 48};

    while(1) {
        commandLCD(0xC0, 1);        // Positionnement du curseur au début de la deuxième ligne
        
        setColor(compteur[0]);      // Change la couleur des LEDs
        
        for(int j = i; j >= 0; j--){
            print((compteur + j), 1);
        }
        
        wait(1);
        
        compteur[0]++;
        
        for(int j = 0; j <= i; j++){
            if(compteur[j] > 57){
                compteur[j] = 48;
                compteur[j+1]++;
            }
        }
        
        if(compteur[i + 1] != 48)
            i++;
            
       
    }
}

void setColor(int nb){

    if(nb % 2){     // impair
        set_color(0,0,255);
    }       
    else{           // pair
        set_color(0,255,0);
    }
}
