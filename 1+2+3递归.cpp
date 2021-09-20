#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

long f(int n)
{
	if (1 == n)
		return 1;
	else
	{
		return n + f(n - 1);
	}
	
}
int main()
{
	printf("5%d \n", f(100));

}
