/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：1.c
*   创 建 者：wy
*   创建日期：2018年03月18日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>

void fun(int *p, int n)
{
    p = (int *)malloc(sizeof(int) * n);

    printf("%p\n", p);

    return;
} 

int main()
{
    int *p = NULL;
    
    fun(p, 10);

    printf("main:%p\n", p);

    return 0;
}
