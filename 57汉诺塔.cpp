#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
//��a�����n�����ӽ���b�ƶ���c��һ��ֻ���ƶ�һ���̣�������С������
//�Ȱ�a���ӵ�ǰn-1�����Ӵ�a����c�Ƶ�b
//��a���ϵ�n������ֱ���ƶ���c
//��b�����ϵ�n-1�����ӽ���a�Ƶ�c
void hannuota(int n, char A, char B, char C)
//A �����ӣ� B������C���ŵ�����
{
	/*�����1�����ӣ�
		ֱ�ӽ�A���������ӣ��Ƶ�C
	����
		�Ƚ�A������n - 1�����ӽ���C�Ƶ�B
		ֱ�ӽ�Aס�����Ӵ�A�Ƶ�C
		���B�����ϵ�n - 1�����ӽ���A�Ƶ�C*/
		if (1 == n)
		{
			printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
		}
		else
		{
			hannuota(n - 1, A, C, B);
			printf("�����Ϊ%d������ֱ�Ӵ�%c�����Ƶ�%c����\n", n, A, C);
			hannuota(n - 1, B, A, C);
		
		}


}
int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	printf("������Ҫ�ƶ����Ӹ���");
	scanf_s("%d", &n);
	hannuota(n, 'A', 'B', 'C');

}
