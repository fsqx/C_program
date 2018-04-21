#include <stdio.h>

int my_strlen(char *str)
{
    int len = 0;

    while (*str != '\0')
    {
        len++;
        str++;
    }

    return len;
}

int my_strcmp(char *s1,char *s2)
{
    while (*s1 != '\0')
    {
        if (*s1 != *s2)
        {
            break;
        }
        s1++;
        s2++;
    }

    if (*s1 == *s2)
    {
        return 0;
    }else if (*s1 > *s2)
    {
        return 1;
    }else
    {
        return -1;
    }
}

int my_strncmp(char *s1,char *s2,int n)
{
    int i = 0;

    while (*s1 != '\0' && i < n - 1)
    {
        if (*s1 != *s2)
        {
            break;
        }
        s1++;
        s2++;
        i++;
    }

    if (*s1 == *s2)
    {
        return 0;
    }else if (*s1 > *s2)
    {
        return 1;
    }else
    {
        return -1;
    }

}

char * reverse(char *str)
{
    int i = 0;
    char tmp;
    int len = my_strlen(str);
    

    for (i = 0; i < len / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
    
    return str;
}

char *my_strcpy(char *dest,char *src)
{
    char *o_dest = dest;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return o_dest;
}

int main()
{
    char s1[7] = "123456";
    char s2[4];

    printf("%s\n",my_strcpy(s2,s1));
    
    return 0;
}
