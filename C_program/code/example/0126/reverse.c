#include <stdio.h>
#include <string.h>

void reverse(char *begin, char *end)
{
    char tmp;

    if (begin >= end)
    {
        return;
    }
    
    tmp = *begin;
    *begin = *end;
    *end = tmp;
    reverse(begin + 1, end - 1);
}

int main()
{
    char a[20] = "123456789";

    printf("%s\n",a);
    reverse(a, a + strlen(a) - 1);
    printf("%s\n",a);

    return 0;
}
