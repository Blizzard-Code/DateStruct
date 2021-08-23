#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct Sqlist
{
	int* arr;
	int count;
	int length;
}SEQ;

void init_Sqlist(SEQ *sq,int length)
{
	sq->arr = (int*)malloc(sizeof(int) * length);
	if (sq->arr == NULL)
	{
		printf("动态分配内存失败");
		exit(-1);
	}
	else 
	{
		sq->count = 0;
		sq->length = length;
		printf("分配内存成功，长度为%d\n", sq->length);
	}
}
bool is_empty(SEQ* sq)
{
	if (sq->count == 0)
		return true;
	else
		return false;
}
bool is_full(SEQ *sq)
{
	if (sq->count == sq->length)
		return true;
	else
		return false;
}
void show_Sqlist(SEQ *sq)
{
	if (is_empty(sq))
	{
		printf("数组内容为空\n");
	}

	for (int i = 0; i < sq->count; i++)
	{
		printf("第%d 个数组内容为%d\n",(i+1),sq->arr[i]);
	}
}

bool append_Sqlist(SEQ *sq,int val)
{
	if (is_full(sq))
	{
		
		return false;
	}
	else
	{
		sq->arr[sq->count] = val;
		sq->count++;
		return true;
	}                                    
}
   bool insert_Sqlist(SEQ *sq,int pos,int val)
{
	if (is_full(sq))
		return false;
	if (pos<1 || pos>sq->count + 1)
		return false;
	
	for (int i = sq->count - 1; i >= pos - 1; i--)
		{
			sq->arr[i + 1] = sq->arr[i];
		}
	sq->arr[pos - 1] = val;
	sq->count++;
	return true;
}
   bool delete_Sqlist(SEQ* sq, int pos, int* e)
   {
	   if (is_empty(sq))
		   return false;
	   if (pos<1 || pos >sq->count)
		   return false;  
	   *e = sq->arr[pos-1];
	   int i = pos - 1;
	   for (i;i<sq->count-1;i++)
	   {
		   sq->arr[i]=sq->arr[i+1];
	   }
	   sq->count--;
   }

   void inversion_Sqlist(SEQ *sq)
   {
	   int i = 0;
	   int j = sq->count - 1;
	   int t;
	   while (i<j)
	   {
		   t = sq->arr[i];
		   sq->arr[i] = sq->arr[j];
		   sq->arr[j] = t;
		   i++;
		   j--;
	   }
   }    
 
 void  sort_Sqlist(SEQ *sq)
   {
	 int i;
	 int j;
	 for (i = 0; i < sq->count; i++)
	 {
		 for (int j=i+1;j<sq->count;j++)
		 {
			 if (sq->arr[i] > sq->arr[j])
			 {
				 int t;
				 t = sq->arr[i];
				 sq->arr[i] = sq->arr[j];
				 sq->arr[j] = t;

			 }
		 }
	 }
   }

int main()
{
	SEQ sq;
	init_Sqlist(&sq,6);
	append_Sqlist(&sq, 12);
	append_Sqlist(&sq, 13);
	append_Sqlist(&sq, 14);
	append_Sqlist(&sq, 51);
	append_Sqlist(&sq, 14);
	show_Sqlist(&sq);
	printf("-------------\n");
	sort_Sqlist(&sq);
	show_Sqlist(&sq);

	/*int e;
	printf("-------------\n");
	delete_Sqlist(&sq,2,&e);
	show_Sqlist(&sq);
	inversion_Sqlist(&sq);*/

	/*printf("-------------\n");
	inversion_Sqlist(&sq);
	show_Sqlist(&sq);*/

	/*show_Sqlist(&sq);
	if(!insert_Sqlist(&sq, 2, 4))
		printf("满了");
	printf("-------------\n");
	show_Sqlist(&sq);*/

	/*append_Sqlist(&sq, 51);
	append_Sqlist(&sq, 1);
	append_Sqlist(&sq, 1);
	if (append_Sqlist(&sq, 1))
		printf("满了");
	show_Sqlist(&sq);
	insert_Sqlist(&sq,1,3 );*/

	sort_Sqlist(&sq);

}
