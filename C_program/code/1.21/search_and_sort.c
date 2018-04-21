#include <stdio.h>

void bubble_sort(int *sheet, int len_of_sheet);
int search(int *sheet, int len_of_sheet, int search_number);
int main()
{
    int i = 0;
    int sheet[10] = {42, 54, 24, 34, 78, 66, 39, 15, 45, 88};
   
    //bubble_sort(sheet, sizeof(sheet)/sizeof(sheet[0]));
    printf("sheet[%d] = %d\n",search(sheet,sizeof(sheet)/sizeof(sheet[0]),24),24);
}

/*冒泡法排序*/
void bubble_sort(int *sheet, int len_of_sheet)
{
    int i = 0;
    int k = 0;
    int flag = 1;
    int temp;
    
    for(i = 0; i < len_of_sheet - 1; i++)
    {
        for(k = 0; k < len_of_sheet - i - 1; k++)
        {
            if(*(sheet + k) > *(sheet + k + 1))
            {
                temp = *(sheet + k);
                *(sheet + k) = * (sheet + k +1);
                *(sheet + k + 1) = temp;
            }     
        }
    }
    
}

/*二分法查找*/
int search(int *sheet, int len_of_sheet, int search_number)
{
    int min = 0;
    int max = len_of_sheet - 1;
    int average = (min + max) / 2;
    bubble_sort(sheet, len_of_sheet);
    /*判断首尾是否是要找的数*/
    if(*sheet == search_number)
    {
        return 0;
    }
    if(*(sheet + max) == search_number)
    {
        return max;
    }

    /*二分法查找*/
    while(average != min)
    {
        if(*(sheet + average) == search_number)
        {
            return average;
        }
        else if(*(sheet + average) > search_number)
        {
            max = average;
        }
        else
        {
            min = average;
        }
        average = (min + max) / 2;
    }
    return -1;

}

