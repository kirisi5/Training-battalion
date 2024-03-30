#include "REG51.h"
void delay(unsigned int t){
	unsigned char i;
	for(;t>0;t--){
		for(i=100;i>0;i--);
	}
}

void main(void){
	while(1){
		unsigned int i;
		for(i=0;i<=7;i++){
			P2=~(0x01<<i);
			delay(300);
		}
	}
}