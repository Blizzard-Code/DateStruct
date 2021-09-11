#include <stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Queue
{
	int* pBase;
	int rear;
	int front;

}QUEUE;

void init(QUEUE *pQ);
bool en_queue(QUEUE* pQ,int val);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *pQ);
bool out_queue(QUEUE* pQ,int *pVal);
int main()
{
	Queue Q;
	init(&Q);
	int val;
	en_queue(&Q,1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	traverse_queue(&Q);
	if (out_queue(&Q, &val))
	{
		printf("出队成功，队列出队的元素是%d ", val);
		printf("\n");
	}
	else
	{
		printf("出队失败");
	}
	traverse_queue(&Q);

}
void init(QUEUE* pQ)
{
	pQ->pBase = (int*)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

bool en_queue(QUEUE* pQ, int val)
{
	if (full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}


}
void traverse_queue(QUEUE* pQ)
{
	int i = pQ->front;
	while (i!=pQ->rear)
	{
		printf("%d ", pQ->pBase[i]);
		i = (i+1) % 6;
	}
	printf("\n");
}

bool full_queue(QUEUE* pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}

bool empty_queue(QUEUE* pQ)
{
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}

bool out_queue(QUEUE* pQ,int *pVal)
{
	if (empty_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}

