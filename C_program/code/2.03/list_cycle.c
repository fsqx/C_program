/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：list_cycle.c
*   创 建 者：wy
*   创建日期：2018年02月08日
*   描    述：循环链表
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int item;
    struct list *next;
}list;

list head_node = {0,&head_node};
/* list tail_node = {0,&head_node}; */
list *head = &head_node;
/* list *tail = head; */

/*制作节点*/
list *mk_node(int item)
{
    list *p = (list *)malloc(sizeof(list));

    if(p == NULL)
    {
        printf("error.\n");
        return NULL;
    }

    p->item = item;
    p->next = NULL;
    return p;
}

/*插入环形链表中*/
void insert_node(list *p)
{
    list *pre = head;
    
    p->next = pre->next;
    pre->next = p;

}

/*遍历*/
void traveral()
{
    list *p = head;
    while(p->next != head)
    {
        p = p->next;
        printf("%d ", p->item);
    }
    printf("\n");

}

/*删除节点*/
void rm_node(list *p)
{
    list *node = head;
    while(node->next != head)
    {

        if(node->next == p)
        {
            node->next = p->next;
            p->next = NULL;
            return;
        }
        node = node->next;
    }
}

list *search_node(int item)
{
    list *node = head;
    while(node->next != head)
    {
        node = node->next;
        if(node->item == item)
        {
            return node;
        }
    }

    return NULL;
}

void joseph_cycle()
{
    int cnt = 0;
    list *p = head;
    list *temp = NULL;
    int i = 40;
    while(i-- > 0)
    {
        cnt++;
        /* 跳出循环的条件*/
        if((head->next == p) && (p->next == head))
        {
            break;
        }

        /* 处理头结点进入循环的情况*/
        if(p == head)
        {
            //printf("a\n");
            cnt--;
            p = p->next;
            continue;
        }

        /*按情况移除节点*/
        if(cnt % 3 == 0)
        {
            temp = p;
            p = p->next;
            printf("%d\n", temp->item);
            rm_node(temp);
            cnt = 0;
            continue;
        }
        p = p->next;
    }

    printf("%d\n", p->item);
}

int main()
{
    int temp;
    list *p = NULL; 
    p = mk_node(10);
    insert_node(p);
    p = mk_node(9);
    insert_node(p);
    p = mk_node(8);
    insert_node(p);
    p = mk_node(7);
    insert_node(p);
    p = mk_node(6);
    insert_node(p);
    p = mk_node(5);
    insert_node(p);
    p = mk_node(4);
    insert_node(p);
    p = mk_node(3);
    insert_node(p);
    p = mk_node(2);
    insert_node(p);
    p = mk_node(1);
    insert_node(p);

    traveral();
    joseph_cycle();
#if 0
    scanf("%d", &temp);
    p = search_node(temp);
    rm_node(p);
    traveral();
#endif
}


