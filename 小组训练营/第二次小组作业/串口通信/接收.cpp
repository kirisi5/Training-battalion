#include <reg52.h>

#define FREQ_OSC 11059200UL
#define BAUD_RATE 9600

// �������ʾ���ֵ���ģ���������Ϊʾ��
// ����ʹ�õ��ǹ���������ܣ�0-9����ģ
unsigned char code DIGIT_CODE[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// ���ڽ����ַ��ı���
volatile unsigned char receivedData;

// ���ڳ�ʼ������
void UART_Init() {
    TMOD |= 0x20; // ��ʱ��1��ģʽ2
    TH1 = 256 - (FREQ_OSC / (12 * 32 * BAUD_RATE));
    TL1 = 256 - (FREQ_OSC / (12 * 32 * BAUD_RATE));
    TR1 = 1; // ������ʱ��1
    SCON = 0x50; // ����ģʽ1��REN�������
    EA = 1;  // �����ж�
    ES = 1;  // �������ж�
}

// �����жϷ������
void UART_ISR() interrupt 4 {
    if (RI) {
        RI = 0; // ��������жϱ�־
        receivedData = SBUF; // ��ȡ���յ�������
    }
}

// ��ʾ�������ٶ�ʹ��P0�����������
void Display(unsigned char num) {
    P0 = DIGIT_CODE[num]; // ��ʾ����
}

void main() {
    UART_Init(); // ��ʼ������

    while (1) {
        if (receivedData >= '0' && receivedData <= '9') { // �򵥵��ַ�ת����
            Display(receivedData - '0'); // ��ʾ���յ�������
            receivedData = 0; // ���ý��յ������ݣ������ظ���ʾ
        }
    }
}
