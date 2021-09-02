#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;//������
	struct Node* pNext;//ָ����
}NODE,*PNODE;//NODE�൱�� struct Node *PNODE�൱�� struct Node *

PNODE create_list();
//��������
void traverse_list(PNODE pHead);
//�ж������Ƿ�Ϊ��
bool is_empty(PNODE pHead);
//��������
int length_list(PNODE pHead);
//��pHeadָ�������ĵ�pos���ڵ��ǰ�����һ���µĽ��  �ýڵ��ֵ��val,����pos��1��ʼ
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int* pVal);
//��������
void sort_list(PNODE pHead);


int main()
{
	PNODE pHead = NULL; //�ȼ��� struct Node *phead=NULL

	pHead = create_list();//����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
	traverse_list(pHead);
	int val;
	/*insert_list(pHead, 4, 33);
	traverse_list(pHead);*/

	if (delete_list(pHead, 3, &val))
		printf("ɾ���ɹ�,ɾ��Ԫ��Ϊ��%d\n", val);
	else
		printf("ɾ��ʧ��\n");
	traverse_list(pHead);
	/*if (is_empty(pHead))
		printf("����Ϊ��");
	else
	{
		printf("������");
	}*/


	/*int len = length_list(pHead);
	printf("������Ϊ%d\n", len);
	sort_list(pHead); 
	traverse_list(pHead);*/

	
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
		for (j = i + 1, q = p->pNext; j < len; j++,q=q->pNext)//��һ��Ԫ��
		{
			if (p->data > q->data)//������a[i] > a[j]
			{
				t = p->data; //������t=a[i];
				p->data = q->data;//a[i]=a[j]
				q->data = t;//a[j]=t
			}

		}
	}
}

//��pHeadָ�������ĵ�pos���ڵ��ǰ�����һ���µĽ��  �ýڵ��ֵ��val,����pos��1��ʼ
bool insert_list(PNODE pHead, int pos, int val)
{  //pos ��ֵ>1 && pos<=�������+1
	int i = 0;//i���ڼ�¼λ��ǰ�ģ���p���ڵ�λ�ã�i=0ʱ��pָ��ͷ���
	PNODE p = pHead;
	//�ж�ͷ����ָ�����Ƿ�Ϊ�գ����Ƿ�ָ������һ����Ч�ڵ㣻
	while (NULL!=p && i<pos-1)//���ڱ�֤p���ڵ�λ��
	{	//����Ϊ��ʱ��ʹpָ�򱻲��λ�õ�ǰһ���ڵ㣬
		//�ұ������λ��ǰ��һ��ֱ��ǰ�������������λ��ǰ�н�㣬
		p = p->pNext;//��������λ��ǰ���޽��ʱ��p=NULL����ѭ��
		++i;
	}
	//��pos=3,������Ϊ1�������λ��ǰ�޽�㣬p=NULL����ѭ��
	//�жϸ���
	if (i>pos-1 || NULL == p)//pos�Ǹ�����pos��Ч
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL==pNew)
	{
		printf("��̬�����ڴ�ʧ��\n");
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
	//ɾ��p�ڵ��Ľڵ�
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
	/*
	* free�ͷŵ���qָ����ָ�����malloc��������ڴ浥Ԫ,qָ�뱾���ǲ����ͷŵ�
	,����֮����Խ�qָ������ָ���µ��ڴ��ַ,
һ��Ƚϰ�ȫ��д���ǣ�free(p);  p=NULL;����free֮���ٸ�p��ֵΪNULL��
ԭ��freeָ�����ջط����p�Ŀռ䣬���ڴ��н�ͨ��malloc��p����ռ�󣬸ÿ�ռ�ʹ����ѷ���״̬��
����free�󣬸ÿ��ڴ�ʹ��ڿ��м��ɷ���״̬��
��ϸ��˵�������ڴ��л���һ������������ѷ��������malloc�󽫴ӿ�����Ϊ�����һ���ڴ�ռ䣬
�����ÿ��ڴ�ӿ�������ɾ�������õ��ѷ�������򣬵���free����ֽ������ѷ�������򻮷ֵ���������
����ʱ�㶨���ָ��p���Ǵ��ڵģ������Ұָ�롣�����ͻ�����ڴ�й¶�������ͻ���ڰ�ȫ���⡣
����Ҫ��p��һ��NULLֵ��
	*/
}