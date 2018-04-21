/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：list_test.c
*   创 建 者：wy
*   创建日期：2018年03月18日
*   描    述：链表练习
*             头结点链表，新建节点，排序插入节点，销毁链表，
*             释放节点，查找节点，移除节点，逆序，遍历输出。
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int item;
    struct list *next;
}list;

/*头结点的建立*/
list head_node = {0, NULL};
list *head = &head_node;

/*新建节点*/list *mk_node(int item)
、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、、
    list *new_node = (list *)malloc(sizeof(list));

    if(new_node == NULL)
    {
        printf("error.");
        exit(1);
    }

    new_node->item = item;
    new_node->next = NULL;

    return new_node;
}

/*顺序插入*/
void seq_insert(list *p)
{
    if(p == NULL)
    {
        exit(1);
    }

    list *pre = head;
    while(pre->next != NULL)
    {
        if(pre->next->item > p->item)
        {
            break;
        }
        pre = pre->next;
    }
    
    p->next = pre->next;
    pre->next = p;
}

/*释放节点*/
void free_node(list *p)
{
    free(p);
}

/*销毁链表*/
void distory()
{
    list *p = head->next;
    while(p != NULL)
    {
        head->next = p->next;
        free_node(p);
        p = head->next;
    }
}
/*查找*/
list *search_node(int item)
{
    list *p = head->next;
    
    while(p != NULL)
    {
        if(p->item == item)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

/*移除节点*/
void rm_node(list *aim_node)
{
    list *pre = head;

    while(pre != NULL)
    {
        if(pre->next == aim_node)
        {
            pre->next = aim_node->next;
            aim_node->next = NULL;
            break;
        }
        pre = pre->next;
    }

}

/*逆序*/
void reverse()
{
    list *pre = NULL;
    list *p = head->next;
    list *next = NULL;

    while(p != NULL)
    {
        next = p->next;
        p->next = pre;
        pre = p;
        p = next;
    }

    head->next = pre;
}

/*遍历输出*/
void traversal()
{
    list *p = head->next;
    while(p != NULL)
    {
        printf("%d\t", p->item);
        p = p->next;
    }
    printf("\n");
}



int main()
{
    list *p = NULL;
    p = mk_node(65);
    seq_insert(p);
    p = mk_node(43);
    seq_insert(p);
    p = mk_node(25);
    seq_insert(p);
    p = mk_node(52);
    seq_insert(p);
    p = mk_node(11);
    seq_insert(p);

    traversal();
    reverse();
    traversal();
    p = search_node(25);
    rm_node(p);
    traversal();
    distory();
    traversal();

    return 0;
}
