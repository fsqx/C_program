#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int item;
    struct node *next;
}node;

node *head = NULL;

void swap(node *p, node *q);

/* 创建节点*/
node *mk_node(int data)
{
    node *p = (node *)malloc(sizeof(node));

    if(p == NULL)
    {
        printf("error!");
        exit(1);
    }
    
    p->item = data;
    p->next = NULL;
    return p;
}

/* 释放内存空间*/
void free_node(node *p)
{
    free(p);
}

/* 插入链表中*/
void insert_node(node *p)
{
    p->next = head;
    head = p;
}

/* 快速排序后插入链表中*/
void insert_node_seq(node *p)
{
    node *headcopy = head;

    /* 处理头指针指向的第一个元素*/
    /* 逻辑运算的短路法则*/
    if(headcopy == NULL || p->item < headcopy->item)
    {
        p->next = headcopy;
        head = p;
        return;
    }

    /*找到对应的位置*/
    while(headcopy->next != NULL)
    {
        if(p->item < headcopy->next->item)
        {
            break;
        }
        headcopy = headcopy->next;
    }
    
    p->next = headcopy->next;
    headcopy->next = p;
    return;
}

void insert_node_cycle(node *p)
{
    node *headcopy = head;

    if(head == NULL)
    {
        headcopy = p;
        p->next = head;
    }

    if(p->item < headcopy->item)
    {
        p->next = headcopy->next;
        headcopy = p;
    }
}

/* 遍历链表*/
void traversal(node *head)
{
    node *p = head;
    while(p != NULL)
    {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

/* 查找链表*/
node *search_node(int data)
{
    node *p = head;
    while(p != NULL)
    {
        if(data == p->item)
        {
            return p;
        }
        p = p->next;
    }
    printf("Cant find data!\n");
    return NULL;
}

/* 移除链表中的某个节点*/
void rm_node(node *p)
{
    node *pre = head;
    if(pre == p)
    {
        pre = p->next;
        p->next = NULL;
        return;
    }

    while(pre->next != NULL)
    {
        if(pre->next == p)
        {
            pre->next = p->next;
            p->next = NULL;
            return;
        }
        pre= pre->next;
    }
    return;
}

/* 链表逆序*/
node *reverse_node(node *head)
{
    node *p = head;
    node *tail = NULL;
    traversal(head);
    while(head->next != NULL)
    {
        p = head;
        while(p->next->next != NULL)
        {
            p = p->next;
        }

        /* 处理头节点*/
        if(tail == NULL)
        {
            tail = p->next;
        }
        p->next->next = p;
        p->next = NULL;
    }
    return tail;
}

/*链表逆序*/
node *reverse_node_p(node *head)
{
    node *p = head;
    node *pre = NULL;
    node *temp = NULL;

    while(p != NULL)
    {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }

    head = pre;
    return head;
}

/* 销毁链表*/
void destory_node(node *head)
{
    node *p = head;
    while(head != NULL)
    {
        head = head->next;
        free(p);
        p = NULL;
    }
}

/* 交换*/
void swap(node *p, node *m)
{
    int temp = 0;
    temp = p->item;
    p->item = m->item;
    m->item = temp;
}

/* 排序*/
/* 只交换链表的值，不破坏链表结构*/
node *seq_node(node *head)
{
    node *p = head;
    node *top = NULL;
    while(p->next != NULL)
    {
        top = p->next;
        while(top != NULL)
        {
            if(top->item < p->item)
            {   
                swap(top, p);
            }
            top = top->next;
        }
        p = p->next;
    }
    return head;
}

int main()
{
    node *p;
    int data;

    p = mk_node(45);
    insert_node_seq(p);
    traversal(head);
    p = mk_node(-12);
    insert_node_seq(p);
    traversal(head);
    p = mk_node(35);
    insert_node_seq(p);
    traversal(head);
    p = mk_node(0);
    insert_node_seq(p);
    traversal(head);
    p = mk_node(99);
    insert_node_seq(p);
    traversal(head);
    p = mk_node(2);
    insert_node_seq(p);
    traversal(head);
    p = mk_node(1);
    insert_node_seq(p);
    traversal(head);

    traversal(head);
    //scanf("%d", &data);
    //p = search_node(data);
    //traversal(reverse_node(head));
    //destory_node(head);
    //traversal(head);
    //printf("%p, %d, %d\n",p, data, p->item);
    //rm_node(p);
    //seq_node(head);
    //traversal(head);
    //traversal(reverse_node_p(head));
    return 0;
}
