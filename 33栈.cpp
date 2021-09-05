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
	PNODE pTop;  //ָ��ջ��
	PNODE pBottom;//ָ��ջ��Ԫ�ص���һ�����
}STACK,*PSTACK;
//��ʼ��ջ
void init(PSTACK pS );

void push(PSTACK, int);

void traverse(PSTACK pS);

bool pop(PSTACK, int*);

bool clear(PSTACK pS);

int main()
{
	STACK S;//STACK �ȼ��� struct Stack ������һ���ڴ�ռ�����pTop,��pBottom
	int val;
	init(&S);//�����ջ
	push(&S,1);//ѹջ
	push(&S,2);
	push(&S, 3);
	push(&S, 4);
	traverse(&S);
	clear(&S);
	if (pop(&S, &val))
	{
		printf("��ջ�ɹ�����ջ��Ԫ����%d\n", val);
	}
	else
	{
		printf("��ջʧ��!\n");
	};
	
	traverse(&S);//�������


}

//�����ջ
void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));//����һ����㣬ʹջ��ָ��ýڵ㡣
	if (pS->pTop == NULL)
	{
		printf("��̬�ڴ����ʧ��");
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
//��ps��ָ���ջ��ջһ�Σ����ѳ�ջԪ�ش���pVal�β���ָ��ı�������ջʧ�ܷ���false;
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

//���
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