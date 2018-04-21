#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
void guess_num(); //猜数字
int *more_then_int(int times, int store_num[times]); //40阶乘
int *add(int *store_num, int *add_num); //两个数组的数相加

int main()
{
    int i;  //赋初值
    int j;  //循环打印
    int sheet[MAX];
    for(i = 0; i < MAX; i++)
    {
        sheet[i] = 0;
    }
    more_then_int(40, sheet);
    for(j = MAX -1; j >= 0; j--)
    {
        printf("%d", *(sheet + j));
    }
    printf("\n");
    /* guess_num(); */
    return 0;

}

int *more_then_int(int times, int *store_num)
{
    int i;
    int j;
    *store_num = 1;
    int store_num_copy[MAX];

    /*乘法转换为加法运算*/
    for(i = 0; i < times; i++)
    {
        for(j = 0; j < MAX ; j++)
        {
            *(store_num_copy + j) = *(store_num + j);
            printf("%d",*(store_num_copy + j))
        }
        printf("\n");

        for(j = 0; j < i; j++)
        {
            add(store_num, store_num_copy);
        }
    }
    return store_num;
}


int *add(int *store_num, int *add_num)
{
    int i = 0;
    int temp; //保存同位相加的结果
    int nin = 0; //上一位的进位
    int *store_num_copy = store_num;
    for(;i < MAX; i++)
    {
        temp = *store_num_copy + *add_num + nin;
        *store_num_copy++ = temp % 10;
        *add_num++;
        nin = temp / 10;
    }
    return store_num;
}

/*
   int *add(int *store_num, int *add_num)
   {
   int i = MAX - 1;
   int temp; //保存同位相加的结果
   int nin = 0; //上一位的进位
   int *store_num_copy = store_num;
   for(;i >= 0; i--)
   {
   temp = *(store_num_copy + i) + *(add_num + i) + nin;
 *(store_num_copy + i) = temp % 10;
 nin = temp / 10;
 }
 return store_num;
 }
 */

void guess_num()
{
    int rand_num = 0;
    int guess_num = 0;
    int cnt = 0;
    srand(time(0));
    rand_num = rand() % 100 + 1;
    printf("猜猜计算机想的是什么？(1-100)\n");
    while(guess_num != rand_num)
    {
        cnt++;
        printf("第%d次，猜吧:", cnt);
        scanf("%d", &guess_num);
        if(guess_num < 100 && guess_num > 0){
            if(guess_num > rand_num)
                printf("大了，小点！\n");
            else
            {
                printf("小了，大点！\n");
            }
        }
        else
        {
            printf("不认得，重新输！\n");
        }
    }

        printf("真厉害，第%d次就猜对了！", cnt);
}
