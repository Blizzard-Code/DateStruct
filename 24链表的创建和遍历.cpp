#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;//������
	struct Node* pNext;//ָ����
}NODE,*PNODE;//NODE�൱�� struct Node*PNODE�൱�� struct Node *

PNODE create_list();
void traverse_list(PNODE pHead);

int main()
{
	PNODE pHead = NULL; //�ȼ��� struct Node *phead=NULL

	pHead = create_list();//����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
	traverse_list(pHead);

}

//����һ����ѭ��������
PNODE create_list()
{
	int len;//���������Ч�ڵ�ĸ���
	int i;
	int val;//������ʱ����û�����Ľڵ�ֵ

	//������һ���������Ч���ݵ�ͷ���
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//ͷ����
	if (pHead == NULL)
	{
		printf("����ʧ�ܣ�������ֹ\n");
		exit(-1);
	}
	PNODE pTail = pHead;//pTail��pHEAD��ָ��ͷ��� ��
	pTail->pNext = NULL;//ͷ����ָ������բ�

	printf("��������Ҫ��������ڵ�ĸ�����len = " );
	scanf_s("%d", &len);

	for ( i = 0; i < len; i++)
	{
		printf("������%d���ڵ��ֵ", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//��
		if (pNew == NULL)  
		{  
			printf("����ʧ�ܣ�������ֹ\n");
			exit(-1);
		}
		pNew->data = val; //������ʱ�ڵ��
		pTail->pNext = pNew; //ָ�������pNew�Ľڵ㣬pNew����pTail�ĺ��� ��
		pNew->pNext = NULL;//����Ľڵ��ָ����Ϊ�բ�
		pTail = pNew;//Ptail��Զָ��ָ��β�ڵ㣬��
	}
	printf("------------------------------\n");

	return pHead;

}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;//pָ���һ����Ч�ڵ�
	
	while (NULL != p)//�ж�pָ��Ľڵ��
	{
		int i = 1;
		printf("��%d���ڵ��������%d\n",i, p->data);
		i++;
		p = p->pNext;
	}
	printf("\n");
}