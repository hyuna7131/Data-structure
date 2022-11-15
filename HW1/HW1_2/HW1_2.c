#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAX_STRING 100
#include <stdio.h> 
typedef char element;

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

int palindrome(char str[])
{
	StackType s;

	int i;// 필요한 변수들 선언 

	init(&s);// 스택을 초기화하라 

	for (i = 0; str[i] != '\0'; i++) //str 의 문자들을 스택에 넣는다 
		push(&s, str[i]);

	for (i = 0; str[i] != '\0'; i++) { //스택에서 하나씩 빼면서 str 의 문자들과 차례로 비교
		if (pop(&s) != str[i])
			return 0;
		else
			return 1;
	}
}

int main(void) {
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome 입니다.\n");
	else
		printf("palindrome 이 아닙니다.\n");
}

//원래는
// 1) 인덱스 첫째 마지막  비교
// 2) 새로운 배열에 문자 저장 후 원래 문자 인덱스 첫째랑 새로운 배열 인덱스 마지막 비교
