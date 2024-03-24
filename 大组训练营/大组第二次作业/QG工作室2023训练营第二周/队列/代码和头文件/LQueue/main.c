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
        printf("链式队列\n");
        printf("1. 初始化队列\n");
        printf("2. 入队\n");
        printf("3. 得到头元素\n");
        printf("4. 判断队列是否为空\n");
        printf("5. 检测长度\n");
        printf("6. 清空队列\n");
        printf("7. 销毁队列\n");
        printf("8. 出队\n");
        printf("9. 输出\n");
        printf("10. 退出\n");
        printf("请选择操作：");
        while (scanf("%d", &choice) != 1) {  // 当输入不是整数时，清空输入缓冲区
            while (getchar() != '\n');  // 清空输入缓冲区
            printf("请重新选择操作：");
        }/*while (scanf("%d", &choice) != 1)会检查scanf函数的返回值，即成功读取的参数个数。
            如果scanf返回值不是1（表示未成功读取1个整数），
            则进入循环体，其中通过while(getchar() != '\n')来清空输入缓冲区，直到遇到换行符为止。*/

        switch (choice) {
        case 1://初始化
            InitLQueue(&s);
            break;
        case 2://入队
            while (1) {
                if (s == NULL) {
                    printf("请先初始化队！\n");
                    break;
                }
                printf("请输入想要输入存入的元素（数字）：");
                scanf("%d", &a);
                if (a == 0)
                    break;
                EnLQueue(&s, &a);
            } //当输入0时停止入队
            break;
        case 3://得到头元素
            if (GetHeadLQueue(&s, &e) == 1) {
                printf("头元素为：%d\n", e); // 正确地打印栈顶元素的值
            }
            else {
                printf("队列为空，不能取头元素！\n");
            }
            break;
        case 4://判断队列是否为空
            if (IsEmptyLQueue(s) == 1) {
                printf("栈不为空\n"); // 正确地打印栈顶元素的值
            }
            else {
                printf("栈为空\n");
            }
            break;
        case 5://检测长度
            length = LengthLQueue(s);
            if (length > 0) {
                printf("栈长度为：%d\n", length); 
            }
            else {
                printf("栈为空\n");
            }
            break;
        case 6://清空队列
            ClearLQueue(s);
            break;
        case 7://销毁队列
            DestoryLQueue(&s);
            break;
        case 8://出队
            DeLQueue(&s);
            break;
        case 9://输出
            LPrint(s);
            break;
        case 10:
            printf("感谢使用，再见！\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }
    } while (choice != 10);
}


int main() {
    displayMenu();
}