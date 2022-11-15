#include <stdio.h>
#include <malloc.h>

// 스택을 위한 타입 정의
typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType* s) // Stack 연산중의 하나라 남겨두었지만 항상 거짓을 반환. 즉 꽉 차있을 때는 없음
{
	return 0;
}
// 삽입 함수
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
// 삭제 함수
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// 피크 함수
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
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
			printf("%d <- top\n", p->data);
		else
			printf("%d\n", p->data);
	}
	printf("--\n");
	
}
// 주 함수
void main()
{
	LinkedStackType s;
	init(&s);  stack_print(&s);
	push(&s, 10); stack_print(&s);
	push(&s, 20); stack_print(&s);
	push(&s, 30); stack_print(&s);
	push(&s, 40); stack_print(&s);
	pop(&s); stack_print(&s);
	push(&s, 50); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);
	pop(&s); stack_print(&s);

	return 0;
}