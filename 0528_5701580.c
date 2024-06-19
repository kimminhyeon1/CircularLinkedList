#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* tail) {
	ListNode* p;

	if (tail == NULL) return;
	p = tail->link;
	while (p != tail) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d (head)\n", p->data);
}
ListNode* insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}
ListNode* insert_last(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
		tail = node;
	}
	return tail;
}
ListNode* delete_first(ListNode* tail) {
	ListNode* removed;
	if (tail == NULL)return NULL;
	removed = tail->link;
	tail->link = removed->link;
	free(removed);
	return tail;
}
ListNode* delete_last(ListNode* tail) {
	ListNode* removed, * pre;
	if (tail == NULL)return NULL;
	pre = tail->link;
	while (pre->link != tail) {
		pre = pre->link;
	}
	removed = tail;
	pre->link = removed->link;
	tail = pre;
	free(removed);
	return tail;
}
int main() {
	ListNode* tail = NULL;
	int choice, num;

	while (1) {
		printf("\n메뉴:\n");
		printf("1: 숫자 입력 받아서 리스트 처음에 추가\n");
		printf("2: 숫자 입력 받아서 리스트 마지막에 추가\n");
		printf("3: 리스트 처음 노드 삭제\n");
		printf("4: 리스트 마지막 노드 삭제\n");
		printf("5: 리스트 프린트\n");
		printf("6: 종료\n");
		printf("메뉴를 선택하세요: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &num);
			tail = insert_first(tail, num);
			break;
		case 2:
			printf("추가할 숫자를 입력하세요: ");
			scanf("%d", &num);
			tail = insert_last(tail, num);
			break;
		case 3:
			tail = delete_first(tail);
			printf("리스트의 처음 노드를 삭제하였습니다.\n");
			break;
		case 4:
			tail = delete_last(tail);
			printf("리스트의 마지막 노드를 삭제하였습니다.\n");
			break;
		case 5:
			print_list(tail);
			break;
		case 6:
			printf("프로그램을 종료합니다.\n");
			exit(0);
		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n");
			break;
		}
	}

	return 0;
}