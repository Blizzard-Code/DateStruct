#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
//把a上面的n个盘子借助b移动到c，一次只能移动一个盘，大盘在小盘子下
//先把a柱子的前n-1个盘子从a借助c移到b
//把a柱上第n个盘子直接移动到c
//把b柱子上的n-1个盘子借助a移到c
void hannuota(int n, char A, char B, char C)
//A 放盘子， B借助，C最后放的柱子
{
	/*如果是1个盘子，
		直接将A柱子上盘子，移倒C
	否则
		先将A柱子上n - 1个盘子借助C移到B
		直接将A住上盘子从A移到C
		最后将B柱子上的n - 1个盘子借助A移到C*/
		if (1 == n)
		{
			printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
		}
		else
		{
			hannuota(n - 1, A, C, B);
			printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
			hannuota(n - 1, B, A, C);
		
		}


}
int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	printf("请输入要移动盘子个数");
	scanf_s("%d", &n);
	hannuota(n, 'A', 'B', 'C');

}
