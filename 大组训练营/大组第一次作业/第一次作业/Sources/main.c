#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"
#include "doubleLists.h"
#define _CRT_SECURE_NO_WARNINGS 1

// ����ڵ�ṹ��


void displayMenu() {
    int choice;
    do {
        printf("QGѵ��Ӫ��һ����ҵ\n");
        printf("1. ������ADT\n");
        printf("2. ˫����ADT\n");
        printf("3. �˳�\n");
        printf("��ѡ�������");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            singleLists();
            break;
        case 2:
            doubleLists();
            break;
        case 3:
            printf("��лʹ�ã��ټ���\n");
            break;
        default:
            printf("��Ч��ѡ�����������롣\n");
        }
    } while (choice != 3);
}

int main() {
    displayMenu();
}


