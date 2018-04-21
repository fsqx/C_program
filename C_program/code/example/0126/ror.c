#include <stdio.h>

unsigned int ror(unsigned int x, int n)
{
    unsigned int mask = 1u;
    int i;

    while (n < 0)
    {
        n = n + 32;
    }

    n = n % 32;
    for (i = 0; i < n; i++)
    {
        x = (x >> 1) | ((x & mask) << 31);
    }

    return x;
}


unsigned int ror2(unsigned int x, int n)
{
    return (x << (32 - n)) | (x >> n);
}

void print_bin(unsigned int x)
{
    unsigned int mask = 1u;
    int i;

    for (i = 31; i >= 0; i--)
    {
        if ((mask << i) & x)
        {
            printf("1");
        }else
        {
            printf("0");
        }
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    print_bin(0xdeadbeef);
    print_bin(ror2(0xdeadbeef,-65));
    print_bin(ror(0xdeadbeef,-65));

    return 0;
}
