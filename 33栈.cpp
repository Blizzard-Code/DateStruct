#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	int data;
	struct Node* pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;  //指向栈顶
	PNODE pBottom;//指向栈底元素的下一个结点
}STACK,*PSTACK;
//初始化栈
void init(PSTACK pS );

void push(PSTACK, int);

void traverse(PSTACK pS);

bool pop(PSTACK, int*);

bool clear(PSTACK pS);

int main()
{
	STACK S;//STACK 等价于 struct Stack 申请了一块内存空间内有pTop,和pBottom
	int val;
	init(&S);//造出空栈
	push(&S,1);//压栈
	push(&S,2);
	push(&S, 3);
	push(&S, 4);
	traverse(&S);
	clear(&S);
	if (pop(&S, &val))
	{
		printf("出栈成功，出栈的元素是%d\n", val);
	}
	else
	{
		printf("出栈失败!\n");
	};
	
	traverse(&S);//遍历输出


}

//造出空栈
void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));//创建一个结点，使栈顶指向该节点。
	if (pS->pTop == NULL)
	{
		printf("动态内存分配失败");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pBottom->pNext = NULL;
	}
	
}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;

}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;

	while (p != pS->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}
bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}
//把ps所指向的栈出栈一次，并把出栈元素存入pVal形参所指向的变量，出栈失败返回false;
bool pop(PSTACK pS, int* pVal)
{
	if (empty(pS))
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
		return true;
	}
}

//清空
bool clear(PSTACK pS)
{
	if (empty(pS))
	{
		return false;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;

		while (p!=pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;

	}

}