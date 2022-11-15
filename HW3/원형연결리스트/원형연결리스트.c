#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // ���Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) // Ʋ��(�����ؾ�)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	} 
	printf("%d->", p->data); // ������������
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
	return head; // �������������͸���ȯ�Ѵ�.
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
	return head; // ����� ��� �����͸� ��ȯ�Ѵ�.
}
ListNode* delete_first(ListNode* head)
{
	ListNode* temp;

	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n"); 
		return NULL;
	}
	else if (head == head->link) { // �� �ϳ��� ��尡 ��������
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
		printf("����Ʈ�� ��� ������ ����\n");
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
		printf("����Ʈ�� ��� ����\n");
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
		printf("����Ʈ�� ��� ����\n");
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
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
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
	
	printf("%d\n", search(head, 20));  //pos ��ȯ

	printf("%d\n", get_size(head));

	return 0;
}