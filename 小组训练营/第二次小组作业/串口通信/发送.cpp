#include <reg52.h>

#define FREQ_OSC 11059200UL // 定义晶振频率
#define BAUD_RATE 9600      // 定义波特率

// 计算波特率定时器重载值
#define TIMER_RELOAD_VALUE (65536 - (FREQ_OSC / (12 * 16 * BAUD_RATE)))

// 定义发送字符函数
void UART_SendChar(unsigned char c) {
    SBUF = c;           // 将要发送的字符放入发送缓冲区
    while (!TI);        // 等待发送完成
    TI = 0;             // 发送完成后清除发送完成标志
}

// 定义发送字符串函数
void UART_SendString(const char *str) {
    while (*str != '\0') {
        UART_SendChar(*str++); // 逐个发送字符串中的字符
    }
}

// 初始化串口
void UART_Init() {
    TMOD |= 0x20;       // 设置定时器1为模式2，8位自动重装载定时器
    TH1 = TIMER_RELOAD_VALUE >> 8; // 设置波特率
    TL1 = TIMER_RELOAD_VALUE & 0xFF;
    TR1 = 1;            // 启动定时器1
    SCON = 0x50;        // 设置串口为模式1，允许接收
}

// 定义延时函数
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1141; j++);
}

int main() {
    UART_Init();    // 初始化串口

    while (1) {
        UART_SendString("Hello World\r\n"); // 发送消息

        delay(1000); // 延时1秒
    }

    return 0;
}
