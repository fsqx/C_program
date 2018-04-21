#include <stdio.h>

void littletobig(char a);
int main()
{
    char *str = "litTletoBig";
    while(*str != '\0')
    {
        littletobig(*str);
        str++;
    }
    printf("\n");
    return 0;
}

void littletobig(char a)
{
    if(a < 'z' && a > 'a')
    {
        a = a - ('a' - 'A');
    
    }
    printf("%c", a);
}
