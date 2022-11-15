#include <stdio.h> 
#define MAX_STACK_SIZE 3 // �迭�� �̿��� ������ �������� ������ �ִ� // ������ ���� Ÿ�� ���� 
typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ �Լ� 
void init(StackType* s)
{
	s->top = -1;
}
// ���� ���� ���� �Լ� 
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ� 
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->stack[++(s->top)] = item;
}

// �����Լ� 
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

// ��ũ�Լ� 
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->stack[s->top];
}

void stack_print(StackType* s)
{
	int i;
	if (is_empty(s))
		printf("<empty>\n");
	else {
		for (i = s->top; i >= 0; i--) {
			if (s->top == i)
				printf("%d <- top\n", peek(s));
			else
				printf("%d\n", s->stack[i]);
		}
	}
	printf("--\n");
}
/*
if (is_empty(s))
		printf("<empty>\n");
	else {
		for (i = s->top; i >= 0; i--) {
		printf("%d\n", s->stack[i]);
			if (s->top == i)
				printf("%d <- top\n");
		}
	}
	printf("--\n");
*/

// ���Լ� 
void main()
{
	StackType s;
	init(&s);     stack_print(&s);
	push(&s, 10); stack_print(&s);
	push(&s, 20); stack_print(&s);
	push(&s, 30); stack_print(&s);
	push(&s, 40); stack_print(&s);
	pop(&s);      stack_print(&s);
	push(&s, 50); stack_print(&s);
	pop(&s);      stack_print(&s);
	pop(&s);      stack_print(&s);
	pop(&s);      stack_print(&s);
}