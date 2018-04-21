/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：list1.c
*   创 建 者：wy
*   创建日期：2018年02月06日
*   描    述：头节点链表练习
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int item;
    struct list *next;
}list;

list head_node = {0,NULL};
list *head = &head_node;

/*申请空间生成节点*/
list *mk_node(int data)
{
    list *p = (list *)malloc(sizeof(list));

    if(p == NULL)
    {
        printf("error.\n");
        return NULL;
    }

    p->item = data;
    p->next = NULL;
    return p;
}

/*插入节点-尾插法*/
void insert_node(list *p)
{
    list *pre = head;

    while(pre->next != NULL)
    {
        pre = pre->next;
    }
    pre->next = p;
}

/*插入节点-快速排序*/
void insert_node_seq(list *p)
{
    list *pre = head;
    
    while(pre->next != NULL)
    {
        if(p->item < pre->next->item)
        {
            break;
        }
        pre = pre->next;
    }

    p->next = pre->next;
    pre->next = p;
}

/*查找*/
list *search(int data)
{
    list *pre = head;
    while(pre->next != NULL)
    {
        if(pre->next->item == data)
        {
            break;
        }
        pre = pre->next;
    }

    return pre->next;
}

/*移除节点*/
list rm_node(list *p)
{
    list *pre = head;
    while(pre->next != p)
    {
        pre = pre->next;
    }

    pre->next = p->next;
}

/*释放空间*/
void free_node(list *p)
{
    free(p);
}

/*逆序输出*/
void reverse_node()
{
    list *pre = NULL;
    list *p = head->next;
    list *temp = NULL;

    while(p != NULL)
    {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }
    head->next = pre;
}

/*遍历输出*/
void traversal()
{
    list *p = head;
    while(p->next != NULL)
    {
        printf("%d ", p->next->item);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    list *p = NULL;
    int data = 0;
    p = mk_node(2);
    insert_node_seq(p);
    p = mk_node(3);
    insert_node_seq(p);
    p = mk_node(50);
    insert_node_seq(p);
    p = mk_node(30);
    insert_node_seq(p);
    p = mk_node(20);
    insert_node_seq(p);
    p = mk_node(-11);
    insert_node_seq(p);
    p = mk_node(-65);
    insert_node_seq(p);
    p = mk_node(23);
    insert_node_seq(p);


    traversal();
    reverse_node();
    traversal();
    /* scanf("%d",&data); */
    p = search(50);
    printf("%p,data=%d,node=%d\n", p, data, p->item);
    p = search(20);
    printf("%p,data=%d,node=%d\n", p, data, p->item);
    /* rm_node(p); */
    /* traversal(); */

}


