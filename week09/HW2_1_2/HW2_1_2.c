#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct {
	char name[30];
} element; // ����� Ÿ��

typedef struct QueueNode { // ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct { // ť ADT ����
	QueueNode* front, * rear;
} LinkedQueueType;

// �ʱ�ȭ �Լ�
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType* q) // �׻� ����, ��ȭ�����϶��� ����. ���Ḯ��Ʈ�� �����Ͽ����Ƿ�
{
	return 0;
}
// ���� �Լ�
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
	else {
		temp->data = item; // ������ ����
		temp->link = NULL; // ��ũ �ʵ带 NULL
		if (is_empty(q)) { // ť�� �����̸�
			q->front = temp;
			q->rear = temp;
		}
		else { // ť�� ������ �ƴϸ�
			q->rear->link = temp; // ������ �߿�
			q->rear = temp;
		}
	}
}
// ���� �Լ�
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) // �������
		printf("ť�� ��� �����ϴ�");
	else {
		item = temp->data; // �����͸� ������.
		q->front = q->front->link; // front �� ������带 ����Ű���� �Ѵ�.
		if (q->front == NULL) // ���� ����
			q->rear = NULL;
		free(temp); // �����޸� ����
		return item; // ������ ��ȯ
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
// ����� ť �׽�Ʈ �Լ�
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

	printf("���� �ּ� ���α׷��Դϴ�.\n");

	while (1)
	{
		printf("i<nsert, ���Է�>. c<heck, ����� üũ>, q<uit>: ");
		scanf(" %c", &icq);

		if (icq == 'i')
		{
			printf("�̸��� �Է�: ");
			scanf("%s", newPerson.name);
			printf("������ �Է�<m or f>: ");
			scanf(" %c", &gender);
			if (gender == 'm')
			{
				if (is_full(&manQ))
					printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
				else
				{
					enqueue(&manQ, newPerson);
					if (is_empty(&womanQ))
					{
						printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
					}
					else
					{
						couple[0] = dequeue(&womanQ);
						couple[1] = dequeue(&manQ);
						printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", couple[0], couple[1]);
					}
				}

			}
			else
				if (is_full(&womanQ))
					printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
				else
				{
					enqueue(&womanQ, newPerson);
					if (is_empty(&manQ))
					{
						printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
					}
					else
					{
						couple[0] = dequeue(&womanQ);
						couple[1] = dequeue(&manQ);
						printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", couple[0], couple[1]);
					}

				}

		}
		else if (icq == 'c')
		{
			printf("���� ����� %d�� ", get_count(&manQ));
			print_queue(&manQ);
			printf("\n");
			printf("���� ����� %d�� ", get_count(&womanQ));
			print_queue(&womanQ);
			printf("\n");
		}
		else
			break;
	}
	
}