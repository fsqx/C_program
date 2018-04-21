#include <stdio.h>
#include <math.h>

int if_pefect_number(int num);  //判断是否是完数
int if_water_number(int num);   //判断是不是水仙花数
int total(int num);             //求一个数各个 位上数字之和
int if_prime_number(int num);   //判断是否是素数
int if_have_nine();             //是否有9
int factorial(int num);         //阶乘
void add_number();              //斐波那契数列
void find_factorial_num();      //abc = a! + b! + c!
void decimal_to_binary(int num);//十进制转换二进制
void decimal_to_octal(int num); //十进制转换八进制
void find_water_number();       //打印所有水仙花数
void decimal_to_hexadecimal(int num);//十进制转换十六进制
void find_pefect_number();      //打印所有完数
void find_prime_number();       //打印所有素数
void find_nine();               //100以内有多少9
void swap(int *num1, int *num2);

int main()
{
//    add_number();             //斐伯纳契数列
//    find_water_number();      //打印水仙花数
//    printf("%d\n", total(1233));//求一个数各位上数字之和
//    find_prime_number();        //打印所有素数
//    find_nine();
//    find_factorial_num();       //abc = a! + b! +c!
//    printf("%d\n",factorial(5));  
    decimal_to_binary(92);
//    printf("\n");
//    decimal_to_octal(92);
//    printf("\n");
//    decimal_to_hexadecimal(92);
//    printf("\n");
//    find_pefect_number();
#if 0
    int num1 = 15;
    int num2 = 13;
    printf("%d  %d\n", num1, num2);
    swap(&num1, &num2);
    printf("%d  %d\n", num1, num2);
#endif
    return 0;
}

/*斐波拉契数列*/
void add_number()
{
    int cnt = 0;
    int total1 = 0;
    int total2 = 1;

    while(total1 <  10000)
    {
        printf("%d\t", total1);
        total1 += total2;
        
        printf("%d\t", total2);
        total2 += total1;
        cnt++;

        if(cnt % 5 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    
}

/*判断是不是水仙花数*/
int if_water_number(int num)
{
    int total = 0;
    int numcopy = num;
    int temp;
    while(num > 0)
    {
        temp = num % 10;
        total = total + temp * temp * temp;
        num /= 10;
    }

    if(total == numcopy)
    {
        return 1;
    }
    return 0;
}

/*打印所有水仙花数*/
void find_water_number()
{
    int i = 100;
    for(; i < 1000; i++)
    {
        if(if_water_number(i))
        {
        printf("%d\n", i);
        }
    }
}

/*计算数各位上的数字之和*/
int total(int num)
{
    int total = 0;
    while(num > 0)
    {
        total = total + num % 10;
        num /= 10;
    }
    return total;
}

/*判断一个数是不是素数*/
int if_prime_number(int num)
{
    int flag = sqrt(num);
    int i = 2;
    for(; i <= flag; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/*打印所有素数*/
void find_prime_number()
{
    int i = 0;
    int cnt = 1;
    for(; i < 100; i++)
    {
        if(i == 2)
        {
            printf("2\t");
            cnt++;
        }
        if(i > 2 && if_prime_number(i))
        {
            printf("%d\t", i);
            cnt++;
        }

        if(cnt % 6 == 0)
        {
            printf("\n");
            cnt = 1;
        }
    }
    printf("\n");
}

/*打印所有的9*/
void find_nine()
{
    int i = 0;
    int cnt;
    for(; i < 100; i++)
    {
        if(if_have_nine(i))
        {
            printf("%d\n", i);
            cnt++;
        }       
    }
    printf("There are %d \'nines\'.\n",cnt);
}

/*判断一个数里是否有9*/
int if_have_nine(int num)
{
    int temp = 0;
    while(num > 0)
    {
        temp = num % 10;
        if(temp == 9)
        {
            return 1;
        }
        num /= 10;
    }
    return 0;
}

/*阶乘*/
int factorial(int num)
{
    int total = 1;
    while(num > 0)
    {
        total *= num;
        num--;
    }
    return total;
}

/*abc = a! + b! +c!*/
void find_factorial_num()
{
    int i = 1;
    int icopy;
    int temp = 0;
    int total = 0;
    
    for(i = 20;i < 1000; i++)
    {
        icopy = i;
        while(icopy > 0)
        {
            temp = icopy % 10;
            total += factorial(temp);
            icopy /= 10;       
        }        
        if(i == total)
        {
            printf("%d\n", total);
        }
        total = 0;
    }
}

void decimal_to_binary(int num)
{
    if(num != 0)
    {
        decimal_to_binary(num / 2);
        printf("%d",num % 2);
    } 
}

void decimal_to_octal(int num)
{
    int temp = num % 8;
    if(num != 0)
    {
        decimal_to_binary(num / 8);
        printf("%d",temp);
    } 

}
void decimal_to_hexadecimal(int num)
{
    int temp = num % 16;
    char sheet[15] = {'1', '2', '3', '4', '5', '6', '7', 
                        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    if(num != 0)
    {
        decimal_to_binary(num / 16);
        printf("%c",sheet[temp -1]);
    } 
}

int if_pefect_number(int num)
{
    int total = 0;
    int i = 1;
    while(num != i)
    {
        if(num % i == 0)
        {
            total += i;
        }
        i++;
    }
    if(total / 2 == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void find_pefect_number()
{
    int i = 0;
    for(; i < 10000; i++)
    {
        if(if_pefect_number(i))
        {
            printf("%d\n", i);
        }
    }
}

void swap(int *num1, int *num2)
{
    int temp; 
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
