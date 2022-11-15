#define MAX_STACK_SIZE 3// 배열을 이용한 스택은 사이즈의 제한이 있다 
#define MAX_STRING_SIZE 10
#include <stdio.h> 
#include <stdlib.h>
/*typedef struct {	int n;	char a[10];}element;        =>element 를 구조체로 선언하면 나머지 바뀔게 없음*/// 스택을 위한 타입 정의
typedef struct {
	int num;
	char c[MAX_STRING_SIZE];
}StackType;

StackType stack[MAX_STACK_SIZE];
int top = -1;

// 스택 초기화 함수 
void init()
{
	top = -1;
}
// 공백 상태 검출 함수 
int is_empty()
{
	return (top == -1);
}
// 포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// 삽입함수 
void push(StackType item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		stack[++(top)] = item;
}

// 삭제함수 
StackType pop()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return stack[(top)--];
}

// 피크함수 
StackType peek()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
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

// 주함수 
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