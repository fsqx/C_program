#include <stdio.h>


void print_array(int a[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int a[], int len)
{
    int i;
    int j;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a + j, a + j + 1);
            }
        }
    }

}

int bin_find(int a[], int begin, int end,int target)
{
    int mid;

    while (begin <= end)
    {
        mid = (begin + end) / 2;
        if (a[mid] == target)
        {
            return mid;
        }else if(a[mid] > target)
        {
            end = mid - 1;
        }else
        {
            begin = mid + 1;
        }
    }

    return -1;
}

int bin_find_r(int a[], int begin, int end,int target)
{
    int mid = (begin + end) / 2;
    if (begin > end)
    {
        return -1;
    }

    if (a[mid] == target)
    {
        return mid;
    }else if(a[mid] > target)
    {
        return bin_find_r(a, begin, mid - 1, target);
    }else
    {   
        return bin_find_r(a, mid + 1, end, target);
    }
}

int main()
{

    int a[] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    int len = sizeof(a) / sizeof(a[0]);
    int pos;
    int target;
    print_array(a, len);
    bubble_sort(a, len);
    print_array(a, len);
    scanf("%d",&target);
    pos = bin_find_r(a, 0, len - 1, target);
    if (pos == -1)
    {
        printf("Can't find target %d\n",target);
    }else
    {
        printf("%d %d %d\n", pos, target, a[pos]);
    }

    return 0;
}
