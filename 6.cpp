#include <stdio.h>
void f(int** q)  //传入的是指针p的地址为   int *类型变量的地址 
// 所有要接受地址的参数为 int **  定义一个 int *类型变量的指针
{
    // q=(int *)0xFFFFFFFF;
    *q = (int*)0xFFFFFFFF;

}
void g(int* cpoint) //传入的point指向的地址（point保存了j的地址） 即：int j变量的地址，要接收地址 则要用int *类型
{
    *cpoint = 12;
}
int main()
{
    int i = 9;
    int* p = &i;
    printf("%p\n", p);
    f(&p);
    printf("%p\n", p);

    int j = 10;
    int* point;
    point = &j;
    g(point);
    printf("%d", j);

}