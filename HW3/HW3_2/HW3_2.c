#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = head->link;
	ListNode* removed;
	if (head == NULL) error("������ �׺��� ����");
	
	if (head->link == NULL) {
		removed = head;
		head = NULL;
	}
	else {
		while (temp->link != NULL){
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;
	}
	free(removed);
	return head; 
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int is_in_list(ListNode* head, element item)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		if (p->data == item)
			return 1;
	return 0;
}

int get_length(ListNode* head)
{
	ListNode* temp = head;
	int count=0;

	while (temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}

int get_total(ListNode* head)
{
	ListNode* temp = head;
	int sum = 0;

	while (temp != NULL) {
		sum += temp->data;
		temp = temp->link;
	}
	return sum;
}

element get_entry(ListNode* head, int pos)
{
	ListNode* p;
	int cnt = 0;
	if (get_length(head) < pos)
		error("index ���� ����Ʈ ���̺��� ŭ");
	for (p = head; p != NULL; p = p->link) {
		if (cnt == pos)
			return p->data;
		cnt++;
	}
	return NULL;
}

ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* temp = head;
	ListNode* prevTemp = head->link;
	ListNode* removed;

	if (!is_in_list(head, key))
		error("list�� key�� ����");

	if (head->data == key) {
		head = head->link;
		free(temp);
	}
	else if (get_entry(head, get_length(head)) == key) {
		while (temp->data != key) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;

		free(removed);
	}

	else {
		while (temp->data != key) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = removed->link;

		free(removed);
	}
	return head;
}

ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* cur = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;

	if (pos == 0) {
		p->link = head->link;
		head->link = p;
	}
	else if (pos == get_length(head)) {
		if (head == NULL)
			head = p;
		else {
			while (cur->link != 0)
				cur = cur->link;
			cur->link = p;
		}
	}
	else {
		int count = 0;

		while (count != pos) {
			if (count == (pos - 1)) {
				p->link = cur->link;
				cur->link = p;
			}
			cur = cur->link;
			count++; 
		}
	}
	return head;
}

ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 
	p->data = value;
	p->link = NULL;
	// (2)
	if (head == NULL) 
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}

ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* prevTemp;

	if (pos == 0)
		head = delete_first(head);
	else if (pos == get_length(head))
		head = delete_last(head);
	else {
		prevTemp = is_in_list(head, get_entry(head, pos - 1)); //ListNode
		head = delete(head, prevTemp);
	}
	return head;
}

ListNode* concatenate(ListNode* head, ListNode* combine )
{
	ListNode* p;
	if (head == NULL) return combine;
	else if (combine == NULL) return head;
	else {
		p = head;
		while (p->link != NULL)
			p = p->link;
		p->link = combine;
		return head;
	}

	/*
	ListNode* temp;

	for (temp = head; temp->link; temp = temp->link);
	temp->link = combine;
	
	return head;
	*/
}

int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3 = NULL;

	//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->10->NULL
	list1 = delete_first(list1);
	// list1�� ���
	print_list(list1);
	//list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�.
	list2 = insert_first(list2, 11);
	list2 = insert(list2, list2, 22);
	list2 = insert_pos(list2, 2, 33);
	list2 = insert_pos(list2, 3, 44);
	//list2�� ���
	print_list(list2);
	// list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33->
	list2 = delete_last(list2);
	// list2�� ���
	print_list(list2);
	//list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����. 
	list3 = insert_first(list3, 11);
	list3 = insert_first(list3, 22);
	list3 = insert_first(list3, 33);
	//list3�� ����Ѵ�. 
	print_list(list3);
	// list1 = 20->30->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�. 
	list1 = concatenate(list1, list3);
	//list1�� ����Ѵ�. 
	print_list(list1);

	//(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ���� 
	if (is_in_list(list1, 33))
		printf("33�� ����Ʈ �ȿ� �ֽ��ϴ�.\n");
	else
		printf("����Ʈ �ȿ� �����ϴ�.\n");

	printf("list1: ��ü ������ %d�Դϴ�.\n", get_length(list1));

	printf("list1 data�� ��ü ��: %d\n", get_total(list1));

	printf("3��° ����� data: %d\n", get_entry(list1, 3));
	
	list1 = delete_by_key(list1, 11);
	print_list(list1);

	list1 = insert_pos(list1, 4, 3);
	print_list(list1);

	list1 = delete_pos(list1, 5);
	print_list(list1);
}