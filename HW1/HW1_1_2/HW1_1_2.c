#define MAX_STACK_SIZE 3// �迭�� �̿��� ������ �������� ������ �ִ� 
#define MAX_STRING_SIZE 10
#include <stdio.h> 
#include <stdlib.h>
/*typedef struct {	int n;	char a[10];}element;        =>element �� ����ü�� �����ϸ� ������ �ٲ�� ����*/// ������ ���� Ÿ�� ����
typedef struct {
	int num;
	char c[MAX_STRING_SIZE];
}StackType;

StackType stack[MAX_STACK_SIZE];
int top = -1;

// ���� �ʱ�ȭ �Լ� 
void init()
{
	top = -1;
}
// ���� ���� ���� �Լ� 
int is_empty()
{
	return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// �����Լ� 
void push(StackType item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		stack[++(top)] = item;
}

// �����Լ� 
StackType pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[(top)--];
}

// ��ũ�Լ� 
StackType peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[top];
}

void stack_print()
{
	int i;
	if (is_empty())
		printf("<empty>\n");
	else {
		for (i = top; i >= 0; i--) {
			if (top == i)
				printf("[%d, %s] <- top\n", stack[i].num, stack[i].c);
			else
				printf("[%d, %s]\n", stack[i].num, stack[i].c);
		}
	}
	printf("--\n");
}

// ���Լ� 
void main()
{
	StackType s;

	StackType n10 = { 10, "ten" };
	StackType n20 = { 20, "twenty" };
	StackType n30 = { 30, "thirty" };
	StackType n40 = { 40, "forty" };
	StackType n50 = { 50, "fifty" };

	init(&s);  stack_print(&s);
	push(n10); stack_print(&s);
	push(n20); stack_print(&s);
	push(n30); stack_print(&s);
	push(n40); stack_print(&s);
	pop();     stack_print(&s);
	push(n50); stack_print(&s);
	pop(&s);   stack_print(&s);
	pop(&s);   stack_print(&s);
	pop(&s);   stack_print(&s);
}