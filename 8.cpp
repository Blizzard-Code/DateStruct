#include <stdio.h>
#include <string.h>
struct Student
{
    int sid;
    char name[200];
    int age;
};

void f(struct Student* pst)
{
    (*pst).sid = 20;
    pst->age = 20;
    strcpy(pst->name, "zs");
}

void g(struct Student* pst)
{
    printf("%d %s %d", pst->age, pst->name, pst->sid);
}

int main()
{
    struct Student st;
    f(&st);
    g(&st);
    // printf("%d %s %d",st.age,st.name,st.sid);
}