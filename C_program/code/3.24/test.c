/*================================================================
*   Copyright (C) 2018 LH elite training camp. All rights reserved.
*   
*   文件名称：test.c
*   创 建 者：wy
*   创建日期：2018年03月25日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <stdlib.h>

void fun(double aa, int *x, double *y)
{
    int int_num = aa;
    *x = int_num;
    *y = aa - *x;
}

int main()
{
    int a = 0;
    double b = 0.0;
    double f = 5104.758300;
    fun(f, &a, &b);
    printf("%d, %lf", a, b);

}
