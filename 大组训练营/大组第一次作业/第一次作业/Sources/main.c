#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"
#include "doubleLists.h"
#define _CRT_SECURE_NO_WARNINGS 1

// 定义节点结构体


void displayMenu() {
    int choice;
    do {
        printf("QG训练营第一次作业\n");
        printf("1. 单链表ADT\n");
        printf("2. 双链表ADT\n");
        printf("3. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            singleLists();
            break;
        case 2:
            doubleLists();
            break;
        case 3:
            printf("感谢使用，再见！\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
        }
    } while (choice != 3);
}

int main() {
    displayMenu();
}


