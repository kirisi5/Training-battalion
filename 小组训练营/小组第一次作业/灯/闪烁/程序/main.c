#include "REG51.h"

sbit button = P1^4;
sbit led = P2^0;

unsigned int flag=0;

void delay(unsigned int time){
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

unsigned char debounce(){
    if(button == 0){ 
        delay(20);
        if(button == 0){ 
            while(!button);
            delay(20);
            return 1;
        }
    }
    return 0;
}

void main(void){
   
    led = 1;
    while(1){
        if(debounce()){
            flag = !flag;
        }
      
        if(flag){
            led = !led;
            delay(50);
        } else {
            led = 1; 
        }
    }
}