#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int *p = *a;
    for(i = 0; i < 4; i++)
    {    for(j = i + 1; j < 4; j++)
        {
                temp = *(p + 4 * i + j);
                *(p + 4 * i + j) = *(p + 4 * j + i);
                *(p + 4 * j + i) = temp;
        }

    }
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}

void matrix_reverse(int a[4][4], int row, int col)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int *p = *a;
    for(i = 0; i < 4; i++)
    {    for(j = i + 1; j < 4; j++)
        {
                temp = *(p + 4 * i + j);
                *(p + 4 * i + j) = *(p + 4 * j + i);
                *(p + 4 * j + i) = temp;
        }
    }
}

void matrix_print(int a[4][4], int row, int col)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    int *p = *a;
    for(i = 0; i < 4; i++)
    {    for(j = i + 1; j < 4; j++)
        {
            printf("%2d ", *(p + 4 * i + j));
        }
    }
}

int *abd[](int a[][])
{
    return a;
}
