#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"

int ifRing(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("不成环\n");
        return 0; // 空链表或只有一个节点的链表不是环
    }

    Node* fast = head; // 快指针，每次移动两个节点
    Node* slow = head; // 慢指针，每次移动一个节点

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next; // 快指针每次移动两个节点
        slow = slow->next;       // 慢指针每次移动一个节点

        if (fast == slow) {
            printf("成环\n");
            return 1; // 快慢指针相遇，链表成环
        }
    }
    printf("不成环\n");
    return 0; // 快指针到达链表末尾，链表不环
}