#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // 노드타입
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) // 틀림(수정해야)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	} 
	printf("%d->", p->data); // 마지막노드출력
		printf("\n");
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1) 
		head->link = node; // (2) 
	}
	return head; // 변경된헤드포인터를반환한다.
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1) 
		head->link = node; // (2) 
		head = node; // (3) 
	}
	return head; // 변경된 헤드 포인터를 반환한다.
}
ListNode* delete_first(ListNode* head)
{
	ListNode* temp;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n"); 
		return NULL;
	}
	else if (head == head->link) { // 즉 하나의 노드가 남았을때
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* temp;
	ListNode* p = head->link;
	
	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}
	else if (head == head->link) {
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head;
		while(p->link != head)
			p = p->link;
		p->link = head->link;
		head = p;
		free(temp);
	}
	return head;
}
ListNode* search(ListNode* head, element data)
{
	int count = 0; 
	ListNode* p = head;

	if (head == NULL) {
		printf("리스트가 비어 있음\n");
		return NULL;
	}
	else if (head == head->link) {
		return count;
	}
	else {
		while (p->data != data) {
			count++;
			p = p->link;
		}
		return count;
	}
}
ListNode* get_size(ListNode* head)
{
	int count = 1;
	ListNode* p = head;

	if (head == NULL) {
		printf("리스트가 비어 있음\n");
		return NULL;
	}
	else if (head == head->link) {
		return count;
	}
	else {
		while (p->link != head) {
			count++;
			p = p->link;
		}
		return count;
	}
}
// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;
	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	head = delete_first(head);
	print_list(head);
	/**/
	head = delete_last(head);
	print_list(head);
	
	printf("%d\n", search(head, 20));  //pos 반환

	printf("%d\n", get_size(head));

	return 0;
}