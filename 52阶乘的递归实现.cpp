#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
//假定n的值是1或大于1的值
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
