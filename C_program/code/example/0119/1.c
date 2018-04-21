#include <stdio.h>

char *up_case(char *p)
{
    char *o_p = p;
    while (*p != '\0')
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p = *p + 'A' - 'a';
        }
        p++;
    }

    return o_p;
}

int main()
{
    char p[] = "Helloworld!";
    printf("%s\n",up_case(p));

    return 0;
}
