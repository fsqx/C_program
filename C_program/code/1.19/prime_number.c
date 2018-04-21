#include <stdio.h>
#include <math.h>
int if_prime_number(int num);
int main()
{
    int i = 0;
    int cnt = 1;
    for(; i < 100; i++)
    {
        if(i == 2)
        {
            printf("2\t");
            cnt++;
        }
        if(i > 2 && if_prime_number(i))
        {
            printf("%d\t",i);
            cnt++;
        }

        if(cnt % 6 == 0)
        {
            printf("\n");
            cnt = 1;
        }
    }
    return 0;
}

int if_prime_number(int num)
{
    int flag = sqrt(num);
    int i = 2;
    for(; i <= flag; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
