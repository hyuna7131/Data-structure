#include <stdio.h> 
#define MAX_STACK_SIZE 3 // 배열을 이용한 스택은 사이즈의 제한이 있다 // 스택을 위한 타입 정의 
typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

// 스택 초기화 함수 
void init(StackType* s)
{
	s->top = -1;
}
// 공백 상태 검출 함수 
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수 
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->stack[++(s->top)] = item;
}

// 삭제함수 
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

// 피크함수 
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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

// 주함수 
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