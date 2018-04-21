#include <stdio.h>

int main()
{
    unsigned char a = -1;

    if (a == 255)
    {
        printf("unsigned char\n");
    }else
    {
        printf("signed char\n");
    }

    return 0;
}
