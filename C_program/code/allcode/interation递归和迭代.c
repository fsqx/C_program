#include <stdio.h>
void count_step();  //记步函数
void swap(int *num_one, int *num_two);  //交换两个数
void hanoi(int from, int aux,int to,int n); //递归--汉诺塔解法
void print_sheet(int *sheet, int len_of_sheet); //打印数组
void end_to_begin(char *sheet); //递归--字符串逆序
void iteration_bubble_sort(int *sheet, int len_of_sheet);   //迭代--冒泡法排序
int min(int a, int b);  //返回两个数中较小的数
int rec_fibonacci(int n);   //递归--fibonacci数列
int ite_fibonacci(int n);   //迭代--fibonacci数列
int recursion_factorial(int num);   //递归--阶乘
int highest_common_factor(int num_one, int num_two); //递归--最大公约数
int iteration_search(int *sheet, int len_of_sheet, int search_num); //迭代--二分法查找
int recursion_search(int *sheet, int low, int high, int search_num);//递归--二分法查找


int main()
{
#if 0
    int a[] = {12, 24, 35, 19, 62, 55, 86, 94, 6};
    iteration_bubble_sort(a, sizeof(a)/sizeof(a[0])); //冒泡法排序
    /*二分法查找*/
    printf("a[%d] = %d\n",iteration_search(a, sizeof(a)/sizeof(a[0]), 94),94);
    printf("a[%d] = %d\n",recursion_search(a, 0, sizeof(a)/sizeof(a[0]), 35),35);
    
    printf("%d\n", recursion_factorial(5));   //计算阶乘
    printf("Highest common factor is:%2d\n",
                   highest_common_factor(12, 24));//最大公约数
    char p[]="123abcdefg";
    end_to_begin(p);
    printf("Highest common factor is:%2d\n",
           highest_common_factor(12, 24));  //最大公约数
    //hanoi(1,2,3,9);
#endif
    ite_fibonacci(100000);
    return 0;
}

/*交换两个数*/
void swap(int *num_one, int * num_two)
{
    int temp;
    temp = *num_one;
    *num_one = *num_two;
    *num_two = temp;
}

/*打印数组*/
void print_sheet(int *sheet, int len_of_sheet)
{
    int i;
    for(i = 0;i < len_of_sheet; i++)
    {
        printf("%2d ", sheet[i]);
    }
    printf("\n");
}

/*冒泡法排序*/
void iteration_bubble_sort(int *sheet, int len_of_sheet)
{
    int i;
    int j;
    print_sheet(sheet, len_of_sheet);
    for(i = 0; i < len_of_sheet - 1; i++)
    {
        for(j = 0; j < len_of_sheet - i -1; j++)
        {
            if(*(sheet + j) > *(sheet + j + 1))
            {
            swap(sheet + j, sheet + j +1);
            }
        }
    }
    print_sheet(sheet, len_of_sheet);
}

/*迭代--二分法查找*/
int iteration_search(int *sheet, int len_of_sheet, int search_num)
{
    int low = 0;
    int high = len_of_sheet;
    int average;
    while(low <= high)
    {
        average = (low + high) / 2;
        if(*(sheet + average) == search_num)
        {
            return average;
        }
        else if(*(sheet + average) < search_num)
        {
            low = average + 1;
        }
        else
        {
            high = average - 1;
        }
    }

    return -1;
}

/*递归--二分法查找*/
int recursion_search(int *sheet, int low, int high, int search_num)
{
    int average = (low + high) / 2;

    if(low > high)  //错误返回
    {
        return -1;
    }
    else if(*(sheet + average) == search_num)   //正确返回
    {
        return average;
    }
    else if(*(sheet + average) < search_num)    //迭代处理
    {
        return recursion_search(sheet, average, high, search_num);
    }
    else
    {
        return recursion_search(sheet, low, average, search_num);
    }
}

/*递归--阶乘*/
int recursion_factorial(int num)
{
    int total;
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return  recursion_factorial(num - 1) * num;
    }
}

/*返回两个数中较小的数*/
int min(int a,int b)
{
    if(a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/*递归--最大公约数*/
int highest_common_factor(int num_one, int num_two)
{
    int i = 2;
    int end = min(num_one, num_two);
    for(; i <= end; i++)
    {
        if(num_one % i == 0 && num_two % i == 0)
        {
            return highest_common_factor(num_one / i, num_two / i) * i;
        }
    }
    return 1;
}

/*递归--字符串逆序*/
void end_to_begin(char *sheet)
{
    if(*sheet != '\0')
    {
        end_to_begin(sheet + 1);
        
    }
    printf("%c", *sheet);
}

/*递归-fibonacci数列*/
int rec_fibonacci(int n)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    return rec_fibonacci(n - 1) + rec_fibonacci(n - 2);
}

/*迭代-fibonacci数列*/
int ite_fibonacci(int n)
{
    int num1 = 0;
    int num2 = 1;
    while(num1 < n)
    {
        printf("%d\n", num1);
        printf("%d\n", num2);
        num1 = num1 + num2;
        num2 = num1 + num2;
    }
}

/*递归--汉诺塔*/
void hanoi(int from, int aux, int to, int n)
{
    if(n == 1)
    {
        count_step();
        printf("Take no.%d from %d to %d\n", n, from, to);
    }
    else
    {
        hanoi(from, to, aux, n-1);
        count_step();
        printf("Take no.%d from %d to %d\n", n, from, to);
        hanoi(aux, from, to, n-1);
    }
}

/*汉诺塔记步函数*/
void count_step()
{
    static int num = 1; //静态数据区的变量自进程创建后不会被释放
    printf("%03d:", num);
    num++;
}
