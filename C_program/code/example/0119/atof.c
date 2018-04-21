#include <stdio.h>

double my_atof(char *p)
{
    int flag = 1;
    double total = 0.0;
    double power = 0.1;

    if (*p == '-')
    {
        flag = -1;
        p++;
    }else if (*p == '+')
    {
        p++;
    }

    while (*p != '\0')
    {
        if (*p == '.')
        {
            p++;
            break;
        }
        total = total * 10 + *p - '0'; 
        p++;
    }
    
    while (*p != '\0')
    {
        total = total + (*p - '0') * power;
        power = power * 0.1;
        p++;
    }

    return total * flag;
}

int main()
{
    printf("%lf\n",my_atof("-123.375"));
    printf("%lf\n",my_atof("-123375"));
    return 0;
}
