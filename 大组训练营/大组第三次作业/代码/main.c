#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"

void displayMenu() {
    int choice;
    do {
        printf("����\n");
        printf("1. ���������µ���ʱ\n");
        printf("2. ����С��������ʱ\n");
        printf("3. ���ɲ�������\n");
        printf("4. �˳�\n");
        printf("��ѡ�������");
        while (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  
            printf("������ѡ�������");
        }

        switch (choice) {
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3_1();
            test3_2();
            break;
        case 4:
            printf("��лʹ�ã��ټ���\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
            break;
        }
    } while (choice != 4);
}


int main() {
    displayMenu();
}
