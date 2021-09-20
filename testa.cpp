#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
void f(int n)
{
	if (n == 1)
	printf("¹þ¹þ");
	else 
		f(n-1);
}
int main()
{
	f(3);

}
