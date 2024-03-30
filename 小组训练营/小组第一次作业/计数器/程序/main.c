#include "REG51.h"

unsigned char s[] = {0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned int count = 0;

void initcounter() {
    TMOD = 0x06;
    TH0 = 0xFF; // ?????? 0xFF,????????
    TL0 = 0xFF;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void display() {
    P2 = s[count];
    if(count == 10) {
        count = 0;
    }
}

void main(void) {
    initcounter();
    while(1) {
        display();
    }
}

void counter() interrupt 1 {
    count++;
    TH0 = 0xFF; // ?????????????????,????????
    TL0 = 0xFF;
}