#include <stdio.h>
#include <math.h>
#define MAX 9
void cnt();
void print(int *sheet);
void swap(int *num1, int *num2);
void print_matrix(int *sheet, int top, int number);

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_matrix(array, 0, MAX);
    return 0;
}

void print_matrix(int *sheet, int top, int number)
{
    int i = 0;
    int array[MAX] = {0};
    for(i = 0; i < MAX; i++)
    {
        *(array + i) = *(sheet + i);
    }

    if(top == number)
    {
        cnt();
        print(sheet);
        return;
    }
    else
    {
        for(i = top; i < number; i++)
        {
            swap((sheet + top), (sheet + i));
            print_matrix(sheet, top + 1, number);
            swap((sheet + i), (sheet + top));
        }
    }
}

void swap(int *num1, int *num2)
{
    int temp = 0;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
/*
void print(int *sheet)
{
    //printf("no.1  no.2    no.3\n");
    int i = 0;
    int j = 0;
    int row = sqrt(MAX);
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < row; j++)
        {
            printf("%d\t",*(sheet + i*row + j));
        }
        printf("\n");
    }
    printf("\n");
}
*/
void print(int *sheet)
{
    int i = 0;
    for(i = 0; i < MAX; i++)
    {
        printf("%d",*(sheet + i));
    }
    printf("\n");
}
void cnt()
{
    static int cnt = 1;
    printf("第%d个:", cnt);
    cnt++;
}
