#include <stdio.h>
#include <stdlib.h>
#include "singleLists.h"

void findCentre(Node* head) {
	Node* p1 = head;
	Node* p2 = head;
	int count = 0;
	while (p2->next != NULL) {
		p2 = p2->next;
		count++;
	}
	if (count % 2 == 0) {
		printf("���е�\n");
	}
	else {
		for (int i = 0; i < (count / 2 + 1); i++) {
			p1 = p1->next;
		}
		printf("��������е�Ϊ��%d\n", p1->data);
	}
}

/**�ϱ������Լ�˼���ģ�����ǲο��Ŀ���ָ�뷨
Node* searchMid(Node* head) {

	Node* fast = head, * slow = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}
**/