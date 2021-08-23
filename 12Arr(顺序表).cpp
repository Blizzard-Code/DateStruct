#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//定义一个数据类型，数据类型的名字叫struct Arr, 该数据类型有三个成员，分别是pBase len,cnt
struct Arr
{
	int* pBase;//存储数组第一个元素的地址
	int len;//数组所能容纳的最大元素个数
	int cnt;//当前数组有效元素的个数
  //  int increment;//自动增长因子

};
//初始化数组
void init_arr(struct Arr* pArr, int length);
//末尾追加
bool append_arr(struct Arr* pArr, int val);
//在第pos个位置上插入val数字,pos的值从1开始
bool insert_arr(struct Arr* pArr, int pos, int val);
//在第pos个位置删除数字，并用变量val保存删除的值;
bool delete_arr(struct Arr* pArr, int pos, int* pVal);
//int get();
//判断是否为空
bool is_empty(struct Arr* pArr);
//判断是否已满
bool is_full(struct Arr* pArr);
//对数组排序
void sort_arr(struct Arr* pArr);
//打印数组
void show_arr(struct Arr* pArr);
//倒置数组
void inversion_arr(struct Arr* pArr);
//查找第
/*void findElem(struct Arr* pArr, int e);

查找第pos位置元素的内容，并返回内容
bool findElem2(struct Arr* pArr, int pos, int* e);
*/
int main()
{
	struct Arr arr;
	int val;
	int e;
	int save;
	init_arr(&arr, 6);
	//    printf("%d",arr.len);
	append_arr(&arr, 12);
	append_arr(&arr, 23);
	append_arr(&arr, 14);
	append_arr(&arr, 51);
	show_arr(&arr);
	printf("-----------");
	insert_arr(&arr, 2, 4);
	show_arr(&arr);
	//append_arr(&arr, 5);
	//insert_arr(&arr, 5, 1);
	//insert_arr(&arr, 6, 1);

	/*if (append_arr(&arr, 8))
	{
		printf("插入成功\n");
	}
	else
	{
		printf("追加失败\n");
	}*/

	/*if (delete_arr(&arr, 10, &val))
	{
		printf("删除元素成功\n");
		printf("您删除的元素是：%d\n", val);

	}
	else
	{
		printf("删除失败\n");
	}*/

	/*show_arr(&arr);
	inversion_arr(&arr);
	printf("倒置之后的数组元素内容是\n");
	show_arr(&arr);
	sort_arr(&arr);
	printf("排序之后的元素内容是\n");
	show_arr(&arr);*/
	//findElem(&arr, 2);

	/*if (findElem2(&arr, 2, &e))
	{
		printf("查找成功\n");
		printf("查找的元素为%d\n", e);
	}
	else
	{
		printf("查找失败");
	}*/

}
//初始化数组，动态分配内存
void init_arr(struct Arr* pArr, int length)
{
	//动态分配内存
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	//相当于pArr指针变量所指向的那个结构体变量的pBase
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败\n");
		exit(-1);//终止整个函数
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	//return;
}

//判断数组是否为空
bool is_empty(struct Arr* pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}

//判断数组是否满
bool is_full(struct Arr* pArr) {
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

//展示数组
void show_arr(struct Arr* pArr)
{
	if (is_empty(pArr))  //数组为空
	{
		printf("数组为空\n");
	}
	else//输出数组有效内容
	{
		int i;
		for (i = 0; i < pArr->cnt; i++)
			printf("%d ", pArr->pBase[i]);
		printf("\n");
	}
}

//在数组末尾添加元素， val是要添加的元素
bool append_arr(struct Arr* pArr, int val)
{
	//满时
	if (is_full(pArr))
		return false;
	//不满时追加
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

//在第pos个位置上插入元素，   pos 位置，val 要插入的元素
bool insert_arr(struct Arr* pArr, int pos, int val)
{
	if (is_full(pArr))
		return false;

	if (pos<1 || pos>pArr->cnt + 1)//判断插入位置是否合法
		return false;

	for (int i = (pArr->cnt) - 1; i > pos - 1; i--)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}

	pArr->pBase[pos - 1] = val;
	(pArr->cnt)++;
	return true;

}

//删除第pos个位置的元素，并把删除的数存储 pos 位置 pval保存删除的元素的变量
bool delete_arr(struct Arr* pArr, int pos, int* pVal)
{
	if (is_empty(pArr))
		return false;

	if (pos<1 || pos>pArr->cnt)
		return false;

	*pVal = pArr->pBase[pos - 1];

	for (int i = pos; i < pArr->cnt; i++)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

//对数组倒序
void inversion_arr(struct  Arr* pArr)
{
	int i = 0;
	int j = pArr->cnt - 1;
	int t;
	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
}

//对数组排序
void sort_arr(struct Arr* pArr)
{
	int i, j, t;

	for (i = 0; i < pArr->cnt; i++)
	{
		for (j = i + 1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[i];
				pArr->pBase[i] = t;
				/*t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;*/
			}
		}
	}

}

/*
//查找x元素位置;
void findElem(struct Arr* pArr, int e)
{
	for (int i=0;i<pArr->len;i++)
	{
		if(e==pArr->pBase[i])
		{
			printf("已找到该元素，该元素的位置为%d", i + 1);
		}
	}
}

//查找第pos位置元素的内容，并返回内容
bool findElem2(struct Arr* pArr, int pos, int * e)
{
	if (is_empty(pArr))
		return false;
	*e = pArr->pBase[pos - 1];
		return true;
}
*/
