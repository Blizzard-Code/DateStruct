#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//����һ���������ͣ��������͵����ֽ�struct Arr, ������������������Ա���ֱ���pBase len,cnt
struct Arr
{
	int* pBase;//�洢�����һ��Ԫ�صĵ�ַ
	int len;//�����������ɵ����Ԫ�ظ���
	int cnt;//��ǰ������ЧԪ�صĸ���
  //  int increment;//�Զ���������

};
//��ʼ������
void init_arr(struct Arr* pArr, int length);
//ĩβ׷��
bool append_arr(struct Arr* pArr, int val);
//�ڵ�pos��λ���ϲ���val����,pos��ֵ��1��ʼ
bool insert_arr(struct Arr* pArr, int pos, int val);
//�ڵ�pos��λ��ɾ�����֣����ñ���val����ɾ����ֵ;
bool delete_arr(struct Arr* pArr, int pos, int* pVal);
//int get();
//�ж��Ƿ�Ϊ��
bool is_empty(struct Arr* pArr);
//�ж��Ƿ�����
bool is_full(struct Arr* pArr);
//����������
void sort_arr(struct Arr* pArr);
//��ӡ����
void show_arr(struct Arr* pArr);
//��������
void inversion_arr(struct Arr* pArr);
//���ҵ�
/*void findElem(struct Arr* pArr, int e);

���ҵ�posλ��Ԫ�ص����ݣ�����������
bool findElem2(struct Arr* pArr, int pos, int* e);
*/
int main()
{
	struct Arr arr;
	int val;
	int e;
	int save;
	init_arr(&arr, 6);
	//    printf("%d",arr.len);
	append_arr(&arr, 12);
	append_arr(&arr, 23);
	append_arr(&arr, 14);
	append_arr(&arr, 51);
	show_arr(&arr);
	printf("-----------");
	insert_arr(&arr, 2, 4);
	show_arr(&arr);
	//append_arr(&arr, 5);
	//insert_arr(&arr, 5, 1);
	//insert_arr(&arr, 6, 1);

	/*if (append_arr(&arr, 8))
	{
		printf("����ɹ�\n");
	}
	else
	{
		printf("׷��ʧ��\n");
	}*/

	/*if (delete_arr(&arr, 10, &val))
	{
		printf("ɾ��Ԫ�سɹ�\n");
		printf("��ɾ����Ԫ���ǣ�%d\n", val);

	}
	else
	{
		printf("ɾ��ʧ��\n");
	}*/

	/*show_arr(&arr);
	inversion_arr(&arr);
	printf("����֮�������Ԫ��������\n");
	show_arr(&arr);
	sort_arr(&arr);
	printf("����֮���Ԫ��������\n");
	show_arr(&arr);*/
	//findElem(&arr, 2);

	/*if (findElem2(&arr, 2, &e))
	{
		printf("���ҳɹ�\n");
		printf("���ҵ�Ԫ��Ϊ%d\n", e);
	}
	else
	{
		printf("����ʧ��");
	}*/

}
//��ʼ�����飬��̬�����ڴ�
void init_arr(struct Arr* pArr, int length)
{
	//��̬�����ڴ�
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
	//return;
}

//�ж������Ƿ�Ϊ��
bool is_empty(struct Arr* pArr)
{
	if (0 == pArr->cnt)
		return true;
	else
		return false;
}

//�ж������Ƿ���
bool is_full(struct Arr* pArr) {
	if (pArr->cnt == pArr->len)
		return true;
	else
		return false;
}

//չʾ����
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
			printf("%d ", pArr->pBase[i]);
		printf("\n");
	}
}

//������ĩβ���Ԫ�أ� val��Ҫ��ӵ�Ԫ��
bool append_arr(struct Arr* pArr, int val)
{
	//��ʱ
	if (is_full(pArr))
		return false;
	//����ʱ׷��
	pArr->pBase[pArr->cnt] = val;
	(pArr->cnt)++;
	return true;
}

//�ڵ�pos��λ���ϲ���Ԫ�أ�   pos λ�ã�val Ҫ�����Ԫ��
bool insert_arr(struct Arr* pArr, int pos, int val)
{
	if (is_full(pArr))
		return false;

	if (pos<1 || pos>pArr->cnt + 1)//�жϲ���λ���Ƿ�Ϸ�
		return false;

	for (int i = (pArr->cnt) - 1; i > pos - 1; i--)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}

	pArr->pBase[pos - 1] = val;
	(pArr->cnt)++;
	return true;

}

//ɾ����pos��λ�õ�Ԫ�أ�����ɾ�������洢 pos λ�� pval����ɾ����Ԫ�صı���
bool delete_arr(struct Arr* pArr, int pos, int* pVal)
{
	if (is_empty(pArr))
		return false;

	if (pos<1 || pos>pArr->cnt)
		return false;

	*pVal = pArr->pBase[pos - 1];

	for (int i = pos; i < pArr->cnt; i++)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}

//�����鵹��
void inversion_arr(struct  Arr* pArr)
{
	int i = 0;
	int j = pArr->cnt - 1;
	int t;
	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--;
	}
}

//����������
void sort_arr(struct Arr* pArr)
{
	int i, j, t;

	for (i = 0; i < pArr->cnt; i++)
	{
		for (j = i + 1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[i];
				pArr->pBase[i] = t;
				/*t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;*/
			}
		}
	}

}

/*
//����xԪ��λ��;
void findElem(struct Arr* pArr, int e)
{
	for (int i=0;i<pArr->len;i++)
	{
		if(e==pArr->pBase[i])
		{
			printf("���ҵ���Ԫ�أ���Ԫ�ص�λ��Ϊ%d", i + 1);
		}
	}
}

//���ҵ�posλ��Ԫ�ص����ݣ�����������
bool findElem2(struct Arr* pArr, int pos, int * e)
{
	if (is_empty(pArr))
		return false;
	*e = pArr->pBase[pos - 1];
		return true;
}
*/
