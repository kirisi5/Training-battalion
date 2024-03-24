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
        printf("链栈\n");
        printf("1. 初始化栈\n");
        printf("2. 入栈\n");
        printf("3. 得到栈顶元素\n");
        printf("4. 判断栈是否为空\n");
        printf("5. 检测长度\n");
        printf("6. 清空栈\n");
        printf("7. 销毁栈\n");
        printf("8. 出栈\n");
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
            s = initLStack();
            break;
        case 2://入栈
            while (1){
                if (s == NULL) {
                    printf("请先初始化栈！\n");
                    break;
                }
                printf("请输入想要输入存入的元素（数字）：");
                scanf("%d", &a);
                if (a == 0)
                    break;
                pushLStack(s,a);
            } //当输入0时停止入栈
            break;
        case 3://得到栈顶元素
            if (getTopLStack(s, &e) == 1) {
                printf("栈顶元素为：%d\n", e); // 正确地打印栈顶元素的值
            }
            else {
                printf("栈为空，不能取栈顶元素！\n");
            }
            break;
        case 4://判断栈是否为空
            if (isEmptyLStack(s) == 1) {
                printf("栈不为空\n"); // 正确地打印栈顶元素的值
            }
            else {
                printf("栈为空\n");
            }
            break;
        case 5://检测长度
            length = LStackLength(s);
            if (length > 0) {
                printf("栈长度为：%d\n", length); // 正确地打印栈顶元素的值
            }
            else {
                printf("栈为空\n");
            }
            break;
        case 6://清空栈
            clearLStack(s);
            break;
        case 7://销毁栈
            destroyLStack(&s);
            break;
        case 8://出栈
            popLStack(s,&b);
            break;
        case 9://输出
            display(s);
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