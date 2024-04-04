#include <reg52.h>

#define FREQ_OSC 11059200UL
#define BAUD_RATE 9600

// 数码管显示数字的字模，这里仅作为示例
// 假设使用的是共阴极数码管，0-9的字模
unsigned char code DIGIT_CODE[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// 用于接收字符的变量
volatile unsigned char receivedData;

// 串口初始化函数
void UART_Init() {
    TMOD |= 0x20; // 定时器1，模式2
    TH1 = 256 - (FREQ_OSC / (12 * 32 * BAUD_RATE));
    TL1 = 256 - (FREQ_OSC / (12 * 32 * BAUD_RATE));
    TR1 = 1; // 启动定时器1
    SCON = 0x50; // 串口模式1，REN允许接收
    EA = 1;  // 允许中断
    ES = 1;  // 允许串口中断
}

// 串口中断服务程序
void UART_ISR() interrupt 4 {
    if (RI) {
        RI = 0; // 清除接收中断标志
        receivedData = SBUF; // 读取接收到的数据
    }
}

// 显示函数，假定使用P0口连接数码管
void Display(unsigned char num) {
    P0 = DIGIT_CODE[num]; // 显示数字
}

void main() {
    UART_Init(); // 初始化串口

    while (1) {
        if (receivedData >= '0' && receivedData <= '9') { // 简单的字符转数字
            Display(receivedData - '0'); // 显示接收到的数字
            receivedData = 0; // 重置接收到的数据，避免重复显示
        }
    }
}
