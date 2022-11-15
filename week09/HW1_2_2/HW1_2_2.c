#include <stdio.h>
#include <malloc.h>

// ������ ���� Ÿ�� ����
typedef struct {
	int n;
	char a[10];
} element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// �ʱ�ȭ �Լ�
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) // Stack �������� �ϳ��� ���ܵξ����� �׻� ������ ��ȯ. �� �� ������ ���� ����
{
	return 0;
}
// ���� �Լ�
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// ��ũ �Լ�
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}
void stack_print(LinkedStackType* s)
{
	StackNode* p = s;

	if (is_empty(p))
		printf("(empty)\n");

	for (p = s->top; p != NULL; p = p->link) {
		if (p == s->top)
			printf("[%d, %s] <- top\n", p->data.n, p->data.a);
		else
			printf("[%d. %s]\n", p->data.n, p->data.a);
	}
	printf("--\n");

}
// �� �Լ�
void main()
{
	LinkedStackType s;
	
	element n10 = { 10, "ten" };
	element n20 = { 20, "twenty" };
	element n30 = { 30, "thirty" };
	element n40 = { 40, "forty" };
	element n50 = { 50, "fifty" };

	init(&s);  stack_print(&s);
	push(&s, n10); stack_print(&s);
	push(&s, n20); stack_print(&s);
	push(&s, n30); stack_print(&s);
	push(&s, n40); stack_print(&s);
	pop(&s); stack_print(&s);
	push(&s, n50); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);

	return 0;
}