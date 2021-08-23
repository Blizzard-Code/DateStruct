#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
////����һ���������ͣ��������͵����ֽ�struct Arr, ������������������Ա���ֱ���pBase len,cnt
struct Arr
{
	int* pBase;//�洢�����һ��Ԫ�صĵ�ַ
	int len;//�����������ɵ����Ԫ�ظ���
	int cnt;//��ǰ������ЧԪ�صĸ���
//    da
  //  int increment;//�Զ���������
};
void init_arr(struct Arr* pArr, int length);
bool append_arr();//ĩβ׷��

bool insert_arr();
bool delete_arr();
int get();
bool is_empty(struct Arr* pArr);
bool is_full();
void sort_arr();
void show_arr(struct Arr* pArr);
void inversion_arr();

int main()
{
	struct Arr arr;
	init_arr(&arr, 6);
	//    printf("%d",arr.len);
	show_arr(&arr);

}

void init_arr(struct Arr* pArr, int length)
{
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	//�൱��pArrָ�������ָ����Ǹ��ṹ�������pBase 
	if (NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ��\n");
		exit(-1);//��ֹ��������		
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}
//�ж������Ƿ�Ϊ�� 
bool is_empty(struct Arr* pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}
void show_arr(struct Arr* pArr)
{
	if (is_empty(pArr))  //����Ϊ�� 
	{
		printf("����Ϊ��\n");
	}
	else//���������Ч���� 
	{
		int i;
		for (i = 0; i < pArr->cnt; i++)
			printf("%d", pArr->pBase[i]);
		printf("\n");
	}
}

