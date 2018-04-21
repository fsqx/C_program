#include <stdio.h>

int total(int num);
int main()
{
    printf("%d\n",total(123));
    return 0;
}

int total(int num)
{
    int total = 0;
    while(num > 0)
    {
        total =total + num % 10;
        num /= 10;
    }
    return total;
}
