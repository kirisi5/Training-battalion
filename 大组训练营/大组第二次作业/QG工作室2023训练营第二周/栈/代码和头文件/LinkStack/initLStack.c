#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

// 初始化链栈
LinkStack* initLStack() {
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    if (s == NULL) {
        return NULL; // 内存分配失败，返回 NULL
    }
    s->top = NULL;
    s->count = 0;
    return s;
}

// 判断链栈是否为空
int isEmptyLStack(LinkStack* s) {
    if (s->top == NULL) {
        return 0; // 栈为空
    }
    else {
        return 1; // 栈不为空
    }
}

// 入栈
void pushLStack(LinkStack* s, ElemType data) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); // 创建新节点
    p->data = data;
    p->next = s->top; // 将新节点插入栈顶
    s->top = p; // 更新栈顶指针
    s->count++;
}

// 出栈
void popLStack(LinkStack* s, ElemType* data) {
    if (isEmptyLStack(s)==1) {
        *data = s->top->data; // 保存出栈元素
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
        s->count--;
    }
}

// 获取栈顶元素
int getTopLStack(LinkStack* s, ElemType* e) {
    if (isEmptyLStack(s)==0) {
        printf("栈空，不能取栈顶元素！\n");
        return 0;
    }
    else {
        *e = s->top->data;
        return 1;
    }
}

// 清空栈
void clearLStack(LinkStack* s) {
    while (isEmptyLStack(s)==1) {
        ElemType m;
        popLStack(s, &m);
    }
}

// 销毁栈
void destroyLStack(LinkStack** s) {
    clearLStack(*s); // 清空栈元素
    free(*s); // 释放栈结构内存
    *s = NULL; // 将栈指针置空
}

// 检测栈长度
int LStackLength(LinkStack* s) {
    int length = 0;
    LinkStackPtr current = s->top;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// 输出从栈顶至栈底
void display(LinkStack* s) {
    if (s == NULL) {
        printf("栈不存在！\n");
        return;
    }

    else if (isEmptyLStack(s)==0) {
        printf("栈为空！\n");
        return;
    }
    else {
        LinkStackPtr current = s->top; // 使用临时指针遍历栈
        while (current != NULL) {
            printf("%d ", current->data); // 打印当前元素的值
            current = current->next; // 移动到下一个元素
        }
        printf("\n");
    }
}