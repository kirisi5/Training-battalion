#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

// ��ʼ����ջ
LinkStack* initLStack() {
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    if (s == NULL) {
        return NULL; // �ڴ����ʧ�ܣ����� NULL
    }
    s->top = NULL;
    s->count = 0;
    return s;
}

// �ж���ջ�Ƿ�Ϊ��
int isEmptyLStack(LinkStack* s) {
    if (s->top == NULL) {
        return 0; // ջΪ��
    }
    else {
        return 1; // ջ��Ϊ��
    }
}

// ��ջ
void pushLStack(LinkStack* s, ElemType data) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode)); // �����½ڵ�
    p->data = data;
    p->next = s->top; // ���½ڵ����ջ��
    s->top = p; // ����ջ��ָ��
    s->count++;
}

// ��ջ
void popLStack(LinkStack* s, ElemType* data) {
    if (isEmptyLStack(s)==1) {
        *data = s->top->data; // �����ջԪ��
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
        s->count--;
    }
}

// ��ȡջ��Ԫ��
int getTopLStack(LinkStack* s, ElemType* e) {
    if (isEmptyLStack(s)==0) {
        printf("ջ�գ�����ȡջ��Ԫ�أ�\n");
        return 0;
    }
    else {
        *e = s->top->data;
        return 1;
    }
}

// ���ջ
void clearLStack(LinkStack* s) {
    while (isEmptyLStack(s)==1) {
        ElemType m;
        popLStack(s, &m);
    }
}

// ����ջ
void destroyLStack(LinkStack** s) {
    clearLStack(*s); // ���ջԪ��
    free(*s); // �ͷ�ջ�ṹ�ڴ�
    *s = NULL; // ��ջָ���ÿ�
}

// ���ջ����
int LStackLength(LinkStack* s) {
    int length = 0;
    LinkStackPtr current = s->top;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// �����ջ����ջ��
void display(LinkStack* s) {
    if (s == NULL) {
        printf("ջ�����ڣ�\n");
        return;
    }

    else if (isEmptyLStack(s)==0) {
        printf("ջΪ�գ�\n");
        return;
    }
    else {
        LinkStackPtr current = s->top; // ʹ����ʱָ�����ջ
        while (current != NULL) {
            printf("%d ", current->data); // ��ӡ��ǰԪ�ص�ֵ
            current = current->next; // �ƶ�����һ��Ԫ��
        }
        printf("\n");
    }
}