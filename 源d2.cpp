#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
	int* pBase;
	int rear;
	int front;
}QUEUE;
void init(QUEUE* q)
{
	q->pBase = (int*)malloc(sizeof(int)*6);
	q->rear = 0;
	q->front = 0;

}
bool is_full(QUEUE* q)
{
	if ((q->rear + 1) % 6 == q->front)
		return true;
	else
		return false;
}
void en_queue(QUEUE* q, int val)
{
	if (is_full(q))
	{
		printf("队列已满，退出程序\n");
		exit(-1);
	}
	else
	{
		q->pBase[q->rear] = val;
		q->rear = (q->rear + 1) % 6;
	}
}

void traverse(QUEUE* q)
{
	int i = q->front;
	while (i!=q->rear)
	{
		printf("%d ", q->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
}
bool is_empty(QUEUE* q)
{
	if (q->rear == q->front)
		return true;
	else
		return false;
}
void quit_queue(QUEUE* q,int *pVal)
{
	if (is_empty(q))
	{
		printf("队列为空，退出程序\n");
	}
	else
	{
		*pVal = q->pBase[q->front];
		q->front = (q->front + 1) % 6;
	}

	
}
int main()
{	
	QUEUE q;
	init(&q);
	en_queue(&q,5);
	en_queue(&q, 6);
	en_queue(&q, 7);
	traverse(&q);
	int val;
	//quit_queue(&q,&val);
	//printf("出队元素为%d\n", val);
	//quit_queue(&q, &val);
	//printf("出队元素为%d\n", val);
	//quit_queue(&q, &val);
	//printf("出队元素为%d\n", val);
	//quit_queue(&q, &val);
	
	traverse(&q);


}
