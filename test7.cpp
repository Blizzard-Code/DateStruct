#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;
	struct Node* pNext;

}NODE,*PNODE;

PNODE create_list()
{
	int len;
	int i;
	int val;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}

	PNODE pTail=pHead;
	pTail->pNext = NULL;

	printf("请输入要生成的节点的个数\n");
	scanf_s("%d", &len);

	for (i = 0; i < len; i++)
	{
		printf("请输入节点的值");
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pHead == NULL)
		{
			printf("动态内存分配失败\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pTail = pNew;
		pTail->pNext = NULL;

	}
	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;

	while (p!=NULL)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}

}

void insert_list()
{

}

int main()
{
	PNODE pHead = NULL;

	pHead = create_list();
	traverse_list(pHead);

}