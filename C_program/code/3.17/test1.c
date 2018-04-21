/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：test1.c
*   创 建 者：wy
*   创建日期：2018年03月17日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    return a + b;
}
int main()
{
    int (*p)(int a, int b) = add;
    printf("%d\n", add(3, 5));
    printf("%d\n", p(3, 5));
    return 0;
}
