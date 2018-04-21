#include <stdio.h>

double get_pi(long long  n)
{
    long long  i;
    int flag = 1;
    double total = 0.0;

    for (i = 0; i < n; i++)
    {
        total += flag * 1 / (2 * i + 1);
        flag = -flag;
    }
    
    return total * 4;
}

int main()
{
    printf("%.10f\n",get_pi(10));
    printf("%.10f\n",get_pi(100));
    printf("%.10f\n",get_pi(10000));
    printf("%.10f\n",get_pi(1000000));
    printf("%.10f\n",get_pi(100000000));
    printf("%.10f\n",get_pi(1000000000));
    return 0;
}
