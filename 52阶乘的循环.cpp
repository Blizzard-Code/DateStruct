#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
int main()
{
	int val;
	int i,mult=1,s;

	printf("������һ������");
	printf("val= ");
	scanf_s("%d", &val);
	for (int i = 1; i <= val; i++)
	{
		mult = mult * i;
	}
		printf("%d���ǣ�%d", val, mult);


}
