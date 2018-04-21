#include <stdio.h>

extern int add(int m, int n);
int main()
{
    int c = 100;
    {
        int c = 203;
        printf("%d\n",c);
    }
    printf("%d\n", c);
    printf("%d\n", add(5, 12));
    return 0;
}
