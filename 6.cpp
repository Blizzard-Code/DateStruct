#include <stdio.h>
void f(int** q)  //�������ָ��p�ĵ�ַΪ   int *���ͱ����ĵ�ַ 
// ����Ҫ���ܵ�ַ�Ĳ���Ϊ int **  ����һ�� int *���ͱ�����ָ��
{
    // q=(int *)0xFFFFFFFF;
    *q = (int*)0xFFFFFFFF;

}
void g(int* cpoint) //�����pointָ��ĵ�ַ��point������j�ĵ�ַ�� ����int j�����ĵ�ַ��Ҫ���յ�ַ ��Ҫ��int *����
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