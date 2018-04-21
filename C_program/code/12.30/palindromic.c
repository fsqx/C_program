#include <stdio.h>

int if_palindromic(char word[]); //反转判断
int if_palindromic_num(int num); //数组判断
int if_palindromic_3(int num);   //迭代判断
int main()
{
    //char str[]="HellolleH";
    //char str[]="1221";
   
    int num = 1237873211;
    if(if_palindromic_3(num))
    {
        printf("This string is a palindromic.\n");
    }
    else
    {
        printf("This string is not a palindromic.\n");
    }
    return 0;
}

/* 判断字符串是否为回文 *
 * 数组方法，将字符串反转 */
int if_palindromic(char word[])
{
    int cnt = -1;
    int i = 0; 
    char *p ;
    p = word;
    while(*p != 0)
    {
        //printf("%c\n",*p);
       
        cnt ++;
        p ++;
    }
   
    //printf("%d", cnt);
    
    for(; i < cnt / 2; i++)
    {
        //printf("%c\n",*(word + i));
        
        if(*(word + i) != *(word + (cnt - i)))
        {
            return 0;
            
        }
    }
    return 1;
}

/* 数组方法 **
 * 容易溢出，或者浪费空间，相对繁琐*/
int if_palindromic_num(int num)
{
    int i = 0;
    int j = 0;
    int a[10]={ 0 };
    int o_num = num;
    while(o_num > 0)
    {
        a[i] = o_num % 10;
        i ++;
        o_num /= 10;
    }

    /*以下是调试内容，用于查看数组的赋值情况以及统计有用数字个数*
      printf("%d\n",i);
       for(j = 0; j <= i; j++)
       {
           printf("%d\n",a[j]);
        }
    */

    for(j = 0; j <=  i / 2; j++)
    {
        if(a[j] != a[i - j - 1])
        {
            return 0;
        }
    } 
    return 1;

}

/*迭代方法判断*/
int if_palindromic_3(int num)
{
    int total = 0;
    int o_num = num;
    while(o_num > 0)
    {
        total = total * 10 + (o_num % 10);
        o_num /= 10;    //取数的最后一位，迭代*10变成最高位，比较新得到的数和原数是否一致;
    }
    if(total == num)
    {
        return 1;
    }
    return 0;
}
