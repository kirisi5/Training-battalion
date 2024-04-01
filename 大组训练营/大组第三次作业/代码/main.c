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
        printf("排序\n");
        printf("1. 大数据量下的用时\n");
        printf("2. 大量小数据量用时\n");
        printf("3. 生成测试数据\n");
        printf("4. 退出\n");
        printf("请选择操作：");
        while (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  
            printf("请重新选择操作：");
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
            printf("感谢使用，再见！\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }
    } while (choice != 4);
}


int main() {
    displayMenu();
}
