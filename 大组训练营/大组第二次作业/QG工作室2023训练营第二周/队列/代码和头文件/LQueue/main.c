#define _CRT_SECURE_NO_WARNINGS 1
#include "LQueue.h"
#include <stdlib.h>
#include <stdio.h>


void displayMenu() {
    int choice;
    LQueue* s = (LQueue*)malloc(sizeof(LQueue));
    QElemType a;
    QElemType e;
    QElemType b;
    int length = 0;
    int ifcontinue;
    do {
        printf("��ʽ����\n");
        printf("1. ��ʼ������\n");
        printf("2. ���\n");
        printf("3. �õ�ͷԪ��\n");
        printf("4. �ж϶����Ƿ�Ϊ��\n");
        printf("5. ��ⳤ��\n");
        printf("6. ��ն���\n");
        printf("7. ���ٶ���\n");
        printf("8. ����\n");
        printf("9. ���\n");
        printf("10. �˳�\n");
        printf("��ѡ�������");
        while (scanf("%d", &choice) != 1) {  // �����벻������ʱ��������뻺����
            while (getchar() != '\n');  // ������뻺����
            printf("������ѡ�������");
        }/*while (scanf("%d", &choice) != 1)����scanf�����ķ���ֵ�����ɹ���ȡ�Ĳ���������
            ���scanf����ֵ����1����ʾδ�ɹ���ȡ1����������
            �����ѭ���壬����ͨ��while(getchar() != '\n')��������뻺������ֱ���������з�Ϊֹ��*/

        switch (choice) {
        case 1://��ʼ��
            InitLQueue(&s);
            break;
        case 2://���
            while (1) {
                if (s == NULL) {
                    printf("���ȳ�ʼ���ӣ�\n");
                    break;
                }
                printf("��������Ҫ��������Ԫ�أ����֣���");
                scanf("%d", &a);
                if (a == 0)
                    break;
                EnLQueue(&s, &a);
            } //������0ʱֹͣ���
            break;
        case 3://�õ�ͷԪ��
            if (GetHeadLQueue(&s, &e) == 1) {
                printf("ͷԪ��Ϊ��%d\n", e); // ��ȷ�ش�ӡջ��Ԫ�ص�ֵ
            }
            else {
                printf("����Ϊ�գ�����ȡͷԪ�أ�\n");
            }
            break;
        case 4://�ж϶����Ƿ�Ϊ��
            if (IsEmptyLQueue(s) == 1) {
                printf("ջ��Ϊ��\n"); // ��ȷ�ش�ӡջ��Ԫ�ص�ֵ
            }
            else {
                printf("ջΪ��\n");
            }
            break;
        case 5://��ⳤ��
            length = LengthLQueue(s);
            if (length > 0) {
                printf("ջ����Ϊ��%d\n", length); 
            }
            else {
                printf("ջΪ��\n");
            }
            break;
        case 6://��ն���
            ClearLQueue(s);
            break;
        case 7://���ٶ���
            DestoryLQueue(&s);
            break;
        case 8://����
            DeLQueue(&s);
            break;
        case 9://���
            LPrint(s);
            break;
        case 10:
            printf("��лʹ�ã��ټ���\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
            break;
        }
    } while (choice != 10);
}


int main() {
    displayMenu();
}