#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
////定义一个数据类型，数据类型的名字叫struct Arr, 该数据类型有三个成员，分别是pBase len,cnt
struct Arr
{
	int* pBase;//存储数组第一个元素的地址
	int len;//数组所能容纳的最大元素个数
	int cnt;//当前数组有效元素的个数
//    da
  //  int increment;//自动增长因子
};
void init_arr(struct Arr* pArr, int length);
bool append_arr();//末尾追加

bool insert_arr();
bool delete_arr();
int get();
bool is_empty(struct Arr* pArr);
bool is_full();
void sort_arr();
void show_arr(struct Arr* pArr);
void inversion_arr();

int main()
{
	struct Arr arr;
	init_arr(&arr, 6);
	//    printf("%d",arr.len);
	show_arr(&arr);

}

void init_arr(struct Arr* pArr, int length)
{
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
	return;
}
//判断数组是否为空 
bool is_empty(struct Arr* pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}
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
			printf("%d", pArr->pBase[i]);
		printf("\n");
	}
}

