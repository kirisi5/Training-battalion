#include <reg52.h>

#define FREQ_OSC 11059200UL // ���徧��Ƶ��
#define BAUD_RATE 9600      // ���岨����

// ���㲨���ʶ�ʱ������ֵ
#define TIMER_RELOAD_VALUE (65536 - (FREQ_OSC / (12 * 16 * BAUD_RATE)))

// ���巢���ַ�����
void UART_SendChar(unsigned char c) {
    SBUF = c;           // ��Ҫ���͵��ַ����뷢�ͻ�����
    while (!TI);        // �ȴ��������
    TI = 0;             // ������ɺ����������ɱ�־
}

// ���巢���ַ�������
void UART_SendString(const char *str) {
    while (*str != '\0') {
        UART_SendChar(*str++); // ��������ַ����е��ַ�
    }
}

// ��ʼ������
void UART_Init() {
    TMOD |= 0x20;       // ���ö�ʱ��1Ϊģʽ2��8λ�Զ���װ�ض�ʱ��
    TH1 = TIMER_RELOAD_VALUE >> 8; // ���ò�����
    TL1 = TIMER_RELOAD_VALUE & 0xFF;
    TR1 = 1;            // ������ʱ��1
    SCON = 0x50;        // ���ô���Ϊģʽ1���������
}

// ������ʱ����
void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1141; j++);
}

int main() {
    UART_Init();    // ��ʼ������

    while (1) {
        UART_SendString("Hello World\r\n"); // ������Ϣ

        delay(1000); // ��ʱ1��
    }

    return 0;
}
