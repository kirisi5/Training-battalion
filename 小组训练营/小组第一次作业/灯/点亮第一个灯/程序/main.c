#include "REG51.h"

sbit button = P1^4;
sbit led = P2^0;


void delay(unsigned int time){
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

void main(void){
    button = 1;
    led = 1;
    while(1){
        if(button == 0){ 
            delay(20);
            if(button == 0){ 
                led = !led;           
                while(button == 0); 
                delay(20);
            }
        }
    }
}