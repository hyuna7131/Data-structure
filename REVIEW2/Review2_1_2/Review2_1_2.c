#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
// 1) typedef���� ����ü Ÿ�� Score ����
typedef struct {
	int midterm;
	int final;
}Score;

void printScore(Score* p) //2) 
{
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�б⸻��� ������ %d\n", p->final);
}
Score* biggerScore(Score* p1, Score* p2) //3) 
{
	int total1, total2;

	total1 = p1->midterm + p1->final;
	total2 = p2->midterm + p2->final;

	if (total1 > total2)
		return p1;
	else
		return p2;
}
Score* totalScore(Score* p1, Score* p2) //4) 
{
	Score* total;
	total = (Score*)malloc(sizeof(Score));

	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;
}
Score* createScore(int m, int f) //5) 
{
	Score* p3;
	p3 = (Score*)malloc(sizeof(Score));

	p3->midterm = m;
	p3->final = f;
}

int main(void) {
	Score s1, s2; // ������ p1, p2��ſ� ����ü���� s1,s2
	Score* p3;

	s1.midterm = 50;
	s1.final = 100;
	s2.midterm = 70;
	s2.final = 70;

	printScore(&s1);
	printScore(&s2);

	printf("-----------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&s1, &s2));

	printf("-----------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(&s1, &s2));

	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}