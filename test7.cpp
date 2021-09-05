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
	printf("\n");

}

bool insert_list(PNODE pHead,int pos,int val)
{
	int i = 0;
	PNODE p = pHead;
	while (p != NULL && i < pos - 1)
	{
		p = p->pNext;
		i++;
	}

	if (i>pos-1 || p==NULL)
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态分配内存失败\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;

}

bool delete_list(PNODE pHead, int pos, int* val)
{
	int i=0;
	PNODE p = pHead;
	while (p->pNext!=NULL && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	if (p->pNext == NULL || i > pos - 1)
		return false;
	PNODE q = p->pNext;
	*val = q->data;
	p->pNext = q->pNext;
	free(q);
	q = NULL;
	return true;
}

int length_list(PNODE pHead)
{

	int len = 0;
	PNODE p = pHead->pNext;
	while (p!=NULL)
	{
		len++;
		p = p->pNext;
	}
	return len;

}
void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p,q;

	for ( i = 0,p=pHead->pNext; i < len; i++,p=p->pNext)
	{
		for (j= i+1,q = p->pNext; j < len; j++,q=q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}
int main()
{
	PNODE pHead = NULL;

	pHead = create_list();
	traverse_list(pHead);
	/*insert_list(pHead, 2, 3);
	traverse_list(pHead);*/
	/*int val;
	delete_list(pHead, 2, &val);
	traverse_list(pHead);*/

	sort_list(pHead);

	traverse_list(pHead);

	


}