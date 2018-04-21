#include <stdio.h>

int find_nine();
int main()
{
    int i = 0;
    for(;i < 100; i++)
    {
        if(find_nine(i))
        {
            printf("%d\t",i);
        }

    }
    return 0;
}

int find_nine(int num)
{
    while(num > 0)
    {
        if(num % 10 == 9)
        {
            return 1;
        }
        num /= 10;
    }
    return 0;
}


