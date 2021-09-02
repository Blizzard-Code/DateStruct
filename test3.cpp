#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//��ʼ��`��
//�ж��Ƿ�����`��
//�ж��Ƿ�Ϊ��`��
//β��`��
//���롤
//����
//��ת
//��ӡ`��
//����
//ɾ����

typedef struct Sqlist
{
	int* p;
	int cnt;
	int length;
}sqlist;
void init_Sqlist(sqlist *sql,int length)
{
	sql->p = (int *)malloc(sizeof(int));
	if (sql->p == NULL)
		printf("��̬�ڴ����ʧ�ܣ�����");
	else
	{
		printf("��̬�ڴ����ɹ�������,��ǰ����Ϊ%d\n",length);
		sql->cnt = 0;
		sql->length = length;

	}
}

bool is_empty(sqlist *sql)
{
	if (sql->cnt == 0)
		return true;
	else
		return false;
}

bool is_full(sqlist *sql)
{
	if (sql->cnt == sql->length)
		return true;
	else
		return false;
}
void show_Sqlist(Sqlist *sql)
{
	if (is_empty(sql))
	{
		printf("������\n");
	}
	else
	{
		/*for (int i = 0; i < sql->length; i++)
		{
			printf("%d ",sql->p[i]);
		}*/

		for (int i = 0; i < sql->cnt; i++)
		{
			printf("%d ", sql->p[i]);
		}
		printf("\n");
	}
}

void append_Sqlist(sqlist* sql, int add)
{
	if (is_full(sql))
	{
		printf("�������޷�������\n");
	}
	else
	{
		sql->p[sql->cnt] = add;
		sql->cnt++;
	}
}
void insert_Sqlist(sqlist *sql,int pos,int add)
{
	if (is_full(sql))
	{
		printf("�������޷�����\n");
	}
	else
	{
		for (int i = sql->cnt-1; i >=pos-1; i--)
		{
		sql->p[i+1] = sql->p[i];
		}
		sql->p[pos - 1] = add;
		sql->cnt++;
	}
}

void delete_Sqlist(sqlist* sql, int pos, int* del)
{
	if (is_empty(sql))
	{ 
		printf("���\n");
	}
	else if (pos<1 || pos>sql->cnt)
	{
		printf("λ��������");
	}
	else
	{
		*del = sql->p[pos - 1];
		for (int i = pos; i < sql->cnt; i++)
		{
		sql->p[i-1] = sql->p[i];
		}
		sql->cnt--;

	}
}

void inversion_Sqlist(sqlist *sql)
{
	if (is_empty(sql))
	{
		printf("���\n");
	}
	else
	{
		int i = 0;
		int j = sql->cnt-1;
		int t = 0;
		while (i<j)
		{
			int t;
			t = sql->p[i];
			sql->p[i] = sql->p[j];
			sql->p[j] = t;
			i++;
			j--;
		}
			printf("��ת�ɹ�");
	}
}

void sort_Sqlist(sqlist* sql)
{
	int i;
	int j;
	int t;
	for ( i = 0; i < sql->cnt; i++)
	{
		for(j=i+1;j< sql->cnt;j++)
		{
			if (sql->p[i] > sql->p[j])
			{
				t = sql->p[i];
				sql->p[i] = sql->p[j];
				sql->p[j] = t;
			}
		}
	}
}
int main()
{	
	sqlist sql;
	init_Sqlist(&sql,4);
	/*show_Sqlist(&sql);
	append_Sqlist(&sql,2);
	append_Sqlist(&sql, 2);
	show_Sqlist(&sql);
	insert_Sqlist(&sql,2,4);*/
	append_Sqlist(&sql, 3);
	append_Sqlist(&sql, 2);
	show_Sqlist(&sql);
	/*insert_Sqlist(&sql, 2, 6);
	printf("��������");
	show_Sqlist(&sql);*/
	//int del;
	//delete_Sqlist(&sql, 3, &del);
	//printf("ɾ������Ϊ%d\n", del);
	//show_Sqlist(&sql);
	/*inversion_Sqlist(&sql);
	show_Sqlist(&sql);*/

	sort_Sqlist(&sql);
	show_Sqlist(&sql);
}