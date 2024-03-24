#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"

// 交换两个整数地址a和b中的值的函数
void swap(int* a, int* b) {
    int temp; // 临时变量用于存储一个值
    temp = *a; // 将a的值存入temp
    *a = *b; // 将b的值赋给a
    *b = temp; // 将temp的值赋给b，实现交换
}

// 两两交换链表中元素的功能
void SchangeParity(Node* head) {
    Node* temp = head->next; // 临时指针用于遍历链表

    // 只遍历链表中至少有两个节点的情况
    while (temp != NULL && temp->next != NULL) {
        // 交换temp节点和temp的下一个节点的数据
        swap(&temp->data, &temp->next->data);

        // 将temp移动到下一个节点（跳过下一个节点）
        temp = temp->next->next;
    }
}