#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Seqlist
{
	int* pBase;
	int length;
	int count;
}Seqlist;

void init_Seqlist(Seqlist *seq,int length)
{
	seq->pBase=(int*)malloc(sizeof(int) * length);

	if (seq->pBase == NULL)
		printf("动态分配内存失败\n");
	else
	{
		printf("动态分配内存成功\n");
		printf("------------------------\n");
		seq->length = length;
		seq->count = 0;
	}
}
bool is_full(Seqlist* seq)
{
	if (seq->count == seq->length)
		return true;
	else
		return false;
}
bool is_empty(Seqlist* seq)
{
	if (seq->count == 0)
		return true;
	else
		return false;
}
void append_Seqlist(Seqlist* seq, int val)
{
	if (is_full(seq))
		printf("表已满，无法继续插入\n");
	else
		seq->pBase[seq->count] = val;
	(seq->count)++;
}
void show_Seqlist(Seqlist* seq)
{
	if (is_empty(seq))
		printf("表为空\n");
	else
	{
		for (int i=0;i<seq->count;i++)
		{
			printf("%d ", seq->pBase[i]);
		}
		printf("\n");
	}
}
void insert_Seqlist(Seqlist* seq, int pos, int val)
{
	if (is_full(seq))
		printf("表已满，无法继续插入\n");
	else if (pos<=0 || pos>seq->count)
	{
		printf("位置输入有误");
	}
	else
	{
		int i= seq->count - 1;
		for (i;i>=pos-1 ;i--)
		{
			seq->pBase[i+1]= seq->pBase[i];
		}
		seq->pBase[pos - 1] = val;
		seq->count++;
	}

}
void delete_Seqlist(Seqlist* seq, int pos, int* e)
{
	if (is_empty(seq))
		printf("表为空");
	else if (pos <= 0 || pos > seq->count)
	{
		printf("位置输入有误");
	}
	else
	{
		int i = pos - 1;
		*e = seq->pBase[pos - 1];
		for (i;i<=pos;i++)
		{
			seq->pBase[i] = seq->pBase[i + 1];
		}
		seq->count--;
	}
}
void sort_Seqlist(Seqlist* seq)
{

	if (is_empty(seq))
		printf("表为空\n");
	else
	{
		int i, j, t;
		for ( i = 0; i < seq->count; i++)
		{
			for ( j = i+1; j < seq->count; j++)
			{
				if (seq->pBase[i] > seq->pBase[j])
				{
					t = seq->pBase[i];
					seq->pBase[i] = seq->pBase[j];
					seq->pBase[j] = t;

				}
			}
		}
	}
}
void inversion_sqlist(Seqlist *seq)
{
	if (is_empty(seq))
		printf("表为空\n");
	else
	{
		int i=0;
		int j=seq->count-1;
		int t;
		while (i<j)
		{
			t = seq->pBase[i];
			seq->pBase[i] = seq->pBase[j];
			seq->pBase[j] = t;
			i++;
			j--;
		}
	}
}
void find_ElemPos(Seqlist *seq,int pos,int *e)
{

	if (is_full(seq))
		printf("表已满\n");
	else if (pos <= 0 || pos > seq->count)
	{
		printf("位置输入有误");
	}
	*e = seq->pBase[pos - 1];
}
void find_Elem(Seqlist* seq, int e, int* pos)
{
	for (int i = 0; i < seq->count; i++)
	{
		if (e == seq->pBase[i])
		{
			*pos = i+1;
		}
	}
}
int main()
{
	Seqlist seq;
	init_Seqlist(&seq,6);
	append_Seqlist(&seq, 7);
	append_Seqlist(&seq, 3);
	append_Seqlist(&seq, 1);
	/*show_Seqlist(&seq);
	insert_Seqlist(&seq, 2, 5);*/
	show_Seqlist(&seq);
	//int e;
	//delete_Seqlist(&seq, 4, &e);
	//sort_Seqlist(&seq);
	//inversion_sqlist(&seq);
	show_Seqlist(&seq);
	//printf("%d", e);
	/*int e;
	find_ElemPos(&seq, 1, &e);
	printf("%d", e);*/
	int pos;
	find_Elem(&seq,3, &pos);
	printf("该元素位置在%d", pos);

}