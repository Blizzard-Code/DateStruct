#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;//数据域
	struct Node* pNext;//指针域
}NODE,*PNODE;//NODE相当于 struct Node*PNODE相当于 struct Node *

PNODE create_list();
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
//在pHead指向的链表的第pos个节点的前面插入一个新的结点  该节点的值是val,并且pos从1开始
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int* pVal);
//排序链表
void sort_list(PNODE pHead);


int main()
{
	PNODE pHead = NULL; //等价于 struct Node *phead=NULL

	pHead = create_list();//创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
	traverse_list(pHead);
	int val;
	/*insert_list(pHead, 4, 33);
	traverse_list(pHead);*/

	if (delete_list(pHead, 3, &val))
		printf("删除成功,删除元素为：%d\n", val);
	else
		printf("删除失败\n");
	traverse_list(pHead);
	/*if (is_empty(pHead))
		printf("链表为空");
	else
	{
		printf("链表不空");
	}*/


	/*int len = length_list(pHead);
	printf("链表长度为%d\n", len);
	sort_list(pHead); 
	traverse_list(pHead);*/

	
}

//创建一个非循环单链表，
PNODE create_list()
{
	int len;//用来存放有效节点的个数
	int i;
	int val;//用来临时存放用户输入的节点值

	//分配了一个不存放有效数据的头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//头结点①
	if (pHead == NULL)
	{
		printf("分配失败，程序终止\n");
		exit(-1);
	}
	PNODE pTail = pHead;//pTail和pHEAD都指向头结点 ②
	pTail->pNext = NULL;//头结点的指针域情空③

	printf("请输入需要生存链表节点的个数：len = " );
	scanf_s("%d", &len);

	for ( i = 0; i < len; i++)
	{
		printf("请输入%d个节点的值", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//④
		if (pNew == NULL)  
		{  
			printf("分配失败，程序终止\n");
			exit(-1);
		}
		pNew->data = val; //生成临时节点⑤
		pTail->pNext = pNew; //指向新造的pNew的节点，pNew放在pTail的后面 ⑥
		pNew->pNext = NULL;//新造的节点的指针域为空⑦
		pTail = pNew;//Ptail永远指向指向尾节点，⑧
	}
	printf("------------------------------\n");

	return pHead;

}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;//p指向第一个有效节点
	
	while (NULL != p)//判断p指向的节点的
	{
		
		printf("%d\n", p->data);
		p = p->pNext;
	}
	printf("\n");
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
	PNODE p = pHead->pNext;
	int len=0;
	while (NULL!=p)
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
	PNODE p, q;
	for (i=0,p=pHead->pNext; i< len - 1;i++, p=p->pNext)
	{
		for (j = i + 1, q = p->pNext; j < len; j++,q=q->pNext)//下一个元素
		{
			if (p->data > q->data)//类似域a[i] > a[j]
			{
				t = p->data; //类似域t=a[i];
				p->data = q->data;//a[i]=a[j]
				q->data = t;//a[j]=t
			}

		}
	}
}

//在pHead指向的链表的第pos个节点的前面插入一个新的结点  该节点的值是val,并且pos从1开始
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	//判断越界
	while (NULL!=p && i<pos-1)
	{
		p = p->pNext;
		++i;
	}
	//判断负数
	if (i>pos-1 || NULL == p)
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL==pNew)
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
bool delete_list(PNODE pHead, int pos, int* pVal)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext)
		return false;

	PNODE q = p->pNext;
	*pVal = q->data;
	//删除p节点后的节点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;

}