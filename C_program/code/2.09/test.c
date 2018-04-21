/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：test.c
*   创 建 者：wy
*   创建日期：2018年02月09日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
}node;

node head_node = {0, NULL};
node *head = &head_node;

/*制作节点*/
node *mk_node(int item)
{
    node *p = (node *)malloc(sizeof(node));

    if(p == NULL)
    {
        printf("error.");
        return NULL;
    }

    p->item = item;
    p->next = NULL;
    return p;
}

/*头插法*/
void insert_head(node *p)
{
    p->next = head->next;
    head->next = p;
}

/*尾插法*/
void insert_tail(node *p)
{
    node *pre = head;
    while(pre->next != NULL)
    {
        pre = pre->next;
    }
    pre->next = p;
}

/*插入排序*/
void insert_seq(node *p)
{
    node *pre = head;
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

/*释放节点*/
void free_node(node *p)
{
    free(p);
}

/*。*/
void reverse_node()
{
    node *p = head->next;
    node *pre = NULL;
    node *temp = NULL;
    
    while(p != NULL)
    {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }
    head->next = pre;
}

/*遍历*/
void traversal()
{
    node *p = head;
    while(p->next != NULL)
    {
        printf("%2d ",p->next->item);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    node *p = NULL;
#if 1
    p = mk_node(23);
    insert_seq(p);
    p = mk_node(12);
    insert_seq(p);
    p = mk_node(37);
    insert_seq(p);
    p = mk_node(34);
    insert_seq(p);
    p = mk_node(56);
    insert_seq(p);
    p = mk_node(26);
    insert_seq(p);
    p = mk_node(17);
    insert_seq(p);
    p = mk_node(8);
    insert_seq(p);
    p = mk_node(99);
    insert_seq(p);
#endif
    printf("%d\n",head->next->item);

    traversal();
    reverse_node();
    traversal();
}
