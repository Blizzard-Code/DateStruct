#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int sid;
    int age;
};
// int f()
// {
//     // int j=20;
//     // return j;
// }
struct Student* CreateStudent()
{
    struct Student* p = (struct Student*)malloc(sizeof(struct Student));
    // p->age=18;
    // p->sid=2019;
    // /*
    (*p).sid = 2020;
    (*p).age = 18;
    // */
    return p;
}
void showStudent(struct Student* pst)
{
    printf("%d %d", pst->sid, pst->age);
}
int main()
{
    // int i=10;
    // i=f();
    // printf("i=%d",i);
    struct Student* ps;
    ps = CreateStudent();
    showStudent(ps);
}