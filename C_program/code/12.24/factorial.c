#include <stdio.h>

int factorial(int num);
int calculate_num(int num, int factorial_sheet[]);

int main()
{
    int factorial_sheet[10] = {0};
    int i = 0;
    int j = 0;

    for(; i <= 9; i++)
    {
        factorial_sheet[i]=factorial(i);
        printf("factorial_sheet[%d]=%d\n", i, factorial_sheet[i]);
        
    }

    for(;j < 100000; j++)
        if(j == calculate_num(j, factorial_sheet))
        {
            printf("%d :%d\n", j, calculate_num(j, factorial_sheet));
        }
}

/*阶乘，用于计算1-9各数的阶乘结果*/
int factorial(int num) 
{
    //int factorial_num = 1; //保存阶乘最后结果

    if(num > 1)
    {
        /* 错误示范，--num表示执行这一句之前，num已经被赋值。	*/
        /* return num * factorial(--num);        	*/  
        return num * factorial(num - 1);    //用num-1 不用num--
    }
    else
    {
        return num;
    }
}
/*计算一个数各个位置上的数阶乘的累积和，各个数字的阶乘结果保存在数组中*/
int calculate_num(int num,int factorial_sheet[])
{
    int temp;
    int count_add = 0;
    while(num > 0)
    {
        temp = num % 10;
        count_add += factorial_sheet[temp];
        num /= 10;
    }
    return count_add;
}

