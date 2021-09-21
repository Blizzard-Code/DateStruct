#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void Quick_Sort(int* a, int low, int high);
int FindPos(int* a, int low, int high);
int main()
{
	int a[6] = { 2,1,0,5,4,3 };
	int i;
	Quick_Sort(a, 0, 5);//�ڶ���������ʾ��һ��Ԫ���±���������ʾ���һ��
	for (i = 0; i < 6; i++)
	{
		printf("%d", a[i]);
		printf("\n");
	}
}
void Quick_Sort(int* a, int low, int high)
{
	int pos;
	if (low < high)
	{
		pos = FindPos(a, low, high);
		Quick_Sort(a, low, pos - 1);
		Quick_Sort(a, pos + 1, high);
	}
}
int FindPos(int* a, int low, int high)
{
	int val = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= val)
			--high;
			a[low] = a[high];


		while (low < high && a[low] <= val)
			++low;
			a[high] = a[low];
	}
	a[low] = val;
	return high;//������low
}