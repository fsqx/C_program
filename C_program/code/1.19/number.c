#include <stdio.h>

int if_water_number(int num);
int main()
{
    int i = 0;
    for(; i < 10000; i++)
    {
        if(if_water_number(i))
        {
            printf("%d\n",i);
        }
        
    }
    return 0;
}

int if_water_number(int num)
{
    int total = 0;
    int numcopy = num;
    int temp;
    while(num > 0)
    {
        temp = num % 10;
        total = total + temp * temp * temp;
        num /= 10;
    }
    if(total == numcopy)
    {
        return 1;
    }
    return 0;
}
