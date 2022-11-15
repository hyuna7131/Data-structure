#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	char name[30];
} element; // 요소의 타입

typedef struct QueueNode { // 큐의 노드의 타입
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { // 큐 ADT 구현
	QueueNode* front, * rear;
} LinkedQueueType;

// 초기화 함수
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedQueueType* q) // 항상 거짓, 포화상태일때가 없다. 연결리스트로 구현하였으므로
{
	return 0;
}
// 삽입 함수
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("메모리를 할당할 수 없습니다");
	else {
		temp->data = item; // 데이터 저장
		temp->link = NULL; // 링크 필드를 NULL
		if (is_empty(q)) { // 큐가 공백이면
			q->front = temp;
			q->rear = temp;
		}
		else { // 큐가 공백이 아니면
			q->rear->link = temp; // 순서가 중요
			q->rear = temp;
		}
	}
}
// 삭제 함수
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // 공백상태
		printf("큐가 비어 있읍니다");
	else {
		item = temp->data; // 데이터를 꺼낸다.
		q->front = q->front->link; // front 를 다음노드를 가리키도록 한다.
		if (q->front == NULL) // 공백 상태
			q->rear = NULL;
		free(temp); // 동적메모리 해제
		return item; // 데이터 반환
	}
}
void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%s ", p->data);
}
int get_count(LinkedQueueType* q) {
	int i, count = 0;
	QueueNode* p;

	for (p = q->front; p != NULL; p = p->link)
		count++;

	return count;
}
// 연결된 큐 테스트 함수
void main()
{
	LinkedQueueType manQ;
	LinkedQueueType womanQ;
	element newPerson;
	char icq;
	char gender;
	element couple[20];

	init(&manQ);
	init(&womanQ);

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
			printf("남성 대기자 %d명 ", get_count(&manQ));
			print_queue(&manQ);
			printf("\n");
			printf("여성 대기자 %d명 ", get_count(&womanQ));
			print_queue(&womanQ);
			printf("\n");
		}
		else
			break;
	}
	
}