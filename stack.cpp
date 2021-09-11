#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	int data;
	struct Node* pNext;

}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

void init(PSTACK ps)
{
	ps->pBottom = (PNODE)malloc(sizeof(NODE));
	if (ps->pBottom == NULL)
	{
		printf("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü\n");
		exit(-1);
	}
	else
	{
		ps->pTop = ps->pBottom;
		ps->pTop->pNext = NULL;
	}
}

void push(PSTACK ps,int val)
{
	PNODE pNew =(PNODE) malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		printf("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü\n");
		exit(-1);
	}
	else
	{
		pNew->data = val;
		pNew->pNext = ps->pTop;
		ps->pTop = pNew;
	}

}

void traverse(PSTACK ps)
{
	PNODE p = ps->pTop;
	while (p!=ps->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool pop(PSTACK ps,int *pVal)
{
	if (ps->pBottom == ps->pTop)
		return false;
	else
	{
		PNODE p;
		p = ps->pTop;
		*pVal = p->data;
		ps->pTop = p->pNext;
		free(p);
		p = NULL;
	
	}

}
int main()
{
	STACK S;
	int val;
	init(&S);
	push(&S,5);
	push(&S, 4);
	push(&S, 3);
	push(&S, 2);
	push(&S, 1);
	traverse(&S);
	pop(&S,&val);
	traverse(&S);


}
