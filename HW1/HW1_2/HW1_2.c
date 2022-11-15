#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100
#define MAX_STRING 100
#include <stdio.h> 
typedef char element;

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

int palindrome(char str[])
{
	StackType s;

	int i;// �ʿ��� ������ ���� 

	init(&s);// ������ �ʱ�ȭ�϶� 

	for (i = 0; str[i] != '\0'; i++) //str �� ���ڵ��� ���ÿ� �ִ´� 
		push(&s, str[i]);

	for (i = 0; str[i] != '\0'; i++) { //���ÿ��� �ϳ��� ���鼭 str �� ���ڵ�� ���ʷ� ��
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
		printf("palindrome �Դϴ�.\n");
	else
		printf("palindrome �� �ƴմϴ�.\n");
}

//������
// 1) �ε��� ù° ������  ��
// 2) ���ο� �迭�� ���� ���� �� ���� ���� �ε��� ù°�� ���ο� �迭 �ε��� ������ ��
