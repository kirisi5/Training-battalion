#include "REG51.h"
#define unit unsigned int
#define uchar unsigned char 
sbit beep=P3^0;

void delay(unsigned int z)
{
	unsigned int x,y;
	for(x=z;x>0;x--){
		for(y=110;y>0;y--);
	}
}

void main()
{
	while(1)
	{
		beep=0;
		delay(100);
		beep=1;
		delay(100);
	}
}
