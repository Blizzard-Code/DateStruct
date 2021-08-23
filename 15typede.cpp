#include<stdio.h>

typedef int zhangsan; //为int 再重新夺取一个名字  zhangsan等价于int 
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST; //将已有的数据类型struct Student{int sid;char name[100];char sex;}取一个名字为ST
 
/*
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}*PST ; //将已有的数据类型struct Student{int sid;char name[100];char sex;}取一个名字为ST
//PST等价于struct Student *PST
*/
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}*PST, ST;//等价于 ST代布 struct Student,PST代布 struct Student * 不加typedef时 是定义变量

int main()
{
	//int i = 10;//等价于 zhangsan i=10;
	//zhangsan j = 12;
	//struct Student st;//等价于ST st
	//struct Student* ps = &st; //等价于 ST *ps
	//printf("%d", j);

	//struct Student st;
	//PST ps = &st;
	//ps->sid = 99;
	//printf("%d", st.sid);

	ST st; //struct Student st
	PST ps;//struct Student *ps

}