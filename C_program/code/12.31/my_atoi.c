#include <stdio.h>

int my_atoi(char *str);

int main()
{
    char * a = "123455";
    char * b = "    wy123455";
    char * c = "    -123455";
    char * d = "    ismy-123455code23";
    
    printf("%d\n",my_atoi(a));
    printf("%d\n",my_atoi(b));
    printf("%d\n",my_atoi(c));
    printf("%d\n",my_atoi(d));
    return 0;
}

int my_atoi(char *str)
{
    int total = 0;
    int flag = 0;

    while(*str != '\0')
    {
        if(*str > '0' && *str < '9')
        {
            total = total * 10 + (*str - '0');
            if(*(str - 1) == '-')
            {
                flag = 1;
            }            
        }
        str ++;
    }
    
    if(flag)
    {
        return -total;
    }
    return total;
}
