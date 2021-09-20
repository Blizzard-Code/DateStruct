#include <stdio.h>
#include<malloc.h>
#include<stdbool.h>
void g();
void k();
void f();
void g()
{
	printf("GGGGGG\n");
	k();
	printf("1\n");
}
void k()
{
	printf("KKKKKK\n");
	f();
	printf("2\n");
}
void f()
{
	printf("FFFFFF\n");
	printf("3");

}

int main()
{
	g();

}
