#include <stdio.h>

int fact(int n)
{
    int total = 1;
    int i;

    if (n == 0)
    {
        return 1;
    }

    for (i = 1; i <= n; i++)
    {
        total = total * i;
    }

    return total;
}

int is_mysterious(int n)
{
    int total = 0;
    int o_n = n;

    while (n > 0)
    {
        total += fact(n % 10);
        n = n / 10;
    }

    if (total == o_n)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int main()
{
    int i = 100;

    for (i = 100; i <1000; i++)
    {
        if (is_mysterious(i) == 1)
        {
            printf("%d \n",i);
        }
    }

    return 0;
}
