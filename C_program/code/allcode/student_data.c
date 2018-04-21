#include <stdio.h>

struct student
{
    int no;
    char name[12];
    char sex;
    char classs[12];
    int grade;
    struct student *next;
};

void print_struct(struct student *s)
{
    printf("%03d %-12s %c %-12s %3d\n", s->no, s->name, s->sex, s->classs, s->grade);
}

int main()
{
}

void test()
{
    struct student s[3] ={  {1, "wangming", 'm', "net", 78},
                            {2, "wangying", 'f', "net", 88},
                            {3, "wangning", 'm', "net", 98}};
    struct student *p;
    struct student *head = &s[0];
    s[0].next = &s[1];
    s[1].next = &s[2];
    s[2].next = NULL;

    p = head;
    
    while(p != NULL)
    {
        print_struct(p);
        p = p->next;
    }
}
