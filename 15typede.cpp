#include<stdio.h>

typedef int zhangsan; //Ϊint �����¶�ȡһ������  zhangsan�ȼ���int 
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST; //�����е���������struct Student{int sid;char name[100];char sex;}ȡһ������ΪST
 
/*
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}*PST ; //�����е���������struct Student{int sid;char name[100];char sex;}ȡһ������ΪST
//PST�ȼ���struct Student *PST
*/
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}*PST, ST;//�ȼ��� ST���� struct Student,PST���� struct Student * ����typedefʱ �Ƕ������

int main()
{
	//int i = 10;//�ȼ��� zhangsan i=10;
	//zhangsan j = 12;
	//struct Student st;//�ȼ���ST st
	//struct Student* ps = &st; //�ȼ��� ST *ps
	//printf("%d", j);

	//struct Student st;
	//PST ps = &st;
	//ps->sid = 99;
	//printf("%d", st.sid);

	ST st; //struct Student st
	PST ps;//struct Student *ps

}