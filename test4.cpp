#include<stdio.h>
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
	int input;

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("动态内存分配失败");
		
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入链表长度为len=\n ");
	scanf_s("%d", &len);
	
	

	for ( i = 0; i < len; i++)
	{
		printf("请输入第%d个结点的值", i + 1);
		scanf_s("%d", &input);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("动态内存分配失败");
			
		}
		
		
			/*pNew->data = input;
			pTail->pNext = pNew;
			pTail = pNew;
			pTail->pNext = NULL;*/
			
		pNew->data = input;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;

		
			

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
bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}

int length_list(PNODE pHead)
{
	/*int length=0;
	while (pHead->pNext!=NULL)
	{
		pHead = pHead->pNext;
		length++;
	}
	return length;*/
	PNODE p = pHead->pNext;
	int length = 0;
	while (p!=NULL)
	{
		p = p->pNext;
		length++;
	}
	return length;
}

bool insert_list(PNODE pHead, int pos, int val)
{
	PNODE p = pHead;
	int i = 0;
	while (p!=NULL && i>pos-1)
	{
		p = p->pNext;
		i++;
	}

	if (p == NULL  || pos<1)
		return  false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("动态内存分配失败");
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;

}
bool delete_list(PNODE pHead, int pos, int* e)
{
	PNODE p=pHead;
	int i = 0;
	while (p->pNext!=NULL && i<pos-1 )
	{
		p = p->pNext;
		i++;
	}
	if (p->pNext == NULL || i > pos - 1)
		return false;
	PNODE q = p->pNext;
	*e = q->data;
	p->pNext = q->pNext;
	free(q);
	q = NULL;
	return true;
}
void sort_list(PNODE pHead)
{
	int i, j, t;
	int length = length_list(pHead);
	PNODE p, q;
	for (i = 0,p=pHead->pNext; i < length-1; i++,p=p->pNext)
	{
		for (j = i+1,q=p->pNext; j < length; j++,q=q->pNext)
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
	int list_len;
	//初始化链表
	pHead = create_list();
	int e;
	//printf("%d \n", pHead->pNext->pNext->data);
	//遍历链表
	/*traverse_list(pHead);
	list_len = length_list(pHead);
	printf("当前链表的长度为%d\n", list_len);*/
//	printf("%d ", pHead->pNext->pNext->data);
	//if (insert_list(pHead, 3, 4))
	//	printf("插入成功\n");
	//else
	//{
	//	printf("插入失败");
	//}
	//traverse_list(pHead);
	/*delete_list(pHead,2,&e);
	traverse_list(pHead);*/
	sort_list(pHead);
	traverse_list(pHead);
}