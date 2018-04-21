/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：list.c
*   创 建 者：wy
*   创建日期：2018年03月15日
*   描    述：
*
================================================================*/
#include <stdio.h>
#include <stdlib.h>

typedef struct list 
{
    int item;
    struct list *next;
}list;

list head_node = {0, NULL};
list *head = &head_node;

list *mk_node(int item)
{
    list *new_node = (list *)malloc(sizeof(list));
    if(new_node == NULL)
    {
        printf("error.\n");
        return NULL;
    }

    new_node->item = item;
    new_node->next = NULL;
    return new_nede;
}

list behand_insert()

int main()
{
    return 0;
}
