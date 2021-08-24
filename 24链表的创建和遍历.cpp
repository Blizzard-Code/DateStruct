#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;//数据域
	struct Node* pNext;//指针域
}NODE,*PNODE;//NODE相当于 struct Node*PNODE相当于 struct Node *

PNODE create_list();
void traverse_list(PNODE pHead);

int main()
{
	PNODE pHead = NULL; //等价于 struct Node *phead=NULL

	pHead = create_list();//创建一个非循环单链表，并将该链表的头结点的地址赋给pHead
	traverse_list(pHead);

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
		int i = 1;
		printf("第%d个节点的数据是%d\n",i, p->data);
		i++;
		p = p->pNext;
	}
	printf("\n");
}