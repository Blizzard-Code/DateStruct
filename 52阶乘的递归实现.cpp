#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
//�ٶ�n��ֵ��1�����1��ֵ
long f(long n)
{
	if (1 == n)
	{
		return 1;
	}
	else
	{
		return f(n - 1) * n;
	}
}
int main()
{

	printf("%d", f(5));
}
