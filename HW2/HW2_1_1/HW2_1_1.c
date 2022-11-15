#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
	char name[30];
}element; 

typedef struct {
	int front;
	int rear;
	element queue[MAX_QUEUE_SIZE];
}QueueType;

void error(char* message) {
	fprintf("stderr, %s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_full(QueueType* q)
{
	return (q->front == (q->rear + 1) % MAX_QUEUE_SIZE);
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) 
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q)) 
		error("큐가 공백상태입니다.");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}

void queue_print(QueueType* q)
{
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%s ", q->queue[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	
}

int get_count(QueueType *q)
{
	if (q->rear >= q->front)
		return q->rear - q->front;
	else
		return (q->rear + MAX_QUEUE_SIZE) - q->front;

}

int main(void)
{
	QueueType manQ;
	QueueType womanQ;
	element newPerson;
	char icq;
	char gender;
	element couple[20];

	init_queue(&manQ);
	init_queue(&womanQ);

	printf("미팅 주선 프로그램입니다.\n");

	while (1)
	{
		printf("i<nsert, 고객입력>. c<heck, 대기자 체크>, q<uit>: ");
		scanf(" %c", &icq);

		if (icq == 'i')
		{
			printf("이름을 입력: ");
			scanf("%s", newPerson.name);
			printf("성별을 입력<m or f>: ");
			scanf(" %c", &gender);
			if (gender == 'm')
			{
				if (is_full(&manQ)) 
					printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
				else
				{
					enqueue(&manQ, newPerson);
					if (is_empty(&womanQ))
					{
						printf("아직 대상자가 없습니다. 기다려주십시오.\n");
					}
					else
					{
						couple[0] = dequeue(&womanQ);
						couple[1] = dequeue(&manQ);
						printf("커플이 탄생했습니다! %s과 %s\n", couple[0], couple[1]);
					}
				}
					
			}
			else
				if (is_full(&womanQ)) 
					printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용\n");
				else 
				{
					enqueue(&womanQ, newPerson);
					if (is_empty(&manQ))
						{
						printf("아직 대상자가 없습니다. 기다려주십시오.\n");
						}
					else
					{						
						couple[0] = dequeue(&womanQ);
						couple[1] = dequeue(&manQ);
						printf("커플이 탄생했습니다! %s과 %s\n", couple[0], couple[1]);
					}
						
				}					
				
		}
		else if (icq == 'c')
		{
			printf("남성 대기자 %d명: ", get_count(&manQ));
			queue_print(&manQ);
			printf("\n");
			printf("여성 대기자 %d명: ", get_count(&womanQ));
			queue_print(&womanQ);
			printf("\n");
		}
		else
			break;
	}
}