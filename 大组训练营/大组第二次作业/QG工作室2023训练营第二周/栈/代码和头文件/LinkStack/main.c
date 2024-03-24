#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "LinkStack.h"

void displayMenu() {
    int choice;
    LinkStack* s;
    ElemType a;
    ElemType e;
    ElemType b;
    int length = 0;
    int ifcontinue;
    do {
        printf("��ջ\n");
        printf("1. ��ʼ��ջ\n");
        printf("2. ��ջ\n");
        printf("3. �õ�ջ��Ԫ��\n");
        printf("4. �ж�ջ�Ƿ�Ϊ��\n");
        printf("5. ��ⳤ��\n");
        printf("6. ���ջ\n");
        printf("7. ����ջ\n");
        printf("8. ��ջ\n");
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
            s = initLStack();
            break;
        case 2://��ջ
            while (1){
                if (s == NULL) {
                    printf("���ȳ�ʼ��ջ��\n");
                    break;
                }
                printf("��������Ҫ��������Ԫ�أ����֣���");
                scanf("%d", &a);
                if (a == 0)
                    break;
                pushLStack(s,a);
            } //������0ʱֹͣ��ջ
            break;
        case 3://�õ�ջ��Ԫ��
            if (getTopLStack(s, &e) == 1) {
                printf("ջ��Ԫ��Ϊ��%d\n", e); // ��ȷ�ش�ӡջ��Ԫ�ص�ֵ
            }
            else {
                printf("ջΪ�գ�����ȡջ��Ԫ�أ�\n");
            }
            break;
        case 4://�ж�ջ�Ƿ�Ϊ��
            if (isEmptyLStack(s) == 1) {
                printf("ջ��Ϊ��\n"); // ��ȷ�ش�ӡջ��Ԫ�ص�ֵ
            }
            else {
                printf("ջΪ��\n");
            }
            break;
        case 5://��ⳤ��
            length = LStackLength(s);
            if (length > 0) {
                printf("ջ����Ϊ��%d\n", length); // ��ȷ�ش�ӡջ��Ԫ�ص�ֵ
            }
            else {
                printf("ջΪ��\n");
            }
            break;
        case 6://���ջ
            clearLStack(s);
            break;
        case 7://����ջ
            destroyLStack(&s);
            break;
        case 8://��ջ
            popLStack(s,&b);
            break;
        case 9://���
            display(s);
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